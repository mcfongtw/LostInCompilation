/*
 * MathParser.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Michael Fong
 */

#include "compile/parser/MathParser.h"

#include "error/Exception.h"
#include "common/Utils.h"
#include "log/Logger.h"

#include "compile/parser/grammar/GrammarLibs.h"

MathParser::MathParser() :
		Parsable() {

}

MathParser::~MathParser() {

}

void MathParser::parse(ASTNodePtr& root, std::string line) {

	util::Conditions::requireNotEmpty(line, "user input expression at parser::parse()");

	LOG(Logger::LEVEL_TRACE, ">>>>>[math parser] " + util::Converts::numberToString(root));
	int ret_yyparse = CompilerUtils::parseSingleLine(root, line.c_str());
	LOG(Logger::LEVEL_TRACE, "<<<<<[math parser] " + util::Converts::numberToString(root));

	util::Conditions::requireNotNull(root, "AST root after parsing");
	switch (ret_yyparse) {
	case 0:
		LOG(Logger::LEVEL_DEBUG, "Parsed successfully.");
		break;
	case 1:
		throw IllegalStateException("Parsed failed; Invalid input.");
		break;
	case 2:
		throw OutOfMemoryException("Parsed failed; Memory exhaustion.");
		break;
	case -1:
		throw IllegalStateException("Scanner initialized failed.");
		break;
	default:
		std::string reason = "Unknown value returned by yyparse() : "
				+ util::Converts::numberToString<int>(ret_yyparse);
		throw IllegalStateException(reason);
		break;
	}

	return;
}

//TODO: finish
void MathParser::parse(std::ifstream inFile) {
	std::string content( (std::istreambuf_iterator<char>(inFile) ),
	                       (std::istreambuf_iterator<char>()    ) );
}
