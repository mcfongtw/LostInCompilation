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
	try {
		CompilerUtils::parseSingleLine(root, line.c_str());
		util::Conditions::requireNotNull(root, "AST root after parsing");
	} catch(Exception e) {
		LOG(Logger::LEVEL_ERROR, "Error during parsing [" + line + "]");
		LOG(Logger::LEVEL_ERROR, e.what());
	}
	LOG(Logger::LEVEL_TRACE, "<<<<<[math parser] " + util::Converts::numberToString(root));

	return;
}

//TODO: finish
void MathParser::parse(std::ifstream inFile) {
	std::string content( (std::istreambuf_iterator<char>(inFile) ),
	                       (std::istreambuf_iterator<char>()    ) );
}
