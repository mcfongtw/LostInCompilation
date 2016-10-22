/*
 * VisitedTreeNode.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: Michael Fong
 */

#include "algorithm/tree/visitor/VisitedTreeNode.h"

#include <queue>

#include "common/Utils.h"
#include "log/Logger.h"

VisitedTreeNode::VisitedTreeNode() :
		TreeNode() {
	LOG(Logger::LEVEL_TRACE,
			"Creating <<" + util::Converts::numberToString(this)
					+ ">> VisitedTreeNode@["
					+ util::Converts::numberToString(this->_depth) + "]");
}

VisitedTreeNode::~VisitedTreeNode() {
	LOG(Logger::LEVEL_TRACE,
			"Deleting <<" + util::Converts::numberToString(this)
					+ ">> VisitedTreeNode@["
					+ util::Converts::numberToString(this->_depth) + "]");
}

void VisitedTreeNode::accept(VisitorPtr ptr) {
    TreeWalkerPtr treePtr = std::dynamic_pointer_cast<TreeWalker>(ptr);
	this->apply(treePtr, DEPTH_FIRST);
}

void VisitedTreeNode::apply(TreeWalkerPtr walker, TraverseStrategy strategy) {
	switch (strategy) {
	case IN_ORDER:
		LOG(Logger::LEVEL_DEBUG, "[Visitor] Begin in-order traversal");
		this->doInOrder(walker);
		break;
	case POST_ORDER:
		LOG(Logger::LEVEL_DEBUG, "[Visitor] Begin post-order traversal");
		this->doPostOrder(walker);
		break;
	case PRE_ORDER:
		LOG(Logger::LEVEL_DEBUG, "[Visitor] Begin pre-order traversal");
		this->doPreOrder(walker);
		break;
	case DEPTH_FIRST:
		LOG(Logger::LEVEL_DEBUG, "[Visitor] Begin depth-first traversal");
		this->doDepthFirst(walker);
		break;
	case BREADTH_FIRST:
		LOG(Logger::LEVEL_DEBUG, "[Visitor] Begin breadth-first traversal");
		this->doBreadthFirst(walker);
		break;
	default:
		break;
	}
}
#include<iostream>
void VisitedTreeNode::doInOrder(TreeWalkerPtr walker) {
	util::Conditions::requireBetween<size_t>(this->getNumOfChildren(), 0, 2,
			"Children # ");

	if (this->isChildAt(0)) {
		VisitedTreeNodePtr left = std::dynamic_pointer_cast<VisitedTreeNode>(
				this->getChildAt(0));
		left->doInOrder(walker);
	}

	VisitedTreeNodePtr current = std::dynamic_pointer_cast<VisitedTreeNode>(this->getThisPtr());
	current->setState(TRAVERSE_IN);
	walker->walk(current);

	if (this->isChildAt(1)) {
		VisitedTreeNodePtr right = std::dynamic_pointer_cast<VisitedTreeNode>(
				this->getChildAt(1));
		right->doInOrder(walker);
	}
}

void VisitedTreeNode::doPostOrder(TreeWalkerPtr walker) {
	util::Conditions::requireBetween<size_t>(this->getNumOfChildren(), 0, 2,
			"Children # ");

	if (this->isChildAt(0)) {
		VisitedTreeNodePtr left = std::dynamic_pointer_cast<VisitedTreeNode>(
				this->getChildAt(0));
		left->doPostOrder(walker);
	}

	if (this->isChildAt(1)) {
		VisitedTreeNodePtr right = std::dynamic_pointer_cast<VisitedTreeNode>(
				this->getChildAt(1));
		right->doPostOrder(walker);
	}

	VisitedTreeNodePtr current = std::dynamic_pointer_cast<VisitedTreeNode>(this->getThisPtr());
	current->setState(TRAVERSE_IN);
	walker->walk(current);
}

void VisitedTreeNode::doPreOrder(TreeWalkerPtr walker) {
	util::Conditions::requireBetween<size_t>(this->getNumOfChildren(), 0, 2,
			"Children # ");

	VisitedTreeNodePtr current = std::dynamic_pointer_cast<VisitedTreeNode>(this->getThisPtr());
	current->setState(TRAVERSE_IN);
	walker->walk(current);

	if (this->isChildAt(0)) {
		VisitedTreeNodePtr left = std::dynamic_pointer_cast<VisitedTreeNode>(
				this->getChildAt(0));
		left->doPreOrder(walker);
	}

	if (this->isChildAt(1)) {
		VisitedTreeNodePtr right = std::dynamic_pointer_cast<VisitedTreeNode>(
				this->getChildAt(1));
		right->doPreOrder(walker);
	}
}

void VisitedTreeNode::doBreadthFirst(TreeWalkerPtr walker) {
	// Create a queue for BFS
	std::queue<VisitedTreeNodePtr> que;

	// Mark the current node as visited and enqueue it
	que.push(std::dynamic_pointer_cast<VisitedTreeNode>(this->getThisPtr()));

	while (que.empty() == false) {
		// Dequeue a vertex from queue and print it
		VisitedTreeNodePtr current = que.front();

		current->setState(TRAVERSE_IN);
		walker->walk(current);
		que.pop();

		for (size_t i = 0; i < current->getNumOfChildren(); i++) {
			VisitedTreeNodePtr child = std::dynamic_pointer_cast<
					VisitedTreeNode>(current->getChildAt(i));
			que.push(child);
		}
	}
}

void VisitedTreeNode::doDepthFirst(TreeWalkerPtr walker) {
	VisitedTreeNodePtr current = std::dynamic_pointer_cast<VisitedTreeNode>(this->getThisPtr());
	current->setState(TRAVERSE_IN);
	walker->walk(current);

	this->visitChildren(walker);

	current->setState(TRAVERSE_OUT);
	walker->walk(current);
}

void VisitedTreeNode::visitChildren(TreeWalkerPtr walker) {
	for (size_t i = 0; i < this->getNumOfChildren(); i++) {
		VisitedTreeNodePtr child = std::dynamic_pointer_cast<VisitedTreeNode>(
				this->getChildAt(i));

		child->doDepthFirst(walker);
	}
}
