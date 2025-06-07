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
     AND = 258,
     OR = 259,
     NOT = 260,
     MENOR = 261,
     MAYOR = 262,
     MENORIGUAL = 263,
     MAYORIGUAL = 264,
     DIFERENTE = 265,
     IGUALIGUAL = 266,
     RESTA = 267,
     SUMA = 268,
     DIVISION = 269,
     MULTI = 270,
     PARENDER = 271,
     PARENIZQ = 272,
     NUMERICO = 273,
     NUMERICODECIMAL = 274,
     IDENTIFICADOR = 275,
     CADENA = 276,
     BOOL = 277,
     CORCHETEABIERTO = 278,
     CORCHETECERRADO = 279,
     SEPARADOR = 280,
     IGUAL = 281,
     SALTO = 282,
     IF = 283,
     ELSE = 284,
     WHILE = 285,
     FOR = 286,
     PUTS = 287,
     END = 288,
     DEF = 289,
     INTERP_INI = 290,
     INTERP_FIN = 291,
     COMENTARIOLINEA = 292
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
#line 183 "parser_latino.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "parser_latino.tab.c"

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    16,    18,    21,
      23,    25,    27,    29,    31,    35,    41,    50,    56,    65,
      71,    72,    74,    76,    80,    83,    84,    88,    90,    94,
      98,   101,   105,   107,   110,   114,   119,   121,   123,   125,
     129,   133,   137,   141,   145,   149,   153,   157,   161,   165,
     169,   173,   177,   180,   182,   185,   187,   190,   192,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    41,    -1,    -1,    27,    40,    -1,    42,
      40,    -1,    41,    42,    40,    -1,    43,    -1,    32,    56,
      -1,    44,    -1,    45,    -1,    46,    -1,    49,    -1,    37,
      -1,    20,    26,    56,    -1,    28,    56,    40,    41,    33,
      -1,    28,    56,    40,    41,    29,    40,    41,    33,    -1,
      30,    56,    40,    41,    33,    -1,    34,    20,    17,    47,
      16,    40,    41,    33,    -1,    34,    20,    40,    41,    33,
      -1,    -1,    48,    -1,    20,    -1,    48,    25,    20,    -1,
      20,    50,    -1,    -1,    17,    51,    16,    -1,    56,    -1,
      51,    25,    56,    -1,    23,    53,    24,    -1,    23,    24,
      -1,    56,    25,    53,    -1,    56,    -1,    20,    55,    -1,
      23,    56,    24,    -1,    55,    23,    56,    24,    -1,    57,
      -1,    52,    -1,    54,    -1,    56,    13,    56,    -1,    56,
      12,    56,    -1,    56,    15,    56,    -1,    56,    14,    56,
      -1,    17,    56,    16,    -1,    56,    11,    56,    -1,    56,
      10,    56,    -1,    56,     6,    56,    -1,    56,     7,    56,
      -1,    56,     8,    56,    -1,    56,     9,    56,    -1,    56,
       3,    56,    -1,    56,     4,    56,    -1,     5,    56,    -1,
      18,    -1,    12,    18,    -1,    19,    -1,    12,    19,    -1,
      21,    -1,    22,    -1,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    77,    78,    82,    92,   102,   108,   114,
     120,   126,   132,   138,   147,   188,   210,   238,   247,   253,
     264,   265,   269,   275,   285,   294,   295,   299,   305,   314,
     337,   350,   372,   392,   401,   407,   416,   422,   431,   437,
     475,   490,   505,   526,   536,   543,   550,   565,   580,   595,
     610,   631,   653,   678,   684,   691,   697,   704,   710,   716
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "NOT", "MENOR", "MAYOR",
  "MENORIGUAL", "MAYORIGUAL", "DIFERENTE", "IGUALIGUAL", "RESTA", "SUMA",
  "DIVISION", "MULTI", "PARENDER", "PARENIZQ", "NUMERICO",
  "NUMERICODECIMAL", "IDENTIFICADOR", "CADENA", "BOOL", "CORCHETEABIERTO",
  "CORCHETECERRADO", "SEPARADOR", "IGUAL", "SALTO", "IF", "ELSE", "WHILE",
  "FOR", "PUTS", "END", "DEF", "INTERP_INI", "INTERP_FIN",
  "COMENTARIOLINEA", "$accept", "programa", "salto", "lista_sentencias",
  "sentencia", "asignacion", "if_else_end", "while_end",
  "funcion_definicion", "parametros_opt", "parametros", "llamada_funcion",
  "argumentos_opt", "argumentos", "array", "expresion_array",
  "acceso_array", "indices_array", "expresion", "valor", 0
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    43,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    57,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     3,     5,     8,     5,     8,     5,
       0,     1,     1,     3,     2,     0,     3,     1,     3,     3,
       2,     3,     1,     2,     3,     4,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     2,     1,     2,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,     0,     0,     0,     0,    13,     0,     2,     3,
       7,     9,    10,    11,    12,     0,     0,    24,     0,     0,
       0,    53,    55,    59,    57,    58,     0,    37,    38,     3,
      36,     3,     8,     3,     1,     3,     3,     5,     0,    27,
      14,    52,    54,    56,     0,     0,    33,    30,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     6,     4,    26,     0,
      43,     0,     0,    29,     0,    50,    51,    46,    47,    48,
      49,    45,    44,    40,    39,    42,    41,     0,     0,    22,
       0,    21,     0,    28,    34,     0,    31,     3,    15,    17,
       3,     0,    19,    35,     0,     0,    23,     0,     0,    16,
      18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,    37,     8,     9,    10,    11,    12,    13,    90,
      91,    14,    17,    38,    27,    48,    28,    46,    49,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int16 yypact[] =
{
     204,   -13,   153,   153,   153,   -14,   -48,    11,   204,   -10,
     -48,   -48,   -48,   -48,   -48,   153,   153,   -48,   153,    -9,
     153,   -48,   -48,    -2,   -48,   -48,    43,   -48,   -48,    16,
     -48,    16,   250,   -15,   -48,   -10,   -10,   -48,    17,   250,
     250,   260,   -48,   -48,   236,   153,     9,   -48,    23,   103,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   204,   204,    -6,   204,   -48,   -48,   -48,   153,
     -48,   123,   153,   -48,   153,   260,   260,    22,    22,    22,
      22,    22,    22,    30,    30,   -48,   -48,   149,   160,   -48,
      25,    21,   171,   250,   -48,   142,   -48,   -10,   -48,   -48,
     -10,    29,   -48,   -48,   204,   204,   -48,   182,   193,   -48,
     -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -28,   -47,    -8,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -24,   -48,   -48,    36,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,    62,    64,    63,    15,    65,    33,    66,    67,    42,
      43,    34,    36,    16,    89,    87,    88,    36,    92,    50,
      51,    45,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    72,    68,    58,    59,    60,    61,    29,    31,
      32,   100,    69,    36,    60,    61,   101,    73,    18,   106,
      96,    39,    40,     0,    41,    19,    44,   107,   108,     0,
      20,    21,    22,    23,    24,    25,    26,    47,     0,   104,
       0,     0,   105,     0,     0,     0,     0,     0,     0,    35,
      35,    71,     0,     0,    35,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,    35,
      35,     0,     0,     0,     0,    93,    50,    51,    95,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    74,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,     0,     0,    50,    51,    94,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    18,     0,
       0,     0,     0,     0,     0,    19,   103,     0,     0,     1,
      20,    21,    22,    23,    24,    25,    26,     2,    97,     3,
       1,     4,    98,     5,     0,     0,     6,     0,     2,     0,
       3,     1,     4,    99,     5,     0,     0,     6,     0,     2,
       0,     3,     1,     4,   102,     5,     0,     0,     6,     0,
       2,     0,     3,     1,     4,   109,     5,     0,     0,     6,
       0,     2,     0,     3,     1,     4,   110,     5,     0,     0,
       6,     0,     2,     0,     3,     0,     4,     0,     5,    50,
      51,     6,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    70,    50,    51,     0,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61
};

static const yytype_int8 yycheck[] =
{
       8,    29,    17,    31,    17,    33,    20,    35,    36,    18,
      19,     0,    27,    26,    20,    62,    63,    27,    65,     3,
       4,    23,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    23,    16,    12,    13,    14,    15,     2,     3,
       4,    16,    25,    27,    14,    15,    25,    24,     5,    20,
      74,    15,    16,    -1,    18,    12,    20,   104,   105,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    97,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    45,    -1,    -1,    92,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,   107,
     108,    -1,    -1,    -1,    -1,    69,     3,     4,    72,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    25,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    24,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    24,    -1,    -1,    20,
      17,    18,    19,    20,    21,    22,    23,    28,    29,    30,
      20,    32,    33,    34,    -1,    -1,    37,    -1,    28,    -1,
      30,    20,    32,    33,    34,    -1,    -1,    37,    -1,    28,
      -1,    30,    20,    32,    33,    34,    -1,    -1,    37,    -1,
      28,    -1,    30,    20,    32,    33,    34,    -1,    -1,    37,
      -1,    28,    -1,    30,    20,    32,    33,    34,    -1,    -1,
      37,    -1,    28,    -1,    30,    -1,    32,    -1,    34,     3,
       4,    37,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    28,    30,    32,    34,    37,    39,    41,    42,
      43,    44,    45,    46,    49,    17,    26,    50,     5,    12,
      17,    18,    19,    20,    21,    22,    23,    52,    54,    56,
      57,    56,    56,    20,     0,    42,    27,    40,    51,    56,
      56,    56,    18,    19,    56,    23,    55,    24,    53,    56,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    40,    40,    17,    40,    40,    40,    16,    25,
      16,    56,    23,    24,    25,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    41,    41,    20,
      47,    48,    41,    56,    24,    56,    53,    29,    33,    33,
      16,    25,    33,    24,    40,    40,    20,    41,    41,    33,
      33
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
#line 70 "parser_latino.y"
    {
        printf("Llamando a recorrerAST\n");
        generarASM((yyvsp[(1) - (1)].simbolo).n);
        liberarAST((yyvsp[(1) - (1)].simbolo).n);
    ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 82 "parser_latino.y"
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
#line 92 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(1) - (3)].simbolo).n, (yyvsp[(2) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);
    ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 102 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 108 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("puts");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoPuts((yyvsp[(2) - (2)].simbolo).n);
        free((yyvsp[(2) - (2)].simbolo).tipo); free((yyvsp[(2) - (2)].simbolo).valor);
    ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 114 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("if_else");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 120 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("while");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 126 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("funcion_definicion");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 132 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("llamada_funcion");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 138 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("comentario_linea");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = NULL; 
        printf("Comentario de línea\n");
    ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 147 "parser_latino.y"
    {
        int pos = buscarTabla((yyvsp[(1) - (3)].stringVal));
        (yyvsp[(3) - (3)].simbolo).n->es_inicializada = 1;

        if ((yyvsp[(3) - (3)].simbolo).tipo && strcmp((yyvsp[(3) - (3)].simbolo).tipo, "matriz") == 0) {
            guardar_simbolo_matriz((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipoBase, (yyvsp[(3) - (3)].simbolo).filas, (yyvsp[(3) - (3)].simbolo).columnas, (yyvsp[(3) - (3)].simbolo).valores ? (yyvsp[(3) - (3)].simbolo).valores : "NULL");
        } else if ((yyvsp[(3) - (3)].simbolo).tipo && strcmp((yyvsp[(3) - (3)].simbolo).tipo, "array") == 0) {
            guardar_simbolo_array((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipoBase, (yyvsp[(3) - (3)].simbolo).tam, (yyvsp[(3) - (3)].simbolo).valores);
        } else {
            guardar_simbolo((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).valor);
        }

        // Comprobación de tipos incompatibles
        const char* tipoNodo = NULL;
        switch ((yyvsp[(3) - (3)].simbolo).n->tipoNodo) {
            case NODO_NUMERO: tipoNodo = "int"; break;
            case NODO_FLOAT:  tipoNodo = "float"; break;
            case NODO_STRING: tipoNodo = "string"; break;
            case NODO_BOOL:   tipoNodo = "bool"; break;
            default: tipoNodo = "otro"; break;
        }

        if (tabla[pos].tipo && tipoNodo && strcmp(tabla[pos].tipo, tipoNodo) != 0) {
            fprintf(stderr,
                    "[ERROR] No puedes asignar un valor de tipo '%s' a la variable '%s' que es de tipo '%s' (línea %d)\n",
                    tipoNodo, tabla[pos].nombre, tabla[pos].tipo, num_linea);
            exit(1);
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

  case 15:

/* Line 1464 of yacc.c  */
#line 188 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("if");
        (yyval.simbolo).valor = NULL;

        struct ast* nodo = malloc(sizeof(struct ast));
        nodo->tipoNodo = NODO_IF;
        nodo->izq = (yyvsp[(2) - (5)].simbolo).n;

        // Construir el else vacío manualmente como lista vacía (para mantener la estructura)
        struct ast* nodoLista = malloc(sizeof(struct ast));
        nodoLista->tipoNodo = NODO_LISTA;
        nodoLista->izq = (yyvsp[(4) - (5)].simbolo).n;
        nodoLista->dcha = NULL;

        nodo->dcha = nodoLista;
        nodo->nombre = NULL;

        (yyval.simbolo).n = nodo;

        free((yyvsp[(2) - (5)].simbolo).tipo); free((yyvsp[(2) - (5)].simbolo).valor);
        free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 210 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("if_else");
        (yyval.simbolo).valor = NULL;

        struct ast* nodo = malloc(sizeof(struct ast));
        nodo->tipoNodo = NODO_IF;
        nodo->izq = (yyvsp[(2) - (8)].simbolo).n;

        // Construimos manualmente la lista con THEN y ELSE
        struct ast* nodoLista = malloc(sizeof(struct ast));
        nodoLista->tipoNodo = NODO_LISTA;
        nodoLista->izq = (yyvsp[(4) - (8)].simbolo).n;     // cuerpo THEN
        nodoLista->dcha = (yyvsp[(7) - (8)].simbolo).n;    // cuerpo ELSE

        nodo->dcha = nodoLista;
        nodo->nombre = NULL;

        (yyval.simbolo).n = nodo;

        free((yyvsp[(2) - (8)].simbolo).tipo); free((yyvsp[(2) - (8)].simbolo).valor);
        free((yyvsp[(4) - (8)].simbolo).tipo); free((yyvsp[(4) - (8)].simbolo).valor);
        free((yyvsp[(7) - (8)].simbolo).tipo); free((yyvsp[(7) - (8)].simbolo).valor);
    ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 238 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("while");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoWhile((yyvsp[(2) - (5)].simbolo).n, (yyvsp[(4) - (5)].simbolo).n);
        free((yyvsp[(2) - (5)].simbolo).tipo); free((yyvsp[(2) - (5)].simbolo).valor); free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 247 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("funcion");
        (yyval.simbolo).valor = strdup((yyvsp[(2) - (8)].stringVal));
        (yyval.simbolo).n = crearNodoFuncion((yyvsp[(2) - (8)].stringVal), (yyvsp[(4) - (8)].simbolo).n, (yyvsp[(7) - (8)].simbolo).n); // nombre, parámetros, cuerpo
        free((yyvsp[(2) - (8)].stringVal)); free((yyvsp[(4) - (8)].simbolo).tipo); free((yyvsp[(4) - (8)].simbolo).valor); free((yyvsp[(7) - (8)].simbolo).tipo); free((yyvsp[(7) - (8)].simbolo).valor);
    ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 253 "parser_latino.y"
    {
        // Definición sin paréntesis ni parámetros
        (yyval.simbolo).tipo = strdup("funcion");
        (yyval.simbolo).valor = strdup((yyvsp[(2) - (5)].stringVal));
        (yyval.simbolo).n = crearNodoFuncion((yyvsp[(2) - (5)].stringVal), NULL, (yyvsp[(4) - (5)].simbolo).n);
        free((yyvsp[(2) - (5)].stringVal)); free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 264 "parser_latino.y"
    { (yyval.simbolo).tipo = strdup("parametros"); (yyval.simbolo).valor = NULL; (yyval.simbolo).n = NULL; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 269 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("parametros");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoParametro((yyvsp[(1) - (1)].stringVal), NULL);
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 275 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("parametros");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoParametro((yyvsp[(3) - (3)].stringVal), (yyvsp[(1) - (3)].simbolo).n);
        free((yyvsp[(3) - (3)].stringVal));
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 285 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("llamada_funcion");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (2)].stringVal));
        (yyval.simbolo).n = crearNodoLlamadaFuncion((yyvsp[(1) - (2)].stringVal), (yyvsp[(2) - (2)].simbolo).n);
        free((yyvsp[(1) - (2)].stringVal)); free((yyvsp[(2) - (2)].simbolo).tipo); free((yyvsp[(2) - (2)].simbolo).valor);
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 294 "parser_latino.y"
    { (yyval.simbolo).tipo = strdup("argumentos"); (yyval.simbolo).valor = NULL; (yyval.simbolo).n = NULL; ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 295 "parser_latino.y"
    { (yyval.simbolo).tipo = strdup("argumentos"); (yyval.simbolo).valor = NULL; (yyval.simbolo).n = (yyvsp[(2) - (3)].simbolo).n; free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 299 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("argumentos");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoArgumento((yyvsp[(1) - (1)].simbolo).n, NULL);
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 305 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("argumentos");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoArgumento((yyvsp[(3) - (3)].simbolo).n, (yyvsp[(1) - (3)].simbolo).n);
        free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 314 "parser_latino.y"
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

  case 30:

/* Line 1464 of yacc.c  */
#line 337 "parser_latino.y"
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

  case 31:

/* Line 1464 of yacc.c  */
#line 350 "parser_latino.y"
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

  case 32:

/* Line 1464 of yacc.c  */
#line 372 "parser_latino.y"
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

  case 33:

/* Line 1464 of yacc.c  */
#line 392 "parser_latino.y"
    {
        //$$.tipo = strdup("acceso_array");
        //$$.valor = NULL;
        //$$.n = crearNodoAccesoArray($1, $2.n);
        //free($1); free($2.tipo); free($2.valor);
    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 401 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(2) - (3)].simbolo).n, NULL);
        free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);
    ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 407 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(1) - (4)].simbolo).n, (yyvsp[(3) - (4)].simbolo).n);
        free((yyvsp[(1) - (4)].simbolo).tipo); free((yyvsp[(1) - (4)].simbolo).valor); free((yyvsp[(3) - (4)].simbolo).tipo); free((yyvsp[(3) - (4)].simbolo).valor);
    ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 416 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].simbolo).valor);
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 422 "parser_latino.y"
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

  case 38:

/* Line 1464 of yacc.c  */
#line 431 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("acceso_array");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 437 "parser_latino.y"
    {
        if ((strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0)){
            // Concatenación de cadenas
            (yyval.simbolo).tipo = strdup("string");

            // Prepara las cadenas (quita comillas si quieres, opcional)
            char* val1 = (yyvsp[(1) - (3)].simbolo).valor;
            char* val2 = (yyvsp[(3) - (3)].simbolo).valor;

            // Quitar comillas alrededor si necesario (opcional)
            // Aquí simplemente concatenamos las representaciones tal como están

            (yyval.simbolo).valor = malloc(strlen(val1) + strlen(val2) + 1);
            sprintf((yyval.simbolo).valor, "%s%s", val1, val2);

            // Crea un nodo de concatenación (usa NODO_CONCAT si tienes, o NODO_SUMA)
            (yyval.simbolo).n = crearNodoOperacion(NODO_CONCAT, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n); // o NODO_SUMA si no tienes NODO_CONCAT

            free(val1);
            free(val2);
        }
        else {
            if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
                fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
                exit(1);
            }
            if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
                fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
                exit(1);
            }
            (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
            // SIEMPRE guarda la expresión textual, no el resultado
            (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
            sprintf((yyval.simbolo).valor, "%s+%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
            (yyval.simbolo).n = crearNodoOperacion(NODO_SUMA, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        }
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 475 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s-%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_RESTA, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 490 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s*%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_MULT, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 505 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        printf("%s\n", (yyvsp[(3) - (3)].simbolo).valor);
        if ((strcmp((yyvsp[(3) - (3)].simbolo).tipo, "int") == 0 && (yyvsp[(3) - (3)].simbolo).n && (yyvsp[(3) - (3)].simbolo).valor == 0) ||
            (strcmp((yyvsp[(3) - (3)].simbolo).tipo, "float") == 0 && (yyvsp[(3) - (3)].simbolo).n && (yyvsp[(3) - (3)].simbolo).n->valor_float == 0.0)) {
            fprintf(stderr, "[ERROR] Division por cero (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s/%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_DIV, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 526 "parser_latino.y"
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

  case 44:

/* Line 1464 of yacc.c  */
#line 536 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s==%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_IGUALIGUAL, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 543 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s!=%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_DIFERENTE, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 550 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s<%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_MENOR, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 565 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s>%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_MAYOR, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 580 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s<=%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_MENORIGUAL, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 595 "parser_latino.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s>=%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_MAYORIGUAL, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 610 "parser_latino.y"
    {
        // Validación de tipos
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") != 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica AND requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        (yyval.simbolo).tipo = strdup("bool");

        // Evaluación del valor (asumiendo que los valores son "true" o "false")
        int val1 = (strcmp((yyvsp[(1) - (3)].simbolo).valor, "true") == 0);
        int val2 = (strcmp((yyvsp[(3) - (3)].simbolo).valor, "true") == 0);

        (yyval.simbolo).valor = strdup((val1 && val2) ? "true" : "false");

        // Nodo del AST
        (yyval.simbolo).n = crearNodoOperacion(NODO_AND, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);

        // Liberar memoria
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 631 "parser_latino.y"
    {
        // Validación de tipos
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") != 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica OR requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        (yyval.simbolo).tipo = strdup("bool");

        // Evaluación del valor (asumiendo que los valores son "true" o "false")
        int val1 = (strcmp((yyvsp[(1) - (3)].simbolo).valor, "true") == 0);
        int val2 = (strcmp((yyvsp[(3) - (3)].simbolo).valor, "true") == 0);

        (yyval.simbolo).valor = strdup((val1 || val2) ? "true" : "false");

        // Nodo del AST
        (yyval.simbolo).n = crearNodoOperacion(NODO_OR, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);

        // Liberar memoria
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
        free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 653 "parser_latino.y"
    {
        // Validación de tipos
        if (strcmp((yyvsp[(2) - (2)].simbolo).tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica NOT requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        (yyval.simbolo).tipo = strdup("bool");

        // Evaluación del valor (asumiendo que los valores son "true" o "false")
        int val = (strcmp((yyvsp[(2) - (2)].simbolo).valor, "true") != 0);

        (yyval.simbolo).valor = strdup((val) ? "true" : "false");

        // Nodo del AST
        (yyval.simbolo).n = crearNodoNot(NODO_NOT, (yyvsp[(2) - (2)].simbolo).n);

        // Liberar memoria
        free((yyvsp[(2) - (2)].simbolo).tipo);
        free((yyvsp[(2) - (2)].simbolo).valor);
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 678 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("int");
        (yyval.simbolo).valor = malloc(12);
        sprintf((yyval.simbolo).valor, "%d", (yyvsp[(1) - (1)].enteroVal));
        (yyval.simbolo).n = crearNodoNumero((yyvsp[(1) - (1)].enteroVal));
    ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 684 "parser_latino.y"
    {
        (yyvsp[(2) - (2)].enteroVal) = -(yyvsp[(2) - (2)].enteroVal); // Negar el número
        (yyval.simbolo).tipo = strdup("int");
        (yyval.simbolo).valor = malloc(12);
        sprintf((yyval.simbolo).valor, "%d", (yyvsp[(2) - (2)].enteroVal));
        (yyval.simbolo).n = crearNodoNumero((yyvsp[(2) - (2)].enteroVal));
    ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 691 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("float");
        (yyval.simbolo).valor = malloc(32);
        sprintf((yyval.simbolo).valor, "%.2f", (yyvsp[(1) - (1)].realVal));
        (yyval.simbolo).n = crearNodoFloat((yyvsp[(1) - (1)].realVal));
    ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 697 "parser_latino.y"
    {
        (yyvsp[(2) - (2)].realVal) = -(yyvsp[(2) - (2)].realVal); // Negar el número
        (yyval.simbolo).tipo = strdup("float");
        (yyval.simbolo).valor = malloc(32);
        sprintf((yyval.simbolo).valor, "%.2f", (yyvsp[(2) - (2)].realVal));
        (yyval.simbolo).n = crearNodoFloat((yyvsp[(2) - (2)].realVal));
    ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 704 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("string");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].stringVal));
        (yyval.simbolo).n = crearNodoString((yyvsp[(1) - (1)].stringVal));
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 710 "parser_latino.y"
    {
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].stringVal));
        (yyval.simbolo).n = crearNodoBool((yyvsp[(1) - (1)].stringVal));
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 716 "parser_latino.y"
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
#line 2455 "parser_latino.tab.c"
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
#line 734 "parser_latino.y"


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

