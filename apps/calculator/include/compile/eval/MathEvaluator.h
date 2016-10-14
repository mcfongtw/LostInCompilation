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
 */
class MathEvaluator : public Evaluator {
public:
	MathEvaluator();
	virtual ~MathEvaluator();

	virtual void eval(VisitedTreeNodePtr root);

private:
	Analyzer _analyzer;
};

#endif /* MATHEVALUATOR_H_ */
