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
 * A utility class that provides a series of static functions operating on an abstract-syntax-tree. The utilities include
 * - create an AST and bind with given children nodes.
 *
 * @since 0.1
 */
class ASTUtils {
public:
	static int reduceTreeWithoutChildren(VisitedTreeNodePtr oldNode, VisitedTreeNodePtr newNode);

	static int reduceTree(VisitedTreeNodePtr oldNode, VisitedTreeNodePtr newNode);

	static ASTNode* createAST(const char* txt, int tokenType, SourceCodePosition position) {
		ASTNode* current = new ASTNode(txt, tokenType, position);

		return current;
	}

	static ASTNode* createAST(const char* txt, int tokenType, ASTNode* child, SourceCodePosition position) {
		ASTNode* current = new ASTNode(txt, tokenType, position);
		current->insertChild(TreeNodePtr(child));

		return current;
	}

	static ASTNode* createAST(const char* txt, int tokenType, ASTNode* child1, ASTNode* child2, SourceCodePosition position) {
		ASTNode* current = new ASTNode(txt, tokenType, position);
		current->insertChild(TreeNodePtr(child1));
		current->insertChild(TreeNodePtr(child2));

		return current;
	}
};

#endif /* ASTUTILS_H_ */
