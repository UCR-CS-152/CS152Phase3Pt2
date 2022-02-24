/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "miniL.y" /* yacc.c:339  */

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
int labelCnt=-1;
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
std::string create_label(){
	labelCnt++;
	return ("_label"+std::to_string(labelCnt));
	}

#line 186 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENT = 259,
    FUNCTION = 260,
    BEGIN_PARAMS = 261,
    END_PARAMS = 262,
    BEGIN_LOCALS = 263,
    END_LOCALS = 264,
    BEGIN_BODY = 265,
    END_BODY = 266,
    INTEGER = 267,
    ARRAY = 268,
    OF = 269,
    IF = 270,
    THEN = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    BREAK = 279,
    READ = 280,
    WRITE = 281,
    NOT = 282,
    TRUE = 283,
    FALSE = 284,
    RETURN = 285,
    PLUS = 286,
    MINUS = 287,
    MULT = 288,
    DIV = 289,
    MOD = 290,
    SEMICOLON = 291,
    COLON = 292,
    COMMA = 293,
    L_PAREN = 294,
    R_PAREN = 295,
    L_SQUARE_BRACKET = 296,
    R_SQUARE_BRACKET = 297,
    ASSIGN = 298,
    EQ = 299,
    NEQ = 300,
    LT = 301,
    GT = 302,
    LTE = 303,
    GTE = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 121 "miniL.y" /* yacc.c:355  */

  int		int_val;
  char*	op_val;
  struct codeNode *node;

#line 282 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 299 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   332

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   195,   195,   197,   215,   225,   226,   225,   265,   266,
     279,   279,   289,   289,   293,   298,   313,   313,   323,   323,
     329,   342,   354,   362,   372,   397,   422,   433,   445,   456,
     468,   474,   481,   488,   489,   502,   514,   522,   532,   557,
     582,   593,   604,   615,   626,   632,   638,   645,   659,   660,
     667,   673,   679,   685,   691,   697,   704,   705,   714,   724,
     730,   739,   748,   758,   770,   776,   784,   800,   801,   808,
     818,   830,   846
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "BREAK", "READ",
  "WRITE", "NOT", "TRUE", "FALSE", "RETURN", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN", "EQ", "NEQ", "LT",
  "GT", "LTE", "GTE", "$accept", "Start", "Program", "FUNCTIONS", "$@1",
  "$@2", "Declaration", "$@3", "$@4", "Declaration2", "$@5", "$@6",
  "Statement", "Statement1", "Bool-Exp", "NotLoop", "Comp", "Expression",
  "Multiplicative-Expr", "Term", "Expression2", "Var", "Ident", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,     7,    32,   -46,    24,   -46,   -46,   -46,   -46,    14,
      37,     7,   -46,    42,    62,     2,    80,    55,    67,     7,
       7,     5,    94,    68,   -46,   -46,   107,   101,    45,    70,
     -46,     1,    82,    75,   105,    79,    96,    96,   103,    89,
      93,     7,     7,     0,   120,    -8,     7,     6,   128,   127,
      96,   129,     0,   121,     1,   113,   113,   -29,   -19,   -46,
       0,   108,    46,    21,   -46,    34,   -46,     0,     0,   -46,
     -46,   -46,   110,   136,   -46,     1,    16,     1,   130,    96,
      96,   134,   114,   115,     7,     7,     0,   -46,     3,   -46,
     113,     0,   113,     0,   117,   113,     0,     0,     0,     0,
       0,     0,     0,   116,   132,   122,   159,     7,   138,    64,
     -46,   -46,   -46,   -46,   -46,   -46,     0,   141,   146,   160,
     156,     1,   113,   113,   -13,    11,   143,     0,     0,   -46,
     139,   -46,   140,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     142,   144,   145,   148,   113,   169,   147,   -46,     7,   149,
       1,   -46,   161,    96,     1,     1,   170,   -46,   -46,   113,
       0,   113,     0,   113,   153,   162,   163,   168,     0,   -46,
     -46,     0,   -46,   184,   193,   -46,   113,   191,   113,   173,
      69,   192,   194,   -46,   174,   -46,   176,   -46,   172,   113,
     113,   113,   -46,   185,   188,   208,   -46,   190,   -46,   113,
     197,     1,   198,    96,   199,   200,     0,   -46,   -46,   -46,
     113,     7,   201,   113,   -46,   113,   213,   113,   202,   113,
     113,   203,   -46,   -46,     7,   -46,   -46,   204,   -46,   113,
     -46,   -46,   113,   -46,   113,   -46,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,    72,     5,     1,     4,     0,
       0,    14,     6,     0,     0,     0,     0,     0,     0,     8,
      14,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    48,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     0,     0,
      48,     0,     0,     0,     0,    33,    33,     0,     0,    64,
       0,     0,    56,    59,    63,    70,     7,     0,     0,     9,
      10,    12,     0,     0,    49,     0,     0,     0,     0,    48,
      48,     0,     0,     0,     0,     0,     0,    30,     0,    31,
      33,     0,    33,     0,     0,    33,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,     0,    14,     0,     0,
      50,    51,    53,    52,    55,    54,     0,     0,     0,     0,
       0,     0,    33,    33,     0,     0,     0,     0,     0,    26,
       0,    28,     0,    65,    32,    57,    58,    60,    61,    62,
      68,     0,     0,     0,    33,     0,     0,    17,    14,     0,
       0,    47,     0,    48,     0,     0,     0,    44,    45,    33,
       0,    33,     0,    33,     0,     0,     0,     0,    67,    66,
      71,     0,    20,     0,     0,    19,    33,     0,    33,     0,
       0,     0,     0,    40,     0,    42,     0,    46,     0,    33,
      33,    33,    69,     0,     0,     0,    22,     0,    24,    33,
       0,     0,     0,    48,     0,     0,     0,    34,    27,    29,
      33,     8,     0,    33,    25,    33,     0,    33,     0,    33,
      33,     0,    21,    11,    14,    23,    36,     0,    38,    33,
      41,    43,    33,    13,    33,    39,    35,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   239,   -46,   -46,   -46,   -45,   -46,   -46,   -18,
     -46,   -46,   -41,    12,   -31,   195,   -46,   126,    -3,   -28,
      81,   -46,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    14,    22,   105,   106,    12,
      29,    35,    44,    87,    51,    52,   116,   140,    62,    63,
     141,    64,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    69,    24,    59,     5,     5,    53,    90,    25,    70,
      13,     5,    91,    78,    17,    18,    36,    92,    23,    13,
      37,    38,    93,   159,    39,    40,    41,    42,   160,     1,
      45,    43,     7,    67,   109,    68,   117,    26,    71,    60,
      57,    58,    65,    11,   127,    23,   128,   161,   119,   120,
      10,    65,   162,    45,    98,    99,   100,    32,    33,    65,
     110,   111,   112,   113,   114,   115,    65,    65,    89,    16,
     137,   138,   139,   101,    45,   102,    45,    96,    97,    15,
     156,   149,   150,   124,   125,    65,   200,   201,    19,   147,
      65,    20,    65,   135,   136,    65,    65,    65,    65,    65,
      65,    65,   129,    27,   131,    28,    13,   134,    21,   177,
      30,    31,    34,   180,   181,    65,    47,     5,    46,    48,
      45,    49,   179,    50,    54,    55,    65,    65,    79,    56,
     175,    66,    80,    81,   157,   158,    82,    83,    84,    85,
      72,    73,    77,    86,    95,    75,   107,    13,   108,    45,
     122,   123,   118,    45,    45,   121,   172,   133,   143,    65,
     216,    65,   146,   152,   145,   153,   223,    65,   144,    61,
      65,   183,   218,   185,   148,   187,   154,   155,    76,   163,
     168,   166,   167,   173,   169,   176,    94,   170,   196,   174,
     198,   171,   182,   103,   104,   188,   194,   178,   189,   190,
      45,   207,   208,   209,   191,    65,   233,   195,   197,   199,
      23,   214,   126,   203,   202,   206,   204,   130,   205,   132,
     212,   210,   222,    13,   211,   225,   213,   226,   142,   228,
     227,   230,   231,   215,   217,   219,   220,   224,   229,   232,
     234,   235,   151,     8,   236,    74,   237,     0,     0,   192,
       0,     0,     0,   164,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,     0,   186,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221
};

static const yytype_int16 yycheck[] =
{
       1,    46,    20,     3,     4,     4,    37,    36,     3,     3,
      11,     4,    41,    54,    12,    13,    15,    36,    19,    20,
      19,    20,    41,    36,    23,    24,    25,    26,    41,     5,
      31,    30,     0,    41,    75,    43,    77,    32,    32,    39,
      41,    42,    43,     6,    41,    46,    43,    36,    79,    80,
      36,    52,    41,    54,    33,    34,    35,    12,    13,    60,
      44,    45,    46,    47,    48,    49,    67,    68,    56,     7,
      98,    99,   100,    39,    75,    41,    77,    31,    32,    37,
     121,    17,    18,    84,    85,    86,    17,    18,     8,   107,
      91,    36,    93,    96,    97,    96,    97,    98,    99,   100,
     101,   102,    90,     9,    92,    37,   107,    95,    41,   150,
       3,    10,    42,   154,   155,   116,    41,     4,    36,    14,
     121,    42,   153,    27,    21,    36,   127,   128,    15,    36,
     148,    11,    19,    20,   122,   123,    23,    24,    25,    26,
      12,    14,    21,    30,    36,    16,    36,   148,    12,   150,
      36,    36,    22,   154,   155,    21,   144,    40,    42,   160,
     201,   162,     3,    22,    42,    19,   211,   168,    36,    43,
     171,   159,   203,   161,    36,   163,    16,    21,    52,    36,
      38,    42,    42,    14,    40,    36,    60,    42,   176,    42,
     178,    43,    22,    67,    68,    42,    12,    36,    36,    36,
     201,   189,   190,   191,    36,   206,   224,    14,    17,    36,
     211,   199,    86,    19,    22,    43,    42,    91,    42,    93,
      12,    36,   210,   224,    36,   213,    36,   215,   102,   217,
      17,   219,   220,    36,    36,    36,    36,    36,    36,    36,
      36,   229,   116,     4,   232,    50,   234,    -1,    -1,   168,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    51,    52,    53,     4,    72,     0,    52,    54,
      36,     6,    59,    72,    55,    37,     7,    12,    13,     8,
      36,    41,    56,    72,    59,     3,    32,     9,    37,    60,
       3,    10,    12,    13,    42,    61,    15,    19,    20,    23,
      24,    25,    26,    30,    62,    72,    36,    41,    14,    42,
      27,    64,    65,    64,    21,    36,    36,    72,    72,     3,
      39,    67,    68,    69,    71,    72,    11,    41,    43,    56,
       3,    32,    12,    14,    65,    16,    67,    21,    62,    15,
      19,    20,    23,    24,    25,    26,    30,    63,    72,    63,
      36,    41,    36,    41,    67,    36,    31,    32,    33,    34,
      35,    39,    41,    67,    67,    57,    58,    36,    12,    62,
      44,    45,    46,    47,    48,    49,    66,    62,    22,    64,
      64,    21,    36,    36,    72,    72,    67,    41,    43,    63,
      67,    63,    67,    40,    63,    68,    68,    69,    69,    69,
      67,    70,    67,    42,    36,    42,     3,    59,    36,    17,
      18,    67,    22,    19,    16,    21,    62,    63,    63,    36,
      41,    36,    41,    36,    67,    67,    42,    42,    38,    40,
      42,    43,    63,    14,    42,    59,    36,    62,    36,    64,
      62,    62,    22,    63,    67,    63,    67,    63,    42,    36,
      36,    36,    70,    67,    12,    14,    63,    17,    63,    36,
      17,    18,    22,    19,    42,    42,    43,    63,    63,    63,
      36,    36,    12,    36,    63,    36,    62,    36,    64,    36,
      36,    67,    63,    56,    36,    63,    63,    17,    63,    36,
      63,    63,    36,    59,    36,    63,    63,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    54,    55,    53,    56,    56,
      57,    56,    58,    56,    59,    59,    60,    59,    61,    59,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    14,     0,     5,
       0,    11,     0,    12,     0,     5,     0,    11,     0,    12,
       5,     8,     7,     9,     7,     8,     4,     7,     4,     7,
       3,     3,     4,     0,     5,     8,     7,     9,     7,     8,
       4,     7,     4,     7,     3,     3,     4,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     3,     4,     0,     1,     3,
       1,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 195 "miniL.y" /* yacc.c:1646  */
    {if(er!=true)std::cout<<(yyvsp[0].node)->code;}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 197 "miniL.y" /* yacc.c:1646  */
    {
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
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 215 "miniL.y" /* yacc.c:1646  */
    { 
		//printf("Start of Program->Functions Program\n");
		//idk bout this one
		codeNode *node= new codeNode;
		node->code=(yyvsp[-1].node)->code+(yyvsp[0].node)->code;
		//if(functions.find("main") == functions.end())
		//	yyerror("No main function defined");
		//printf("Functions Program\n");
		(yyval.node)=node;
	 }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 225 "miniL.y" /* yacc.c:1646  */
    {add_function_to_symbol_table((yyvsp[0].node)->name);}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 226 "miniL.y" /* yacc.c:1646  */
    {
				Function *f=get_function();
				assignments="";
				//for(int i=0; i<f->declarations.size();i++){
				//		assignments+=std::string("= ")+f->declarations[i].name+std::string(", $")+std::to_string(i)+std::string("\n");
				//	}
				}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 233 "miniL.y" /* yacc.c:1646  */
    {
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
	node->code = (yyvsp[-12].node)->code;
	node->code += std::string("func ") + (yyvsp[-12].node)->name + std::string("\n")+(yyvsp[-8].node)->code+par->code+(yyvsp[-4].node)->code+(yyvsp[-1].node)->code+std::string("endfunc\n");
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
	(yyval.node) = node;
}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 265 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 266 "miniL.y" /* yacc.c:1646  */
    {
								//printf("Start of Declaration->Ident\n");
								Type t=Integer;
								std::string var=(yyvsp[-4].node)->name;
								if(find(var)){yyerror("Variable has already declared");er=true;}
								add_variable_to_symbol_table(var,t);
								//printf("%s\n",$1->name;
								//printf("After adding to symbol table\n");
								codeNode *node = new codeNode;
								node->code=(yyvsp[-4].node)->code;
								node->code+= std::string(". ")+(yyvsp[-4].node)->name+std::string("\n")+(yyvsp[0].node)->code;
								(yyval.node)=node;
								}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 279 "miniL.y" /* yacc.c:1646  */
    {if((yyvsp[0].int_val)<=0){yyerror("Array can't be declared with size of less than 1");er=true;}}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 279 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Declaration->Ident array\n");
				Type t=Array;
				if(find((yyvsp[-10].node)->name)){yyerror("Array has already declared");er=true;}
				add_variable_to_symbol_table((yyvsp[-10].node)->name,t);				
				codeNode *node = new codeNode;
                                node->code=(yyvsp[-10].node)->code;
                                node->code+= std::string(".[] ")+(yyvsp[-10].node)->name+std::string(", ")+std::to_string((yyvsp[-6].int_val))+std::string("\n")+(yyvsp[0].node)->code;
								(yyval.node) = node;
								}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 289 "miniL.y" /* yacc.c:1646  */
    {yyerror("Array can't be declared with size of less than 1");er=true;}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 289 "miniL.y" /* yacc.c:1646  */
    {
					add_variable_to_symbol_table((yyvsp[-11].node)->name,Array);		
				}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 293 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node= new codeNode;node->code="";int i=0;
			//while(!paramCount.empty()){node->code+=std::string("= ")+paramCount.top()+std::string(", $")+std::to_string(i)+std::string("\n");i++;paramCount.pop();}
			(yyval.node)=node;
			}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 298 "miniL.y" /* yacc.c:1646  */
    {
                                                                //printf("Start of Declaration->Ident\n");
                                                                Type t=Integer;
                                                                std::string var=(yyvsp[-4].node)->name;
								if(find(var)){yyerror("Variable already declared");er=true;}
                                                                add_variable_to_symbol_table(var,t);
                                                                //printf("%s\n",$1->name;
                                                                //printf("After adding to symbol table\n");
                                                                codeNode *node = new codeNode;
                                                                node->code=(yyvsp[-4].node)->code;
								paramCount.push((yyvsp[-4].node)->name);
                                                                node->code+= std::string(". ")+(yyvsp[-4].node)->name+std::string("\n")+(yyvsp[0].node)->code;
								//paramCount.push($1->name);
                                                                (yyval.node)=node;
                                                                }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 313 "miniL.y" /* yacc.c:1646  */
    {if(find((yyvsp[-4].node)->name)){yyerror("Variable already declared");er=true;}}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 313 "miniL.y" /* yacc.c:1646  */
    {
                                //printf("Start of Declaration->Ident array\n");
                                Type t=Array;
								if((yyvsp[-6].int_val)<=0){yyerror("Array can't be declared with size of less than 1");er=true;}
												add_variable_to_symbol_table((yyvsp[-10].node)->name,t);
												codeNode *node = new codeNode;
												node->code=(yyvsp[-10].node)->code;
                                node->code+= std::string(".[] ")+(yyvsp[-10].node)->name+std::string(", ")+std::to_string((yyvsp[-6].int_val))+std::string("\n")+(yyvsp[0].node)->code;
                                                                (yyval.node) = node;
                                                                }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 323 "miniL.y" /* yacc.c:1646  */
    {yyerror("Array can't be declared with size of less than 1");er=true;}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 323 "miniL.y" /* yacc.c:1646  */
    {
					add_variable_to_symbol_table((yyvsp[-11].node)->name,Array);	
				}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 329 "miniL.y" /* yacc.c:1646  */
    {
			//printf("start of Statement->Ident Assign\n");
			std::string var_name = (yyvsp[-4].node)->name;
			idents_used.push_back(make_pair((yyvsp[-4].node)->name,numLines));
			std::string error;
			//if(!find(var_name)){
			//	yyerror("Can't assign to an undefined variable");
			//}
			codeNode *node = new codeNode;
			node->code = (yyvsp[-2].node)->code;
			node->code += std::string("= ") + var_name + std::string(", ") + (yyvsp[-2].node)->name + std::string("\n")+(yyvsp[0].node)->code;
			(yyval.node) = node;
		}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 342 "miniL.y" /* yacc.c:1646  */
    {
					//printf("Start of Statement->Ident array assign\n");
			                std::string array_name= (yyvsp[-7].node)->name;
					arrays_used.push_back(make_pair((yyvsp[-7].node)->name,numLines));
                    			codeNode *node = new codeNode;
					//if(!find(array_name)){
					//	yyerror("Can't access undefined reference to an array");
					//}
					node->code=(yyvsp[-5].node)->code + (yyvsp[-2].node)->code;
					node->code=std::string("[]= ")+ array_name+std::string(", ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
					(yyval.node)=node;
                }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 354 "miniL.y" /* yacc.c:1646  */
    {
									codeNode *node = new codeNode;
									node->code=(yyvsp[-5].node)->code;
									std::string label1=create_label();
									node->code+=std::string("! ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n");
									node->code+=std::string("?:= ")+label1+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n")+(yyvsp[-3].node)->code+std::string(": ")+label1+std::string("\n")+(yyvsp[0].node)->code;
									(yyval.node)=node;
									}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 362 "miniL.y" /* yacc.c:1646  */
    {
                                                                        codeNode *node = new codeNode;
                                                                        node->code=(yyvsp[-7].node)->code;
                                                                        std::string label1=create_label();
									std::string label2=create_label();
                                                                        node->code+=std::string("! ")+(yyvsp[-7].node)->name+std::string(", ")+(yyvsp[-7].node)->name+std::string("\n");
                                                                        node->code+=std::string("?:= ")+label1+std::string(", ")+(yyvsp[-7].node)->name+std::string("\n")+(yyvsp[-5].node)->code+std::string(":= ")+label2+std::string("\n")+std::string(": ")+label1+std::string("\n")+(yyvsp[-3].node)->code;
									node->code+=std::string(": ")+label2+std::string("\n")+(yyvsp[0].node)->code;
                                                                        (yyval.node)=node;
									}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 372 "miniL.y" /* yacc.c:1646  */
    {
											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											node->code=(yyvsp[-5].node)->code;
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-3].node)->code.find(br);
											while(found!=std::string::npos){
													std::string replace=std::string(":= ")+label2;
													(yyvsp[-3].node)->code.replace(found,br.length(),replace);
													found = (yyvsp[-3].node)->code.find(br);
												}
											found = (yyvsp[-3].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label1;
                                                                                                        (yyvsp[-3].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-3].node)->code.find(con);
                                                                                                }
											node->code+=std::string("! ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n");
											node->code+=std::string(": ")+label1+std::string("\n")+std::string("?:= ")+label2+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n")+(yyvsp[-3].node)->code+(yyvsp[-5].node)->code;
											node->code+=std::string("! ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n");
											node->code+=std::string(":= ")+label1+std::string("\n")+std::string(": ")+label2+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
											}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 397 "miniL.y" /* yacc.c:1646  */
    {
											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											std::string label3=create_label();
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-5].node)->code.find(br);
											//node->code=$6->code;
											while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label3;
                                                                                                        (yyvsp[-5].node)->code.replace(found,br.length(),replace);
                                                                                                        found = (yyvsp[-5].node)->code.find(br);
                                                                                                }
                                                                                        found = (yyvsp[-5].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label2;
                                                                                                        (yyvsp[-5].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-5].node)->code.find(con);
                                                                                                }
											node->code=std::string(": ")+label1+std::string("\n")+(yyvsp[-5].node)->code+(yyvsp[-2].node)->code;
											node->code+=std::string(": ")+label2+std::string("\n")+std::string("?:= ")+label1+std::string(", ")+(yyvsp[-2].node)->name+std::string("\n");
											node->code+=std::string(": ")+label3+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
											}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 422 "miniL.y" /* yacc.c:1646  */
    {
							//printf("Start of Statement->Read Ident\n");
							std::string var_name = (yyvsp[-2].node)->name;
					                idents_used.push_back(make_pair((yyvsp[-2].node)->name,numLines));
							codeNode *node = new codeNode;
							//if(!find(var_name)){
							//	yyerror("Can't read from an undefined variable");
							//}
							node->code=std::string(".< ")+var_name+std::string("\n")+(yyvsp[0].node)->code;
							(yyval.node)=node;
						}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 433 "miniL.y" /* yacc.c:1646  */
    {
													//printf("Start of Statement->Read array\n");
													std::string var_name = (yyvsp[-5].node)->name;
													arrays_used.push_back(make_pair((yyvsp[-5].node)->name,numLines));
													codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't read from an undefined array");
													//}
													node->code = (yyvsp[-3].node)->code;
													node->code+=std::string(".[]< ")+var_name+std::string(", ")+(yyvsp[-3].node)->name+std::string("\n")+(yyvsp[0].node)->code;
													(yyval.node)=node;
												}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 445 "miniL.y" /* yacc.c:1646  */
    {
							//printf("Start of Statement->Write Ident\n");
                            std::string var_name = (yyvsp[-2].node)->name;
			    idents_used.push_back(make_pair((yyvsp[-2].node)->name,numLines));
                            codeNode *node = new codeNode;
							//if(!find(var_name)){
							//	yyerror("Can't write to an undefined variable");
							//}
                            node->code=std::string(".> ")+var_name+std::string("\n")+(yyvsp[0].node)->code;
                            (yyval.node)=node;
                            }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 456 "miniL.y" /* yacc.c:1646  */
    {
						//printf("Start of Statement->Write array\n");
                                                    std::string var_name = (yyvsp[-5].node)->name;
						    arrays_used.push_back(make_pair((yyvsp[-5].node)->name,numLines));
                                                    codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't write to an undefined array");
													//}
													node->code = (yyvsp[-3].node)->code;
                                                    node->code+=std::string(".[]> ")+var_name+std::string(", ")+(yyvsp[-3].node)->name+std::string("\n")+(yyvsp[0].node)->code;
                                                    (yyval.node)=node;
												}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 468 "miniL.y" /* yacc.c:1646  */
    {
                                                codeNode *node = new codeNode;
                                                node->code = std::string("Continue \n");
                                                node->name = std::string ("Continue");
                                                (yyval.node)=node;
                                                }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 474 "miniL.y" /* yacc.c:1646  */
    {//maybe return break as a name then do where to go in level above
                                                codeNode *node = new codeNode;
                                                node->code = std::string("Break \n");
                                                node->name = std::string ("Break");
                                                (yyval.node)=node;
                                                }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 481 "miniL.y" /* yacc.c:1646  */
    {//return src 
			//printf("Start of Statement->Return\n");
			codeNode *node = new codeNode;
			node->code =(yyvsp[-2].node)->code+std::string("ret ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
			(yyval.node) = node;
		}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 488 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 489 "miniL.y" /* yacc.c:1646  */
    {
					//printf("Start of Statement1->Ident Assign\n");
					std::string var_name = (yyvsp[-4].node)->name;
					idents_used.push_back(make_pair((yyvsp[-4].node)->name,numLines));
					std::string error;
					//if(!find(var_name)){
					//	yyerror("Can't assign variable to undefined reference");
					//}
					codeNode *node = new codeNode;
					node->code = (yyvsp[-2].node)->code;
					node->code += std::string("= ") + var_name + std::string(", ") + (yyvsp[-2].node)->name + std::string("\n")+(yyvsp[0].node)->code;
					(yyval.node) = node;
				}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 502 "miniL.y" /* yacc.c:1646  */
    {
														//printf("Start of Statement1->Ident array assign\n");
														std::string array_name= (yyvsp[-7].node)->name;
														arrays_used.push_back(make_pair((yyvsp[-7].node)->name,numLines));
														codeNode *node = new codeNode;
														//if(!find(array_name)){
														//	yyerror("Undefined reference to an array");
														//}
														node->code=(yyvsp[-5].node)->code + (yyvsp[-2].node)->code;
														node->code+=std::string("[]= ")+ array_name+std::string(", ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
														(yyval.node)=node;
														}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 514 "miniL.y" /* yacc.c:1646  */
    {
                                                                        codeNode *node = new codeNode;
                                                                        node->code=(yyvsp[-5].node)->code;
                                                                        std::string label1=create_label();
                                                                        node->code+=std::string("! ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n");
                                                                        node->code+=std::string("?:= ")+label1+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n")+(yyvsp[-3].node)->code+std::string(": ")+label1+std::string("\n")+(yyvsp[0].node)->code;
                                                                        (yyval.node)=node;
                                                                        }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 522 "miniL.y" /* yacc.c:1646  */
    {
                                                                        codeNode *node = new codeNode;
                                                                        node->code=(yyvsp[-7].node)->code;
                                                                        std::string label1=create_label();
                                                                        std::string label2=create_label();
                                                                        node->code+=std::string("! ")+(yyvsp[-7].node)->name+std::string(", ")+(yyvsp[-7].node)->name+std::string("\n");
                                                                        node->code+=std::string("?:= ")+label1+std::string(", ")+(yyvsp[-7].node)->name+std::string("\n")+(yyvsp[-5].node)->code+std::string(":= ")+label2+std::string("\n")+std::string(": ")+label1+std::string("\n")+(yyvsp[-3].node)->code;
                                                                        node->code+=std::string(": ")+label2+std::string("\n")+(yyvsp[0].node)->code;
                                                                        (yyval.node)=node;
                                                                        }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 532 "miniL.y" /* yacc.c:1646  */
    {
											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											node->code=(yyvsp[-5].node)->code;
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-3].node)->code.find(br);
											while(found!=std::string::npos){
													std::string replace=std::string(":= ")+label2;
													(yyvsp[-3].node)->code.replace(found,br.length(),replace);
													found = (yyvsp[-3].node)->code.find(br);
												}
											found = (yyvsp[-3].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label1;
                                                                                                        (yyvsp[-3].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-3].node)->code.find(con);
                                                                                                }
											node->code+=std::string("! ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n");
											node->code+=std::string(": ")+label1+std::string("\n")+std::string("?:= ")+label2+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n")+(yyvsp[-3].node)->code+(yyvsp[-5].node)->code;
											node->code+=std::string("! ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n");
											node->code+=std::string(":= ")+label1+std::string("\n")+std::string(": ")+label2+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
                                                                                        }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 557 "miniL.y" /* yacc.c:1646  */
    {
											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											std::string label3=create_label();
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-5].node)->code.find(br);
											//node->code=$6->code;
											while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label3;
                                                                                                        (yyvsp[-5].node)->code.replace(found,br.length(),replace);
                                                                                                        found = (yyvsp[-5].node)->code.find(br);
                                                                                                }
                                                                                        found = (yyvsp[-5].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label2;
                                                                                                        (yyvsp[-5].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-5].node)->code.find(con);
                                                                                                }
											node->code=std::string(": ")+label1+std::string("\n")+(yyvsp[-5].node)->code+(yyvsp[-2].node)->code;
											node->code+=std::string(": ")+label2+std::string("\n")+std::string("?:= ")+label1+std::string(", ")+(yyvsp[-2].node)->name+std::string("\n");
											node->code+=std::string(": ")+label3+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
                                                                                        }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 582 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Statement1->Read Ident\n");
                            std::string var_name = (yyvsp[-2].node)->name;
			    idents_used.push_back(make_pair((yyvsp[-2].node)->name, numLines));
                            codeNode *node = new codeNode;
							//if(!find(var_name)){
							//		yyerror("Can't read from undefined reference");
							//}
                            node->code=std::string(".< ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
                            (yyval.node)=node;
                        }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 593 "miniL.y" /* yacc.c:1646  */
    {
						//printf("Start of Statement1->Read array\n");
                                                    std::string var_name = (yyvsp[-5].node)->name;
							arrays_used.push_back(make_pair((yyvsp[-5].node)->name,numLines));
                                                	codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't Read from undefined reference");
													//}
                                                    node->code=(yyvsp[-3].node)->code+std::string(".[]< ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-3].node)->name+std::string("\n")+(yyvsp[0].node)->code;
                                                    (yyval.node)=node;
                                                    }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 604 "miniL.y" /* yacc.c:1646  */
    {
			//printf("Start of Statement1->Write Ident\n");
                            std::string var_name = (yyvsp[-2].node)->name;
			    idents_used.push_back(make_pair((yyvsp[-2].node)->name, numLines));
                            codeNode *node = new codeNode;
							//if(!find($2->name)){
							//	yyerror("Can't write to undefined reference to an array");
							//}
                            node->code=std::string(".> ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
                            (yyval.node)=node;
                            }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 615 "miniL.y" /* yacc.c:1646  */
    {
						//printf("Start of Statement1->WRITE array\n");
                                                    std::string var_name = (yyvsp[-5].node)->name;
						    arrays_used.push_back(make_pair((yyvsp[-5].node)->name,numLines));
                                                    codeNode *node = new codeNode;
													//if(!find(var_name)){
													//	yyerror("Can't write from undefined reference to an array");
													//}
                                                    node->code=(yyvsp[-3].node)->code+std::string(".[]> ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-3].node)->name+std::string("\n")+(yyvsp[0].node)->code;
                                                    (yyval.node)=node;
                                                    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 626 "miniL.y" /* yacc.c:1646  */
    {
						codeNode *node = new codeNode;
						node->code = std::string("Continue \n");
						node->name = std::string ("Continue");
						(yyval.node)=node;
						}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 632 "miniL.y" /* yacc.c:1646  */
    {//maybe return break as a name then do where to go in level above
						codeNode *node = new codeNode;
                                                node->code = std::string("Break \n");
                                                node->name = std::string ("Break");
                                                (yyval.node)=node;
						}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 638 "miniL.y" /* yacc.c:1646  */
    {//return src
			//printf("Start of Statment1->Return Expression Semicolon Statement1\n");
                        codeNode *node = new codeNode;
                        node->code = (yyvsp[-2].node)->code+std::string("ret ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;;
                        (yyval.node) = node;
			}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 645 "miniL.y" /* yacc.c:1646  */
    {
							codeNode *node = new codeNode;
							std::string temp=create_temp();
							node->code=(yyvsp[-2].node)->code+(yyvsp[0].node)->code;
							node->code+=std::string(". ")+temp+std::string("\n");
							node->code+=(yyvsp[-1].node)->name+std::string(" ")+temp+std::string(", ")+(yyvsp[-2].node)->name+std::string(", ")+(yyvsp[0].node)->name+std::string("\n");
							node->name=temp;
							int not_count=std::stoi((yyvsp[-3].node)->name);
							for(int i=0;i<not_count;i++){
								node->code+=std::string("! ")+temp+std::string(", ")+temp+std::string("\n");
								}
							(yyval.node)=node;
							}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 659 "miniL.y" /* yacc.c:1646  */
    {codeNode *node=new codeNode;node->name="0";(yyval.node)=node;}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 660 "miniL.y" /* yacc.c:1646  */
    {
				codeNode *node = new codeNode;
				int not_count=std::stoi((yyvsp[0].node)->name)+1;
				node->name=std::to_string(not_count);
				}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 667 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "==";
			(yyval.node) = node;
		}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 673 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "!=";
			(yyval.node) = node;
		}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 679 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = ">";
			(yyval.node) = node;
		}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 685 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "<";
			(yyval.node) = node;
		}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 691 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = ">=";
			(yyval.node) = node;
		}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 697 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "<=";
			(yyval.node) = node;
		}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 704 "miniL.y" /* yacc.c:1646  */
    {codeNode *node = new codeNode; node->code=(yyvsp[0].node)->code;node->name=(yyvsp[0].node)->name;(yyval.node)=node;}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 705 "miniL.y" /* yacc.c:1646  */
    {
			//printf("Start of Expression -> Multi PLUS Multi\n");
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
			node->code += std::string("+ ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
			node->name = temp;
			(yyval.node) = node;
		}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 714 "miniL.y" /* yacc.c:1646  */
    {
			//printf("Start of Expression -> Multi MINUS Multi\n");
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
			node->code += std::string("- ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
			node->name = temp;
			(yyval.node) = node;
		}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 724 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term\n");
				codeNode *node= new codeNode;
				node->code=(yyvsp[0].node)->code;
				node->name=(yyvsp[0].node)->name;
				(yyval.node)=node;}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 730 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term MULT Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("* ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 739 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term Div Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("/ ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 748 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term MOD Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("% ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 758 "miniL.y" /* yacc.c:1646  */
    {//return temp register
				//printf("start of Term->Var\n");
				//std::string temp = create_temp();
				codeNode *node = new codeNode;
				//if(!find($1->name)){
				//	yyerror("Undefined reference to a variable");
				//}
				node->code = (yyvsp[0].node)->code;
				//node->code += std::string(". ") + $1->name + std::string("\n");
				node->name = (yyvsp[0].node)->name;
				(yyval.node) = node;
			}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 770 "miniL.y" /* yacc.c:1646  */
    {//return number;
			//printf("start of Term->Number\n");
			codeNode *node = new codeNode;
			node->name = std::to_string((yyvsp[0].int_val));//using immediate value so i think i can just stop after this
			(yyval.node) = node;
			}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 776 "miniL.y" /* yacc.c:1646  */
    {//return expression
			//printf("start of Term->L_Paren Expression R_paren\n");
			//std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = (yyvsp[-1].node) -> code;// don't need to do the node->code+= stuff as substuff of expression takes care of that
			node->name = (yyvsp[-1].node)->name;
			(yyval.node) = node;
						}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 784 "miniL.y" /* yacc.c:1646  */
    {//function call
			//printf("start of Term->Ident L_Paren Expression R_paren\n");i
			std::string temp= create_temp();
			std::string func_name = (yyvsp[-3].node)->name;
			functionscalled.push_back(make_pair((yyvsp[-3].node)->name,numLines));
			codeNode *node = new codeNode;
			node->code=std::string(". ")+temp+std::string("\n");
			//if(!find(func_name)){
			//	yyerror("Undefined reference to a function that doesn't exist");
			//}
			node->code+=(yyvsp[-1].node)->code+std::string("call ") + func_name+std::string(", ")+ temp+ std::string("\n");//need to check this one
			node->name=temp;
			(yyval.node) = node;// I have no clue wat im doing for this one, also i think we missing a grammar rule bc table says call name, dest changed so that the dest is the temp name that it is returned to
		}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 800 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 801 "miniL.y" /* yacc.c:1646  */
    {
				codeNode *node=new codeNode;
				//printf("start of expression2->expression\n");
				node->code=(yyvsp[0].node)->code+std::string("param ")+(yyvsp[0].node)->name+std::string("\n");
				//printf("end of expression2->expression\n");
				(yyval.node)=node;
}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 808 "miniL.y" /* yacc.c:1646  */
    {
						codeNode *node = new codeNode;
						//printf("start of expression2->expression comma expression2\n");
						node->code=(yyvsp[-2].node)->code+std::string("param ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
						//printf("end of expression2->expression comma expression2\n");
						(yyval.node)=node;
						}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 818 "miniL.y" /* yacc.c:1646  */
    {
				codeNode *node = new codeNode;
				node->code = "";
				//printf("start of Var->Ident\n");
				node->name = (yyvsp[0].node)->name;
				idents_used.push_back(make_pair((yyvsp[0].node)->name, numLines));
				//if(!find(node->name)){
				//	yyerror("Undefined reference to an identifier");
				//}//printf("end of Var->Ident\n");
				(yyval.node) = node;
				
			}
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 830 "miniL.y" /* yacc.c:1646  */
    {//array access statement store temp to return temp register
				//printf("Start of Var->Ident array\n");
				std::string var_name = create_temp();
				arrays_used.push_back(make_pair((yyvsp[-3].node)->name, numLines));
               			codeNode *node = new codeNode;
					//if(!find($1->name)){
					//	yyerror("Undefined reference to a nonexistent identifier");
					//}
		            node->code=(yyvsp[-1].node)->code+std::string(". ")+var_name+std::string("\n")+std::string("=[] ")+var_name+std::string(", ")+(yyvsp[-3].node)->name+std::string(", ")+(yyvsp[-1].node)->name+std::string("\n");
                	node->name=var_name;//was temp but that wasn't declared so not sure what to do just changed to var_name
					//printf("end of var->Ident square brackets\n");
		            (yyval.node)=node;//Just copied pasted with some slight adjustments from thomas implementation
			}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 846 "miniL.y" /* yacc.c:1646  */
    {
			//printf("Start of Ident->IDENT\n");
			codeNode *node = new codeNode;
			//printf("start of Ident->IDENT\n");
			node->code = "";
			node->name = (yyvsp[0].op_val);
			for(int i = 0; i < reservedWords.size(); ++i){
				if(node -> name == reservedWords[i])
					yyerror("Using a reserved keyword");
			}
			//printf("after strdup\n");
			//if(!find(node->name)){
			//	yyerror("Undefined reference to identifier");
			//}
			//printf("End of Ident->IDENT\n");
			//$$.code="";
			//$$.name=$1;
			(yyval.node)=node;
		}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2546 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 865 "miniL.y" /* yacc.c:1906  */
 

int main(int argc, char **argv) {
   //printf("In main\n");
   yyparse();
   return 0;
}
