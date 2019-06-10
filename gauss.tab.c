
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 ".\\gauss.y"

	#include <stdio.h>
    #include <stdlib.h>
    #include "tabelaHash.h"
    #include <string.h>
    #include <conio.h>

  int yylex(void);
  int yyerror(char *s);
  extern int yylineno;
  extern char * yytext; 

  int escopo = 0;
  char buffer [33];

  //typedef enum {false, true} bool;

  struct valor makeValorFunc(char *nome, char *retorno, char *Params);
  struct valor make_pointerID(char* tipo, char* nome, int tamanho);



/* Line 189 of yacc.c  */
#line 96 "gauss.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAVE_ESQUERDA = 258,
     CHAVE_DIREITA = 259,
     PARENTESE_ESQUERDA = 260,
     PARENTESE_DIREITA = 261,
     COLCHETE_ESQUERDA = 262,
     COLCHETE_DIREITA = 263,
     PONTO_E_VIRGULA = 264,
     VIRGULA = 265,
     PONTO = 266,
     DOIS_PONTOS = 267,
     E_LOGICO = 268,
     E_LOGICO_CURTO_CIRCUITO = 269,
     OU_LOGICO = 270,
     OU_LOGICO_CURTO_CIRCUITO = 271,
     EXCLAMACAO = 272,
     ASTERISCO = 273,
     PRINT_INT = 274,
     PRINT_FLOAT = 275,
     PRINT_CHAR = 276,
     PRINT_STRING = 277,
     MODULO = 278,
     BARRA = 279,
     INCREMENTO = 280,
     DECREMENTO = 281,
     MAIS = 282,
     MENOS_UNARIO = 283,
     EXPONENCIACAO = 284,
     ATRIBUICAO = 285,
     OPERADOR_TERNARIO = 286,
     MENOR_QUE = 287,
     MAIOR_QUE = 288,
     MENOR_OU_IGUAL_A = 289,
     MAIOR_OU_IGUAL_A = 290,
     IGUAL_A = 291,
     DIFERENTE_DE = 292,
     MAIS_IGUAL = 293,
     MENOS_IGUAL = 294,
     VEZES_IGUAL = 295,
     DIV_IGUAL = 296,
     EXPONENCIACAO_IGUAL = 297,
     FOR = 298,
     END_FOR = 299,
     DO = 300,
     WHILE = 301,
     END_WHILE = 302,
     SWITCH = 303,
     END_SWITCH = 304,
     CASE = 305,
     END_CASE = 306,
     DEFAULT = 307,
     IF = 308,
     END_IF = 309,
     ELSE = 310,
     ELSEIF = 311,
     THEN = 312,
     STRUCT = 313,
     ENDSTRUCT = 314,
     IS = 315,
     END = 316,
     FUNCAO = 317,
     PROC = 318,
     RETURN = 319,
     TBEGIN = 320,
     CONSTANTE = 321,
     PRINTF = 322,
     SCANF = 323,
     CARACTERE = 324,
     STRING = 325,
     INTEIRO = 326,
     FLOAT = 327,
     DOUBLE = 328,
     VOID = 329,
     BOOLEANO = 330,
     TRUE = 331,
     FALSE = 332,
     JUMP = 333,
     BREAK = 334,
     TNULL = 335,
     DIGITO = 336,
     ID = 337,
     LITERAL_QUALQUER = 338
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 23 ".\\gauss.y"

  int    iValue;  /* integer value */
  float  fValue;  /* float value */
  double dValue;  /* double value */
  int   bValue;  /* boolean value */
  char   cValue;  /* char value */
  char * sValue;  /* string value */
  struct valor sStruct;



/* Line 214 of yacc.c  */
#line 227 "gauss.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 239 "gauss.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  211

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    18,    21,
      24,    28,    31,    33,    36,    42,    45,    47,    49,    51,
      54,    57,    59,    62,    65,    71,    77,    79,    83,    84,
      86,    89,    93,    95,    97,    99,   101,   106,   108,   112,
     115,   119,   126,   137,   146,   154,   155,   159,   162,   170,
     171,   174,   176,   179,   186,   188,   190,   192,   194,   198,
     201,   204,   208,   212,   214,   216,   218,   220,   222,   224,
     226,   228,   230,   232,   234,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   260,   262,   266,
     270,   272,   273,   275,   279,   283,   285,   289,   291,   295,
     299,   303,   307,   308,   311,   318,   323,   336,   338,   340,
     345
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      85,     0,    -1,    86,    -1,    89,    86,    -1,   127,    -1,
      86,   127,    -1,    91,    -1,    91,    87,    -1,   119,   128,
      -1,   119,   125,    -1,   119,   125,    88,    -1,   119,   110,
      -1,    90,    -1,    90,    89,    -1,    58,    82,    60,   100,
      59,    -1,    88,     9,    -1,   103,    -1,   101,    -1,   102,
      -1,   110,     9,    -1,    98,     9,    -1,   106,    -1,    92,
       9,    -1,    93,     9,    -1,    67,     5,    94,    95,     6,
      -1,    68,     5,    94,    95,     6,    -1,   121,    -1,    94,
      10,   121,    -1,    -1,    96,    -1,    10,    97,    -1,    10,
      97,    96,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    82,     5,    99,     6,    -1,   121,    -1,   121,    10,
      99,    -1,    88,     9,    -1,    88,     9,   100,    -1,    46,
       5,   120,     6,    87,    47,    -1,    43,     5,    88,     9,
     120,     9,   110,     6,    87,    44,    -1,    53,     5,   120,
       6,    57,    87,   105,    54,    -1,    53,     5,   120,     6,
      57,    87,   105,    -1,    -1,    55,    57,    87,    -1,    55,
     104,    -1,    48,     5,   120,     6,   108,   107,    49,    -1,
      -1,    52,    87,    -1,   109,    -1,   109,   108,    -1,    50,
       5,   128,     6,    12,    87,    -1,   111,    -1,   112,    -1,
     113,    -1,   114,    -1,   128,    30,   121,    -1,   128,   115,
      -1,   115,    82,    -1,   128,   118,   120,    -1,   125,    30,
     124,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,
      29,    -1,    24,    -1,    23,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    42,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,   121,    13,   121,    -1,   121,    15,   121,    -1,
     121,    -1,    -1,   128,    -1,   128,   116,   128,    -1,   128,
     117,   128,    -1,   122,    -1,     3,   123,     4,    -1,    81,
      -1,    81,    10,   123,    -1,   121,    10,   121,    -1,    82,
      10,    82,    -1,    82,    10,   125,    -1,    -1,   119,    82,
      -1,   119,    82,     7,     8,    10,   126,    -1,   119,    82,
      10,   126,    -1,    62,    82,     5,   126,     6,    64,   119,
      60,    65,    87,    61,    82,    -1,    82,    -1,    81,    -1,
      82,     7,   121,     8,    -1,     5,   121,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    58,    61,    62,    65,    66,    69,    74,
      75,    76,    79,    80,    83,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    97,   100,   103,   104,   107,   108,
     111,   112,   115,   116,   117,   118,   121,   124,   125,   128,
     129,   132,   135,   143,   146,   149,   150,   151,   154,   158,
     159,   162,   163,   166,   170,   171,   172,   173,   176,   179,
     180,   183,   186,   189,   190,   193,   194,   195,   196,   197,
     200,   201,   202,   203,   204,   205,   208,   209,   210,   211,
     212,   215,   216,   217,   218,   219,   220,   221,   227,   228,
     229,   232,   233,   234,   235,   236,   239,   242,   243,   246,
     249,   250,   253,   254,   255,   256,   259,   264,   265,   266,
     267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAVE_ESQUERDA", "CHAVE_DIREITA",
  "PARENTESE_ESQUERDA", "PARENTESE_DIREITA", "COLCHETE_ESQUERDA",
  "COLCHETE_DIREITA", "PONTO_E_VIRGULA", "VIRGULA", "PONTO", "DOIS_PONTOS",
  "E_LOGICO", "E_LOGICO_CURTO_CIRCUITO", "OU_LOGICO",
  "OU_LOGICO_CURTO_CIRCUITO", "EXCLAMACAO", "ASTERISCO", "PRINT_INT",
  "PRINT_FLOAT", "PRINT_CHAR", "PRINT_STRING", "MODULO", "BARRA",
  "INCREMENTO", "DECREMENTO", "MAIS", "MENOS_UNARIO", "EXPONENCIACAO",
  "ATRIBUICAO", "OPERADOR_TERNARIO", "MENOR_QUE", "MAIOR_QUE",
  "MENOR_OU_IGUAL_A", "MAIOR_OU_IGUAL_A", "IGUAL_A", "DIFERENTE_DE",
  "MAIS_IGUAL", "MENOS_IGUAL", "VEZES_IGUAL", "DIV_IGUAL",
  "EXPONENCIACAO_IGUAL", "FOR", "END_FOR", "DO", "WHILE", "END_WHILE",
  "SWITCH", "END_SWITCH", "CASE", "END_CASE", "DEFAULT", "IF", "END_IF",
  "ELSE", "ELSEIF", "THEN", "STRUCT", "ENDSTRUCT", "IS", "END", "FUNCAO",
  "PROC", "RETURN", "TBEGIN", "CONSTANTE", "PRINTF", "SCANF", "CARACTERE",
  "STRING", "INTEIRO", "FLOAT", "DOUBLE", "VOID", "BOOLEANO", "TRUE",
  "FALSE", "JUMP", "BREAK", "TNULL", "DIGITO", "ID", "LITERAL_QUALQUER",
  "$accept", "prog", "subprog", "stmts", "decl", "struct_list", "struct",
  "stmt", "print", "scan", "ids", "types_args", "prints_list",
  "tipos_prints", "invoca_procedimento", "parametros", "decl_list",
  "while_stmt", "for_stmt", "if_stmt", "if_stmt_in_else", "elses_opcoes",
  "switch_stmt", "default", "case_stmt", "case", "atribuicoes",
  "atribuicao_simples", "atribuicao_unaria", "atribuicao_composta",
  "atribuicao_paralela", "operador_unario", "operador", "operador_comp",
  "operador_composto", "type", "valor", "expressoes", "vetorial",
  "lista_de_digitos", "expressoes_list", "vars", "args", "funcao", "id", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    89,    89,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    98,    99,    99,   100,
     100,   101,   102,   103,   104,   105,   105,   105,   106,   107,
     107,   108,   108,   109,   110,   110,   110,   110,   111,   112,
     112,   113,   114,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   121,   121,   121,   121,   121,   122,   123,   123,   124,
     125,   125,   126,   126,   126,   126,   127,   128,   128,   128,
     128
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     2,     2,
       3,     2,     1,     2,     5,     2,     1,     1,     1,     2,
       2,     1,     2,     2,     5,     5,     1,     3,     0,     1,
       2,     3,     1,     1,     1,     1,     4,     1,     3,     2,
       3,     6,    10,     8,     7,     0,     3,     2,     7,     0,
       2,     1,     2,     6,     1,     1,     1,     1,     3,     2,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     0,     1,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     0,     2,     6,     4,    12,     1,     1,     4,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     0,    12,     4,     0,     0,
       1,     5,     3,    13,     0,   102,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,    39,    14,
      91,    63,    64,   108,   107,    11,    54,    55,    56,    57,
       0,     9,     8,   103,     0,    40,     0,   107,     0,    95,
      92,    91,     0,    60,    91,    10,    91,    76,    77,    78,
      79,    80,    59,    91,     0,   102,     0,    97,     0,   110,
      69,    68,    65,    66,    67,    70,    71,    72,    73,    74,
      75,     0,     0,     0,   100,   101,     0,    62,    58,    61,
      90,     0,   105,     0,     0,    96,    93,    94,   109,    91,
      91,    91,   102,     0,    98,    99,    88,    89,   104,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     6,
       0,     0,     0,    17,    18,    16,    21,     0,     0,     0,
       0,    91,    91,    91,    91,    91,    91,     0,    15,     7,
      22,    23,    20,    19,     0,     0,     0,     0,    28,    26,
      28,     0,    37,   106,    91,     0,     0,     0,    91,     0,
      29,     0,    36,    91,     0,     0,     0,    49,    51,     0,
      32,    33,    34,    35,    30,    27,    24,    25,    38,     0,
      41,     0,     0,     0,    52,    45,     0,    31,     0,     0,
      50,    48,     0,     0,     0,     0,     0,     0,    47,    43,
       0,     0,    91,    46,    42,    53,     0,     0,     0,    45,
      44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,   117,   118,     5,     6,   119,   120,   121,
     148,   159,   160,   174,   122,   151,    24,   123,   124,   125,
     198,   193,   126,   183,   167,   168,   127,    36,    37,    38,
      39,    40,    81,    82,    63,    25,    89,    90,    49,    68,
      87,   128,    27,     7,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -118
static const yytype_int16 yypact[] =
{
     -32,   -76,   -75,    23,   -34,   -34,   -26,  -118,   -21,    45,
    -118,  -118,   -34,  -118,     7,     7,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,    46,    -5,    17,   -23,    69,     7,  -118,
       6,  -118,  -118,  -118,    31,  -118,  -118,  -118,  -118,  -118,
      22,    -9,    85,    93,    42,  -118,    24,   105,   107,  -118,
     173,     6,    32,  -118,     6,  -118,     6,  -118,  -118,  -118,
    -118,  -118,  -118,     6,   108,     7,     7,   109,   113,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,    20,    20,   110,   111,  -118,   118,  -118,  -118,  -118,
      78,   119,  -118,    72,    24,  -118,  -118,  -118,  -118,     6,
       6,     6,     7,    68,  -118,  -118,  -118,  -118,  -118,   117,
     129,   130,   132,   133,   134,   135,    41,    80,   136,   117,
     137,   138,   139,  -118,  -118,  -118,  -118,   140,   120,    85,
       7,     6,     6,     6,     6,     6,     6,    70,  -118,  -118,
    -118,  -118,  -118,  -118,   142,   147,   152,   153,   151,  -118,
     151,   156,   154,  -118,     6,   117,   116,   114,    14,   161,
    -118,   162,  -118,     6,   164,   127,   170,   125,   116,   117,
    -118,  -118,  -118,  -118,   168,  -118,  -118,  -118,  -118,    17,
    -118,    20,   117,   131,  -118,   124,    48,  -118,   175,   176,
    -118,  -118,    -8,   141,   117,   181,   189,   117,  -118,  -118,
     159,   117,     6,  -118,  -118,  -118,   198,   155,   117,   124,
    -118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,   206,  -111,   -10,   207,  -118,  -118,  -118,  -118,
      79,    65,    43,  -118,  -118,    53,   190,  -118,  -118,  -118,
    -118,    10,  -118,  -118,    52,  -118,   -24,  -118,  -118,  -118,
    -118,   -37,  -118,  -118,  -118,   -13,  -117,   -27,  -118,   128,
    -118,   -12,   -55,     8,   -25
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    35,    26,    48,    23,    62,     8,     9,   139,    46,
      92,    30,    11,    41,   145,   146,   147,    46,    23,    30,
      11,    54,    30,    10,    83,    30,     1,    86,     2,    88,
       2,    55,     1,   170,   171,   172,   173,   164,    51,    14,
      85,    52,    31,    32,   165,   196,   136,   108,    51,   197,
      15,    52,    26,    93,    29,    28,    96,    97,   185,    43,
      16,    17,    18,    19,    20,    21,    22,   170,   171,   172,
     173,   190,   105,   106,   107,    44,    16,    17,    18,    19,
      20,    21,    22,   200,   129,   206,   203,    33,    47,    26,
     205,   100,    62,   101,   129,    33,    47,   209,    33,    34,
      64,    33,    47,    65,    53,    67,    66,   149,   149,   152,
      31,    32,    51,    69,    84,    56,    91,    95,    98,    94,
     144,    52,    30,    57,    58,    59,    60,    61,    99,   102,
     129,   175,   103,   109,   130,   131,   152,   132,   133,   134,
     135,   137,    31,    32,   129,   138,   140,   141,   142,   143,
      54,   154,   153,   155,   129,   188,   189,   129,   156,   157,
     110,   158,   162,   111,   163,   112,   166,   176,   177,   129,
     113,   169,   129,   179,   180,   181,   129,   182,   186,   192,
     191,   194,   195,   129,   114,   115,    16,    17,    18,    19,
      20,    21,    22,   201,   202,   199,    70,    71,    33,   116,
      72,    73,    74,   204,   207,    75,    76,    77,    78,    79,
      80,    12,   208,    13,   150,   161,   178,   187,    45,   210,
     184,     0,   104
};

static const yytype_int16 yycheck[] =
{
      25,    25,    15,    30,    14,    42,    82,    82,   119,     3,
      65,     5,     4,    25,   131,   132,   133,     3,    28,     5,
      12,    30,     5,     0,    51,     5,    58,    54,    62,    56,
      62,    41,    58,    19,    20,    21,    22,   154,     7,    60,
      52,    10,    25,    26,   155,    53,     5,   102,     7,    57,
       5,    10,    65,    66,    59,     9,    81,    82,   169,    82,
      69,    70,    71,    72,    73,    74,    75,    19,    20,    21,
      22,   182,    99,   100,   101,     6,    69,    70,    71,    72,
      73,    74,    75,   194,   109,   202,   197,    81,    82,   102,
     201,    13,   129,    15,   119,    81,    82,   208,    81,    82,
       7,    81,    82,    10,    82,    81,    64,   134,   135,   136,
      25,    26,     7,     6,    82,    30,     8,     4,     8,    10,
     130,    10,     5,    38,    39,    40,    41,    42,    10,    10,
     155,   158,    60,    65,     5,     5,   163,     5,     5,     5,
       5,    61,    25,    26,   169,     9,     9,     9,     9,     9,
      30,     9,    82,     6,   179,   179,   181,   182,     6,     6,
      43,    10,     6,    46,    10,    48,    50,     6,     6,   194,
      53,    57,   197,     9,    47,     5,   201,    52,    10,    55,
      49,     6,     6,   208,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    12,     5,    54,    23,    24,    81,    82,
      27,    28,    29,    44,     6,    32,    33,    34,    35,    36,
      37,     5,    57,     6,   135,   150,   163,   174,    28,   209,
     168,    -1,    94
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    62,    85,    86,    89,    90,   127,    82,    82,
       0,   127,    86,    89,    60,     5,    69,    70,    71,    72,
      73,    74,    75,    88,   100,   119,   119,   126,     9,    59,
       5,    25,    26,    81,    82,   110,   111,   112,   113,   114,
     115,   125,   128,    82,     6,   100,     3,    82,   121,   122,
     128,     7,    10,    82,    30,    88,    30,    38,    39,    40,
      41,    42,   115,   118,     7,    10,    64,    81,   123,     6,
      23,    24,    27,    28,    29,    32,    33,    34,    35,    36,
      37,   116,   117,   121,    82,   125,   121,   124,   121,   120,
     121,     8,   126,   119,    10,     4,   128,   128,     8,    10,
      13,    15,    10,    60,   123,   121,   121,   121,   126,    65,
      43,    46,    48,    53,    67,    68,    82,    87,    88,    91,
      92,    93,    98,   101,   102,   103,   106,   110,   125,   128,
       5,     5,     5,     5,     5,     5,     5,    61,     9,    87,
       9,     9,     9,     9,    88,   120,   120,   120,    94,   121,
      94,    99,   121,    82,     9,     6,     6,     6,    10,    95,
      96,    95,     6,    10,   120,    87,    50,   108,   109,    57,
      19,    20,    21,    22,    97,   121,     6,     6,    99,     9,
      47,     5,    52,   107,   108,    87,    10,    96,   110,   128,
      87,    49,    55,   105,     6,     6,    53,    57,   104,    54,
      87,    12,     5,    87,    44,    87,   120,     6,    57,    87,
     105
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 57 ".\\gauss.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 58 ".\\gauss.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 61 ".\\gauss.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 62 ".\\gauss.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 65 ".\\gauss.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 66 ".\\gauss.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 69 ".\\gauss.y"
    {
                                insert(
                                    strcat(itoa(escopo, buffer,10), (yyvsp[(2) - (2)].sStruct)),
                                    make_poiterID((yyvsp[(2) - (2)].sStruct), (yyvsp[(1) - (2)].sValue)));
                            ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 74 ".\\gauss.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 75 ".\\gauss.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 76 ".\\gauss.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 79 ".\\gauss.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 80 ".\\gauss.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 83 ".\\gauss.y"
    {;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 86 ".\\gauss.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 87 ".\\gauss.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 88 ".\\gauss.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 89 ".\\gauss.y"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 90 ".\\gauss.y"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 91 ".\\gauss.y"
    {;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 92 ".\\gauss.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 93 ".\\gauss.y"
    {;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 94 ".\\gauss.y"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 97 ".\\gauss.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 100 ".\\gauss.y"
    {;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 103 ".\\gauss.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 104 ".\\gauss.y"
    {;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 107 ".\\gauss.y"
    {;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 108 ".\\gauss.y"
    {;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 111 ".\\gauss.y"
    {;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 112 ".\\gauss.y"
    {;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 115 ".\\gauss.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 116 ".\\gauss.y"
    {;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 117 ".\\gauss.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 118 ".\\gauss.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 121 ".\\gauss.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 124 ".\\gauss.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 125 ".\\gauss.y"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 128 ".\\gauss.y"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 129 ".\\gauss.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 132 ".\\gauss.y"
    {;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 139 ".\\gauss.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 143 ".\\gauss.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 146 ".\\gauss.y"
    {;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 149 ".\\gauss.y"
    {;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 150 ".\\gauss.y"
    {;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 151 ".\\gauss.y"
    {;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 155 ".\\gauss.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 162 ".\\gauss.y"
    {;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 163 ".\\gauss.y"
    {;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 166 ".\\gauss.y"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 170 ".\\gauss.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 171 ".\\gauss.y"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 172 ".\\gauss.y"
    {;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 173 ".\\gauss.y"
    {;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 176 ".\\gauss.y"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 179 ".\\gauss.y"
    {;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 180 ".\\gauss.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 183 ".\\gauss.y"
    {;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 186 ".\\gauss.y"
    {;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 189 ".\\gauss.y"
    {;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 190 ".\\gauss.y"
    {;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 193 ".\\gauss.y"
    {;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 194 ".\\gauss.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 195 ".\\gauss.y"
    {;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 196 ".\\gauss.y"
    {;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 197 ".\\gauss.y"
    {;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 200 ".\\gauss.y"
    {;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 201 ".\\gauss.y"
    {;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 202 ".\\gauss.y"
    {;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 203 ".\\gauss.y"
    {;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 204 ".\\gauss.y"
    {;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 205 ".\\gauss.y"
    {;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 208 ".\\gauss.y"
    {;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 209 ".\\gauss.y"
    {;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 210 ".\\gauss.y"
    {;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 211 ".\\gauss.y"
    {;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 212 ".\\gauss.y"
    {;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 215 ".\\gauss.y"
    {;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 216 ".\\gauss.y"
    {;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 217 ".\\gauss.y"
    {;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 218 ".\\gauss.y"
    {;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 219 ".\\gauss.y"
    {;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 220 ".\\gauss.y"
    {;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 221 ".\\gauss.y"
    {;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 227 ".\\gauss.y"
    {;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 228 ".\\gauss.y"
    {;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 229 ".\\gauss.y"
    {;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 232 ".\\gauss.y"
    {;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 233 ".\\gauss.y"
    {;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 234 ".\\gauss.y"
    {;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 235 ".\\gauss.y"
    {;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 236 ".\\gauss.y"
    {;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 239 ".\\gauss.y"
    {;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 242 ".\\gauss.y"
    {;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 243 ".\\gauss.y"
    {;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 246 ".\\gauss.y"
    {;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 249 ".\\gauss.y"
    {;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 250 ".\\gauss.y"
    {;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 253 ".\\gauss.y"
    {(yyval.sValue) = "";}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 254 ".\\gauss.y"
    {(yyval.sValue) = strcat((yyvsp[(1) - (2)].sValue), (yyvsp[(2) - (2)].sValue));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 255 ".\\gauss.y"
    {(yyval.sValue) = '';}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 256 ".\\gauss.y"
    {(yyval.sValue) = '';}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 261 ".\\gauss.y"
    {makeValorFunc((yyvsp[(2) - (12)].sValue), (yyvsp[(7) - (12)].sValue), (yyvsp[(4) - (12)].sValue));}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 264 ".\\gauss.y"
    { (yyval.sStruct) = (yyvsp[(1) - (1)].sValue);}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 265 ".\\gauss.y"
    {(yyval.sStruct) = (yyvsp[(1) - (1)].iValue);}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 266 ".\\gauss.y"
    {;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 267 ".\\gauss.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 2401 "gauss.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 269 ".\\gauss.y"


int main (void) {
  return yyparse ( );
}

struct valor make_pointerID(char* tipo, char* nome){
    struct valor temp;
    temp.variavel->id = nome;
    temp.variavel->tipo = tipo;
    temp.variavel->escopo = itoa(escopo);
    return temp;
}

valor makeValorFunc(char *nome, char *retorno, char *tiposParams){
    struct valor temp;
    temp.funcao->id = nome;
    temp.funcao->retorno = retorno;
    temp.funcao->tiposParams = tiposParams;
    int key = 10;
    insert(key, temp);

    return NULL;
}


int yyerror (char *msg) {
  fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
  return 0;
}


