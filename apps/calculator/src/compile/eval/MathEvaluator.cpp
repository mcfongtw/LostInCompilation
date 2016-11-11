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
	this->_analyzer = std::make_shared<Analyzer>(stack);
}

MathEvaluator::~MathEvaluator() {

}

void MathEvaluator::startEval() {
	this->_symtabStack->openScope();
}

void MathEvaluator::doEval(VisitedTreeNodePtr root) {
	util::Conditions::requireNotNull(root, "AST root set for parse result");

	root->apply(this->_analyzer, DEPTH_FIRST);
}

void MathEvaluator::stopEval() {
	this->_symtabStack->closeScope();

	std::shared_ptr<Analyzer> analyzerPtr = std::dynamic_pointer_cast<Analyzer>(this->_analyzer);

//	RuntimeStack rtStack = analyzerPtr->getRunTimeStack();
//	util::Conditions::requireLessThan<int>(rtStack.size(), 2, "The runtime stack has more than 1 stack!");
//	rtStack.pop();s
}

RuntimeData MathEvaluator::getLastAnswer() {
	RuntimeData result = nullptr;

	std::shared_ptr<Analyzer> analyzerPtr = std::dynamic_pointer_cast<Analyzer>(this->_analyzer);

	RuntimeStack rtStack = analyzerPtr->getRunTimeStack();
    if(rtStack.isEmpty()) {
        LOG(Logger::LEVEL_INFO, "Runtime stack is empty for Last Answer");
    } else {
        LOG(Logger::LEVEL_TRACE,
            "Get Last Answer, Runtime Call Stack has " + rtStack.toString());
        result = rtStack.top();
    }

	return result;
}

