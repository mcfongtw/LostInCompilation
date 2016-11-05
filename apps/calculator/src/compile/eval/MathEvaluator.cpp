/*
 * MathEvaluator.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Michael Fong
 */

#include "compile/eval/MathEvaluator.h"
#include "common/Utils.h"

MathEvaluator::MathEvaluator(SymTabStackPtr stack){
	this->_symtabStack = stack;
	this->_walker = std::make_shared<Analyzer>(stack);
}

MathEvaluator::~MathEvaluator() {

}

void MathEvaluator::startEval() {
	this->_symtabStack->openScope();
}

void MathEvaluator::doEval(VisitedTreeNodePtr root) {
	util::Conditions::requireNotNull(root, "AST root set for parse result");

	root->apply(this->_walker, DEPTH_FIRST);
}

void MathEvaluator::stopEval() {
	this->_symtabStack->closeScope();
}