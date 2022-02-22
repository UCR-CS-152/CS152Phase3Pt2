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

#line 181 "y.tab.c" /* yacc.c:339  */

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
#line 116 "miniL.y" /* yacc.c:355  */

  int		int_val;
  char*	op_val;
  struct codeNode *node;

#line 277 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 294 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  220

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
       0,   187,   187,   189,   207,   217,   218,   217,   257,   258,
     271,   283,   288,   303,   317,   330,   342,   343,   344,   345,
     346,   357,   369,   380,   392,   393,   394,   401,   402,   415,
     427,   428,   429,   430,   431,   442,   453,   464,   475,   476,
     477,   484,   486,   487,   489,   490,   491,   492,   493,   494,
     496,   497,   506,   516,   522,   531,   540,   550,   562,   568,
     576,   592,   593,   600,   610,   622,   638
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
  "$@2", "Declaration", "Declaration2", "Statement", "Statement1",
  "Bool-Exp", "NotLoop", "Comp", "Expression", "Multiplicative-Expr",
  "Term", "Expression2", "Var", "Ident", YY_NULLPTR
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

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,     2,     9,   -43,    15,   -43,   -43,   -43,   -43,   -13,
      21,     2,   -43,    13,    46,   -10,    52,    33,    23,     2,
       2,    73,    71,    48,   -43,    41,    77,    28,    74,   183,
      61,    58,    86,    75,    75,    79,    65,    68,     2,     2,
       4,    95,     5,     2,   106,    78,    75,    94,     4,    90,
     183,   223,   223,   -19,   -15,   -43,     4,    80,     0,     1,
     -43,    20,   -43,     4,     4,   -43,    82,     2,   -43,   183,
     -33,   183,    93,    75,    75,    96,    84,    87,     2,     2,
       4,   -43,    24,   -43,   223,     4,   223,     4,    85,   223,
       4,     4,     4,     4,     4,     4,     4,    88,    92,   117,
     -43,    55,   -43,   -43,   -43,   -43,   -43,   -43,     4,   110,
     116,   120,   119,   183,   223,   223,   -12,   -11,   105,     4,
       4,   -43,   104,   -43,   107,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   109,   111,   112,   114,   223,   140,   122,   183,
     -43,   126,    75,   183,   183,   131,   -43,   -43,   223,     4,
     223,     4,   223,   121,   128,   129,   136,     4,   -43,   -43,
       4,   -43,   137,   223,   157,   223,   139,    57,   154,   159,
     -43,   141,   -43,   143,   -43,   138,   223,   223,   223,   -43,
     152,     2,   -43,   156,   -43,   223,   158,   183,   163,    75,
     169,   174,     4,   -43,   -43,   -43,   223,   -43,   223,   -43,
     223,   162,   223,   175,   223,   223,   176,   -43,   -43,   -43,
     178,   -43,   223,   -43,   -43,   223,   223,   -43,   -43,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,    66,     5,     1,     4,     0,
       0,    11,     6,     0,     0,     0,     0,     0,     0,     8,
      11,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    42,     0,     0,     0,
       0,    27,    27,     0,     0,    58,     0,     0,    50,    53,
      57,    64,     7,     0,     0,     9,     0,    11,    43,     0,
       0,     0,     0,    42,    42,     0,     0,     0,     0,     0,
       0,    24,     0,    25,    27,     0,    27,     0,     0,    27,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
      13,     0,    44,    45,    47,    46,    49,    48,     0,     0,
       0,     0,     0,     0,    27,    27,     0,     0,     0,     0,
       0,    20,     0,    22,     0,    59,    26,    51,    52,    54,
      55,    56,    62,     0,     0,     0,    27,     0,     0,     0,
      41,     0,    42,     0,     0,     0,    38,    39,    27,     0,
      27,     0,    27,     0,     0,     0,     0,    61,    60,    65,
       0,    14,     0,    27,     0,    27,     0,     0,     0,     0,
      34,     0,    36,     0,    40,     0,    27,    27,    27,    63,
       0,     8,    16,     0,    18,    27,     0,     0,     0,    42,
       0,     0,     0,    28,    21,    23,    27,    10,    27,    19,
      27,     0,    27,     0,    27,    27,     0,    15,    17,    30,
       0,    32,    27,    35,    37,    27,    27,    33,    29,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   186,   -43,   -43,   -43,   -42,   -16,   -17,    19,
     -29,   147,   -43,    81,    -9,   -36,    59,   -43,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    14,    22,    12,    41,    81,
      47,    48,   108,   132,    58,    59,   133,    60,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    65,    17,    18,    24,    49,     5,    55,     5,     7,
      13,   102,   103,   104,   105,   106,   107,    84,    23,    13,
       1,    86,    85,    10,   148,   150,    87,    11,    42,   149,
     151,    90,    91,    72,    92,    93,    94,    53,    54,    61,
      30,    31,    23,    56,   111,   112,    63,    61,    64,    42,
      15,   100,   101,    16,   109,    61,   129,   130,   131,    95,
      19,    96,    61,    61,    21,   119,    13,   120,    42,    20,
      42,    83,   138,   139,   186,   187,    25,   116,   117,    61,
      26,   127,   128,    28,    61,    27,    61,    29,    32,    61,
      61,    61,    61,    61,    61,    61,   145,    43,    45,    44,
      50,    51,    46,   121,    52,   123,    62,    61,   126,    66,
      69,    71,    42,   166,    67,   110,    89,   113,    61,    61,
     114,    57,   164,   115,    99,   125,   167,   168,   136,    70,
     135,   137,   141,   146,   147,   142,   143,    88,    42,   197,
     144,   152,    42,    42,    97,    98,   155,   157,    61,   156,
      61,   158,   162,   169,   159,   161,    61,   160,   163,    61,
     203,   118,   165,   175,   176,   177,   122,   170,   124,   172,
     201,   174,   178,   181,   183,   185,   188,   134,   189,   210,
      23,   192,   182,   190,   184,   191,    42,     5,   196,   140,
       8,    61,   198,    68,   200,   193,   194,   195,    33,   202,
     153,   154,    34,    35,   199,   204,    36,    37,    38,    39,
     205,   212,   215,    40,   216,   207,   179,   208,     0,   209,
       0,   211,     0,   213,   214,     0,     0,     5,     0,     0,
     171,   217,   173,     0,   218,   219,     0,     0,    73,     0,
       0,   180,    74,    75,     0,     0,    76,    77,    78,    79,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206
};

static const yytype_int16 yycheck[] =
{
       1,    43,    12,    13,    20,    34,     4,     3,     4,     0,
      11,    44,    45,    46,    47,    48,    49,    36,    19,    20,
       5,    36,    41,    36,    36,    36,    41,     6,    29,    41,
      41,    31,    32,    50,    33,    34,    35,    38,    39,    40,
      12,    13,    43,    39,    73,    74,    41,    48,    43,    50,
      37,    67,    69,     7,    71,    56,    92,    93,    94,    39,
       8,    41,    63,    64,    41,    41,    67,    43,    69,    36,
      71,    52,    17,    18,    17,    18,     3,    78,    79,    80,
       9,    90,    91,    42,    85,    37,    87,    10,    14,    90,
      91,    92,    93,    94,    95,    96,   113,    36,    12,    41,
      21,    36,    27,    84,    36,    86,    11,   108,    89,     3,
      16,    21,   113,   142,    36,    22,    36,    21,   119,   120,
      36,    40,   139,    36,    42,    40,   143,   144,    36,    48,
      42,    14,    22,   114,   115,    19,    16,    56,   139,   181,
      21,    36,   143,   144,    63,    64,    42,    38,   149,    42,
     151,    40,    12,    22,    42,   136,   157,    43,    36,   160,
     189,    80,    36,    42,    36,    36,    85,   148,    87,   150,
     187,   152,    36,    36,    17,    36,    22,    96,    19,    17,
     181,    43,   163,    42,   165,    42,   187,     4,    36,   108,
       4,   192,    36,    46,    36,   176,   177,   178,    15,    36,
     119,   120,    19,    20,   185,    36,    23,    24,    25,    26,
      36,    36,    36,    30,    36,   196,   157,   198,    -1,   200,
      -1,   202,    -1,   204,   205,    -1,    -1,     4,    -1,    -1,
     149,   212,   151,    -1,   215,   216,    -1,    -1,    15,    -1,
      -1,   160,    19,    20,    -1,    -1,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    51,    52,    53,     4,    68,     0,    52,    54,
      36,     6,    57,    68,    55,    37,     7,    12,    13,     8,
      36,    41,    56,    68,    57,     3,     9,    37,    42,    10,
      12,    13,    14,    15,    19,    20,    23,    24,    25,    26,
      30,    58,    68,    36,    41,    12,    27,    60,    61,    60,
      21,    36,    36,    68,    68,     3,    39,    63,    64,    65,
      67,    68,    11,    41,    43,    56,     3,    36,    61,    16,
      63,    21,    58,    15,    19,    20,    23,    24,    25,    26,
      30,    59,    68,    59,    36,    41,    36,    41,    63,    36,
      31,    32,    33,    34,    35,    39,    41,    63,    63,    42,
      57,    58,    44,    45,    46,    47,    48,    49,    62,    58,
      22,    60,    60,    21,    36,    36,    68,    68,    63,    41,
      43,    59,    63,    59,    63,    40,    59,    64,    64,    65,
      65,    65,    63,    66,    63,    42,    36,    14,    17,    18,
      63,    22,    19,    16,    21,    58,    59,    59,    36,    41,
      36,    41,    36,    63,    63,    42,    42,    38,    40,    42,
      43,    59,    12,    36,    58,    36,    60,    58,    58,    22,
      59,    63,    59,    63,    59,    42,    36,    36,    36,    66,
      63,    36,    59,    17,    59,    36,    17,    18,    22,    19,
      42,    42,    43,    59,    59,    59,    36,    56,    36,    59,
      36,    58,    36,    60,    36,    36,    63,    59,    59,    59,
      17,    59,    36,    59,    59,    36,    36,    59,    59,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    54,    55,    53,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    67,    67,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    14,     0,     5,
      10,     0,     5,    10,     5,     8,     7,     9,     7,     8,
       4,     7,     4,     7,     3,     3,     4,     0,     5,     8,
       7,     9,     7,     8,     4,     7,     4,     7,     3,     3,
       4,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     3,
       4,     0,     1,     3,     1,     4,     1
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
#line 187 "miniL.y" /* yacc.c:1646  */
    {if(er!=true)std::cout<<(yyvsp[0].node)->code;}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 189 "miniL.y" /* yacc.c:1646  */
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
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 207 "miniL.y" /* yacc.c:1646  */
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
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 217 "miniL.y" /* yacc.c:1646  */
    {add_function_to_symbol_table((yyvsp[0].node)->name);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 218 "miniL.y" /* yacc.c:1646  */
    {
				Function *f=get_function();
				assignments="";
				//for(int i=0; i<f->declarations.size();i++){
				//		assignments+=std::string("= ")+f->declarations[i].name+std::string(", $")+std::to_string(i)+std::string("\n");
				//	}
				}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 225 "miniL.y" /* yacc.c:1646  */
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
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 257 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 258 "miniL.y" /* yacc.c:1646  */
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
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 271 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Declaration->Ident array\n");
				Type t=Array;
				if(find((yyvsp[-9].node)->name)){yyerror("Array has already declared");er=true;}
				if((yyvsp[-5].int_val)<=0){yyerror("Array can't be declared with size of less than 1");er=true;}
				add_variable_to_symbol_table((yyvsp[-9].node)->name,t);				
				codeNode *node = new codeNode;
                                node->code=(yyvsp[-9].node)->code;
                                node->code+= std::string(".[] ")+(yyvsp[-9].node)->name+std::string(", ")+std::to_string((yyvsp[-5].int_val))+std::string("\n")+(yyvsp[0].node)->code;
								(yyval.node) = node;
								}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 283 "miniL.y" /* yacc.c:1646  */
    {
			codeNode *node= new codeNode;node->code="";int i=0;
			//while(!paramCount.empty()){node->code+=std::string("= ")+paramCount.top()+std::string(", $")+std::to_string(i)+std::string("\n");i++;paramCount.pop();}
			(yyval.node)=node;
			}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 288 "miniL.y" /* yacc.c:1646  */
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
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 303 "miniL.y" /* yacc.c:1646  */
    {
                                //printf("Start of Declaration->Ident array\n");
                                Type t=Array;
				if(find((yyvsp[-9].node)->name)){yyerror("Variable already declared");er=true;}
				if((yyvsp[-5].int_val)<=0){yyerror("Array can't be declared with size of less than 1");er=true;}
                                add_variable_to_symbol_table((yyvsp[-9].node)->name,t);
                                codeNode *node = new codeNode;
                                node->code=(yyvsp[-9].node)->code;
                                node->code+= std::string(".[] ")+(yyvsp[-9].node)->name+std::string(", ")+std::to_string((yyvsp[-5].int_val))+std::string("\n")+(yyvsp[0].node)->code;
                                                                (yyval.node) = node;
                                                                }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 317 "miniL.y" /* yacc.c:1646  */
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
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 330 "miniL.y" /* yacc.c:1646  */
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
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 342 "miniL.y" /* yacc.c:1646  */
    {}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 343 "miniL.y" /* yacc.c:1646  */
    {}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 344 "miniL.y" /* yacc.c:1646  */
    {}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 345 "miniL.y" /* yacc.c:1646  */
    {}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 346 "miniL.y" /* yacc.c:1646  */
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
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 357 "miniL.y" /* yacc.c:1646  */
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
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 369 "miniL.y" /* yacc.c:1646  */
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
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 380 "miniL.y" /* yacc.c:1646  */
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
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 392 "miniL.y" /* yacc.c:1646  */
    {}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 393 "miniL.y" /* yacc.c:1646  */
    {}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 394 "miniL.y" /* yacc.c:1646  */
    {//return src 
			//printf("Start of Statement->Return\n");
			codeNode *node = new codeNode;
			node->code =(yyvsp[-2].node)->code+std::string("ret ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
			(yyval.node) = node;
		}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 401 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 402 "miniL.y" /* yacc.c:1646  */
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
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 415 "miniL.y" /* yacc.c:1646  */
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
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 427 "miniL.y" /* yacc.c:1646  */
    {}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 428 "miniL.y" /* yacc.c:1646  */
    {}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 429 "miniL.y" /* yacc.c:1646  */
    {}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 430 "miniL.y" /* yacc.c:1646  */
    {}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 431 "miniL.y" /* yacc.c:1646  */
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
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 442 "miniL.y" /* yacc.c:1646  */
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
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 453 "miniL.y" /* yacc.c:1646  */
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
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 464 "miniL.y" /* yacc.c:1646  */
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
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 475 "miniL.y" /* yacc.c:1646  */
    {}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 476 "miniL.y" /* yacc.c:1646  */
    {}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 477 "miniL.y" /* yacc.c:1646  */
    {//return src
			//printf("Start of Statment1->Return Expression Semicolon Statement1\n");
                        codeNode *node = new codeNode;
                        node->code = (yyvsp[-2].node)->code+std::string("ret ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;;
                        (yyval.node) = node;
			}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 484 "miniL.y" /* yacc.c:1646  */
    {}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 486 "miniL.y" /* yacc.c:1646  */
    {}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 487 "miniL.y" /* yacc.c:1646  */
    {}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 489 "miniL.y" /* yacc.c:1646  */
    {}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 490 "miniL.y" /* yacc.c:1646  */
    {}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 491 "miniL.y" /* yacc.c:1646  */
    {}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 492 "miniL.y" /* yacc.c:1646  */
    {}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 493 "miniL.y" /* yacc.c:1646  */
    {}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 494 "miniL.y" /* yacc.c:1646  */
    {}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 496 "miniL.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 497 "miniL.y" /* yacc.c:1646  */
    {
			//printf("Start of Expression -> Multi PLUS Multi\n");
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
			node->code += std::string("+ ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
			node->name = temp;
			(yyval.node) = node;
		}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 506 "miniL.y" /* yacc.c:1646  */
    {
			//printf("Start of Expression -> Multi MINUS Multi\n");
			std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
			node->code += std::string("- ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
			node->name = temp;
			(yyval.node) = node;
		}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 516 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term\n");
				codeNode *node= new codeNode;
				node->code=(yyvsp[0].node)->code;
				node->name=(yyvsp[0].node)->name;
				(yyval.node)=node;}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 522 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term MULT Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("* ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 531 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term Div Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("/ ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 540 "miniL.y" /* yacc.c:1646  */
    {
				//printf("Start of Multi->Term MOD Term\n");
				std::string temp = create_temp();
				codeNode *node = new codeNode;
				node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code+std::string(". ")+temp+std::string("\n");
				node->code += std::string("% ") + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
				node->name = temp;
				(yyval.node) = node;
			}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 550 "miniL.y" /* yacc.c:1646  */
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
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 562 "miniL.y" /* yacc.c:1646  */
    {//return number;
			//printf("start of Term->Number\n");
			codeNode *node = new codeNode;
			node->name = std::to_string((yyvsp[0].int_val));//using immediate value so i think i can just stop after this
			(yyval.node) = node;
			}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 568 "miniL.y" /* yacc.c:1646  */
    {//return expression
			//printf("start of Term->L_Paren Expression R_paren\n");
			//std::string temp = create_temp();
			codeNode *node = new codeNode;
			node->code = (yyvsp[-1].node) -> code;// don't need to do the node->code+= stuff as substuff of expression takes care of that
			node->name = (yyvsp[-1].node)->name;
			(yyval.node) = node;
						}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 576 "miniL.y" /* yacc.c:1646  */
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
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 592 "miniL.y" /* yacc.c:1646  */
    {codeNode *node= new codeNode;(yyval.node)=node;}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 593 "miniL.y" /* yacc.c:1646  */
    {
				codeNode *node=new codeNode;
				//printf("start of expression2->expression\n");
				node->code=(yyvsp[0].node)->code+std::string("param ")+(yyvsp[0].node)->name+std::string("\n");
				//printf("end of expression2->expression\n");
				(yyval.node)=node;
}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 600 "miniL.y" /* yacc.c:1646  */
    {
						codeNode *node = new codeNode;
						//printf("start of expression2->expression comma expression2\n");
						node->code=(yyvsp[-2].node)->code+std::string("param ")+(yyvsp[-2].node)->name+std::string("\n")+(yyvsp[0].node)->code;
						//printf("end of expression2->expression comma expression2\n");
						(yyval.node)=node;
						}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 610 "miniL.y" /* yacc.c:1646  */
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
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 622 "miniL.y" /* yacc.c:1646  */
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
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 638 "miniL.y" /* yacc.c:1646  */
    {
			//printf("Start of Ident->IDENT\n");
			codeNode *node = new codeNode;
			//printf("start of Ident->IDENT\n");
			node->code = "";
			node->name = (yyvsp[0].op_val);
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
			(yyval.node)=node;
		}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2286 "y.tab.c" /* yacc.c:1646  */
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
#line 657 "miniL.y" /* yacc.c:1906  */
 

int main(int argc, char **argv) {
   //printf("In main\n");
   yyparse();
   return 0;
}
