/*
 * TreeTraverse.h
 *
 *  Created on: Dec 25, 2014
 *      Author: Michael Fong
 */

#ifndef TREETRAVERSE_H_
#define TREETRAVERSE_H_

#include "algorithm/tree/TreeNode.h"
#include "algorithm/tree/TreeContext.h"
#include "algorithm/tree/traditional/LIFO/NodeStack.h"

class TreeTraverse {
public:
	TreeTraverse();

	virtual ~TreeTraverse();

	virtual void apply(TreeNodePtr, TraverseStrategy);

	virtual TreeNodeStack& getNodeStack();

private:

	void doInOrder(TreeNodePtr);

	void doPostOrder(TreeNodePtr);

	void doPreOrder(TreeNodePtr);

	void doBreadthFirst(TreeNodePtr);

	void doDepthFirst(TreeNodePtr);

	TreeNodeStack _stack;
};

#endif /* TREETRAVERSE_H_ */
