/*
 * TreeTraverse.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: Michael Fong
 */

#include "algorithm/tree/traditional/LIFO/TreeTraverse.h"

#include <queue>

#include "algorithm/tree/traditional/LIFO/NodeStack.h"
#include "log/Logger.h"
#include "common/Utils.h"

TreeTraverse::TreeTraverse() {

}

TreeTraverse::~TreeTraverse() {

}

void TreeTraverse::apply(TreeNodePtr current, TraverseStrategy strategy) {
	switch (strategy) {
	case IN_ORDER:
		LOG(Logger::LEVEL_DEBUG, "[Traverse] Begin in-order traversal");
		this->doInOrder(current);
		break;
	case POST_ORDER:
		LOG(Logger::LEVEL_DEBUG, "[Traverse] Begin post-order traversal");
		this->doPostOrder(current);
		break;
	case PRE_ORDER:
		LOG(Logger::LEVEL_DEBUG, "[Traverse] Begin pre-order traversal");
		this->doPreOrder(current);
		break;
	case DEPTH_FIRST:
		LOG(Logger::LEVEL_DEBUG, "[Traverse] Begin depth-first traversal");
		this->doDepthFirst(current);
		break;
	case BREADTH_FIRST:
		LOG(Logger::LEVEL_DEBUG, "[Traverse] Begin breadth-first traversal");
		this->doBreadthFirst(current);
		break;
	default:
		break;
	}
}

TreeNodeStack& TreeTraverse::getNodeStack() {
	return this->_stack;
}

void TreeTraverse::doInOrder(TreeNodePtr current) {
	util::Conditions::requireBetween<size_t>(current->getNumOfChildren(), 0, 2,
			"Children # ");

	if (current->isChildAt(0)) {
		TreeNodePtr left = current->getChildAt(0);
		this->doInOrder(left);
	}

	current->setState(TRAVERSE_IN);
	this->_stack.push_back(current);

	if (current->isChildAt(1)) {
		TreeNodePtr right = current->getChildAt(1);
		this->doInOrder(right);
	}
}

void TreeTraverse::doPostOrder(TreeNodePtr current) {
	util::Conditions::requireBetween<size_t>(current->getNumOfChildren(), 0, 2,
			"Children # ");

	if (current->isChildAt(0)) {
		TreeNodePtr left = current->getChildAt(0);
		this->doPostOrder(left);
	}

	if (current->isChildAt(1)) {
		TreeNodePtr right = current->getChildAt(1);
		this->doPostOrder(right);
	}

	current->setState(TRAVERSE_IN);
	this->_stack.push_back(current);
}

void TreeTraverse::doPreOrder(TreeNodePtr current) {
	util::Conditions::requireBetween<size_t>(current->getNumOfChildren(), 0, 2,
			"Children # ");

	current->setState(TRAVERSE_IN);
	this->_stack.push_back(current);

	if (current->isChildAt(0)) {
		TreeNodePtr left = current->getChildAt(0);
		this->doPreOrder(left);
	}

	if (current->isChildAt(1)) {
		TreeNodePtr right = current->getChildAt(1);
		this->doPreOrder(right);
	}
}

void TreeTraverse::doDepthFirst(TreeNodePtr current) {
	current->setState(TRAVERSE_IN);
	this->_stack.push_back(current);

	for(size_t i = 0; i < current->getNumOfChildren(); i++) {
		TreeNodePtr child = current->getChildAt(i);
		this->doDepthFirst(child);
	}

	current->setState(TRAVERSE_OUT);
	this->_stack.push_back(current);
}


void TreeTraverse::doBreadthFirst(TreeNodePtr root) {
	// Create a queue for BFS
	std::queue<TreeNodePtr> que;

	// Mark the current node as visited and enqueue it
	que.push(root);

	while (que.empty() == false) {
		// Dequeue a vertex from queue and print it
		TreeNodePtr current = que.front();

		current->setState(TRAVERSE_IN);
		this->_stack.push_back(current);

		que.pop();

		for (size_t i = 0; i < current->getNumOfChildren(); i++) {
			TreeNodePtr child = current->getChildAt(i);
			que.push(child);
		}
	}
}


