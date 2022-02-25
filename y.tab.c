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
int loopCount=0;
bool er=false;
bool inLoop=false;
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

#line 188 "y.tab.c" /* yacc.c:339  */

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
#line 123 "miniL.y" /* yacc.c:355  */

  int		int_val;
  char*	op_val;
  struct codeNode *node;

#line 284 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 301 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

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
       0,   197,   197,   199,   217,   225,   226,   225,   265,   266,
     279,   279,   289,   289,   293,   298,   313,   313,   323,   323,
     329,   342,   354,   362,   372,   372,   372,   397,   397,   397,
     423,   434,   446,   457,   469,   469,   475,   475,   482,   489,
     490,   503,   515,   523,   533,   533,   533,   558,   558,   558,
     583,   594,   605,   616,   627,   627,   633,   633,   639,   646,
     660,   661,   669,   675,   681,   687,   693,   699,   706,   707,
     716,   726,   732,   741,   750,   760,   772,   778,   784,   792,
     808,   809,   816,   826,   838,   854
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
  "Statement", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "Statement1",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "Bool-Exp", "NotLoop",
  "Comp", "Expression", "Multiplicative-Expr", "Term", "Expression2",
  "Var", "Ident", YY_NULLPTR
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

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,     9,    17,   -72,     4,   -72,   -72,   -72,   -72,     2,
      56,     9,   -72,    35,    67,    16,    75,    59,    61,     9,
       9,     1,    88,    63,   -72,   -72,   101,    96,    42,    65,
     -72,    33,    74,    70,   100,    73,    92,   -72,   -72,   -72,
     -72,     9,     9,    11,   110,    -7,     9,     3,   113,   108,
      92,   112,    11,    92,   105,    94,    95,   -29,   -25,   -72,
     129,    11,    99,    45,    31,   -72,     5,   -72,    11,    11,
     -72,   -72,   -72,   102,   124,   -72,    33,   -24,   116,    33,
     163,   163,   163,    11,   163,    11,   -72,   107,   163,    11,
      11,    11,    11,    11,    11,    11,    98,   106,   109,   146,
       9,   114,    62,   -72,   -72,   -72,   -72,   -72,   -72,    11,
      33,   132,    92,   -72,   136,   -72,   -72,     9,     9,    11,
     -72,     6,   -72,   -72,   118,   -72,   119,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   120,   125,   122,   126,   163,   154,
     128,   -72,     9,   138,    33,   -72,   150,   156,   160,    92,
     -72,   145,   148,   -10,    -9,   149,    11,    11,   155,   159,
      11,   -72,   -72,    11,   -72,   178,   182,   -72,   163,   175,
     -72,    92,    33,   176,    33,   163,   163,   163,    11,   163,
      11,   163,   157,   162,   163,   163,   -72,   167,   168,   194,
     -72,   173,   174,   177,    68,    33,   189,   -72,   -72,   -72,
     170,   -72,   179,   -72,   172,   163,   -72,   -72,   163,     9,
     180,   163,   163,   -72,   181,    33,   196,   201,   190,   191,
      11,   -72,   -72,   -72,     9,   -72,   -72,   163,   163,   208,
     -72,    92,   163,   163,   192,   -72,   -72,   -72,   193,   195,
     197,   -72,   -72,   163,   163,   163,   -72,   -72,   -72,   -72,
     163,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,    85,     5,     1,     4,     0,
       0,    14,     6,     0,     0,     0,     0,     0,     0,     8,
      14,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    60,    24,    27,    34,
      36,     0,     0,     0,     0,     0,     8,     0,     0,     0,
      60,     0,     0,    60,     0,     0,     0,     0,     0,    76,
       0,     0,     0,    68,    71,    75,    83,     7,     0,     0,
       9,    10,    12,     0,     0,    61,     0,     0,     0,     0,
      39,    39,    39,     0,    39,     0,    77,     0,    39,     0,
       0,     0,     0,     0,    80,     0,     0,     0,     0,     0,
      14,     0,     0,    62,    63,    65,    64,    67,    66,     0,
       0,     0,    60,    44,     0,    54,    56,     0,     0,     0,
      35,     0,    37,    30,     0,    32,     0,    78,    38,    69,
      70,    72,    73,    74,    81,     0,     0,     0,    39,     0,
       0,    17,    14,     0,     0,    59,     0,     0,     0,    60,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    79,    84,     0,    20,     0,     0,    19,    39,     0,
      25,    60,     0,     0,     0,    39,    39,    39,     0,    39,
       0,    39,     0,     0,    39,    39,    82,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    55,    57,    50,
       0,    52,     0,    58,     0,    39,    31,    33,    39,     8,
       0,    39,    39,    28,     0,     0,     0,     0,     0,     0,
       0,    40,    21,    11,    14,    23,    26,    39,    39,     0,
      45,    60,    39,    39,     0,    13,    29,    42,     0,     0,
       0,    51,    53,    39,    39,    39,    48,    41,    43,    46,
      39,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   226,   -72,   -72,   -72,   -43,   -72,   -72,   -19,
     -72,   -72,   -71,   -72,   -72,   -72,   -72,   -72,   -72,    64,
     -72,   -72,   -72,   -72,   -72,   -72,   -51,   184,   -72,    44,
     -22,   -72,    76,   -72,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    14,    22,    98,    99,    12,
      29,    35,    44,    53,   192,    54,   227,    55,    56,   120,
     149,   239,   174,   250,   151,   152,    51,    52,   109,   134,
      63,    64,   135,    65,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    24,    78,    70,    25,   102,    71,    82,   111,     1,
      13,    84,    83,     5,    59,     5,    85,     7,    23,    13,
     103,   104,   105,   106,   107,   108,   177,   179,    17,    18,
      45,   178,   180,    26,    68,    72,    69,     5,    10,   146,
      57,    58,    66,    60,    94,    23,    95,   156,    36,   157,
      61,    66,    37,    38,    32,    33,    39,    40,    41,    42,
      66,   148,    11,    43,    91,    92,    93,    66,    66,   131,
     132,   133,    15,   169,    16,    45,    89,    90,    45,   143,
     144,   141,    66,    19,    66,   214,   215,    62,    66,    66,
      66,    66,    66,    66,    66,    20,    77,    27,   173,    13,
      28,   194,    21,   196,    30,    87,    31,    34,    66,    45,
      46,    47,    96,    97,    48,    49,   153,   154,    66,    50,
     193,    67,    74,   167,   216,    73,    79,   124,    76,   126,
      80,    81,    86,   129,   130,    88,   101,   110,   100,   136,
     137,    13,   138,    45,   229,   122,   123,   127,   125,   140,
     142,   139,   128,   145,   147,    66,    66,   150,   160,    66,
     158,   159,    66,   155,   162,   161,   223,     5,   165,   163,
     166,    45,   170,    45,   168,   171,   172,    66,   112,    66,
     240,   175,   113,   114,   176,   181,   115,   116,   117,   118,
     188,   184,   191,   119,    45,   185,   189,   195,   205,   204,
     182,   183,   164,   208,   209,   235,   210,   187,    23,   211,
     212,   217,   218,   213,    45,   220,   224,   228,   230,    66,
     231,   219,   200,    13,   202,   238,   232,   233,   243,   244,
       8,   245,   190,   246,    75,     0,   186,     0,     0,   197,
     198,   199,     0,   201,     0,   203,     0,     0,   206,   207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,   221,
       0,     0,   222,     0,     0,   225,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   237,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,   251
};

static const yytype_int16 yycheck[] =
{
       1,    20,    53,    46,     3,    76,     3,    36,    79,     5,
      11,    36,    41,     4,     3,     4,    41,     0,    19,    20,
      44,    45,    46,    47,    48,    49,    36,    36,    12,    13,
      31,    41,    41,    32,    41,    32,    43,     4,    36,   110,
      41,    42,    43,    32,    39,    46,    41,    41,    15,    43,
      39,    52,    19,    20,    12,    13,    23,    24,    25,    26,
      61,   112,     6,    30,    33,    34,    35,    68,    69,    91,
      92,    93,    37,   144,     7,    76,    31,    32,    79,    17,
      18,   100,    83,     8,    85,    17,    18,    43,    89,    90,
      91,    92,    93,    94,    95,    36,    52,     9,   149,   100,
      37,   172,    41,   174,     3,    61,    10,    42,   109,   110,
      36,    41,    68,    69,    14,    42,   117,   118,   119,    27,
     171,    11,    14,   142,   195,    12,    21,    83,    16,    85,
      36,    36,     3,    89,    90,    36,    12,    21,    36,    95,
      42,   142,    36,   144,   215,    81,    82,    40,    84,     3,
      36,    42,    88,   109,    22,   156,   157,    21,    38,   160,
      42,    42,   163,   119,    42,    40,   209,     4,    14,    43,
      42,   172,    22,   174,    36,    19,    16,   178,    15,   180,
     231,    36,    19,    20,    36,    36,    23,    24,    25,    26,
      12,    36,    17,    30,   195,    36,    14,    21,    36,    42,
     156,   157,   138,    36,    36,   224,    12,   163,   209,    36,
      36,    22,    42,    36,   215,    43,    36,    36,    22,   220,
      19,    42,   178,   224,   180,    17,    36,    36,    36,    36,
       4,    36,   168,    36,    50,    -1,   160,    -1,    -1,   175,
     176,   177,    -1,   179,    -1,   181,    -1,    -1,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   205,
      -1,    -1,   208,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
      -1,    -1,    -1,    -1,   250
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    51,    52,    53,     4,    84,     0,    52,    54,
      36,     6,    59,    84,    55,    37,     7,    12,    13,     8,
      36,    41,    56,    84,    59,     3,    32,     9,    37,    60,
       3,    10,    12,    13,    42,    61,    15,    19,    20,    23,
      24,    25,    26,    30,    62,    84,    36,    41,    14,    42,
      27,    76,    77,    63,    65,    67,    68,    84,    84,     3,
      32,    39,    79,    80,    81,    83,    84,    11,    41,    43,
      56,     3,    32,    12,    14,    77,    16,    79,    76,    21,
      36,    36,    36,    41,    36,    41,     3,    79,    36,    31,
      32,    33,    34,    35,    39,    41,    79,    79,    57,    58,
      36,    12,    62,    44,    45,    46,    47,    48,    49,    78,
      21,    62,    15,    19,    20,    23,    24,    25,    26,    30,
      69,    84,    69,    69,    79,    69,    79,    40,    69,    79,
      79,    80,    80,    80,    79,    82,    79,    42,    36,    42,
       3,    59,    36,    17,    18,    79,    62,    22,    76,    70,
      21,    74,    75,    84,    84,    79,    41,    43,    42,    42,
      38,    40,    42,    43,    69,    14,    42,    59,    36,    62,
      22,    19,    16,    76,    72,    36,    36,    36,    41,    36,
      41,    36,    79,    79,    36,    36,    82,    79,    12,    14,
      69,    17,    64,    76,    62,    21,    62,    69,    69,    69,
      79,    69,    79,    69,    42,    36,    69,    69,    36,    36,
      12,    36,    36,    36,    17,    18,    62,    22,    42,    42,
      43,    69,    69,    56,    36,    69,    69,    66,    36,    62,
      22,    19,    36,    36,    79,    59,    69,    69,    17,    71,
      76,    69,    69,    36,    36,    36,    36,    69,    69,    69,
      73,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    54,    55,    53,    56,    56,
      57,    56,    58,    56,    59,    59,    60,    59,    61,    59,
      62,    62,    62,    62,    63,    64,    62,    65,    66,    62,
      62,    62,    62,    62,    67,    62,    68,    62,    62,    69,
      69,    69,    69,    69,    70,    71,    69,    72,    73,    69,
      69,    69,    69,    69,    74,    69,    75,    69,    69,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    14,     0,     5,
       0,    11,     0,    12,     0,     5,     0,    11,     0,    12,
       5,     8,     7,     9,     0,     0,     9,     0,     0,    10,
       4,     7,     4,     7,     0,     4,     0,     4,     4,     0,
       5,     8,     7,     9,     0,     0,     9,     0,     0,    10,
       4,     7,     4,     7,     0,     4,     0,     4,     4,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     2,     3,     4,
       0,     1,     3,     1,     4,     1
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
#line 197 "miniL.y" /* yacc.c:1646  */
    {if(er!=true)std::cout<<(yyvsp[0].node)->code;}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 199 "miniL.y" /* yacc.c:1646  */
    {
					if(symbol_table[symbol_table.size()-1].name!="main"){std::cout<<"No main function defined\n";er=true;}
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
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 217 "miniL.y" /* yacc.c:1646  */
    { 
		//printf("Start of Program->Functions Program\n");
		//idk bout this one
		codeNode *node= new codeNode;
		node->code=(yyvsp[-1].node)->code+(yyvsp[0].node)->code;
		//printf("Functions Program\n");
		(yyval.node)=node;
	 }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 225 "miniL.y" /* yacc.c:1646  */
    {add_function_to_symbol_table((yyvsp[0].node)->name);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
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
#line 1607 "y.tab.c" /* yacc.c:1646  */
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
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 265 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 1649 "y.tab.c" /* yacc.c:1646  */
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
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 279 "miniL.y" /* yacc.c:1646  */
    {if((yyvsp[0].int_val)<=0){yyerror("Array can't be declared with size of less than 1");er=true;}}
#line 1673 "y.tab.c" /* yacc.c:1646  */
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
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 289 "miniL.y" /* yacc.c:1646  */
    {yyerror("Array can't be declared with size of less than 1");er=true;}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 289 "miniL.y" /* yacc.c:1646  */
    {
					add_variable_to_symbol_table((yyvsp[-11].node)->name,Array);		
				}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 293 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node= new codeNode;node->code="";int i=0;
			//while(!paramCount.empty()){node->code+=std::string("= ")+paramCount.top()+std::string(", $")+std::to_string(i)+std::string("\n");i++;paramCount.pop();}
			(yyval.node)=node;
			}
#line 1712 "y.tab.c" /* yacc.c:1646  */
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
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 313 "miniL.y" /* yacc.c:1646  */
    {if(find((yyvsp[-4].node)->name)){yyerror("Variable already declared");er=true;}}
#line 1738 "y.tab.c" /* yacc.c:1646  */
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
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 323 "miniL.y" /* yacc.c:1646  */
    {yyerror("Array can't be declared with size of less than 1");er=true;}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 323 "miniL.y" /* yacc.c:1646  */
    {
					add_variable_to_symbol_table((yyvsp[-11].node)->name,Array);	
				}
#line 1767 "y.tab.c" /* yacc.c:1646  */
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
#line 1785 "y.tab.c" /* yacc.c:1646  */
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
#line 1802 "y.tab.c" /* yacc.c:1646  */
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
#line 1815 "y.tab.c" /* yacc.c:1646  */
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
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 372 "miniL.y" /* yacc.c:1646  */
    {inLoop=true;loopCount++;}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 372 "miniL.y" /* yacc.c:1646  */
    {if(loopCount>0)loopCount--;if(loopCount==0)inLoop=false;}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 372 "miniL.y" /* yacc.c:1646  */
    {
											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											node->code=(yyvsp[-6].node)->code;
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-4].node)->code.find(br);
											while(found!=std::string::npos){
													std::string replace=std::string(":= ")+label2;
													(yyvsp[-4].node)->code.replace(found,br.length(),replace);
													found = (yyvsp[-4].node)->code.find(br);
												}
											found = (yyvsp[-4].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label1;
                                                                                                        (yyvsp[-4].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-4].node)->code.find(con);
                                                                                                }
											node->code+=std::string("! ")+(yyvsp[-6].node)->name+std::string(", ")+(yyvsp[-6].node)->name+std::string("\n");
											node->code+=std::string(": ")+label1+std::string("\n")+std::string("?:= ")+label2+std::string(", ")+(yyvsp[-6].node)->name+std::string("\n")+(yyvsp[-4].node)->code+(yyvsp[-6].node)->code;
											node->code+=std::string("! ")+(yyvsp[-6].node)->name+std::string(", ")+(yyvsp[-6].node)->name+std::string("\n");
											node->code+=std::string(":= ")+label1+std::string("\n")+std::string(": ")+label2+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
											}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 397 "miniL.y" /* yacc.c:1646  */
    {inLoop=true;loopCount++;}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 397 "miniL.y" /* yacc.c:1646  */
    {if(loopCount>0)loopCount--;if(loopCount==0)inLoop=false;}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 397 "miniL.y" /* yacc.c:1646  */
    {

											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											std::string label3=create_label();
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-6].node)->code.find(br);
											//node->code=$6->code;
											while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label3;
                                                                                                        (yyvsp[-6].node)->code.replace(found,br.length(),replace);
                                                                                                        found = (yyvsp[-6].node)->code.find(br);
                                                                                                }
                                                                                        found = (yyvsp[-6].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label2;
                                                                                                        (yyvsp[-6].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-6].node)->code.find(con);
                                                                                                }
											node->code=std::string(": ")+label1+std::string("\n")+(yyvsp[-6].node)->code+(yyvsp[-3].node)->code;
											node->code+=std::string(": ")+label2+std::string("\n")+std::string("?:= ")+label1+std::string(", ")+(yyvsp[-3].node)->name+std::string("\n");
											node->code+=std::string(": ")+label3+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
											}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 423 "miniL.y" /* yacc.c:1646  */
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
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 434 "miniL.y" /* yacc.c:1646  */
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
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 446 "miniL.y" /* yacc.c:1646  */
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
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 457 "miniL.y" /* yacc.c:1646  */
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
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 469 "miniL.y" /* yacc.c:1646  */
    {if(inLoop==false){er=true;yyerror("Continue is not in loop");}}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 469 "miniL.y" /* yacc.c:1646  */
    {
                                                codeNode *node = new codeNode;
                                                node->code = std::string("Continue \n");
                                                node->name = std::string ("Continue");
                                                (yyval.node)=node;
                                                }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 475 "miniL.y" /* yacc.c:1646  */
    {if(inLoop==false){er=true;yyerror("Break is not in loop");}}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 475 "miniL.y" /* yacc.c:1646  */
    {//maybe return break as a name then do where to go in level above
                                                codeNode *node = new codeNode;
                                                node->code = std::string("Break \n");
                                                node->name = std::string ("Break");
                                                (yyval.node)=node;
                                                }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 482 "miniL.y" /* yacc.c:1646  */
    {//return src 
			//printf("Start of Statement->Return\n");
			codeNode *node = new codeNode;
			node->code =(yyvsp[-2].node)->code+std::string("ret ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
			(yyval.node) = node;
		}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 489 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 490 "miniL.y" /* yacc.c:1646  */
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
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 503 "miniL.y" /* yacc.c:1646  */
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
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 515 "miniL.y" /* yacc.c:1646  */
    {
                                                                        codeNode *node = new codeNode;
                                                                        node->code=(yyvsp[-5].node)->code;
                                                                        std::string label1=create_label();
                                                                        node->code+=std::string("! ")+(yyvsp[-5].node)->name+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n");
                                                                        node->code+=std::string("?:= ")+label1+std::string(", ")+(yyvsp[-5].node)->name+std::string("\n")+(yyvsp[-3].node)->code+std::string(": ")+label1+std::string("\n")+(yyvsp[0].node)->code;
                                                                        (yyval.node)=node;
                                                                        }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 523 "miniL.y" /* yacc.c:1646  */
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
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 533 "miniL.y" /* yacc.c:1646  */
    {inLoop=true;loopCount++;}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 533 "miniL.y" /* yacc.c:1646  */
    {if(loopCount>0)loopCount--;if(loopCount==0)inLoop=false;}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 533 "miniL.y" /* yacc.c:1646  */
    {
											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											node->code=(yyvsp[-6].node)->code;
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-4].node)->code.find(br);
											while(found!=std::string::npos){
													std::string replace=std::string(":= ")+label2;
													(yyvsp[-4].node)->code.replace(found,br.length(),replace);
													found = (yyvsp[-4].node)->code.find(br);
												}
											found = (yyvsp[-4].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label1;
                                                                                                        (yyvsp[-4].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-4].node)->code.find(con);
                                                                                                }
											node->code+=std::string("! ")+(yyvsp[-6].node)->name+std::string(", ")+(yyvsp[-6].node)->name+std::string("\n");
											node->code+=std::string(": ")+label1+std::string("\n")+std::string("?:= ")+label2+std::string(", ")+(yyvsp[-6].node)->name+std::string("\n")+(yyvsp[-4].node)->code+(yyvsp[-6].node)->code;
											node->code+=std::string("! ")+(yyvsp[-6].node)->name+std::string(", ")+(yyvsp[-6].node)->name+std::string("\n");
											node->code+=std::string(":= ")+label1+std::string("\n")+std::string(": ")+label2+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
                                                                                        }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 558 "miniL.y" /* yacc.c:1646  */
    {inLoop=true;loopCount++;}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 558 "miniL.y" /* yacc.c:1646  */
    {if(loopCount>0)loopCount--;if(loopCount==0)inLoop=false;}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 558 "miniL.y" /* yacc.c:1646  */
    {
											codeNode *node = new codeNode;
											std::string label1=create_label();
											std::string label2=create_label();
											std::string label3=create_label();
											std::string br=std::string("Break");
											std::string con=std::string("Continue");
											std::size_t found = (yyvsp[-6].node)->code.find(br);
											//node->code=$6->code;
											while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label3;
                                                                                                        (yyvsp[-6].node)->code.replace(found,br.length(),replace);
                                                                                                        found = (yyvsp[-6].node)->code.find(br);
                                                                                                }
                                                                                        found = (yyvsp[-6].node)->code.find(con);
                                                                                        while(found!=std::string::npos){
                                                                                                        std::string replace=std::string(":= ")+label2;
                                                                                                        (yyvsp[-6].node)->code.replace(found,con.length(),replace);
                                                                                                        found = (yyvsp[-6].node)->code.find(con);
                                                                                                }
											node->code=std::string(": ")+label1+std::string("\n")+(yyvsp[-6].node)->code+(yyvsp[-3].node)->code;
											node->code+=std::string(": ")+label2+std::string("\n")+std::string("?:= ")+label1+std::string(", ")+(yyvsp[-3].node)->name+std::string("\n");
											node->code+=std::string(": ")+label3+std::string("\n")+(yyvsp[0].node)->code;
											(yyval.node)=node;
                                                                                        }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 583 "miniL.y" /* yacc.c:1646  */
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
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 594 "miniL.y" /* yacc.c:1646  */
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
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 605 "miniL.y" /* yacc.c:1646  */
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
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 616 "miniL.y" /* yacc.c:1646  */
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
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 627 "miniL.y" /* yacc.c:1646  */
    {if(inLoop==false){er=true;yyerror("Continue not in loop.");}}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 627 "miniL.y" /* yacc.c:1646  */
    {
						codeNode *node = new codeNode;
						node->code = std::string("Continue \n");
						node->name = std::string ("Continue");
						(yyval.node)=node;
						}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 633 "miniL.y" /* yacc.c:1646  */
    {if(inLoop==false){er=true;yyerror("Break not in loop.");}}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 633 "miniL.y" /* yacc.c:1646  */
    {//maybe return break as a name then do where to go in level above
						codeNode *node = new codeNode;
                                                node->code = std::string("Break \n");
                                                node->name = std::string ("Break");
                                                (yyval.node)=node;
						}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 639 "miniL.y" /* yacc.c:1646  */
    {//return src
			//printf("Start of Statment1->Return Expression Semicolon Statement1\n");
                        codeNode *node = new codeNode;
                        node->code = (yyvsp[-2].node)->code+std::string("ret ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
                        (yyval.node) = node;
			}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 646 "miniL.y" /* yacc.c:1646  */
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
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 660 "miniL.y" /* yacc.c:1646  */
    {codeNode *node=new codeNode;node->name="0";(yyval.node)=node;}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 661 "miniL.y" /* yacc.c:1646  */
    {
				codeNode *node = new codeNode;
				int not_count=std::stoi((yyvsp[0].node)->name)+1;
				node->name=std::to_string(not_count);
				(yyval.node)=node;
				}
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 669 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "==";
			(yyval.node) = node;
		}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 675 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "!=";
			(yyval.node) = node;
		}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 681 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = ">";
			(yyval.node) = node;
		}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 687 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "<";
			(yyval.node) = node;
		}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 693 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = ">=";
			(yyval.node) = node;
		}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 699 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node = new codeNode;
			node -> code = "";
			node -> name = "<=";
			(yyval.node) = node;
		}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 706 "miniL.y" /* yacc.c:1646  */
    {codeNode *node = new codeNode; node->code=(yyvsp[0].node)->code;node->name=(yyvsp[0].node)->name;(yyval.node)=node;}
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 707 "miniL.y" /* yacc.c:1646  */
    {
                        //printf("Start of Expression -> Multi PLUS Multi\n");
                        std::string temp = create_temp();
                        codeNode *node = new codeNode;
                        node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
                        node->code += std::string("+ ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
                        node->name = temp;
                        (yyval.node) = node;
                }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 716 "miniL.y" /* yacc.c:1646  */
    {
                        //printf("Start of Expression -> Multi MINUS Multi\n");
                        std::string temp = create_temp();
                        codeNode *node = new codeNode;
                        node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
                        node->code += std::string("- ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
                        node->name = temp;
                        (yyval.node) = node;
                }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 726 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term\n");
				codeNode *node= new codeNode;
				node->code=(yyvsp[0].node)->code;
				node->name=(yyvsp[0].node)->name;
				(yyval.node)=node;}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 732 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term MULT Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("* ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 741 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term Div Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("/ ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 750 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term MOD Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("% ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 760 "miniL.y" /* yacc.c:1646  */
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
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 772 "miniL.y" /* yacc.c:1646  */
    {//return number;
			//printf("start of Term->Number\n");
			codeNode *node = new codeNode;
			node->name = std::to_string((yyvsp[0].int_val));//using immediate value so i think i can just stop after this
			(yyval.node) = node;
			}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 778 "miniL.y" /* yacc.c:1646  */
    {//return number;
                        //printf("start of Term->Number\n");
                        codeNode *node = new codeNode;
                        node->name = std::string("-")+std::to_string((yyvsp[0].int_val));//using immediate value so i think i can just stop after this
                        (yyval.node) = node;
                        }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 784 "miniL.y" /* yacc.c:1646  */
    {//return expression
			//printf("start of Term->L_Paren Expression R_paren\n");
			//std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = (yyvsp[-1].node) -> code;// don't need to do the node->code+= stuff as substuff of expression takes care of that
			node->name = (yyvsp[-1].node)->name;
			(yyval.node) = node;
						}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 792 "miniL.y" /* yacc.c:1646  */
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
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 808 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 809 "miniL.y" /* yacc.c:1646  */
    {
				codeNode *node=new codeNode;
				//printf("start of expression2->expression\n");
				node->code=(yyvsp[0].node)->code+std::string("param ")+(yyvsp[0].node)->name+std::string("\n");
				//printf("end of expression2->expression\n");
				(yyval.node)=node;
}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 816 "miniL.y" /* yacc.c:1646  */
    {
						codeNode *node = new codeNode;
						//printf("start of expression2->expression comma expression2\n");
						node->code=(yyvsp[-2].node)->code+std::string("param ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
						//printf("end of expression2->expression comma expression2\n");
						(yyval.node)=node;
						}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 826 "miniL.y" /* yacc.c:1646  */
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
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 838 "miniL.y" /* yacc.c:1646  */
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
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 854 "miniL.y" /* yacc.c:1646  */
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
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2640 "y.tab.c" /* yacc.c:1646  */
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
#line 873 "miniL.y" /* yacc.c:1906  */
 

int main(int argc, char **argv) {
   //printf("In main\n");
   yyparse();
   return 0;
}
