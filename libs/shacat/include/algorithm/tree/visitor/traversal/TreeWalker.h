/*
 * TreeWalker.h
 *
 *  Created on, Feb 6, 2014
 *      Author, Michael Fong
 */

#ifndef TREEWALKER_H_
#define TREEWALKER_H_

#include "algorithm/tree/visitor/VisitedTreeNode.h"
#include "algorithm/tree/TreeContext.h"
#include "algorithm/visitor/Visitor.h"

class VisitedTreeNode;
typedef std::shared_ptr<VisitedTreeNode> VisitedTreeNodePtr;

/**
 * An abstract tree traversal class implementing Visitor.  A TreeWalker will operate on a tree structured rooted at VisitedTreeNode with respect to which traversal strategy
 * -# In-order traversal
 * -# Post-order traversal
 * -# Pre-Order traversal
 * -# Breadth-first traversal
 * -# Depth-first traversal (default traversal strategy)
 *
 * The life cycle of visiting is as the following:
 * - startWalking()
 * - walk()
 * - stopWalking()
 *
 * @since 0.1
 *
 */
class TreeWalker : public Visitor {
public:
	TreeWalker() {

	}

	virtual ~TreeWalker() {

	}

    /**
     * entry point for performing the tree traversal.
     *
     * @param ptr VisitedObject to visit to
     *
     * @return result code.
     */
	virtual int walk(VisitedTreeNodePtr ptr) = 0;

protected:
    /**
     * Hide intentionally, as we only expose walk(ptr) to outside
     *
     * @param ptr VisitedObject to visit to
     *
     * @return result of walk(ptr)
     */
	virtual int visit(VisitedObjectPtr ptr) {
		VisitedTreeNodePtr treeNodePtr = std::dynamic_pointer_cast<VisitedTreeNode>(ptr);
		this->walk(treeNodePtr);
	}

    /**
     * When walk starts.
     *
     * @return result code.
     */
	virtual int startWalking() = 0;

    /**
     * When walk stops.
     *
     * @return result code.
     */
	virtual int stopWalking() = 0;
};

#endif /* TREEWALKER_H_ */
