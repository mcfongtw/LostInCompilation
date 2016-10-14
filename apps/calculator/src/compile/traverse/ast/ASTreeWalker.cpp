/*
 * ASTreeWalker.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */
#include <string>

#include "compile/traverse/ast/ASTreeWalker.h"
#include "algorithm/tree/ast/ASTNode.h"
#include "common/Utils.h"
#include "error/Exception.h"
#include "../../../compile/parser/grammar/bison/calc.tab.hpp"

class Converts;


ASTreeWalker::ASTreeWalker() :  TreeWalker(){

}

ASTreeWalker::~ASTreeWalker() {

}


int ASTreeWalker::walk(VisitedTreeNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode");

	int result = 0;
	TraverseAction action = ptr->getState();

	if(action== TRAVERSE_IN && ptr->isRoot()) {
		this->startWalking();
	}

	ASTNodePtr astNode = std::dynamic_pointer_cast<ASTNode>(ptr);
	util::Conditions::requireNotNull(astNode, "AST Node");

	switch(astNode->getToken()) {
		/* binary subtrees */
		case TOKEN_OP_ADD:
		case TOKEN_OP_SUB:
		case TOKEN_OP_MUL:
		case TOKEN_OP_DIV:
		case TOKEN_OP_NEG:
		case TOKEN_OP_MOD:
		case TOKEN_OP_POW:
			this->_ptr = &ASTreeWalker::walk_MATH;
			break;

		/* unary subtree */
		case TOKEN_OP_ASSIGN:
			this->_ptr = &ASTreeWalker::walk_ASSIGN;
			break;

//		case TOKEN_FUNC_DEF:
//			this->_ptr = &ASTreeWalker::walk_FUNC;
//			result = this->walk_FUNC(node, action);
//			break;

			/* leaf node */
		case TOKEN_NUMBER:
			this->_ptr = &ASTreeWalker::walk_NUMBER;
			break;
		case TOKEN_INTEGER:
			this->_ptr = &ASTreeWalker::walk_INTEGER;
			break;
		case TOKEN_ID:
			this->_ptr = &ASTreeWalker::walk_ID;
			break;
		case TOKEN_LITERAL:
			this->_ptr = &ASTreeWalker::walk_LITERAL;
			break;
		default:
			std::string reason = "Error: bad token : " + util::Converts::numberToString(astNode->getToken());
			throw IllegalStateException(reason);
	}

	result = (this->*_ptr)(std::dynamic_pointer_cast<ASTNode>(ptr));


	if(action == TRAVERSE_OUT  && ptr->isRoot()) {
			this->stopWalking();
	}
	return result;
}
