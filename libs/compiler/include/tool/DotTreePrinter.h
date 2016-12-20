/*
 * DotPrinter.h
 *
 *  Created on: Mar 24, 2012
 *      Author: shannaracat
 */

#ifndef DOTPRINTER_H
#define DOTPRINTER_H

#include <fstream>

#include "algorithm/tree/visitor/traversal/TreeWalker.h"
#include "algorithm/tree/ast/ASTNode.h"
#include "tool/Printer.h"

/**
 * DotTreePrinter attempts to print the abstract-syntax-tree in DOT language. User may
 * then view the tree structure. For details, please check DOT documentation.
 *
 * @since 0.1
 */
class DotTreePrinter : public TreeWalker, public Printer {
public:

	DotTreePrinter();

    DotTreePrinter(DotTreePrinter& that);

	virtual ~DotTreePrinter();

	virtual int startWalking();

	virtual int stopWalking();

	virtual int walk(VisitedTreeNodePtr ptr);

private :
	int _nodeIdForDot = 1;

};

#endif /* ASTWALKER_H_ */
