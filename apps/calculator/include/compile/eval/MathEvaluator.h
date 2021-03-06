/*
 * MathEvaluator.h
 *
 *  Created on: May 5, 2014
 *      Author: Michael Fong
 */

#ifndef MATHEVALUATOR_H_
#define MATHEVALUATOR_H_

#include "compile/eval/Evaluator.h"
#include "compile/eval/Analyzer.h"

/**
 *
 * MathEvaluator inherits from Evaluator and implements the concrete functionalities for evaluate a math expression
 * represented by an abstract syntax tree
 *
 * @since 0.1
 */
class MathEvaluator : public Evaluator {
public:
	MathEvaluator(SymTabStackPtr);

	virtual ~MathEvaluator();

	virtual void startEval();

	virtual void doEval(VisitedTreeNodePtr root);

	virtual void stopEval();

	virtual RuntimeData getLastAnswer();
private:
	TreeWalkerPtr _analyzer;

	SymTabStackPtr _symtabStack;
};

#endif /* MATHEVALUATOR_H_ */
