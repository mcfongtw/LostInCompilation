/*
 * MathEvaluator.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Michael Fong
 */

#include "compile/eval/MathEvaluator.h"
#include "common/Utils.h"

MathEvaluator::MathEvaluator() {
	this->_walker = std::make_shared<Analyzer>();
}

MathEvaluator::~MathEvaluator() {

}

void MathEvaluator::eval(VisitedTreeNodePtr root) {
	util::Conditions::requireNotNull(root, "AST root set for parse result");

	root->apply(this->_walker, DEPTH_FIRST);
}
