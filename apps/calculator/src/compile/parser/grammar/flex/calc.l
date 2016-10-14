/*================================================================
				FLEX SETTING
================================================================*/
/* In order to make flex to scan case-insensitive tokens, add '-i' to command-line option. */

%option noyywrap 
%option nounput noinput
%option nodefault 
%option yylineno

/* enable yylex(YYSTYPE*, ...) */
%option bison-bridge

/* enable yylex(..., YYLTYPE*, ...) */
%option bison-locations

/* scanner_t in yylex(...)*/
%option reentrant

%{
#include "compile/parser/grammar/GrammarLibs.h"

char token_buffer[1024];
char *token_buffer_ptr;

size_t yy_custom_col = 0;

%}

/*================================================================
				PARTIAL TOKEN DEFINITION
================================================================*/
/*
 * 0x28: (
 * 0x29: )
 * 0x2a: +
 * 0x2b: -
 * 0x2c: *
 * 0x2d: /
 */
 //TODO: should take off a-z; however, ambiguous w/ numeric number
SEG 		([^ a-z+\x2d()*/%^\n0-9]+)
DIGIT		([0-9])
EXP			([Ee][-+]?[0-9]+)
LETTER		[a-zA-Z]
ALPHA_NUM	[a-zA-Z0-9_]
ALPHA 		[a-zA-Z_]
HEX_LETTER 	[a-fA-F0-9]

/*================================================================
				TOKEN DEFINITION
================================================================*/
%x STRING_STATE 
%%  
	/* there needs to be a space/tab, other there will be an unrecognized rule error */

	/* arithmetic operators */
"+"  				{ yy_custom_col += 1; return TOKEN_OP_ADD; }
"-"  				{ yy_custom_col += 1; return TOKEN_OP_SUB; }
"*"  				{ yy_custom_col += 1; return TOKEN_OP_MUL; }
"/"  				{ yy_custom_col += 1; return TOKEN_OP_DIV; }
"%"					{ yy_custom_col += 1; return TOKEN_OP_MOD; }
"^"					{ yy_custom_col += 1; return TOKEN_OP_POW; }
"="  				{ yy_custom_col += 1; return TOKEN_OP_ASSIGN; }

"("  |
")"  | 
"["	 |
"]"  |
","	 |
":"	 |
"{"  |
"}"					{ yy_custom_col += 1; return yytext[0]; }


	/* alpha-numeric identifier -- can be used for file name*/
{LETTER}+{ALPHA_NUM}*"."?{ALPHA_NUM}*	{ 
						yylval->text= (char*) malloc(sizeof(char) * strlen(yytext));
						strcpy((char*) yylval->text, yytext);
						yy_custom_col += strlen(yytext); 
	
						return TOKEN_ID;
					}
					
	/* numeric data */
"-"?[0-9]+"."[0-9]+ 	{ 	
						yylval->text= (char*) malloc(sizeof(char) * strlen(yytext));
						strcpy((char*) yylval->text, yytext); 
						yy_custom_col += strlen(yytext);
	
						return TOKEN_NUMBER; 
					}
					
	/* numeric data */
"-"?[0-9]+			{ 	
						yylval->text= (char*) malloc(sizeof(char) * strlen(yytext));
						strcpy((char*) yylval->text, yytext);
						yy_custom_col += strlen(yytext); 

						return TOKEN_INTEGER; 
					}	
					
	/* end of line */
"\n"				{ 	
						yy_custom_col = 0;
					}
										
";"      			{  	
						yy_custom_col += 1;
						return TOKEN_EOS; 
					}
					
"//".*				{ 
						
					}

[ ]   				{ 	/* ignore whitespace */

					}
"\t"				{	/* ignore tabs */

					}
"\""      			{ 	/* Begin to process a string token */
						//a sophisticated designed rule to recognize a C-style string.
						token_buffer_ptr = token_buffer; 

						
						BEGIN(STRING_STATE);
					}
<STRING_STATE>\\[0-7]{1,3} {	
						/* octal escape sequence */
						int result;

						(void) sscanf( yytext + 1, "%o", &result );

						if ( result > 0xff ) {
							/* error, constant is out-of-bounds */
						}

						*token_buffer_ptr++ = result;
					}
<STRING_STATE>\\[0-9]+ 	{
						/* generate error - bad escape sequence; something
						 * like '\48' or '\0777777'
						 */
 	 	 	 	 	}
<STRING_STATE>\\n  		{ 	
						*token_buffer_ptr++ = '\n';
					}
<STRING_STATE>\\t  		{ 
						*token_buffer_ptr++ = '\t';
					}
<STRING_STATE>\\r  		{ 
						*token_buffer_ptr++ = '\r';
					}
<STRING_STATE>\\b			{ 
						*token_buffer_ptr++ = '\b';
					}
<STRING_STATE>\\f  		{ 
						*token_buffer_ptr++ = '\f';
					}					
<STRING_STATE>\\(.|\n)  	{ 
						*token_buffer_ptr++ = yytext[1];
					}
<STRING_STATE>[^\\\n\"]+	{
						char *yptr = yytext;
						
						while ( *yptr ) {
							*token_buffer_ptr++ = *yptr++;							
						}

						
					}
<STRING_STATE>[\r\n]+		{
						/*
						 * TODO: there is a bug in the situation of a line ended with an unterminated string, so 
						 * the scanner will continue to match token from next input 
						 */				

						/* error - unterminated string constant from file*/
						//yyerror(0, "<Lexer> unterminated string content at line %d col %d.\n", yylineno);
						
						/* deliver with what we have after throwing the error message */
						BEGIN(INITIAL);
						*token_buffer_ptr = '\0';
						
						yylval->text= (char*) malloc(sizeof(char) * strlen(token_buffer));
						strcpy((char*) yylval->text, token_buffer);
						yy_custom_col += strlen(yytext); 
						
						/* return string constant token type and
						 * value to parser
						 */
	
						
						return TOKEN_LITERAL;
					}
<STRING_STATE>\"	{	/* saw closing quote - all done */
						BEGIN(INITIAL);
						*token_buffer_ptr = '\0';
						
						yylval->text= (char*) malloc(sizeof(char) * strlen(token_buffer));
						strcpy((char*) yylval->text, token_buffer);
						yy_custom_col += strlen(yytext); 
						
						/* return string constant token type and
						 * value to parser
						 */
						
						return TOKEN_LITERAL;
					}
																			

.       			{ 	
						//yyerror(0, "<Lexer> Mystery character %c at line %d col %d.\n", *yytext, yylineno); 
					}
%%
/*================================================================
					NATIVE CODE BLOCK
================================================================*/