%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string>
  #include <vector>
  #include <string.h>
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
char *identToken;
int numberToken;
int  count_names = 0;


enum Type { Integer, Array };
struct Symbol {
  std::string name;
  Type type;
};
struct Function {
  std::string name;
  std::vector<Symbol> declarations;
};

std::vector <Function> symbol_table;


Function *get_function() {
  int last = symbol_table.size()-1;
  return &symbol_table[last];
}

bool find(std::string &value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {
      return true;
    }
  }
  return false;
}

void add_function_to_symbol_table(std::string &value) {
  Function f; 
  f.name = value; 
  symbol_table.push_back(f);
}

void add_variable_to_symbol_table(std::string &value, Type t) {
  Symbol s;
  s.name = value;
  s.type = t;
  Function *f = get_function();
  f->declarations.push_back(s);
}

void print_symbol_table(void) {
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].declarations.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
    }
  }
  printf("--------------------\n");
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
	add_function_to_symbol_table($2->name);
	std::string assignments="";
	Function *f=get_function();
	int array_count=0;
	for(int i=0;i<f->declarations.size();i++){
			if(f->declarations[i]->type!=Array)
			assingmnets+=std::string("= ")+f->dclarations[i]->name+std::string(", $")+std::to_string(i-array_count)+std::string("\n");
			else array_count++;
			}
	codeNode *node = new codeNode;
	node->code = $2->code;
	node->code += std::string("func ") + $2->name + std::string("\n")+$5->code+assignments+$8->code+$11->code;
	$$ = node;
}

Declaration: 	{printf("Declaration->Epsilon\n");}
		|Ident COLON INTEGER SEMICOLON Declaration {
								Type t=Integer;
								add_variable_to_symbol_table($1->name,t);
								codeNode *node = new codeNode;
								node->code=$1->code;
								node->code+= std::string(". ")+$1->name+std::string("\n")+$5->code;
								$$=node;
								}
		|Ident COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER SEMICOLON Declaration{
				Type t=Array
				add_variable_to_symbol_table($1->name,t);				
				codeNode *node = new codeNode;
                                node->code=$1->code;
                                node->code+= std::string(".[] ")+$1->name+std::string(", ")+std::to_string($5)+std::string("\n")+$10->code;
								$$ = node;
								}
		;

Statement: 	Var ASSIGN Expression SEMICOLON Statement1 {
			std::string var_name = $1;
			std::string error;
			if(!find(var_name)){
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
					if(!find(array_name)){
						yyerror(error.c_str());
					}
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
							if(!find($2->name)){
								yyerror(error.c_str());
							}
							node->code=std::string(".< ")+$2->name+std::string("\n")+$4->code;
							node->name=temp;
							$$=node;
						}
                |READ Ident L_SQUARE_BRACKE Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
													std::string temp = create_temp();
													codeNode *node = new codeNode;
													if(!find($2->name)){
														yyerror(error.c_str());
													}
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
                |RETURN Expression SEMICOLON Statement1 {//return src
                        codeNode *node = new codeNode;
                        node->code = std::string("ret ")+$2->name+std::string("\n")+$4->code;;
                        $$ = code;
			}

Bool-Exp:	NotLoop Expression Comp Expression {printf("Bool-Exp->NotLoop Expression Comp Expression\n");}	

NotLoop:	{printf("NotLoop->Epsilon\n");}
		|NOT NotLoop{printf("NotLoop->NOT NotLoop\n");}

Comp:		EQ{printf("Comp->EQ\n");}
		|NEQ{printf("Comp->NEQ\n");}
		|GT{printf("Comp->GT\n");}
		|LT{printf("Comp->LT\n");}
		|GTE{printf("Comp->GET\n");}
		|LTE{printf("Comp->LTE\n");}

Expression:	Multiplicative-Expr{//not sure if this is correct but I think it is needed}
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
			node->code = $1 -> code;//using immediate value so i think i can just stop after this
			$$ = node;
			}
		|L_PAREN Expression R_PAREN{//return expression
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $2 -> code;// don't need to do the node->code+= stuff as substuff of expression takes care of that
			node->name = temp;
			$$ = node;
						}
		|Ident L_PAREN Expression2 R_PAREN{//function call
			codeNode *node = new codeNode;
			std::string temp = create_temp();
			if(!find($1->name)){
				yyerror(error.c_str());
			}
			node->code+=$3->code+std::string("call ") + $1->name +std::string(", ")+ temp+ std::string("\n");
			node->name = temp;
			$$ = node;// I have no clue wat im doing for this one, also i think we missing a grammar rule bc table says call name, dest changed so that the dest is the temp name that it is returned to
		}

Expression1: 	{}
		|Expression{
				codeNode *node=new codeNode;
                node->code=std::string("param ")+$1->name+std::string("\n");
                $$=node;
}

Expression2: 	{}
		|Expression{
				codeNode *node=new codeNode;
				node->code=std::string("param ")+$1->name+std::string("\n");
				$$=node;
}
		|Expression COMMA Expression2{
						codeNode *node = new codeNode;
						node->code=std::string("param ")+$1->name+std::string("\n")+$3->code;
						$$=node;
						}


Var:
    		Ident{
				codeNode *node = new codeNode;
				node->code = "";
				node->name = $1->name;
				if(!find(node->name)){
					yyerror(error.c_str());
				}
				$$ = node;
				
			}
    		| Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {//array access statement store temp to return temp register
				std::string temp = create_temp();
                codeNode *node = new codeNode;
				if(!find($1->name)){
					yyerror(error.c_str());
				}
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
			if(!find(node->name)){
				yyerror(error.c_str());
			}
			std::string error;
			$$ = node;
		}
%% 

int main(int argc, char **argv) {
   yyparse();
   return 0;
}
