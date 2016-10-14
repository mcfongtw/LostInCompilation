/*
 * Parser.h
 *
 *  Created on: May 1, 2014
 *      Author: Michael Fong
 */

#ifndef PARSABLE_H_
#define PARSABLE_H_

#include "algorithm/tree/ast/ASTNode.h"
#include <string>
#include <fstream>


/**
 * An top-level abstract class that defines what a parser does in general.
 */
class Parsable {
public:
	Parsable() {

	}

	virtual ~Parsable() {

	}

	virtual void parse(ASTNodePtr& root, std::string line) = 0;

	virtual void parse(std::ifstream inFile) = 0;
};

#endif /* PARSABLE_H_ */
