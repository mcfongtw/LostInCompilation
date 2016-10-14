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
 * An top-level abstract class that defines what an evaluator does in general.
 */
class Evaluator {
public:
	Evaluator() {

	}

	virtual ~Evaluator() {

	}

	virtual void eval(VisitedTreeNodePtr root) = 0;
};

#endif /* EVALUATOR_H_ */
