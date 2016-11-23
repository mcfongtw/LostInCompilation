/*
 * Evaluator.h
 *
 *  Created on: May 5, 2014
 *      Author: Michael Fong
 */

#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include "algorithm/tree/ast/ASTNode.h"

/**
 * A pure abstract class to evaluate the semantic meaning of an expression given a parsed abstract syntax tree.
 *
 * @since 0.1
 */
class Evaluator {
public:
	Evaluator() {

	}

	virtual ~Evaluator() {

	}

	virtual void startEval() = 0;

	virtual void doEval(VisitedTreeNodePtr root) = 0;

	virtual void stopEval() = 0;
};

#endif /* EVALUATOR_H_ */
