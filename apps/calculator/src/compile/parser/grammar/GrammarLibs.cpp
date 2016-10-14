/*
 * GrammarLibs.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: Michael Fong
 */

#include <iostream>
#include <cstring>
#include "stdarg.h"
#include "stdio.h"

#include "compile/parser/grammar/GrammarLibs.h"

/*
 * Custom variable
 */
static char* yyexpr;

void yyerror(YYLTYPE *locp, ASTNodePtr& root, yyscan_t yyscanner, const char* error_msg, ...) {
	std::cout << "Parse error:" << std::endl;
	std::cout << yyexpr << std::endl;
	for(size_t i = 0; i < yy_custom_col - 1; i++) {
		std::cout << " ";
	}
	std::cout << "^" << std::endl;;
	std::cout << "Possible reason: ";

	va_list args;
	va_start(args, error_msg);
	vfprintf(stdout, error_msg, args);

	std::cout << std::endl;

	/*
	 * 	//fprintf(stderr, "Parser error from <%d,%d> to <%d,%d> \n",
		//	@1.first_line, @1.first_column, @1.last_line, @1.last_column);
	 */

	// use YYLTYPE
//	if (locp) {
//		/*
//		 * (:%d.%d -> :%d.%d)
//		 *
//		 * 						locp->first_line, locp->first_column,
//						locp->last_line,  locp->last_column
//		 */
//	  }
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
	LOG(Logger::LEVEL_TRACE, ">>>>>[yyparse] " + util::Converts::numberToString(root));
	int parse_result = yyparse(root, scanner);
	LOG(Logger::LEVEL_TRACE, "<<<<<[yyparse] " + util::Converts::numberToString(root));
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);

	LOG(Logger::LEVEL_DEBUG, "Parsing [" + std::string(line) + "] produces AST rooted at [" + root->getText() + "]");
	return parse_result;
}
