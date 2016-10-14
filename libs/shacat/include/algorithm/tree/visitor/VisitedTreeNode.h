/*
 * VisitedTreeNode.h
 *
 *  Created on: Nov 23, 2014
 *      Author: Michael Fong
 */

#ifndef VISITEDTREENODE_H_
#define VISITEDTREENODE_H_

#include "algorithm/tree/TreeNode.h"
#include "algorithm/tree/visitor/traversal/TreeWalker.h"
#include "algorithm/tree/TreeContext.h"


class TreeWalker;
class VisitedTreeNode;

typedef std::shared_ptr<VisitedTreeNode> VisitedTreeNodePtr;
typedef std::shared_ptr<TreeWalker> TreeWalkerPtr;

class VisitedTreeNode : public TreeNode  {

public:
	VisitedTreeNode();

	virtual ~VisitedTreeNode();

	virtual void apply(TreeWalkerPtr, TraverseStrategy);

private:
	void doInOrder(TreeWalkerPtr);

	void doPostOrder(TreeWalkerPtr);

	void doPreOrder(TreeWalkerPtr);

	void doBreadthFirst(TreeWalkerPtr);

	void doDepthFirst(TreeWalkerPtr);

	void visitChildren(TreeWalkerPtr);
};



#endif /* VISITEDTREENODE_H_ */
