%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string>
  #include <vector>
  #include <stack>
  #include <utility>
  #include <string.h>
  #include <iostream>
  extern FILE * yyin;
  extern int  numLines;
  extern int numColumns;
  std::vector<std::string> reservedWords = {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOR", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR",  "NOT", "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "COLON", "SEMICOLON", "COMMA", "ASSIGN", "function", "ident", "beginparams", "endparams", "beginlocals", "endlocals", "integer", "beginbody", "endbody", "beginloop", "endloop", "if", "endif", "for", "continue", "while", "else", "read", "do", "write"};
  int yylex();
  void yyerror(const char *msg) {
    printf("Error at Line %d:  Column: %d. %s\n", numLines, numColumns, msg);
  }
  int has_main = 0;
  struct codeNode{
	  std::string code;
	  std::string name;
  };
char *identToken;
int numberToken;
int  count_names = 0;
int identCnt = -1;
std::stack<std::string> paramCount;
std::vector<std::pair<std::string,int>>functionscalled;
std::vector<std::pair<std::string,int>>idents_used;
std::vector<std::pair<std::string,int>>arrays_used;
bool er=false;
std::string assignments;
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

bool find(std::string value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {
      return true;
    }
  }
  return false;
}
bool findI(std::string value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value&&s->type==Integer) {
      return true;
    }
  }
  return false;
}

bool findA(std::string value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value&&s->type==Array) {
      return true;
    }
  }
  return false;
}


void add_function_to_symbol_table(std::string value) {
  Function f; 
  f.name = value; 
  symbol_table.push_back(f);
}

void add_variable_to_symbol_table(std::string value, Type t) {
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

std::string create_temp(){
	identCnt++;
	return ("_tmp" + std::to_string(identCnt));
}
%}

%union{
  int		int_val;
  char*	op_val;
  struct codeNode *node;
}

%start Start 

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
%type <node> Start
%type <node> Program 
%type <node> FUNCTIONS 
%type <node> Declaration
%type <node> Declaration2 
%type <node> Statement 
%type <node> Statement1 
%type <node> Expression 
%type <node> Multiplicative-Expr 
%type <node> Term 
%type <node> Expression2 
%type <node> Var 
%type <node> Ident

%%

Start: Program{if(er!=true)std::cout<<$1->code;}

Program:		/* empty */{
					if(symbol_table[symbol_table.size()-1].name!="main")yyerror("No main function defined");
					//check functions called here
					//std::string result=strdup($1->code);
					//printf("%s",result);
					bool f=false;
					for(int i=0; i<functionscalled.size();i++){
						for(int j=0;j<symbol_table.size();j++){
							if(functionscalled[i].first==symbol_table[j].name)f=true;
						}
						if(f==false){
							er=true;
							std::cout<<"Line " <<functionscalled[i].second<<": Function called which has not been defined.\n";
						}
						f=true;
					}
					if(er==true)exit;
					}
    | FUNCTIONS Program	{ 
		//printf("Start of Program->Functions Program\n");
		//idk bout this one
		codeNode *node= new codeNode;
		node->code=$1->code+$2->code;
		//if(functions.find("main") == functions.end())
		//	yyerror("No main function defined");
		//printf("Functions Program\n");
		$$=node;
	 };
FUNCTIONS: FUNCTION Ident{add_function_to_symbol_table($2->name);} SEMICOLON BEGIN_PARAMS Declaration2
				{
				Function *f=get_function();
				assignments="";
				//for(int i=0; i<f->declarations.size();i++){
				//		assignments+=std::string("= ")+f->declarations[i].name+std::string(", $")+std::to_string(i)+std::string("\n");
				//	}
				}
	 END_PARAMS BEGIN_LOCALS Declaration END_LOCALS BEGIN_BODY Statement END_BODY {
	//printf("Start of Functions->Function\n");
	//add_function_to_symbol_table($2->name);
	//std::string assignments="";
	//Function *f=get_function();
	//int array_count=0;
	//for(int i=0;i<f->declarations.size();i++){
	//		if(f->declarations[i].type!=Array)
	//		assignments+=std::string("= ")+f->declarations[i].name+std::string(", $")+std::to_string(i-array_count)+std::string("\n");
	//		else array_count++;
	//		}
	//checked variables and arrays used here
	codeNode *node = new codeNode;
	int i=0;
	codeNode *par= new codeNode;
	par->code="";
	while(!paramCount.empty()){par->code+=std::string("= ")+paramCount.top()+std::string(", $")+std::to_string(i)+std::string("\n");i++;paramCount.pop();}
	node->code = $2->code;
	node->code += std::string("func ") + $2->name + std::string("\n")+$6->code+par->code+$10->code+$13->code+std::string("endfunc\n");
        for (int i=0;i<idents_used.size();i++){
		if(!find(idents_used[i].first)){std::cout<<"Line "<<idents_used[i].second<<": Identifier "<<idents_used[i].first<<" used without having been defined\n";er=true;}
		if(!findI(idents_used[i].first)&&find(idents_used[i].first)){std::cout<<"Line "<<idents_used[i].second<<": Array index used while using an integer variable\n"; er=true;}
	}
        for (int i=0;i<arrays_used.size();i++){
                if(!find(arrays_used[i].first)){std::cout<<"Line "<<arrays_used[i].second<<": Identifier "<<arrays_used[i].first<<"  used without having been defined\n";er=true;}
                if(!findA(arrays_used[i].first)&&find(arrays_used[i].first)){std::cout<<"Line "<<arrays_used[i].second<<": Array index used while using an integer variable\n"; er=true;}
        }
        idents_used.clear();
	arrays_used.clear();
	$$ = node;
};

Declaration: 	{codeNode *node= new codeNode;$$=node;}
		|Ident COLON INTEGER SEMICOLON Declaration {
								//printf("Start of Declaration->Ident\n");
								Type t=Integer;
								std::string var=$1->name;
								if(find(var)){yyerror("Variable has already declared");er=true;}
								add_variable_to_symbol_table(var,t);
								//printf("%s\n",$1->name;
								//printf("After adding to symbol table\n");
								codeNode *node = new codeNode;
								node->code=$1->code;
								node->code+= std::string(". ")+$1->name+std::string("\n")+$5->code;
								$$=node;
								}
		|Ident COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER SEMICOLON Declaration{
				//printf("Start of Declaration->Ident array\n");
				Type t=Array;
				if(find($1->name)){yyerror("Array has already declared");er=true;}
				if($5<0){yyerror("Array can't be declared with size of less than 1");er=true;}
				add_variable_to_symbol_table($1->name,t);				
				codeNode *node = new codeNode;
                                node->code=$1->code;
                                node->code+= std::string(".[] ")+$1->name+std::string(", ")+std::to_string($5)+std::string("\n")+$10->code;
								$$ = node;
								}
		;
Declaration2:    {
			codeNode *node= new codeNode;node->code="";int i=0;
			//while(!paramCount.empty()){node->code+=std::string("= ")+paramCount.top()+std::string(", $")+std::to_string(i)+std::string("\n");i++;paramCount.pop();}
			$$=node;
			}
                |Ident COLON INTEGER SEMICOLON Declaration2 {
                                                                //printf("Start of Declaration->Ident\n");
                                                                Type t=Integer;
                                                                std::string var=$1->name;
								if(find(var)){yyerror("Variable already declared");er=true;}
                                                                add_variable_to_symbol_table(var,t);
                                                                //printf("%s\n",$1->name;
                                                                //printf("After adding to symbol table\n");
                                                                codeNode *node = new codeNode;
                                                                node->code=$1->code;
								paramCount.push($1->name);
                                                                node->code+= std::string(". ")+$1->name+std::string("\n")+$5->code;
								//paramCount.push($1->name);
                                                                $$=node;
                                                                }
                |Ident COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER SEMICOLON Declaration2{
                                //printf("Start of Declaration->Ident array\n");
                                Type t=Array;
				if(find($1->name)){yyerror("Variable already declared");er=true;}
				if($5<=0){yyerror("Array can't be declared with size of less than 1");er=true;}
                                add_variable_to_symbol_table($1->name,t);
                                codeNode *node = new codeNode;
                                node->code=$1->code;
                                node->code+= std::string(".[] ")+$1->name+std::string(", ")+std::to_string($5)+std::string("\n")+$10->code;
                                                                $$ = node;
                                                                }
                ;


Statement: 	Ident ASSIGN Expression SEMICOLON Statement1 {
			//printf("start of Statement->Ident Assign\n");
			std::string var_name = $1->name;
			idents_used.push_back(make_pair($1->name,numLines));
			std::string error;
			//if(!find(var_name)){
			//	yyerror("Can't assign to an undefined variable");
			//}
			codeNode *node = new codeNode;
			node->code = $3->code;
			node->code += std::string("= ") + var_name + std::string(", ") + $3->name + std::string("\n")+$5->code;
			$$ = node;
		}
                |Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET ASSIGN Expression SEMICOLON Statement1{
					//printf("Start of Statement->Ident array assign\n");
			                std::string array_name= $1->name;
					arrays_used.push_back(make_pair($1->name,numLines));
                    			codeNode *node = new codeNode;
					//if(!find(array_name)){
					//	yyerror("Can't access undefined reference to an array");
					//}
					node->code=$3->code + $6->code;
					node->code=std::string("[]= ")+ array_name+std::string(", ")+$3->name+std::string(", ")+$6->name+std::string("\n")+$8->code;
					$$=node;
                }
		|IF Bool-Exp THEN Statement ENDIF SEMICOLON Statement1 {}
		|IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statement1 {}
		|WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1 {}
		|DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1 {}
		|READ Ident SEMICOLON Statement1 {
							//printf("Start of Statement->Read Ident\n");
							std::string var_name = $2->name;
					                idents_used.push_back(make_pair($2->name,numLines));
							codeNode *node = new codeNode;
							//if(!find(var_name)){
							//	yyerror("Can't read from an undefined variable");
							//}
							node->code=std::string(".< ")+var_name+std::string("\n")+$4->code;
							$$=node;
						}
                |READ Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
													//printf("Start of Statement->Read array\n");
													std::string var_name = $2->name;
													arrays_used.push_back(make_pair($2->name,numLines));
													codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't read from an undefined array");
													//}
													node->code = $4->code;
													node->code+=std::string(".[]< ")+var_name+std::string(", ")+$4->name+std::string("\n")+$7->code;
													$$=node;
												}
		|WRITE Ident SEMICOLON Statement1 {
							//printf("Start of Statement->Write Ident\n");
                            std::string var_name = $2->name;
			    idents_used.push_back(make_pair($2->name,numLines));
                            codeNode *node = new codeNode;
							//if(!find(var_name)){
							//	yyerror("Can't write to an undefined variable");
							//}
                            node->code=std::string(".> ")+var_name+std::string("\n")+$4->code;
                            $$=node;
                            }
                |WRITE Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
						//printf("Start of Statement->Write array\n");
                                                    std::string var_name = $2->name;
						    arrays_used.push_back(make_pair($2->name,numLines));
                                                    codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't write to an undefined array");
													//}
													node->code = $4->code;
                                                    node->code+=std::string(".[]> ")+var_name+std::string(", ")+$4->name+std::string("\n")+$7->code;
                                                    $$=node;
												}
		|CONTINUE SEMICOLON Statement1 {}
		|BREAK SEMICOLON Statement1 {}
		|RETURN Expression SEMICOLON Statement1 {//return src 
			//printf("Start of Statement->Return\n");
			codeNode *node = new codeNode;
			node->code =$2->code+std::string("ret ")+$2->name+std::string("\n")+$4->code;
			$$ = node;
		}

Statement1:	{codeNode *node= new codeNode;$$=node;}
		|Ident ASSIGN Expression SEMICOLON Statement1 {
					//printf("Start of Statement1->Ident Assign\n");
					std::string var_name = $1->name;
					idents_used.push_back(make_pair($1->name,numLines));
					std::string error;
					//if(!find(var_name)){
					//	yyerror("Can't assign variable to undefined reference");
					//}
					codeNode *node = new codeNode;
					node->code = $3->code;
					node->code += std::string("= ") + var_name + std::string(", ") + $3->name + std::string("\n")+$5->code;
					$$ = node;
				}
		|Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET ASSIGN Expression SEMICOLON Statement1{
														//printf("Start of Statement1->Ident array assign\n");
														std::string array_name= $1->name;
														arrays_used.push_back(make_pair($1->name,numLines));
														codeNode *node = new codeNode;
														//if(!find(array_name)){
														//	yyerror("Undefined reference to an array");
														//}
														node->code=$3->code + $6->code;
														node->code+=std::string("[]= ")+ array_name+std::string(", ")+$3->name+std::string(", ")+$6->name+std::string("\n")+$8->code;
														$$=node;
														}
                |IF Bool-Exp THEN Statement ENDIF SEMICOLON Statement1 {}
                |IF Bool-Exp THEN Statement ELSE Statement ENDIF SEMICOLON Statement1 {}
                |WHILE Bool-Exp BEGINLOOP Statement ENDLOOP SEMICOLON Statement1 {}
                |DO BEGINLOOP Statement ENDLOOP WHILE Bool-Exp SEMICOLON Statement1 {}
		|READ Ident SEMICOLON Statement1 {
				//printf("Start of Statement1->Read Ident\n");
                            std::string var_name = $2->name;
			    idents_used.push_back(make_pair($2->name, numLines));
                            codeNode *node = new codeNode;
							//if(!find(var_name)){
							//		yyerror("Can't read from undefined reference");
							//}
                            node->code=std::string(".< ")+$2->name+std::string("\n")+$4->code;
                            $$=node;
                        }
                |READ Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
						//printf("Start of Statement1->Read array\n");
                                                    std::string var_name = $2->name;
							arrays_used.push_back(make_pair($2->name,numLines));
                                                	codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't Read from undefined reference");
													//}
                                                    node->code=$4->code+std::string(".[]< ")+$2->name+std::string(", ")+$4->name+std::string("\n")+$7->code;
                                                    $$=node;
                                                    }
                |WRITE Ident SEMICOLON Statement1 {
			//printf("Start of Statement1->Write Ident\n");
                            std::string var_name = $2->name;
			    idents_used.push_back(make_pair($2->name, numLines));
                            codeNode *node = new codeNode;
							//if(!find($2->name)){
							//	yyerror("Can't write to undefined reference to an array");
							//}
                            node->code=std::string(".> ")+$2->name+std::string("\n")+$4->code;
                            $$=node;
                            }
                |WRITE Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET SEMICOLON Statement1 {
						//printf("Start of Statement1->WRITE array\n");
                                                    std::string var_name = $2->name;
						    arrays_used.push_back(make_pair($2->name,numLines));
                                                    codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't write from undefined reference to an array");
													//}
                                                    node->code=$4->code+std::string(".[]> ")+$2->name+std::string(", ")+$4->name+std::string("\n")+$7->code;
                                                    $$=node;
                                                    }
                |CONTINUE SEMICOLON Statement1 {}
                |BREAK SEMICOLON Statement1 {}
                |RETURN Expression SEMICOLON Statement1 {//return src
			//printf("Start of Statment1->Return Expression Semicolon Statement1\n");
                        codeNode *node = new codeNode;
                        node->code = $2->code+std::string("ret ")+$2->name+std::string("\n")+$4->code;;
                        $$ = node;
			}

Bool-Exp:	NotLoop Expression Comp Expression {}	

NotLoop:	{}
		|NOT NotLoop{}

Comp:		EQ{}
		|NEQ{}
		|GT{}
		|LT{}
		|GTE{}
		|LTE{}

Expression:	Multiplicative-Expr{$$=$1;}//not sure if this is correct but I think it is needed}
		|Multiplicative-Expr PLUS Multiplicative-Expr{
			//printf("Start of Expression -> Multi PLUS Multi\n");
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $1->code + $3->code+std::string(". ")+temp+std::string("\n");
			node->code += std::string("+ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
			node->name = temp;
			$$ = node;
		}
		|Multiplicative-Expr MINUS Multiplicative-Expr{
			//printf("Start of Expression -> Multi MINUS Multi\n");
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $1->code + $3->code+std::string(". ")+temp+std::string("\n");
			node->code += std::string("- ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
			node->name = temp;
			$$ = node;
		}

Multiplicative-Expr: 	Term {
				//printf("Start of Multi->Term\n");
				codeNode *node= new codeNode;
				node->code=$1->code;
				node->name=$1->name;
				$$=node;}
			|Term MULT Term {
				//printf("Start of Multi->Term MULT Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("* ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}
			|Term DIV Term {
				//printf("Start of Multi->Term Div Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("/ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}
			|Term MOD Term {
				//printf("Start of Multi->Term MOD Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = $1->code + $3->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("% ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
				node->name = temp;
				$$ = node;
			}

Term:		Var{//return temp register
				//printf("start of Term->Var\n");
				//std::string temp = create_temp();
				codeNode *node = new codeNode;
				//if(!find($1->name)){
				//	yyerror("Undefined reference to a variable");
				//}
				node->code = $1->code;
				//node->code += std::string(". ") + $1->name + std::string("\n");
				node->name = $1->name;
				$$ = node;
			}
		|NUMBER{//return number;
			//printf("start of Term->Number\n");
			codeNode *node = new codeNode;
			node->name = std::to_string($1);//using immediate value so i think i can just stop after this
			$$ = node;
			}
		|L_PAREN Expression R_PAREN{//return expression
			//printf("start of Term->L_Paren Expression R_paren\n");
			//std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = $2 -> code;// don't need to do the node->code+= stuff as substuff of expression takes care of that
			node->name = $2->name;
			$$ = node;
						}
		|Ident L_PAREN Expression2 R_PAREN{//function call
			//printf("start of Term->Ident L_Paren Expression R_paren\n");i
			std::string temp= create_temp();
			std::string func_name = $1->name;
			functionscalled.push_back(make_pair($1->name,numLines));
			codeNode *node = new codeNode;
			node->code=std::string(". ")+temp+std::string("\n");
			//if(!find(func_name)){
			//	yyerror("Undefined reference to a function that doesn't exist");
			//}
			node->code+=$3->code+std::string("call ") + func_name+std::string(", ")+ temp+ std::string("\n");//need to check this one
			node->name=temp;
			$$ = node;// I have no clue wat im doing for this one, also i think we missing a grammar rule bc table says call name, dest changed so that the dest is the temp name that it is returned to
		}


Expression2: 	{codeNode *node= new codeNode;$$=node;}
		|Expression{
				codeNode *node=new codeNode;
				//printf("start of expression2->expression\n");
				node->code=$1->code+std::string("param ")+$1->name+std::string("\n");
				//printf("end of expression2->expression\n");
				$$=node;
}
		|Expression COMMA Expression2{
						codeNode *node = new codeNode;
						//printf("start of expression2->expression comma expression2\n");
						node->code=$1->code+std::string("param ")+$1->name+std::string("\n")+$3->code;
						//printf("end of expression2->expression comma expression2\n");
						$$=node;
						}


Var:
    		Ident{
				codeNode *node = new codeNode;
				node->code = "";
				//printf("start of Var->Ident\n");
				node->name = $1->name;
				idents_used.push_back(make_pair($1->name, numLines));
				//if(!find(node->name)){
				//	yyerror("Undefined reference to an identifier");
				//}//printf("end of Var->Ident\n");
				$$ = node;
				
			}
    		| Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {//array access statement store temp to return temp register
				//printf("Start of Var->Ident array\n");
				std::string var_name = create_temp();
				arrays_used.push_back(make_pair($1->name, numLines));
               			codeNode *node = new codeNode;
					//if(!find($1->name)){
					//	yyerror("Undefined reference to a nonexistent identifier");
					//}
		            node->code=$3->code+std::string(". ")+var_name+std::string("\n")+std::string("=[] ")+var_name+std::string(", ")+$1->name+std::string(", ")+$3->name+std::string("\n");
                	node->name=var_name;//was temp but that wasn't declared so not sure what to do just changed to var_name
					//printf("end of var->Ident square brackets\n");
		            $$=node;//Just copied pasted with some slight adjustments from thomas implementation
			}
    		;

Ident:/*We need to check this for sure*/
        IDENT{
			//printf("Start of Ident->IDENT\n");
			codeNode *node = new codeNode;
			//printf("start of Ident->IDENT\n");
			node->code = "";
			node->name = $1;
			//for(int i = 0; i < reservedWords.size(); ++i){
				//if(node -> name == reservedWords[i])
				//	yyerror("Using a reserved keyword");
			//}
			//printf("after strdup\n");
			//if(!find(node->name)){
			//	yyerror("Undefined reference to identifier");
			//}
			//printf("End of Ident->IDENT\n");
			//$$.code="";
			//$$.name=$1;
			$$=node;
		}
%% 

int main(int argc, char **argv) {
   //printf("In main\n");
   yyparse();
   return 0;
}
