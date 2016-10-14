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
#include "ASTPrinter.h"

/**
 * DotPrinter attempts to print the abstract-syntax-tree in DOT language. User may
 * then view the tree structure. For details, please check DOT documentation.
 */
class DotPrinter : public TreeWalker, ASTPrinter {
public:

	DotPrinter(std::string fname);

	virtual ~DotPrinter();

	virtual int startWalking();

	virtual int stopWalking();

	virtual int walk(ASTNodePtr ptr);

private:
	std::ofstream _fout;

	int close();

};

#endif /* ASTWALKER_H_ */
