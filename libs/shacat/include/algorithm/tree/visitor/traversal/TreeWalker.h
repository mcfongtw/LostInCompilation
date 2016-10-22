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
 * An abstract tree traversal class. One of the two parts of implementing visitor pattern.
 * Simply, the order of visiting an object (in this case, VisitedTreeNode), should be as the following:
 *
 * startWalking()
 * walk()
 * stopWalking()
 *
 */
class TreeWalker : public Visitor {
public:
	TreeWalker() {

	}

	virtual ~TreeWalker() {

	}

	virtual int walk(VisitedTreeNodePtr ptr) = 0;

protected:
    //Hide intentionally, as we only expose walk(ptr) to outside
	virtual int visit(VisitedObjectPtr ptr) {
		VisitedTreeNodePtr treeNodePtr = std::dynamic_pointer_cast<VisitedTreeNode>(ptr);
		this->walk(treeNodePtr);
	}
	virtual int startWalking() = 0;

	virtual int stopWalking() = 0;
};

#endif /* TREEWALKER_H_ */
