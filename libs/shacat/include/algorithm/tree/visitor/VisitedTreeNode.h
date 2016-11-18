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
#include "algorithm/visitor/VisitedObject.h"


class TreeWalker;
class VisitedTreeNode;

typedef std::shared_ptr<VisitedTreeNode> VisitedTreeNodePtr;
typedef std::shared_ptr<TreeWalker> TreeWalkerPtr;

/**
 * An implementation of TreeNode and VisitedObject that represent a tree data structure.
 *
 * A TreeWalkerPtr will operate on a this tree-like structure with respect to which traversal strategy
 * -# In-order traversal
 * -# Post-order traversal
 * -# Pre-Order traversal
 * -# Breadth-first traversal
 * -# Depth-first traversal (default traversal strategy)
 *
 * @since 0.1
 *
 */
class VisitedTreeNode : public TreeNode, public VisitedObject {

public:
	VisitedTreeNode();

	virtual ~VisitedTreeNode();

    /**
     * VisitedTreeNode accepts a visitor by performing DEPTH_FIRST traversal (default)
     *
     * @param visitor pointer to a Visitor
     */
	virtual void accept(VisitorPtr visitor);

    /**
     * VisitedTreeNode accepts a visitor by performing a desginated traversal strategy (default)
     *
     * @param walker pointer to a TreeWalker
     * @param strategy a designated traversal strategy
     */
	virtual void apply(TreeWalkerPtr walker, TraverseStrategy strategy);

private:
    /**
     * TreeWalker recursively visit the tree via in-order fasion.
     *
     * NOTE: only valid for binary tree
     *
     * @param walker TreeWalker to visit children node
     */
	void doInOrder(TreeWalkerPtr walker);

    /**
     * TreeWalker recursively visit the tree via post-order fasion.
     *
     * NOTE: only valid for binary tree
     *
     * @param walker TreeWalker to visit children node
     */
	void doPostOrder(TreeWalkerPtr walker);

    /**
     * TreeWalker recursively visit the tree via pre-order fasion.
     *
     * NOTE: only valid for binary tree
     *
     * @param walker TreeWalker to visit children node
     */
	void doPreOrder(TreeWalkerPtr walker);

    /**
     * TreeWalker recursively visit the tree via breadth-first fasion.
     *
     * @param walker TreeWalker to visit children node
     */
	void doBreadthFirst(TreeWalkerPtr walker);

    /**
     * TreeWalker recursively visit the tree via depth-first fasion.
     *
     * @param walker TreeWalker to visit children node
     */
	void doDepthFirst(TreeWalkerPtr walker);

    /**
     * TreeWalker visit the children nodes
     *
     * NOTE: only for DEPTH_FIRST strategy
     *
     * @param walker TreeWalker to visit children node
     */
	void visitChildren(TreeWalkerPtr walker);
};



#endif /* VISITEDTREENODE_H_ */
