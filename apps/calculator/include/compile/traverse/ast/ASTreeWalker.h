/*
 * ASTreeWalker.h
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */

#ifndef ASTREEWALKER_H_
#define ASTREEWALKER_H_

#include "algorithm/tree/visitor/traversal/TreeWalker.h"
#include "algorithm/tree/ast/ASTNode.h"

/**
 * An abstract class of inheriting top-level TreeWalker.In ASTreeWalker, each node visiting is further
 * classified into different visiting function according to token type.
 */
class ASTreeWalker : public TreeWalker {
public:
	ASTreeWalker();

	virtual ~ASTreeWalker();

	virtual int walk(VisitedTreeNodePtr ptr);

protected:
	virtual int walk_MATH(ASTNodePtr ptr) = 0;

	virtual int walk_ASSIGN(ASTNodePtr ptr) = 0;

	virtual int walk_FUNC(ASTNodePtr ptr) = 0;

	virtual int walk_INTEGER(ASTNodePtr ptr) = 0;

	virtual int walk_NUMBER(ASTNodePtr ptr) = 0;

	virtual int walk_LITERAL(ASTNodePtr ptr) = 0;

	virtual int walk_ID(ASTNodePtr ptr) = 0;

private:
	/**
	 * Function pointer to AST traversal functions
	 *
	 * @param TreeNode* to visit
	 * @param Traversal action
	 *
	 * @return traversal result
	 */
	typedef int (ASTreeWalker::*ASTPathPtr)(ASTNodePtr);

	ASTPathPtr _ptr  = 0;
};

#endif /* ASTREEWALKER_H_ */
