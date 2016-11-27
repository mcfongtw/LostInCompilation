/*
 * TreeNode.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */
#include "algorithm/tree/TreeNode.h"

#include <exception>

#include "common/Utils.h"
#include "log/Logger.h"

TreeNode::TreeNode() {
	this->_parent = nullptr;
	this->_isRoot = true;
	this->_depth = 0;
	this->_state = NO_INTERNAL_ACTION;

	LOG(Logger::LEVEL_TRACE,
			"Creating <<" + util::Converts::numberToString(this)
					+ ">> TreeNode @["
					+ util::Converts::numberToString(this->_depth) + "]");
}

TreeNode::TreeNode(TreeNode* const that) {
	this->_parent = that->_parent;
	this->_isRoot = that->_isRoot;
	this->_depth = that->_depth;
	this->_state = that->_state;

	this->insertChildren(that->_children);

	LOG(Logger::LEVEL_TRACE,
			"Cloning <<" + util::Converts::numberToString(this)
					+ ">> TreeNode @["
					+ util::Converts::numberToString(this->_depth) + "]");
}

TreeNode::TreeNode(TreeNodePtr that) {
	this->_parent = that->_parent;
	this->_isRoot = that->_isRoot;
	this->_depth = that->_depth;
	this->_state = that->_state;

	this->insertChildren(that->_children);

	LOG(Logger::LEVEL_TRACE,
			"Cloning <<" + util::Converts::numberToString(this)
					+ ">> TreeNode @["
					+ util::Converts::numberToString(this->_depth) + "]");
}

TreeNode::~TreeNode() {
	this->_parent = nullptr;

	LOG(Logger::LEVEL_TRACE, "Deleting <<" + util::Converts::numberToString(this) + ">> TreeNode@["
					+ util::Converts::numberToString(this->_depth) + "]");
}

void TreeNode::insertChild(TreeNodePtr childPtr, ParentNodePtr parentPtr) {
	util::Conditions::requireNotNull(childPtr, "newly inserted tree ptr");
	util::Conditions::requireNotNull(childPtr, "parent tree ptr");

	this->_children.push_back(childPtr);

	childPtr->_isRoot = false;
	childPtr->_depth = this->_depth + 1;

	childPtr->_parent = parentPtr;
}

void TreeNode::insertChild(TreeNodePtr childPtr) {
    //TODO: is it possible to reuse insertChild(childPtr, this as smart_ptr)?
	util::Conditions::requireNotNull(childPtr, "newly inserted tree ptr");

	this->_children.push_back(childPtr);

	childPtr->_isRoot = false;
	childPtr->_depth = this->_depth + 1;

	childPtr->_parent = this;
}

void TreeNode::insertChildren(std::vector<TreeNodePtr>& childrenPtr) {
	util::Conditions::requireNotNull(&childrenPtr, "newly inserted children");

	for (size_t i = 0; i < childrenPtr.size(); i++) {
		TreeNodePtr childPtr = childrenPtr[i];
		this->insertChild(childPtr);
	}
}

size_t TreeNode::getNumOfChildren() {
	return this->_children.size();
}

size_t TreeNode::getChildIndexOf(TreeNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "get child index of patr");

	for (size_t i = 0; i < this->_children.size(); i++) {
		if (this->_children[i] == ptr) {
			return i;
		}
	}
	return -1;
}

bool TreeNode::isChildAt(size_t i) {
	return this->_children.size() > i;
}

TreeNodePtr TreeNode::getChildAt(size_t i) {
	util::Conditions::requireLessThan<int>(i, this->_children.size(),
			"AST children index ");

	return this->_children[i];
}

void TreeNode::replaceChildAt(size_t i, TreeNodePtr newPtr) {
	util::Conditions::requireLessThan<int>(i, this->_children.size(),
			"Tree children index ");

	this->_children.erase(this->_children.begin() + i);
	this->_children.insert(this->_children.begin() + i, newPtr);
}

void TreeNode::removeAllChildren() {
	this->_children.clear();
}

bool TreeNode::isRoot() {
//	return this->_parent == 0;
	return this->_isRoot;
}

bool TreeNode::isLeaf() {
	return this->_children.empty();
}

size_t TreeNode::getDepth() {
	return this->_depth;
}

void TreeNode::setState(TraverseAction action) {
	LOG(Logger::LEVEL_DEBUG,
			"Changing ST <<" + util::Converts::numberToString(this)
					+ ">> TreeNode@["
					+ util::Converts::numberToString(this->_depth) + "] from "
					+ util::Converts::numberToString(this->_state) + " to "
					+ util::Converts::numberToString(action));
	this->_state = action;
}

TraverseAction TreeNode::getState() {
	return this->_state;
}

std::string TreeNode::toString() {
	std::string result = "";

	//address
	result += "addr : " + util::Converts::numberToString(this) + "\n";

	//State
	for(size_t j = 0; j <= this->_depth; j++) {
		result += "\t";
	}
	if(this->_state == TRAVERSE_IN) {
		result += "ST : -->\n";
	} else if(this->_state == TRAVERSE_OUT) {
		result += "ST : <--\n";
	} else if(this->_state == TRAVERSE_SECOND) {
		result += "ST : -->-->\n";
	} else {
		result += "ST : N.A.\n";
	}

	//recursively drill down
	for(size_t i = 0; i < this->_children.size(); i++) {
		for(size_t j = 0; j <= this->_depth; j++) {
			result += "\t";
		}
		result += "[" + util::Converts::numberToString<size_t>(i) + "] : " + this->_children[i]->toString();
	}

	return result;
}

void TreeNode::setParent(ParentNodePtr ptr) {
	this->_parent = ptr;
}

ParentNodePtr TreeNode::getParent() {
	return this->_parent;
}

void TreeNode::replace(TreeNodePtr thatPtr) {
	util::Conditions::requireNotNull(thatPtr, "TreeNode::replace - new replaced AST Node");

	//change member variable
	thatPtr->_depth = this->_depth;
	thatPtr->_isRoot = this->_isRoot;

	//change children node
	thatPtr->insertChildren(this->_children);
	this->_children.clear();

	//change parent node
	thatPtr->_parent = this->_parent;
	if (this->_parent != nullptr) {
		size_t index = this->_parent->getChildIndexOf(this->getThisPtr());
		this->_parent->replaceChildAt(index, thatPtr);
	}
}

TreeNodePtr TreeNode::searchParent(TreeNodePtr target) {
	TreeNodePtr result = nullptr;

	for (size_t i = 0; i < this->_children.size(); i++) {
		TreeNodePtr child = this->_children[i];

		result = child->searchParent(target);

		if (child == target) {
			result = this->getThisPtr();
			break;
		}
	}

	return result;
}

TreeNodePtr TreeNode::getThisPtr() {
	TreeNodePtr ptr = nullptr;

	try {
		ptr = this->shared_from_this();
	} catch(std::bad_weak_ptr& e) {
		throw IllegalStateException("There must be at least one std::shared ref count for this before using shared_from_this()");
	}

	return ptr;
}
