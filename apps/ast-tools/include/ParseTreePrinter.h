/*
 * ParseTreePrinter.h
 *
 *  Created on: Dec 23, 2014
 *      Author: Michael Fong
 */

#ifndef PARSETREEPRINTER_H_
#define PARSETREEPRINTER_H_

#include "algorithm/tree/visitor/traversal/TreeWalker.h"
#include "algorithm/tree/ast/ASTNode.h"
#include "ASTPrinter.h"

class ParseTreePrinter: public TreeWalker, ASTPrinter {

	ParseTreePrinter();

	virtual ~ParseTreePrinter();

	virtual int startWalking();

	virtual int stopWalking();

	virtual int walk(ASTNodePtr ptr);
};

#endif /* PARSETREEPRINTER_H_ */
