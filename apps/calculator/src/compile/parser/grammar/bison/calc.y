/*================================================================
				BISON SETTINGS
================================================================*/
//expect 0 shift-reduce conflict
%expect 0

//expect 0 reduce-reduce conflict
%expect-rr 0 

//require a bison version of 
%require "3.02"

%error-verbose

//the parser is made reentrant
%define api.pure full

//enable struct YYLTYPE
%locations


//pass the indicated param into scanner, effecting yylex_init(..), yy_scan_string(..), yy_delete_buffer(..), yylex_destroy(..)
%lex-param   {yyscan_t scanner}

//pass the indicated param into parser, effecting yyparse(..), yyerror(..)
%parse-param {ASTNodePtr& root}
%parse-param {yyscan_t scanner}

%code top {
#include <iostream>
#include "compile/parser/grammar/GrammarLibs.h"
#include "compile/SourceCodePosition.h"

#include "tool/DotTreePrinter.h"
#include "tool/AsciiTreePrinter.h"
#include "tool/Appender.h"
#include "hack/DebugLib.h"
#include <string>

#define YYDEBUG 0
}

%code requires {
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif
}
%code provides {
//const char* yy_current_line;

class ASTNode;
class ParseResult;
}
/*================================================================
						SEMANTIC RECORDS
================================================================*/
%union {
	const char* text;
	ASTNode* node;
}

%destructor { delete $$; }<text>
/*================================================================
						OPERATOR PRECEDENCE
================================================================*/
/* order defines precedence as the following:
 * 0- comparison operators
 * 1- =
 * 2- '+' and '-' 
 * 3- '*' and '/' 
 */
%nonassoc TOKEN_OP_GTR TOKEN_OP_LES TOKEN_OP_EQ TOKEN_OP_NEQ TOKEN_OP_GEQ TOKEN_OP_LEQ
%nonassoc TOKEN_OP_OR TOKEN_OP_AND
%right TOKEN_OP_ASSIGN 
%left TOKEN_OP_ADD TOKEN_OP_SUB 
%left TOKEN_OP_MUL TOKEN_OP_DIV TOKEN_OP_MOD TOKEN_OP_POW
%left TOKEN_OP_NEG

/*================================================================
						TERMINAL (TOKENS) RETURNED TYPES
================================================================*/
%token TOKEN_EOS 
%token <text> TOKEN_NUMBER TOKEN_INTEGER
%token <text> TOKEN_ID TOKEN_LITERAL
%token <text> TOKEN_OP_ADD TOKEN_OP_SUB TOKEN_OP_MUL TOKEN_OP_DIV TOKEN_OP_MOD TOKEN_OP_ASSIGN
//Fake
%token <texT> TOKEN_CALL, TOKEN_ARGS

/*================================================================
						NON-TERMINAL RETURNED TYPES
================================================================*/
/* declare non-terminal rules */
%type <node> statement
%type <node> exprStmt compoundExp
%type <node> funcCallExp arguments
%type <node> declareExp 
%type <node> mathExp arithmeticExp
%type <node> assignExp
%type <node> unaryExp 
%type <node> term atom
%type <node> string identifier number


/*================================================================
						GRAMMAR RULES for the CALC LANGUAGE
================================================================*/
%%
input:			
							{ 	 }					
	| statement	 			{   // first statement
								//TODO: maybe we should include EOL	 at the end of rule	
									if($1 != NULL) {
										LOG(Logger::LEVEL_TRACE, ">>>>>[bison] " + util::Converts::numberToString(root));																	
										root.reset($1);
										LOG(Logger::LEVEL_TRACE, "<<<<<[bison] " + util::Converts::numberToString(root));
									} else {						
										std::cerr << "AST is nullptr!" << std::endl;
									}
									
									YYACCEPT;
        						}		        						
	| error  					{ 
									//yyerror(result, "<Parser> error at (input) '%s'\n", yytext);
    								
    								std::string cause = std::string("Parse Exception for input '")  + std::string("'");
    								throw ParseException(cause);
    								YYABORT;  								
								}		
	;
	
statement: 	 				
	exprStmt 					 {	$$ = $1;  }
    ;
    
/*================================================================
		REAL EXPRESSION BEGINS HERE
================================================================*/	
//expression that forms a statement
exprStmt: 
	declareExp					{ $$ = $1; }
	| assignExp					{ $$ = $1; }
	| compoundExp				{ $$ = $1; }
	| funcCallExp				{ $$ = $1; }
	;
	
declareExp:
	identifier string			{ $$ = $1; }
	;

assignExp:
	identifier TOKEN_OP_ASSIGN compoundExp		{ 
                                    SourceCodePosition position(@2.last_line, @2.last_column);
									ASTNode* current = ASTUtils::createAST("=", TOKEN_OP_ASSIGN, $1, $3, position);
									
									$$ = current;	
								}
	;

compoundExp:			
	mathExp 					{ $$ = $1; }				
	;

funcCallExp:
	identifier '(' ')'			{
                                    SourceCodePosition position(@2.last_line, @2.last_column);
                                    ASTNode* current = ASTUtils::createAST("CALL", TOKEN_CALL, $1, position);

                                    $$ = current;
                                }
	| identifier '(' arguments ')'
                                {
                                    SourceCodePosition position(@2.last_line, @2.last_column);
                                    //TODO: Enhancement: maybe we can reduce AST via pulling the cascaded arguments TreeNode onto this level
                                    ASTNode* current = ASTUtils::createAST("CALL", TOKEN_CALL, $1, $3, position);

                                    $$ = current;
                                }
	;

arguments:
	exprStmt					{
                                    SourceCodePosition position(@1.last_line, @1.last_column);
                                    ASTNode* current = ASTUtils::createAST("ARGS", TOKEN_ARGS, $1, position);

                                    $$ = current;
                                }
	| exprStmt ',' arguments	{
									SourceCodePosition position(@2.last_line, @2.last_column);
                                    //TODO: Enhancement: maybe we can reduce AST via pulling the cascaded arguments TreeNode onto the same level of tree
									ASTNode* current = ASTUtils::createAST("ARGS", TOKEN_ARGS, $1, $3, position);

									$$ = current;
                                }
	;


mathExp:
	unaryExp					{ $$ = $1; }
	| arithmeticExp				{ $$ = $1; }
	;	

arithmeticExp:	
    mathExp TOKEN_OP_ADD mathExp 	{
                                    SourceCodePosition position(@2.last_line, @2.last_column);
									ASTNode* current = ASTUtils::createAST("+", TOKEN_OP_ADD, $1, $3, position);
									
									$$ = current;
								}
    | mathExp TOKEN_OP_SUB mathExp 	{
                                    SourceCodePosition position(@2.last_line, @2.last_column);
    								ASTNode* current = ASTUtils::createAST("-", TOKEN_OP_SUB, $1, $3, position);
									
									$$ = current;
								}
    | mathExp TOKEN_OP_MUL mathExp 	{
                                    SourceCodePosition position(@2.last_line, @2.last_column);
    								ASTNode* current = ASTUtils::createAST("*", TOKEN_OP_MUL, $1, $3, position);
									
									$$ = current;    
								}
    | mathExp TOKEN_OP_DIV mathExp 	{
                                    SourceCodePosition position(@2.last_line, @2.last_column);
    								ASTNode* current = ASTUtils::createAST("/", TOKEN_OP_DIV, $1, $3, position);
									
									$$ = current;     
								}
    | mathExp TOKEN_OP_MOD mathExp 	{
                                    SourceCodePosition position(@2.last_line, @2.last_column);
    								ASTNode* current = ASTUtils::createAST("%", TOKEN_OP_MOD, $1, $3, position);
									
									$$ = current;    
    							}
    | mathExp TOKEN_OP_POW mathExp {
                                    SourceCodePosition position(@2.last_line, @2.last_column);
                                    //FIXME: % should be ^
      								ASTNode* current = ASTUtils::createAST("%", TOKEN_OP_POW, $1, $3, position);
									
									$$ = current;     
								}							
    ;

unaryExp:
	atom						{ $$ = $1; }
	|'(' compoundExp ')' 		{ $$ = $2; }
    | TOKEN_OP_SUB term  %prec TOKEN_OP_NEG	{
                                    SourceCodePosition position(@1.last_line, @1.last_column);
    								ASTNode* current = ASTUtils::createAST("Neg", TOKEN_OP_NEG, $2, position);
    								
    								$$ = current;
    							}
    //negation has the same precedence as multiplication/division
    ;

atom:
	term						{ $$ = $1; }
   	| string 					{ $$ = $1; }
   	;	

term:
   	number 						{ $$ = $1; }
   	| identifier				{ $$ = $1; }
   	;	

number:
	TOKEN_NUMBER				{
                                    SourceCodePosition position(@1.last_line, @1.last_column);
                                    $$ = ASTUtils::createAST($1, TOKEN_NUMBER, position);
                                }
	| TOKEN_INTEGER				{
                                    SourceCodePosition position(@1.last_line, @1.last_column);
                                    $$ = ASTUtils::createAST($1, TOKEN_INTEGER, position);
                                }
	;
	
string:
	TOKEN_LITERAL				{
                                    SourceCodePosition position(@1.last_line, @1.last_column);
                                    $$ = ASTUtils::createAST($1, TOKEN_LITERAL, position);
                                }
	;

identifier:
	TOKEN_ID 					{
                                    SourceCodePosition position(@1.last_line, @1.last_column);
                                    $$ = ASTUtils::createAST($1, TOKEN_ID, position);
                                }
	;
%%
/*================================================================
					NATIVE CODE BLOCK
================================================================*/