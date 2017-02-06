/*
 * GrammarLibs.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: Michael Fong
 */

#include <iostream>
#include <cstring>

#include "compile/parser/grammar/GrammarLibs.h"

/*
 * Custom variable
 */
static char* yyexpr;

void yyerror(YYLTYPE *locp, ASTNodePtr& root, yyscan_t yyscanner, const char* error_msg, ...) {
	std::stringstream ss;

	ss << "Parse error:" << std::endl;
	ss << yyexpr << std::endl;

    //relocate to a step before the error position
	for(size_t i = 0; i < yy_custom_col; i++) {
		ss << " ";
	}
	ss << "^" << std::endl;;
	ss << "Possible reason: ";

	ss << error_msg << std::endl;

    ParseExceptionTranslator::translate(std::string(error_msg), ss.str());

//	va_list args;
//	va_start(args, error_msg);
//	vfprintf(stdout, error_msg, args);
//
//	std::cout << std::endl;
}

int CompilerUtils::parseSingleLine(ASTNodePtr& root, const char* line) {
	yyexpr = (char*) malloc(sizeof(char) * strlen(line));
	strcpy(yyexpr, line);

	yyscan_t scanner;
	yy_buffer_state* state;

	if (yylex_init(&scanner)) {
		// couldn't initialize
		return -1;
	}

	state = yy_scan_string(line, scanner);

    //reinitialize row
    yyset_lineno(1, scanner);

    //reinitialize column
    yyset_column(0, scanner);
    yy_custom_col = 0;

	LOG(Logger::LEVEL_TRACE, ">>>>>[yyparse] " + util::Converts::numberToString(root));
	int parse_result = yyparse(root, scanner);
	LOG(Logger::LEVEL_TRACE, "<<<<<[yyparse] " + util::Converts::numberToString(root));
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);

	LOG(Logger::LEVEL_DEBUG, "Parsing [" + std::string(line) + "] produces AST rooted at [" + root->getText() + "]");

	return parse_result;
}
