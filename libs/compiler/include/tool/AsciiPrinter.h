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
#include "tool/Printer.h"

class AsciiPrinter: public TreeWalker, public Printer {
public:
	AsciiPrinter();

	AsciiPrinter(AsciiPrinter& that);

	virtual ~AsciiPrinter();

	virtual int startWalking();

	virtual int stopWalking();

	virtual int walk(VisitedTreeNodePtr ptr);
};

#endif /* PARSETREEPRINTER_H_ */
