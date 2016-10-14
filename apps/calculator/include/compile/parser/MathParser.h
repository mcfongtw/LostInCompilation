/*
 * MathParser.h
 *
 *  Created on: May 1, 2014
 *      Author: Michael Fong
 */

#ifndef MATHPARSER_H_
#define MATHPARSER_H_

#include "compile/parser/Parser.h"

/**
 *
 * MathParser inherits from Parser and implements the concrete functionalities
 * for parsing a math expression generated by Bison and Flex.
 */
class MathParser: public Parsable {
public:
	MathParser();

	virtual ~MathParser();

	virtual void parse(ASTNodePtr& root, std::string line);

	virtual void parse(std::ifstream inFile);
};

#endif /* MATHPARSER_H_ */
