%{
  #include <stdio.h>
  #include <stdlib.h>
  extern FILE * yyin;
  extern int  numLines;
  extern int numColumns;
  void yyerror(const char *msg) {
    printf("Error at  Line %d:  Row: %d\n", numLines, numColumns);
  }
  int has_main = 0;
  struct codeNode{
	  std::string code;
	  std::string name;
  }
%}

%union{
  int		int_val;
  char*	op_val;
}

%start Program 

%token	<int_val>	NUMBER
%token	<op_val>	IDENT
%token FUNCTION
%token BEGIN_PARAMS
%token END_PARAMS
%token BEGIN_LOCALS
%token END_LOCALS
%token BEGIN_BODY
%token END_BODY
%token INTEGER
%token ARRAY
%token OF
%token IF
%token THEN
%token ENDIF
%token ELSE
%token WHILE
%token DO
%token BEGINLOOP
%token ENDLOOP
%token CONTINUE
%token BREAK
%token READ
%token WRITE
%token NOT
%token TRUE
%token FALSE
%token RETURN
%token PLUS
%token MINUS
%token MULT
%token DIV
%token MOD
%token SEMICOLON
%token COLON
%token COMMA
%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token ASSIGN
%token EQ
%token NEQ
%token LT
%token GT
%token LTE
%token GTE


%%

Program:		/* empty */{printf("Program->Epsilon\n");}
    | FUNCTIONS Program	{ 
		if($2 == "main"){
			if(!has_main){
				has_main++;
				printf("func main");
			}
			else{
				printf("Error Line %d: There is already a main function", numLines);
				exit(1);
			}
		}
		else{
			if(!has_main){
				printf("Error Line %d: There is no main function", numLines);
				exit(1);
			}
			else{
				printf("func %d\n", $2);
			}
		}
	 };
FUNCTIONS: FUNCTION Ident SEMICOLON BEGIN_PARAMS Declaration END_PARAMS BEGIN_LOCALS Declaration END_LOCALS BEGIN_BODY Statement END_BODY {printf("FUNCTIONS-> FUNCTION Ident SEMICOLON BEGIN_PARAMS Declaration END_PARAMS BEGIN_LOCALS Declaration END_LOCALS BEGIN_BODY Statement END_BODY\n");}

Declaration: 	{printf("Declaration->Epsilon\n");}
		|Ident COLON INTEGER SEMICOLON Declaration {printf("Declaration->Ident COLON NUMBER SEMICOLON Declaration\n");}
		|Ident COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER SEMICOLON Declaration{printf("Declaration->Ident COLON ARRAY L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET OF NUMBER SEMICOLON Declaration\n",$5);}
		;

Statement: 	Var ASSIGN Expression SEMICOLON Statement1 {printf("Statement->Var ASSIGN Expression SEMICOLON Statement1\n");}
		|IF Bool-Exp THEN Statement ENDIF SEMICOLON Statement1 {printf("Statement->IF Bool-Exp THEN Statement ENDIF SEMICOLON Statment1\n");}
		|IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statement1 {printf("Statement->IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statment1\n");}
		|WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1 {printf("Statement->WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1\n");}
		|DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1 {printf("Statement->DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1\n");}
		|READ Var SEMICOLON Statement1 {printf("Statement->READ Var SEMICOLON Statement1\n");}
		|WRITE Var SEMICOLON Statement1 {printf("Statement->WRITE Var SEMICOLON Statement1\n");}
		|CONTINUE SEMICOLON Statement1 {printf("Statement->CONTINUE SEMICOLON Statement1\n");}
		|BREAK SEMICOLON Statement1 {printf("Statement->BREAK SEMICOLON Statement1\n");}
		|RETURN Expression SEMICOLON Statement1 {printf("Statement->RETURN Expression SEMICOLON Statement1\n");}

Statement1:	{printf("Statement1->Epsilon\n");}
		|Var ASSIGN Expression SEMICOLON Statement1 {printf("Statement1->Var ASSIGN Expression SEMICOLON Statement1\n");}
                |IF Bool-Exp THEN Statement ENDIF SEMICOLON Statement1 {printf("Statement1->IF Bool-Exp THEN Statement ENDIF SEMICOLON Statment1\n");}
                |IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statement1 {printf("Statement1->IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statment1\n");}
                |WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1 {printf("Statement1->WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1\n");}
                |DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1 {printf("Statement1->DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1\n");}
                |READ Var SEMICOLON Statement1 {printf("Statement1->READ Var SEMICOLON Statement1\n");}
                |WRITE Var SEMICOLON Statement1 {printf("Statement1->WRITE Var SEMICOLON Statement1\n");}
                |CONTINUE SEMICOLON Statement1 {printf("Statement1->CONTINUE SEMICOLON Statement1\n");}
                |BREAK SEMICOLON Statement1 {printf("Statement1->BREAK SEMICOLON Statement1\n");}
                |RETURN Expression SEMICOLON Statement1 {printf("Statement1->RETURN Expression SEMICOLON Statement1\n");}

Bool-Exp:	NotLoop Expression Comp Expression {printf("Bool-Exp->NotLoop Expression Comp Expression\n");}	

NotLoop:	{printf("NotLoop->Epsilon\n");}
		|NOT NotLoop{printf("NotLoop->NOT NotLoop\n");}

Comp:		EQ{printf("Comp->EQ\n");}
		|NEQ{printf("Comp->NEQ\n");}
		|GT{printf("Comp->GT\n");}
		|LT{printf("Comp->LT\n");}
		|GTE{printf("Comp->GET\n");}
		|LTE{printf("Comp->LTE\n");}

Expression:	Multiplicative-Expr{printf("Expression->Multiplicative-Expr\n");}
		|Multiplicative-Expr PLUS Multiplicative-Expr{
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $1->code + $3->code + decl_temp_code(temp);
			node->code += std::string("+ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
			node->name = temp;
			$$ = node;
		}
		|Multiplicative-Expr MINUS Multiplicative-Expr{
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $1->code + $3->code + decl_temp_code(temp);
			node->code += std::string("- ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
			node->name = temp;
			$$ = node;
		}

Multiplicative-Expr: 	Term {printf("%d\n", $1);}
			|Term MULT Term {
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code + decl_temp_code(temp);
				node->code += std::string("* ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}
			|Term DIV Term {
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code + decl_temp_code(temp);
				node->code += std::string("/ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}
			|Term MOD Term {
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code + decl_temp_code(temp);
				node->code += std::string("% ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}

Term:		Var {printf("Term->Var\n");}
		|NUMBER{printf("Term->NUMBER %d\n",$1);}
		|L_PAREN Expression R_PAREN{printf("Term->L_PAREN Expression R_PAREN\n");}
		|Ident L_PAREN Expression1 R_PAREN{printf("Term->Ident L_PAREN Expression1 R_PAREN\n");}

Expression1: 	{printf("Expression1->Epsilon\n");}
		|Expression{printf("Expression1->Epsilon\n");}
		|Expression COMMA Expression1 {printf("Expression1->Epsilon\n");}

Var:
    		Ident{
				codeNode *node = new codeNode;
				node->code = "";
				node->name = $1;
				std::string error;
				if(!find(node->name, Iteger, error)){
					yyerror(error.c_str());
				}
				$$ = node;
			}
    		| Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {printf("Var->Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET\n");}
    		;

Ident:
        IDENT{$$ = $1;}
%% 

int main(int argc, char **argv) {
   yyparse();
   return 0;
}
