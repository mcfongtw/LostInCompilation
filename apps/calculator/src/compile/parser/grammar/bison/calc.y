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
						TOKENS
================================================================*/
%token TOKEN_EOS 
%token <text> TOKEN_NUMBER TOKEN_INTEGER
%token <text> TOKEN_ID TOKEN_LITERAL
%token <text> TOKEN_OP_ADD TOKEN_OP_SUB TOKEN_OP_MUL TOKEN_OP_DIV TOKEN_OP_MOD TOKEN_OP_ASSIGN

/*================================================================
						NON-TERMINAL TYPES
================================================================*/
/* declare non-terminal rules */
%type <node> statement
%type <node> exprStmt compoundExpr 
%type <node> declareExp 
%type <node> mathExp arithmeticExp
%type <node> assignExp
%type <node> unaryExp 
%type <node> term atom
%type <node> string identifier number

/**
funcArgList:
	compoundExpr						
	| funcArgList ',' compoundExpr
	;
**/

/*================================================================
						GRAMMAR RULES for the VIEW LANGUAGE
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
	| compoundExpr				{ $$ = $1; }
	;
	
declareExp:
	identifier string			{ $$ = $1; }
	;

assignExp:
	identifier TOKEN_OP_ASSIGN compoundExpr		{ 
									ASTNode* current = ASTUtils::createAST("=", TOKEN_OP_ASSIGN, $1, $3);
									
									$$ = current;	
								}
	;

compoundExpr:			
	mathExp 					{ $$ = $1; }				
	;

mathExp:
	unaryExp					{ $$ = $1; }
	| arithmeticExp				{ $$ = $1; }
	;	

arithmeticExp:	
    mathExp TOKEN_OP_ADD mathExp 	{ 
									ASTNode* current = ASTUtils::createAST("+", TOKEN_OP_ADD, $1, $3);									
									
									$$ = current;
								}
    | mathExp TOKEN_OP_SUB mathExp 	{ 
    								ASTNode* current = ASTUtils::createAST("-", TOKEN_OP_SUB, $1, $3);
									
									$$ = current;
								}
    | mathExp TOKEN_OP_MUL mathExp 	{ 
    								ASTNode* current = ASTUtils::createAST("*", TOKEN_OP_MUL, $1, $3);
									
									$$ = current;    
								}
    | mathExp TOKEN_OP_DIV mathExp 	{ 
    								ASTNode* current = ASTUtils::createAST("/", TOKEN_OP_DIV, $1, $3);
									
									$$ = current;     
								}
    | mathExp TOKEN_OP_MOD mathExp 	{ 
    								ASTNode* current = ASTUtils::createAST("%", TOKEN_OP_MOD, $1, $3);
									
									$$ = current;    
    							}
    | mathExp TOKEN_OP_POW mathExp {
      								ASTNode* current = ASTUtils::createAST("%", TOKEN_OP_POW, $1, $3);
									
									$$ = current;     
								}							
    ;

unaryExp:
	atom						{ $$ = $1; }
	|'(' compoundExpr ')' 		{ $$ = $2; }
    | TOKEN_OP_SUB term  %prec TOKEN_OP_NEG	{ 
    								ASTNode* current = ASTUtils::createAST("Neg", TOKEN_OP_NEG, $2);
    								
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
	TOKEN_NUMBER				{ $$ = ASTUtils::createAST($1, TOKEN_NUMBER);}
	| TOKEN_INTEGER				{ $$ = ASTUtils::createAST($1, TOKEN_INTEGER);}
	;
	
string:
	TOKEN_LITERAL				{ $$ = ASTUtils::createAST($1, TOKEN_LITERAL); }
	;

identifier:
	TOKEN_ID 					{ $$ = ASTUtils::createAST($1, TOKEN_ID); }
	;
%%
/*================================================================
					NATIVE CODE BLOCK
================================================================*/