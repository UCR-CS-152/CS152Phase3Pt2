   /* cs152-miniL phase1 */
   
%{   
   /* write your C code here for definitions of variables and including headers */
   #include "y.tab.h"
   int numLines = 1;
   int numColumns = 0;
%}

   /* some common rules */
DIGIT    [0-9]
LETTER   [a-zA-Z]

%%
   /* specific lexer rules in regex */
["##"][^\n]*   {asm ("nop");}

" "		      {
		            numColumns++;
                  //return SPACE;
		         }

{DIGIT}+[a-zA-Z][a-zA-Z0-9]*	{
		                           printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", numLines, numColumns, yytext);
		                           return -1;
		                        }

{DIGIT}+	      {
                  yylval.int_val = atoi(yytext);
		            numColumns+=strlen(yytext);
                  return NUMBER;
		         }
"\n"           {
                  numLines++;
                  numColumns = 0;
                  //return NEWLINE;
               }
"\t"           {
                  numColumns+=4;
                  //return TAB;
               }
"function"     {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return FUNCTION;
               }
"beginparams"  {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return BEGIN_PARAMS;
               }
"endparams"    {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return END_PARAMS;
               }
"beginlocals"  {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return BEGIN_LOCALS;
               }
"endlocals"    {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return END_LOCALS;
               }
"beginbody"    {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return BEGIN_BODY;
               }
"endbody"      {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return END_BODY;
               }
"integer"      {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return INTEGER;
               }
"array"        {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return ARRAY;
               }
"of"           {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return OF;
               }   
"if"           {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return IF;
               }     
"then"         {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return THEN;
               }  
"endif"        {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return ENDIF;
               }  
"else"         {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return ELSE;
               }   
"while"        {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return WHILE;
               } 
"do"           {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return DO;
               }   
"beginloop"    {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return BEGINLOOP;
               }
"endloop"      {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return ENDLOOP;
               } 
"continue"     {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return CONTINUE;
               }
"break"        {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return BREAK;
               } 
"read"         {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return READ;
               }      
"write"        {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return WRITE;
               } 
"not"          {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return NOT;
               }   
"true"         {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return TRUE;
               }      
"false"        {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return FALSE;
               }       
"return"       {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return RETURN;
               }                                                                                                                                          
"+"            {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return PLUS;
               }
"-"            {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return MINUS;
               }
"*"            {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return MULT;
               }
"/"            {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return DIV;
               }
"%"            {
                  //yylval.op_val = yytext;
                  numColumns+=yyleng;
                  return MOD;
               }
{LETTER}[a-zA-Z"_"0-9]*["_"]  {
                        printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", numLines, numColumns, yytext);
                        return -1;
                              }

{LETTER}[a-zA-Z"_"0-9]*       {
                        numColumns+=strlen(yytext);
			               yylval.op_val=yytext;
                        return IDENT;
		               }
";"            {
                  numColumns+=yyleng;
                  return SEMICOLON;
               }     
":"            {
                  numColumns+=yyleng;
                  return COLON;
               }  
","            {
                  numColumns+=yyleng;
                  return COMMA;
               }
"("            {
                  numColumns+=yyleng;
                  return L_PAREN;
               }                                                                 
")"            {
                  numColumns+=yyleng;
                  return R_PAREN;
               } 
"["            {
                  numColumns+=yyleng;
                  return L_SQUARE_BRACKET;
               }     
"]"            {
                  numColumns+=yyleng;
                  return R_SQUARE_BRACKET;
               } 
":="           {
                  numColumns+=yyleng;
                  return ASSIGN;
               }   
"=="           {
                  numColumns+=yyleng;
                  return EQ;
               }
"<>"           {
                  numColumns+=yyleng;
                  return NEQ;
               }
"<"            {
                  numColumns+=yyleng;
                  return LT;
               }     
">"            {
                  numColumns+=yyleng;
                  return GT;
               }  
"<="           {
                  numColumns+=yyleng;
                  return LTE;
               }
">="           {
                  numColumns+=yyleng;
                  return GTE;
               }                                                                 
.              {
		            printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", numLines, numColumns, yytext);
                  exit(-1);
               }            

%%
	/* C functions used in lexer */

