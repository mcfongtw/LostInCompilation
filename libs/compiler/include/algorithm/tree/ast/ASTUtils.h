/*
 * ASTReducer.h
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */

#ifndef ASTUTILS_H_
#define ASTUTILS_H_

#include "algorithm/tree/ast/ASTNode.h"
#include <vector>


/**
 * A utility class that provides a series of helper functions operating on an abstract-syntax-tree.
 */
class ASTUtils {
public:
	static int reduceTree(VisitedTreeNodePtr oldNode, VisitedTreeNodePtr newNode);

	static int reduceTree(VisitedTreeNodePtr oldNode, VisitedTreeNodePtr newNode, std::vector<VisitedTreeNodePtr>& newChildren);


	static ASTNode* createAST(const char* txt, int tokenType) {
		ASTNode* current = new ASTNode(txt, tokenType);

		return current;
	}

	static ASTNode* createAST(const char* txt, int tokenType, ASTNode* child) {
		ASTNode* current = new ASTNode(txt, tokenType);
		current->insertChild(TreeNodePtr(child));

		return current;
	}

	static ASTNode* createAST(const char* txt, int tokenType, ASTNode* child1, ASTNode* child2) {
		ASTNode* current = new ASTNode(txt, tokenType);
		current->insertChild(TreeNodePtr(child1));
		current->insertChild(TreeNodePtr(child2));

		return current;
	}
};

#endif /* ASTUTILS_H_ */
