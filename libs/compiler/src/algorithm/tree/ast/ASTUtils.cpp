/*
 * ASTReducer.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */

#include "algorithm/tree/ast/ASTUtils.h"
#include "common/Utils.h"

int ASTUtils::reduceTreeWithoutChildren(VisitedTreeNodePtr oldPtr, VisitedTreeNodePtr newPtr) {
	util::Conditions::requireNotNull(oldPtr, "ASTUtils::reduceTreeWithoutChildren - old ASTNode");
	util::Conditions::requireNotNull(newPtr, "new ASTNode");

	oldPtr->replace(newPtr);

	newPtr->removeAllChildren();

	return 1;
}

int ASTUtils::reduceTree(VisitedTreeNodePtr oldPtr, VisitedTreeNodePtr newPtr) {
	util::Conditions::requireNotNull(oldPtr, "ASTUtils::reduceTreeWithoutChildren - old ASTNode");
	util::Conditions::requireNotNull(newPtr, "new ASTNode");

	oldPtr->replace(newPtr);

	return 1;
}

