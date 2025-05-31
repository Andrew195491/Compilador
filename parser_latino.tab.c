/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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
#line 1 "parser_latino.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "AST_latino.h"

extern int yylex();
extern int num_linea;
extern FILE* yyin;
extern FILE* yyout;

void yyerror(const char* s) {
    fprintf(stderr, "[ERROR] Sintaxis invalida en linea %d: %s\n", num_linea, s);
    exit(1);
}


/* Line 189 of yacc.c  */
#line 91 "parser_latino.tab.c"

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
     MENOR = 258,
     MAYOR = 259,
     MENORIGUAL = 260,
     MAYORIGUAL = 261,
     DIFERENTE = 262,
     IGUALIGUAL = 263,
     RESTA = 264,
     SUMA = 265,
     DIVISION = 266,
     MULTI = 267,
     PARENDER = 268,
     PARENIZQ = 269,
     NUMERICO = 270,
     NUMERICODECIMAL = 271,
     IDENTIFICADOR = 272,
     CADENA = 273,
     BOOL = 274,
     CORCHETEABIERTO = 275,
     CORCHETECERRADO = 276,
     SEPARADOR = 277,
     IGUAL = 278,
     SALTO = 279,
     IF = 280,
     ELSE = 281,
     WHILE = 282,
     FOR = 283,
     PUTS = 284,
     END = 285,
     DEF = 286,
     INTERP_INI = 287,
     INTERP_FIN = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 19 "parser_latino.y"

    int enteroVal;
    float realVal;
    char* stringVal;
    struct {
        char* tipo;
        char* valor;
        char* tipoBase;
        int tam;
        int filas; // Para matrices
        int columnas; // Para matrices
        char* valores;
        char* tipoBaseReal;
        struct ast *n;
    } simbolo;



/* Line 214 of yacc.c  */
#line 179 "parser_latino.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "parser_latino.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNRULES -- Number of states.  */
#define YYNSTATES  100

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    15,    17,    20,
      22,    24,    26,    28,    32,    38,    47,    53,    62,    68,
      69,    71,    73,    77,    80,    81,    85,    87,    91,    95,
      98,   102,   104,   107,   111,   116,   118,   120,   122,   126,
     130,   134,   138,   142,   146,   150,   154,   158,   162,   166,
     168,   170,   172,   174
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    37,    -1,    -1,    24,    -1,    38,    36,
      -1,    37,    38,    24,    -1,    39,    -1,    29,    52,    -1,
      40,    -1,    41,    -1,    42,    -1,    45,    -1,    17,    23,
      52,    -1,    25,    52,    36,    37,    30,    -1,    25,    52,
      36,    37,    26,    36,    37,    30,    -1,    27,    52,    36,
      37,    30,    -1,    31,    17,    14,    43,    13,    36,    37,
      30,    -1,    31,    17,    36,    37,    30,    -1,    -1,    44,
      -1,    17,    -1,    44,    22,    17,    -1,    17,    46,    -1,
      -1,    14,    47,    13,    -1,    52,    -1,    47,    22,    52,
      -1,    20,    49,    21,    -1,    20,    21,    -1,    52,    22,
      49,    -1,    52,    -1,    17,    51,    -1,    20,    52,    21,
      -1,    51,    20,    52,    21,    -1,    53,    -1,    48,    -1,
      50,    -1,    52,    10,    52,    -1,    52,     9,    52,    -1,
      52,    12,    52,    -1,    52,    11,    52,    -1,    14,    52,
      13,    -1,    52,     8,    52,    -1,    52,     7,    52,    -1,
      52,     3,    52,    -1,    52,     4,    52,    -1,    52,     5,
      52,    -1,    52,     6,    52,    -1,    15,    -1,    16,    -1,
      18,    -1,    19,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    73,    74,    78,    88,    97,   103,   109,
     115,   121,   127,   136,   156,   163,   174,   183,   189,   200,
     201,   205,   211,   221,   230,   231,   235,   241,   250,   273,
     286,   308,   328,   337,   343,   352,   358,   367,   373,   389,
     403,   417,   436,   446,   456,   466,   476,   486,   496,   510,
     516,   522,   528,   534
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MENOR", "MAYOR", "MENORIGUAL",
  "MAYORIGUAL", "DIFERENTE", "IGUALIGUAL", "RESTA", "SUMA", "DIVISION",
  "MULTI", "PARENDER", "PARENIZQ", "NUMERICO", "NUMERICODECIMAL",
  "IDENTIFICADOR", "CADENA", "BOOL", "CORCHETEABIERTO", "CORCHETECERRADO",
  "SEPARADOR", "IGUAL", "SALTO", "IF", "ELSE", "WHILE", "FOR", "PUTS",
  "END", "DEF", "INTERP_INI", "INTERP_FIN", "$accept", "programa", "salto",
  "lista_sentencias", "sentencia", "asignacion", "if_else_end",
  "while_end", "funcion_definicion", "parametros_opt", "parametros",
  "llamada_funcion", "argumentos_opt", "argumentos", "array",
  "expresion_array", "acceso_array", "indices_array", "expresion", "valor", 0
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
     285,   286,   287,   288
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    38,
      38,    38,    38,    39,    40,    40,    41,    42,    42,    43,
      43,    44,    44,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     3,     1,     2,     1,
       1,     1,     1,     3,     5,     8,     5,     8,     5,     0,
       1,     1,     3,     2,     0,     3,     1,     3,     3,     2,
       3,     1,     2,     3,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,     0,     0,     0,     0,     0,     2,     3,     7,
       9,    10,    11,    12,     0,     0,    23,     0,    49,    50,
      53,    51,    52,     0,    36,    37,     3,    35,     3,     8,
       3,     1,     0,     4,     5,     0,    26,    13,     0,     0,
      32,    29,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     6,    25,
       0,    42,     0,     0,    28,     0,    45,    46,    47,    48,
      44,    43,    39,    38,    41,    40,     0,     0,    21,     0,
      20,     0,    27,    33,     0,    30,     3,    14,    16,     3,
       0,    18,    34,     0,     0,    22,     0,     0,    15,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,    34,     7,     8,     9,    10,    11,    12,    79,
      80,    13,    16,    35,    24,    42,    25,    40,    43,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -32
static const yytype_int16 yypact[] =
{
     140,   -10,   179,   179,   179,   -11,    21,   140,     1,   -32,
     -32,   -32,   -32,   -32,   179,   179,   -32,   179,   -32,   -32,
      22,   -32,   -32,    91,   -32,   -32,    24,   -32,    24,   180,
      23,   -32,    19,   -32,   -32,   114,   180,   180,   169,   179,
      25,   -32,    38,    72,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   140,   140,    43,   140,   -32,   -32,
     179,   -32,    92,   179,   -32,   179,    29,    29,    29,    29,
      29,    29,     6,     6,   -32,   -32,   -15,   108,   -32,    33,
      44,   117,   180,   -32,   111,   -32,     1,   -32,   -32,     1,
      50,   -32,   -32,   140,   140,   -32,   124,   133,   -32,   -32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -25,   -31,    -7,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,     7,   -32,   -32,     5,   -32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      32,    54,     1,    55,    14,    57,    30,    26,    28,    29,
       2,    86,     3,    15,     4,    87,     5,    52,    53,    36,
      37,    31,    38,    76,    77,    33,    81,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    56,    50,    51,
      52,    53,    39,    58,    62,    63,    89,    33,    33,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    64,
      78,    93,    96,    97,    94,    82,    90,    95,    84,    32,
      32,     0,    85,     0,    32,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,    32,
      32,     0,     0,     0,    65,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    17,    18,    19,    20,    21,
      22,    23,    41,    83,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     1,     0,    59,     0,     0,
       0,     0,    92,     2,     1,     3,    60,     4,    88,     5,
       0,     1,     2,     0,     3,     0,     4,    91,     5,     2,
       1,     3,     0,     4,    98,     5,     0,     1,     2,     0,
       3,     0,     4,    99,     5,     2,     0,     3,     0,     4,
       0,     5,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    61,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    17,    18,    19,    20,    21,    22,    23
};

static const yytype_int8 yycheck[] =
{
       7,    26,    17,    28,    14,    30,    17,     2,     3,     4,
      25,    26,    27,    23,    29,    30,    31,    11,    12,    14,
      15,     0,    17,    54,    55,    24,    57,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    14,     9,    10,
      11,    12,    20,    24,    39,    20,    13,    24,    24,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    21,
      17,    86,    93,    94,    89,    60,    22,    17,    63,    76,
      77,    -1,    65,    -1,    81,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    96,
      97,    -1,    -1,    -1,    22,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    14,    15,    16,    17,    18,
      19,    20,    21,    21,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    17,    -1,    13,    -1,    -1,
      -1,    -1,    21,    25,    17,    27,    22,    29,    30,    31,
      -1,    17,    25,    -1,    27,    -1,    29,    30,    31,    25,
      17,    27,    -1,    29,    30,    31,    -1,    17,    25,    -1,
      27,    -1,    29,    30,    31,    25,    -1,    27,    -1,    29,
      -1,    31,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    14,    15,    16,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    25,    27,    29,    31,    35,    37,    38,    39,
      40,    41,    42,    45,    14,    23,    46,    14,    15,    16,
      17,    18,    19,    20,    48,    50,    52,    53,    52,    52,
      17,     0,    38,    24,    36,    47,    52,    52,    52,    20,
      51,    21,    49,    52,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    36,    36,    14,    36,    24,    13,
      22,    13,    52,    20,    21,    22,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    37,    37,    17,    43,
      44,    37,    52,    21,    52,    49,    26,    30,    30,    13,
      22,    30,    21,    36,    36,    17,    37,    37,    30,    30
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

/* Line 1464 of yacc.c  */
#line 66 "parser_latino.y"
    {
        printf("Llamando a recorrerAST\n");
        generarASM((yyvsp[(1) - (1)].simbolo).n);
        liberarAST((yyvsp[(1) - (1)].simbolo).n);
    ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 78 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (2)].simbolo).tipo);
        if ((yyvsp[(1) - (2)].simbolo).valor != NULL) {
            (yyval.simbolo).valor = strdup((yyvsp[(1) - (2)].simbolo).valor);
        } else {
            (yyval.simbolo).valor = NULL;
        }
        (yyval.simbolo).n = (yyvsp[(1) - (2)].simbolo).n;
        free((yyvsp[(1) - (2)].simbolo).tipo); free((yyvsp[(1) - (2)].simbolo).valor);
    ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 88 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(1) - (3)].simbolo).n, (yyvsp[(2) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);
    ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 97 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 103 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("puts");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoPuts((yyvsp[(2) - (2)].simbolo).n);
        free((yyvsp[(2) - (2)].simbolo).tipo); free((yyvsp[(2) - (2)].simbolo).valor);
    ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 109 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("if_else");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 115 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("while");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 121 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("funcion_definicion");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 127 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("llamada_funcion");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 136 "parser_latino.y"
    {
        (yyvsp[(3) - (3)].simbolo).n->es_inicializada = 1;
        if ((yyvsp[(3) - (3)].simbolo).tipo && strcmp((yyvsp[(3) - (3)].simbolo).tipo, "matriz") == 0) {
            // Si tienes forma de calcular filas/columnas, ponlo aquí. Si no, déjalo en 0.
            guardar_simbolo_matriz((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipoBase, (yyvsp[(3) - (3)].simbolo).filas, (yyvsp[(3) - (3)].simbolo).columnas, (yyvsp[(3) - (3)].simbolo).valores ? (yyvsp[(3) - (3)].simbolo).valores : "NULL");
        } else if ((yyvsp[(3) - (3)].simbolo).tipo && strcmp((yyvsp[(3) - (3)].simbolo).tipo, "array") == 0) {
            guardar_simbolo_array((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipoBase, (yyvsp[(3) - (3)].simbolo).tam, (yyvsp[(3) - (3)].simbolo).valores);
        } else {
            guardar_simbolo((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).valor);
        }
        (yyval.simbolo).tipo = strdup("asignacion");
        (yyval.simbolo).valor = NULL;
        (yyvsp[(3) - (3)].simbolo).n->es_inicializada = 1;
        (yyval.simbolo).n = crearNodoAsignacion((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].simbolo).n);
        mostrar_tabla();
        free((yyvsp[(1) - (3)].stringVal)); free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).valor);
        free((yyvsp[(3) - (3)].simbolo).tipoBase); free((yyvsp[(3) - (3)].simbolo).valores);
    ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 156 "parser_latino.y"
    {
        // if sin else
        (yyval.simbolo).tipo = strdup("if");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoIf((yyvsp[(2) - (5)].simbolo).n, (yyvsp[(4) - (5)].simbolo).n, NULL);
        free((yyvsp[(2) - (5)].simbolo).tipo); free((yyvsp[(2) - (5)].simbolo).valor); free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 163 "parser_latino.y"
    {
        // if con else
        (yyval.simbolo).tipo = strdup("if_else");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoIf((yyvsp[(2) - (8)].simbolo).n, (yyvsp[(4) - (8)].simbolo).n, (yyvsp[(7) - (8)].simbolo).n);
        free((yyvsp[(2) - (8)].simbolo).tipo); free((yyvsp[(2) - (8)].simbolo).valor); free((yyvsp[(4) - (8)].simbolo).tipo); free((yyvsp[(4) - (8)].simbolo).valor); free((yyvsp[(7) - (8)].simbolo).tipo); free((yyvsp[(7) - (8)].simbolo).valor);
    ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 174 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("while");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoWhile((yyvsp[(2) - (5)].simbolo).n, (yyvsp[(4) - (5)].simbolo).n);
        free((yyvsp[(2) - (5)].simbolo).tipo); free((yyvsp[(2) - (5)].simbolo).valor); free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 183 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("funcion");
        (yyval.simbolo).valor = strdup((yyvsp[(2) - (8)].stringVal));
        (yyval.simbolo).n = crearNodoFuncion((yyvsp[(2) - (8)].stringVal), (yyvsp[(4) - (8)].simbolo).n, (yyvsp[(7) - (8)].simbolo).n); // nombre, parámetros, cuerpo
        free((yyvsp[(2) - (8)].stringVal)); free((yyvsp[(4) - (8)].simbolo).tipo); free((yyvsp[(4) - (8)].simbolo).valor); free((yyvsp[(7) - (8)].simbolo).tipo); free((yyvsp[(7) - (8)].simbolo).valor);
    ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 189 "parser_latino.y"
    {
        // Definición sin paréntesis ni parámetros
        (yyval.simbolo).tipo = strdup("funcion");
        (yyval.simbolo).valor = strdup((yyvsp[(2) - (5)].stringVal));
        (yyval.simbolo).n = crearNodoFuncion((yyvsp[(2) - (5)].stringVal), NULL, (yyvsp[(4) - (5)].simbolo).n);
        free((yyvsp[(2) - (5)].stringVal)); free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 200 "parser_latino.y"
    { (yyval.simbolo).tipo = strdup("parametros"); (yyval.simbolo).valor = NULL; (yyval.simbolo).n = NULL; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 205 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("parametros");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoParametro((yyvsp[(1) - (1)].stringVal), NULL);
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 211 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("parametros");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoParametro((yyvsp[(3) - (3)].stringVal), (yyvsp[(1) - (3)].simbolo).n);
        free((yyvsp[(3) - (3)].stringVal));
    ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 221 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("llamada_funcion");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (2)].stringVal));
        (yyval.simbolo).n = crearNodoLlamadaFuncion((yyvsp[(1) - (2)].stringVal), (yyvsp[(2) - (2)].simbolo).n);
        free((yyvsp[(1) - (2)].stringVal)); free((yyvsp[(2) - (2)].simbolo).tipo); free((yyvsp[(2) - (2)].simbolo).valor);
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 230 "parser_latino.y"
    { (yyval.simbolo).tipo = strdup("argumentos"); (yyval.simbolo).valor = NULL; (yyval.simbolo).n = NULL; ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 231 "parser_latino.y"
    { (yyval.simbolo).tipo = strdup("argumentos"); (yyval.simbolo).valor = NULL; (yyval.simbolo).n = (yyvsp[(2) - (3)].simbolo).n; free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 235 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("argumentos");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoArgumento((yyvsp[(1) - (1)].simbolo).n, NULL);
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 241 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("argumentos");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoArgumento((yyvsp[(3) - (3)].simbolo).n, (yyvsp[(1) - (3)].simbolo).n);
        free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 250 "parser_latino.y"
    {
        if ((yyvsp[(2) - (3)].simbolo).tipoBase && strcmp((yyvsp[(2) - (3)].simbolo).tipoBase, "array") == 0) {
            (yyval.simbolo).tipo = strdup("matriz");
            // Tipo base real: el tipo base del primer subarray
            // Suponemos que $2.valores tiene los valores linealizados y $2.n guarda la estructura
            // Aquí asumimos que guardaste filas y columnas en $2.filas y $2.columnas
            (yyval.simbolo).tipoBase = (yyvsp[(2) - (3)].simbolo).tipoBaseReal ? strdup((yyvsp[(2) - (3)].simbolo).tipoBaseReal) : strdup("int");
            (yyval.simbolo).tam = (yyvsp[(2) - (3)].simbolo).tam;
            (yyval.simbolo).filas = (yyvsp[(2) - (3)].simbolo).filas;
            (yyval.simbolo).columnas = (yyvsp[(2) - (3)].simbolo).columnas;
        } else {
            (yyval.simbolo).tipo = strdup("array");
            (yyval.simbolo).tipoBase = strdup((yyvsp[(2) - (3)].simbolo).tipoBase);
            (yyval.simbolo).tam = (yyvsp[(2) - (3)].simbolo).tam;
            (yyval.simbolo).filas = 0;
            (yyval.simbolo).columnas = 0;
        }
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).valores = strdup((yyvsp[(2) - (3)].simbolo).valores);
        (yyval.simbolo).n = (yyvsp[(2) - (3)].simbolo).n;
        free((yyvsp[(2) - (3)].simbolo).tipoBase); free((yyvsp[(2) - (3)].simbolo).valores);
        if ((yyvsp[(2) - (3)].simbolo).tipoBaseReal) free((yyvsp[(2) - (3)].simbolo).tipoBaseReal);
    ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 273 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("array");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).tipoBase = strdup("int");
        (yyval.simbolo).tam = 0;
        (yyval.simbolo).filas = 0;
        (yyval.simbolo).columnas = 0;
        (yyval.simbolo).valores = strdup("");
        (yyval.simbolo).n = NULL;
    ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 286 "parser_latino.y"
    {
        if ((yyvsp[(1) - (3)].simbolo).tipo && strcmp((yyvsp[(1) - (3)].simbolo).tipo, "array") == 0) {
            (yyval.simbolo).tipoBase = strdup((yyvsp[(1) - (3)].simbolo).tipo);
            (yyval.simbolo).tam = (yyvsp[(3) - (3)].simbolo).tam + 1;
            (yyval.simbolo).valores = malloc(strlen((yyvsp[(1) - (3)].simbolo).valores) + strlen((yyvsp[(3) - (3)].simbolo).valores) + 2);
            sprintf((yyval.simbolo).valores, "%s %s", (yyvsp[(1) - (3)].simbolo).valores, (yyvsp[(3) - (3)].simbolo).valores);
            // Para matriz: filas = $3.filas + 1, columnas = columnas del primer subarray
            (yyval.simbolo).filas = (yyvsp[(3) - (3)].simbolo).filas + 1;
            (yyval.simbolo).columnas = (yyvsp[(1) - (3)].simbolo).tam; // Suponiendo que todos los subarrays tienen el mismo tamaño
            (yyval.simbolo).tipoBaseReal = (yyvsp[(1) - (3)].simbolo).tipoBase ? strdup((yyvsp[(1) - (3)].simbolo).tipoBase) : strdup("int");
        } else {
            (yyval.simbolo).tipoBase = strdup((yyvsp[(1) - (3)].simbolo).tipo);
            (yyval.simbolo).tam = (yyvsp[(3) - (3)].simbolo).tam + 1;
            (yyval.simbolo).valores = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor) + strlen((yyvsp[(3) - (3)].simbolo).valores) + 2);
            sprintf((yyval.simbolo).valores, "%s %s", (yyvsp[(1) - (3)].simbolo).valor, (yyvsp[(3) - (3)].simbolo).valores);
            (yyval.simbolo).filas = 0;
            (yyval.simbolo).columnas = 0;
            (yyval.simbolo).tipoBaseReal = NULL;
        }
        (yyval.simbolo).n = crearNodoArray((yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(1) - (3)].simbolo).valores); free((yyvsp[(1) - (3)].simbolo).tipoBase); free((yyvsp[(3) - (3)].simbolo).tipoBase); free((yyvsp[(3) - (3)].simbolo).valores); if ((yyvsp[(3) - (3)].simbolo).tipoBaseReal) free((yyvsp[(3) - (3)].simbolo).tipoBaseReal);
    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 308 "parser_latino.y"
    {
        (yyval.simbolo).tipoBase = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).tam = 1;
        if ((yyvsp[(1) - (1)].simbolo).tipo && strcmp((yyvsp[(1) - (1)].simbolo).tipo, "array") == 0) {
            (yyval.simbolo).valores = strdup((yyvsp[(1) - (1)].simbolo).valores);
            (yyval.simbolo).filas = 1;
            (yyval.simbolo).columnas = (yyvsp[(1) - (1)].simbolo).tam;
            (yyval.simbolo).tipoBaseReal = (yyvsp[(1) - (1)].simbolo).tipoBase ? strdup((yyvsp[(1) - (1)].simbolo).tipoBase) : strdup("int");
        } else {
            (yyval.simbolo).valores = strdup((yyvsp[(1) - (1)].simbolo).valor);
            (yyval.simbolo).filas = 0;
            (yyval.simbolo).columnas = 0;
            (yyval.simbolo).tipoBaseReal = NULL;
        }
        (yyval.simbolo).n = crearNodoArray((yyvsp[(1) - (1)].simbolo).n, NULL);
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor); if ((yyvsp[(1) - (1)].simbolo).tipoBase) free((yyvsp[(1) - (1)].simbolo).tipoBase);
    ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 328 "parser_latino.y"
    {
        //$$.tipo = strdup("acceso_array");
        //$$.valor = NULL;
        //$$.n = crearNodoAccesoArray($1, $2.n);
        //free($1); free($2.tipo); free($2.valor);
    ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 337 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(2) - (3)].simbolo).n, NULL);
        free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);
    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 343 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(1) - (4)].simbolo).n, (yyvsp[(3) - (4)].simbolo).n);
        free((yyvsp[(1) - (4)].simbolo).tipo); free((yyvsp[(1) - (4)].simbolo).valor); free((yyvsp[(3) - (4)].simbolo).tipo); free((yyvsp[(3) - (4)].simbolo).valor);
    ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 352 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].simbolo).valor);
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 358 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo); // <-- Propaga "array" o "matriz"
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).tipoBase = (yyvsp[(1) - (1)].simbolo).tipoBase ? strdup((yyvsp[(1) - (1)].simbolo).tipoBase) : NULL;
        (yyval.simbolo).tam = (yyvsp[(1) - (1)].simbolo).tam;
        (yyval.simbolo).valores = (yyvsp[(1) - (1)].simbolo).valores ? strdup((yyvsp[(1) - (1)].simbolo).valores) : strdup(""); // <-- Cambia esto
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 367 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("acceso_array");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 373 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
        // SIEMPRE guarda la expresión textual, no el resultado
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s+%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_SUMA, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 389 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
         if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_RESTA, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 403 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
         if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_MULT, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 417 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
         if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
            exit(1);
        }
        if ((strcmp((yyvsp[(3) - (3)].simbolo).tipo, "int") == 0 && (yyvsp[(3) - (3)].simbolo).n && (yyvsp[(3) - (3)].simbolo).n->valor_int == 0) ||
            (strcmp((yyvsp[(3) - (3)].simbolo).tipo, "float") == 0 && (yyvsp[(3) - (3)].simbolo).n && (yyvsp[(3) - (3)].simbolo).n->valor_float == 0.0)) {
            fprintf(stderr, "[ERROR] Division por cero (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_DIV, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 436 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(2) - (3)].simbolo).tipo);
        if ((yyvsp[(2) - (3)].simbolo).valor != NULL) {
            (yyval.simbolo).valor = strdup((yyvsp[(2) - (3)].simbolo).valor);
        } else {
            (yyval.simbolo).valor = NULL;
        }
        (yyval.simbolo).n = (yyvsp[(2) - (3)].simbolo).n;
        free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);
    ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 446 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_IGUALIGUAL, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 456 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_DIFERENTE, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 466 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_MENOR, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 476 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_MAYOR, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 486 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_MENORIGUAL, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 496 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoOperacion(NODO_MAYORIGUAL, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 510 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("int");
        (yyval.simbolo).valor = malloc(12);
        sprintf((yyval.simbolo).valor, "%d", (yyvsp[(1) - (1)].enteroVal));
        (yyval.simbolo).n = crearNodoNumero((yyvsp[(1) - (1)].enteroVal));
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 516 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("float");
        (yyval.simbolo).valor = malloc(32);
        sprintf((yyval.simbolo).valor, "%.2f", (yyvsp[(1) - (1)].realVal));
        (yyval.simbolo).n = crearNodoFloat((yyvsp[(1) - (1)].realVal));
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 522 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("string");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].stringVal));
        (yyval.simbolo).n = crearNodoString((yyvsp[(1) - (1)].stringVal));
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 528 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].stringVal));
        (yyval.simbolo).n = crearNodoBool((yyvsp[(1) - (1)].stringVal));
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 534 "parser_latino.y"
    {
        int pos = buscarTabla((yyvsp[(1) - (1)].stringVal));
        if (pos == -1){
            fprintf(stderr, "ERROR, LA VARIABLE  '%s' NO ESTA DECLARADA EN (linea %d)\n", (yyvsp[(1) - (1)].stringVal), num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup(tabla[pos].tipo);
        // Si es array o matriz, usa sus valores linealizados
        if (tabla[pos].tipo && (strcmp(tabla[pos].tipo, "array") == 0 || strcmp(tabla[pos].tipo, "matriz") == 0)) {
            (yyval.simbolo).valor = tabla[pos].Valores ? strdup(tabla[pos].Valores) : strdup("");
        } else {
            (yyval.simbolo).valor = tabla[pos].valor ? strdup(tabla[pos].valor) : strdup("");
        }
        (yyval.simbolo).n = crearNodoVariable((yyvsp[(1) - (1)].stringVal));
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;



/* Line 1464 of yacc.c  */
#line 2214 "parser_latino.tab.c"
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



/* Line 1684 of yacc.c  */
#line 552 "parser_latino.y"


int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    }
    yyout = fopen("output.asm", "w");
    if (!yyout) {
        perror("output.asm");
        return 1;
    }
    printf("Analizando...\n");
    yyparse();
    fclose(yyout);
    return 0;
}

