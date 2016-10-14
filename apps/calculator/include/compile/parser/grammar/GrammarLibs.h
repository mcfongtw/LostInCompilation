/*
 * ParserLibs.h
 *
 *  Created on: Apr 24, 2014
 *      Author: Michael Fong
 */

#ifndef GRAMMARLIBS_H_
#define GRAMMARLIBS_H_

#include <cstdio>

#include "log/Logger.h"
#include "common/Utils.h"
#include "error/Exception.h"
#include "error/ParseException.h"
#include "hack/DebugLib.h"
#include "algorithm/tree/ast/ASTNode.h"
#include "algorithm/tree/ast/ASTUtils.h"

#include "../../../../src/compile/parser/grammar/bison/calc.tab.hpp"
//TODO: include --header-file=calc.lex.hpp in flex builder
//#include "../../../../src/core/parser/grammar/flex/calc.lex./hpp"

/*
 * **************************
 * extern variable from lexer
 * **************************
 */
struct yy_buffer_state;

extern size_t yy_custom_col;

/*
 * ************************************
 * Extern function prototype for lexer
 * ************************************
 */
extern int yylex(YYSTYPE*, YYLTYPE*, yyscan_t);

extern void yy_delete_buffer(struct yy_buffer_state*, yyscan_t);

extern struct yy_buffer_state* yy_scan_string (const char*, yyscan_t );

extern int yylex_init(yyscan_t*);

extern int yylex_destroy(yyscan_t);

extern void* yyget_extra  (yyscan_t yyscanner);

extern int yyget_lineno  (yyscan_t yyscanner);

extern int yyget_column  (yyscan_t yyscanner);

extern FILE *yyget_in  (yyscan_t yyscanner);

extern FILE *yyget_out  (yyscan_t yyscanner);

extern int yyget_leng  (yyscan_t yyscanner);

extern char *yyget_text  (yyscan_t yyscanner);;

/*
 * ***************************
 * extern variable from parser
 * ***************************
 */
//None

/*
 * ************************************
 * Extern function prototypes for parser
 * ************************************
 */
//Add more argument in beginning if add more parameters in %parse-param{Class}
extern void yyerror(YYLTYPE*, ASTNodePtr&, yyscan_t, const char*, ...);

class CompilerUtils {
public:
	static int parseSingleLine(ASTNodePtr& root, const char* line);
};

#endif /* GRAMMARLIBS_H_ */
