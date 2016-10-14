/*
 * ASTReducer.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */

#include "algorithm/tree/ast/ASTUtils.h"
#include "common/Utils.h"

int ASTUtils::reduceTree(VisitedTreeNodePtr oldPtr, VisitedTreeNodePtr newPtr) {
	util::Conditions::requireNotNull(oldPtr, "ASTUtils::reduceTree - old ASTNode");
	util::Conditions::requireNotNull(newPtr, "new ASTNode");

	oldPtr->replace(newPtr);

	newPtr->removeAllChildren();

	return 1;
}

int ASTUtils::reduceTree(VisitedTreeNodePtr oldPtr, VisitedTreeNodePtr newPtr,
		std::vector<VisitedTreeNodePtr>& newChildrenPtr) {
	ASTUtils::reduceTree(oldPtr, newPtr);

	for (size_t i = 0; i < newChildrenPtr.size(); i++) {
		VisitedTreeNodePtr newChildPtr = newChildrenPtr[i];
		newPtr->insertChild(newChildPtr);
	}

	return 1;
}

