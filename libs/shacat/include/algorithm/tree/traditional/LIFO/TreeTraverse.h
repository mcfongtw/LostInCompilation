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

/**
 * LIFO (stack) implementation of tree visiting algorithm. A TreeTraverse algorithm will operate on a tree structured rooted at TreeNodePtr with help of TreeNodeStack
 * with respect to which traversal strategy
 * -# In-order traversal
 * -# Post-order traversal
 * -# Pre-Order traversal
 * -# Breadth-first traversal
 * -# Depth-first traversal
 *
 * @since 0.1
 */
class TreeTraverse {
public:
	TreeTraverse();

	virtual ~TreeTraverse();

	virtual void apply(TreeNodePtr, TraverseStrategy);

	virtual TreeNodeStack& getNodeStack();

private:
    /**
     * Traverse recursively on tree via in-order fasion with aid from NodeStack
     *
     * NOTE: only valid for binary tree
     *
     * @param node node to perform traversal from
     */
	void doInOrder(TreeNodePtr node);

    /**
     * Traverse recursively on tree via post-order fasion with aid from NodeStack
     *
     * NOTE: only valid for binary tree
     *
     * @param node node to perform traversal from
     */
	void doPostOrder(TreeNodePtr node);

    /**
     * Traverse recursively on tree via pre-order fasion with aid from NodeStack
     *
     * NOTE: only valid for binary tree
     *
     * @param node node to perform traversal from
     */
	void doPreOrder(TreeNodePtr node);

    /**
     * Traverse recursively on tree via breadth-first fasion with aid from NodeStack
     *
     * @param node node to perform traversal from
     */
	void doBreadthFirst(TreeNodePtr node);

    /**
     * Traverse recursively on tree via depth-firs fasion with aid from NodeStack
     *
     * @param node node to perform traversal from
     */
	void doDepthFirst(TreeNodePtr node);

	TreeNodeStack _stack;
};

#endif /* TREETRAVERSE_H_ */
