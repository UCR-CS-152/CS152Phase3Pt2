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
		//idk bout this one
		codeNode *node= new codeNode;
		node->code=$1->code+$2->code;
		$$=node;
	 };
FUNCTIONS: FUNCTION Ident SEMICOLON BEGIN_PARAMS Declaration END_PARAMS BEGIN_LOCALS Declaration END_LOCALS BEGIN_BODY Statement END_BODY {
	codeNode *node = new codeNode;
	node->code = $2->code;
	node->code += std::string("func ") + $2->name + std::string("\n")+$5->code+$8->code+$11->code;
	$$ = node;
}

Declaration: 	{printf("Declaration->Epsilon\n");}
		|Ident COLON INTEGER SEMICOLON Declaration {
								codeNode *node = new codeNode;
								node->code=$1->code;
								node->code+= std::string(". ")+$1->name+std::string("\n")+$5->code;
								$$=node;
								}
		|Ident COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER SEMICOLON Declaration{
								codeNode *node = new codeNode;
                                                                node->code=$1->code;
                                                                node->code+= std::string(".[] ")+$1->name+std::string(", ")+std::to_string($5)+std::string("\n")+$10->code;
								}
		;

Statement: 	Var ASSIGN Expression SEMICOLON Statement1 {
			std::string var_name = $1;
			std::string error;
			if(!find(node->name, Integer, error)){
				yyerror(error.c_str());
			}
			codeNode *node = new codeNode;
			node->code = $3->code;
			node->code += std::string("= ") + var_name + std::string(", ") + $3->name + std::string("\n")+$5->code;
			$$ = node;
		}
                |Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET ASSIGN Experession SEMICOLON Statement1{
                                                                                                                std::string array_name= $1->name;
                                                                                                                codeNode *node = new codeNode;
                                                                                                                node->code=$3->code + $6->code;
                                                                                                                node->code=std::string("[]= ")+ array_name+std::string(", ")+$3->name+std::string(", ")+$6->name+std::string("\n")+$9->code;
                                                                                                                $$=node;
                                                                                                                }
		|IF Bool-Exp THEN Statement ENDIF SEMICOLON Statement1 {printf("Statement->IF Bool-Exp THEN Statement ENDIF SEMICOLON Statment1\n");}
		|IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statement1 {printf("Statement->IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statment1\n");}
		|WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1 {printf("Statement->WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1\n");}
		|DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1 {printf("Statement->DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1\n");}
		|READ Ident SEMICOLON Statement1 {
							std::string temp = create_temp();
							codeNode *node = new codeNode;
							node->code=std::string(".< ")+$2->name+std::string("\n")+$4->code;
							node->name=temp;
							$$=node;
						}
                |READ Ident L_SQUARE_BRACKE Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
													std::string temp = create_temp();
													codeNode *node = new codeNode;
													node->code=std::string(",[]< ")+$2->name+std::string(", ")+$4->code+std::string("\n")+$7->code;
													node->name=temp;
													$$=node;
												}
		|WRITE Ident SEMICOLON Statement1 {
                                                        std::string temp = create_temp();
                                                        codeNode *node = new codeNode;
                                                        node->code=std::string(".> ")+$2->name+std::string("\n")+$4->code;
                                                        node->name=temp;
                                                        $$=node;
                                                }
                |WRITE Ident L_SQUARE_BRACKE Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
                                                                                                        std::string temp = create_temp();
                                                                                                        codeNode *node = new codeNode;
                                                                                                        node->code=std::string(",[]> ")+$2->name+std::string(", ")+$4->code+std::string("\n")+$7->code;
                                                                                                        node->name=temp;
                                                                                                        $$=node;
												}
		|CONTINUE SEMICOLON Statement1 {printf("Statement->CONTINUE SEMICOLON Statement1\n");}
		|BREAK SEMICOLON Statement1 {printf("Statement->BREAK SEMICOLON Statement1\n");}
		|RETURN Expression SEMICOLON Statement1 {//return src 
			codeNode *node = new codeNode;
			node->code = std::string("ret ")+$2->name+std::string("\n")+$4->code;;
			$$ = code;
		}

Statement1:	{printf("Statement1->Epsilon\n");}
		|Ident ASSIGN Expression SEMICOLON Statement1 {
					std::string var_name = $1->name;
					std::string error;
					if(!find(node->name, Integer, error)){
						yyerror(error.c_str());
					}
					codeNode *node = new codeNode;
					node->code = $3->code;
					node->code += std::string("= ") + var_name + std::string(", ") + $3->name + std::string("\n")+$5->code;
					$$ = node;
				}
		|Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET ASSIGN Experession SEMICOLON Statement1{
														std::string array_name= $1->name;
														codeNode *node = new codeNode;
														node->code=$3->code + $6->code;
														node->code=std::string("[]= ")+ array_name+std::string(", ")+$3->name+std::string(", ")+$6->name+std::string("\n")+$9->code;
														$$=node;
														}
                |IF Bool-Exp THEN Statement ENDIF SEMICOLON Statement1 {printf("Statement1->IF Bool-Exp THEN Statement ENDIF SEMICOLON Statment1\n");}
                |IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statement1 {printf("Statement1->IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statment1\n");}
                |WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1 {printf("Statement1->WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1\n");}
                |DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1 {printf("Statement1->DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1\n");}
		|READ Ident SEMICOLON Statement1 {
                                                        std::string temp = create_temp();
                                                        codeNode *node = new codeNode;
                                                        node->code=std::string(".< ")+$2->name+std::string("\n")+$4->code;
                                                        node->name=temp;
                                                        $$=node;
                                                }
                |READ Ident L_SQUARE_BRACKE Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
                                                                                                        std::string temp = create_temp();
                                                                                                        codeNode *node = new codeNode;
                                                                                                        node->code=std::string(",[]< ")+$2->name+std::string(", ")+$4->code+std::string("\n")+$7->code;
                                                                                                        node->name=temp;
                                                                                                        $$=node;
                                                                                                }
                |WRITE Ident SEMICOLON Statement1 {
                                                        std::string temp = create_temp();
                                                        codeNode *node = new codeNode;
                                                        node->code=std::string(".> ")+$2->name+std::string("\n")+$4->code;
                                                        node->name=temp;
                                                        $$=node;
                                                }
                |WRITE Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
                                                                                                        std::string temp = create_temp();
                                                                                                        codeNode *node = new codeNode;
                                                                                                        node->code=std::string(",[]> ")+$2->name+std::string(", ")+$4->code+std::string("\n")+$7->code;
                                                                                                        node->name=temp;
                                                                                                        $$=node;
                                                                                                }
                |CONTINUE SEMICOLON Statement1 {printf("Statement1-> CONITNUE SEMICOLON Statement1\n");}
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
			node->code = $1->code + $3->code;
			node->code += std::string("+ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
			node->name = temp;
			$$ = node;
		}
		|Multiplicative-Expr MINUS Multiplicative-Expr{
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $1->code + $3->code;
			node->code += std::string("- ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
			node->name = temp;
			$$ = node;
		}

Multiplicative-Expr: 	Term {printf("%d\n", $1);}
			|Term MULT Term {
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code;
				node->code += std::string("* ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}
			|Term DIV Term {
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code;
				node->code += std::string("/ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}
			|Term MOD Term {
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code;
				node->code += std::string("% ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}

Term:		Var{//return temp register
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code;
				node->code += std::string(". ") + temp + std::string("\n");
				node->name = temp;
				$$ = node;
			}
		|NUMBER{//return number;
			codeNode *node = new codeNode;
			node->code = $1 -> code;//using immediate valye so i think i can just stop after this
			$$ = node;
			}
		|L_PAREN Expression R_PAREN{//return expression
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $2 -> code;// don't need to do the node->code+= stuff as substuff of expression takes care of that
			node->name = temp;
			$$ = node;
						}
		|Ident L_PAREN Expression1 R_PAREN{//function call
			codeNode *node = new codeNode;
			std::string dest = create_temp();
			node->code+=std::string("call ") + $1->name + std::string("\n");
			node->name = dest;
			$$ = node;// I have no clue wat im doing for this one
		}

Expression1: 	{printf("Expression1->Epsilon\n");}
		|Expression{printf("Expression1->Expression\n");}
		|Expression COMMA Expression1 {printf("Expression1->Expression COMMA Expression1\n");}

Var:
    		Ident{
				codeNode *node = new codeNode;
				node->code = "";
				node->name = $1->name;
				//std::string error;
				//if(!find(node->name, Integer, error)){
				//	yyerror(error.c_str());
				//}
				$$ = node;
				
			}
    		| Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {//array access statement store temp to return temp register
				std::string temp = create_temp();
                codeNode *node = new codeNode;
                node->code=std::string(",[]> ")+$1->name+std::string(", ")+$3->code+std::string("\n");
                node->name=temp;
                $$=node;//Just copied pasted with some slight adjustments from thomas implementation
			}
    		;

Ident:/*We need to check this for sure*/
        IDENT{
			codeNode *node = new codeNode;
			node->code = "";
			node->name = $1;
			std::string error;
			if(!find(node->name, Integer, error)){
				yyerror(error.c_str());
			}
			$$ = node;
		}
%% 

int main(int argc, char **argv) {
   yyparse();
   return 0;
}
