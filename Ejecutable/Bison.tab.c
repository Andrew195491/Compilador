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
#line 1 "Ejecutable/Bison.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_Simbolos.h"
#include "Arbol_ABS.h"

extern int yylex();
extern int num_linea;
extern FILE* yyin;
extern FILE* yyout;

void yyerror(const char* s) {
    fprintf(stderr, "[ERROR] Sintaxis invalida en linea %d: %s\n", num_linea, s);
    exit(1);
}


/* Line 189 of yacc.c  */
#line 91 "Ejecutable/Bison.tab.c"

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
#line 19 "Ejecutable/Bison.y"

    int enteroVal;
    float realVal;
    char* stringVal;
    struct {
        char* tipo;
        char* valor;
        char* tipoBase;
        int tam;
        int filas;
        int columnas;
        char* valores;
        char* tipoBaseReal;
        struct ast *n;
    } simbolo;



/* Line 214 of yacc.c  */
#line 183 "Ejecutable/Bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "Ejecutable/Bison.tab.c"

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNRULES -- Number of states.  */
#define YYNSTATES  87

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
      23,    25,    27,    31,    37,    46,    52,    56,    59,    63,
      65,    68,    72,    77,    79,    81,    83,    87,    91,    95,
      99,   103,   107,   111,   115,   119,   123,   127,   131,   135,
     138,   140,   143,   145,   148,   150,   152
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    41,    -1,    -1,    27,    40,    -1,    42,
      40,    -1,    41,    42,    40,    -1,    43,    -1,    32,    50,
      -1,    44,    -1,    45,    -1,    37,    -1,    20,    26,    50,
      -1,    28,    50,    40,    41,    33,    -1,    28,    50,    40,
      41,    29,    40,    41,    33,    -1,    30,    50,    40,    41,
      33,    -1,    23,    47,    24,    -1,    23,    24,    -1,    50,
      25,    47,    -1,    50,    -1,    20,    49,    -1,    23,    50,
      24,    -1,    49,    23,    50,    24,    -1,    51,    -1,    46,
      -1,    48,    -1,    50,    13,    50,    -1,    50,    12,    50,
      -1,    50,    15,    50,    -1,    50,    14,    50,    -1,    17,
      50,    16,    -1,    50,    11,    50,    -1,    50,    10,    50,
      -1,    50,     6,    50,    -1,    50,     7,    50,    -1,    50,
       8,    50,    -1,    50,     9,    50,    -1,    50,     3,    50,
      -1,    50,     4,    50,    -1,     5,    50,    -1,    18,    -1,
      12,    18,    -1,    19,    -1,    12,    19,    -1,    21,    -1,
      22,    -1,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    77,    78,    82,    92,   102,   108,   114,
     120,   126,   135,   220,   226,   237,   246,   266,   279,   309,
     329,   332,   338,   347,   353,   362,   368,   396,   411,   426,
     447,   457,   464,   471,   486,   501,   516,   531,   548,   566,
     589,   595,   602,   608,   615,   621,   627
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
  "sentencia", "asignacion", "if_else_end", "while_end", "array",
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    43,    44,    44,    45,    46,    46,    47,    47,
      48,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     3,     1,     2,     1,
       1,     1,     3,     5,     8,     5,     3,     2,     3,     1,
       2,     3,     4,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     2,     1,     2,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    11,     0,     2,     3,     7,
       9,    10,     0,     0,     0,     0,    40,    42,    46,    44,
      45,     0,    24,    25,     3,    23,     3,     8,     1,     3,
       3,     5,    12,    39,    41,    43,     0,     0,    20,    17,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     4,    30,     0,
       0,    16,     0,    37,    38,    33,    34,    35,    36,    32,
      31,    27,    26,    29,    28,     0,     0,    21,     0,    18,
       3,    13,    15,    22,     0,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,    31,     7,     8,     9,    10,    11,    22,    40,
      23,    38,    41,    25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int16 yypact[] =
{
     161,   -21,   143,   143,   143,   -48,    13,   161,   -10,   -48,
     -48,   -48,   143,   143,    14,   143,   -48,   -48,    15,   -48,
     -48,   123,   -48,   -48,    12,   -48,    12,   207,   -48,   -10,
     -10,   -48,   207,   217,   -48,   -48,   193,   143,    17,   -48,
      30,    73,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   161,   161,   -48,   -48,   -48,    93,
     143,   -48,   143,   217,   217,    16,    16,    16,    16,    16,
      16,    20,    20,   -48,   -48,    33,   139,   -48,   112,   -48,
     -10,   -48,   -48,   -48,   161,   150,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -20,   -47,    -7,   -48,   -48,   -48,   -48,    -6,
     -48,   -48,    -1,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      29,    24,    26,    27,    54,    12,    55,    75,    76,    56,
      57,    32,    33,    28,    36,    42,    43,    30,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    50,    51,
      52,    53,    34,    35,    52,    53,    59,    85,    37,    30,
      60,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     1,    61,     0,    79,     0,     0,    78,
      84,     2,    80,     3,     0,     4,    81,     0,    29,    29,
       5,     0,     0,     0,     0,     0,    42,    43,    29,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,    42,    43,    62,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,    42,    43,    77,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    13,     0,
       0,     0,     0,     0,     0,    14,    83,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    39,    13,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     1,
      15,    16,    17,    18,    19,    20,    21,     2,     0,     3,
       1,     4,    82,     0,     0,     0,     5,     0,     2,     0,
       3,     1,     4,    86,     0,     0,     0,     5,     0,     2,
       0,     3,     0,     4,     0,     0,    42,    43,     5,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    58,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53
};

static const yytype_int8 yycheck[] =
{
       7,     2,     3,     4,    24,    26,    26,    54,    55,    29,
      30,    12,    13,     0,    15,     3,     4,    27,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    12,    13,
      14,    15,    18,    19,    14,    15,    37,    84,    23,    27,
      23,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    20,    24,    -1,    62,    -1,    -1,    60,
      80,    28,    29,    30,    -1,    32,    33,    -1,    75,    76,
      37,    -1,    -1,    -1,    -1,    -1,     3,     4,    85,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    25,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    24,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    24,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    20,
      17,    18,    19,    20,    21,    22,    23,    28,    -1,    30,
      20,    32,    33,    -1,    -1,    -1,    37,    -1,    28,    -1,
      30,    20,    32,    33,    -1,    -1,    -1,    37,    -1,    28,
      -1,    30,    -1,    32,    -1,    -1,     3,     4,    37,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    28,    30,    32,    37,    39,    41,    42,    43,
      44,    45,    26,     5,    12,    17,    18,    19,    20,    21,
      22,    23,    46,    48,    50,    51,    50,    50,     0,    42,
      27,    40,    50,    50,    18,    19,    50,    23,    49,    24,
      47,    50,     3,     4,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    40,    40,    40,    40,    16,    50,
      23,    24,    25,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    41,    41,    24,    50,    47,
      29,    33,    33,    24,    40,    41,    33
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
#line 70 "Ejecutable/Bison.y"
    {
        printf("Llamando a recorrerAST\n");
        generarASM((yyvsp[(1) - (1)].simbolo).n);
        liberarAST((yyvsp[(1) - (1)].simbolo).n);
    ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 82 "Ejecutable/Bison.y"
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
#line 92 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(1) - (3)].simbolo).n, (yyvsp[(2) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);
    ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 102 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 108 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("puts");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoPuts((yyvsp[(2) - (2)].simbolo).n);
        free((yyvsp[(2) - (2)].simbolo).tipo); free((yyvsp[(2) - (2)].simbolo).valor);
    ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 114 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("if_else");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 120 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("while");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 126 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("comentario_linea");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = NULL; 
        printf("Comentario de línea\n");
    ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 135 "Ejecutable/Bison.y"
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

        const char* tipoNodo = NULL;
        switch ((yyvsp[(3) - (3)].simbolo).n->tipoNodo) {
            case NODO_NUMERO: tipoNodo = "int"; break;
            case NODO_FLOAT:  tipoNodo = "float"; break;
            case NODO_STRING: tipoNodo = "string"; break;
            case NODO_BOOL:   tipoNodo = "bool"; break;
            case NODO_ARRAY:   tipoNodo = "array"; break;
            case NODO_SUMA: {
                struct ast* izq = (yyvsp[(3) - (3)].simbolo).n->izq;
                struct ast* dcha = (yyvsp[(3) - (3)].simbolo).n->dcha;

                if ((izq && izq->tipoNodo == NODO_FLOAT) || (dcha && dcha->tipoNodo == NODO_FLOAT)) {
                    (yyvsp[(3) - (3)].simbolo).tipo = strdup("float");
                } else {
                    tipoNodo = "int";
                }
        break;
    }
    case NODO_RESTA: {
                struct ast* izq = (yyvsp[(3) - (3)].simbolo).n->izq;
                struct ast* dcha = (yyvsp[(3) - (3)].simbolo).n->dcha;

                if ((izq && izq->tipoNodo == NODO_FLOAT) || (dcha && dcha->tipoNodo == NODO_FLOAT)) {
                    (yyvsp[(3) - (3)].simbolo).tipo = strdup("float");
                } else {
                    tipoNodo = "int";
                }
        break;
    }
    case NODO_MULT: {
                struct ast* izq = (yyvsp[(3) - (3)].simbolo).n->izq;
                struct ast* dcha = (yyvsp[(3) - (3)].simbolo).n->dcha;

                if ((izq && izq->tipoNodo == NODO_FLOAT) || (dcha && dcha->tipoNodo == NODO_FLOAT)) {
                    (yyvsp[(3) - (3)].simbolo).tipo = strdup("float");
                } else {
                    tipoNodo = "int";
                }
        break;
    }
    case NODO_DIV: {
                struct ast* izq = (yyvsp[(3) - (3)].simbolo).n->izq;
                struct ast* dcha = (yyvsp[(3) - (3)].simbolo).n->dcha;

                if ((izq && izq->tipoNodo == NODO_FLOAT) || (dcha && dcha->tipoNodo == NODO_FLOAT)) {
                    (yyvsp[(3) - (3)].simbolo).tipo = strdup("float");
                } else {
                    tipoNodo = "int";
                }
        break;
    }
            default: tipoNodo = "otro"; break;
        }

        if (tabla[pos].tipo && tipoNodo && strcmp(tabla[pos].tipo, tipoNodo) != 0) {
            fprintf(stderr,
                    "[ERROR] No puedes asignar un valor de tipo '%s' a la variable '%s' que es de tipo '%s' (linea %d)\n",
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

  case 13:

/* Line 1464 of yacc.c  */
#line 220 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("if");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoIf((yyvsp[(2) - (5)].simbolo).n, (yyvsp[(4) - (5)].simbolo).n, NULL);
        free((yyvsp[(2) - (5)].simbolo).tipo); free((yyvsp[(2) - (5)].simbolo).valor); free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 226 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("if_else");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoIf((yyvsp[(2) - (8)].simbolo).n, (yyvsp[(4) - (8)].simbolo).n, (yyvsp[(7) - (8)].simbolo).n);
        free((yyvsp[(2) - (8)].simbolo).tipo); free((yyvsp[(2) - (8)].simbolo).valor); free((yyvsp[(4) - (8)].simbolo).tipo); free((yyvsp[(4) - (8)].simbolo).valor); free((yyvsp[(7) - (8)].simbolo).tipo); free((yyvsp[(7) - (8)].simbolo).valor);
    ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 237 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("while");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoWhile((yyvsp[(2) - (5)].simbolo).n, (yyvsp[(4) - (5)].simbolo).n);
        free((yyvsp[(2) - (5)].simbolo).tipo); free((yyvsp[(2) - (5)].simbolo).valor); free((yyvsp[(4) - (5)].simbolo).tipo); free((yyvsp[(4) - (5)].simbolo).valor);
    ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 246 "Ejecutable/Bison.y"
    {
        if ((yyvsp[(2) - (3)].simbolo).tipoBase && strcmp((yyvsp[(2) - (3)].simbolo).tipoBase, "array") == 0) {
            (yyval.simbolo).tipo = strdup("matriz");
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

  case 17:

/* Line 1464 of yacc.c  */
#line 266 "Ejecutable/Bison.y"
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

  case 18:

/* Line 1464 of yacc.c  */
#line 279 "Ejecutable/Bison.y"
    {
        if ((yyvsp[(1) - (3)].simbolo).tipo && strcmp((yyvsp[(1) - (3)].simbolo).tipo, "array") == 0) {
            
            if ((yyvsp[(3) - (3)].simbolo).tipoBaseReal && (yyvsp[(1) - (3)].simbolo).tipoBase && strcmp((yyvsp[(1) - (3)].simbolo).tipoBase, (yyvsp[(3) - (3)].simbolo).tipoBaseReal) != 0) {
                fprintf(stderr, "[ERROR] Los elementos de la matriz deben tener el mismo tipo base (linea %d). Encontrado: '%s' y '%s'\n", num_linea, (yyvsp[(1) - (3)].simbolo).tipoBase, (yyvsp[(3) - (3)].simbolo).tipoBaseReal);
                exit(1);
            }
            (yyval.simbolo).tipoBase = strdup((yyvsp[(1) - (3)].simbolo).tipo);
            (yyval.simbolo).tam = (yyvsp[(3) - (3)].simbolo).tam + 1;
            (yyval.simbolo).valores = malloc(strlen((yyvsp[(1) - (3)].simbolo).valores) + strlen((yyvsp[(3) - (3)].simbolo).valores) + 2);
            sprintf((yyval.simbolo).valores, "%s %s", (yyvsp[(1) - (3)].simbolo).valores, (yyvsp[(3) - (3)].simbolo).valores);
            (yyval.simbolo).filas = (yyvsp[(3) - (3)].simbolo).filas + 1;
            (yyval.simbolo).columnas = (yyvsp[(1) - (3)].simbolo).tam;
            (yyval.simbolo).tipoBaseReal = (yyvsp[(1) - (3)].simbolo).tipoBase ? strdup((yyvsp[(1) - (3)].simbolo).tipoBase) : strdup("int");
        } else {    
            if ((yyvsp[(3) - (3)].simbolo).tipoBase && strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipoBase) != 0) {
                fprintf(stderr, "[ERROR] Los elementos del array deben ser del mismo tipo (linea %d). Encontrado: '%s' y '%s'\n", num_linea, (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipoBase);
                exit(1);
            }
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

  case 19:

/* Line 1464 of yacc.c  */
#line 309 "Ejecutable/Bison.y"
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

  case 21:

/* Line 1464 of yacc.c  */
#line 332 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(2) - (3)].simbolo).n, NULL);
        free((yyvsp[(2) - (3)].simbolo).tipo); free((yyvsp[(2) - (3)].simbolo).valor);
    ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 338 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("lista");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = crearNodoLista((yyvsp[(1) - (4)].simbolo).n, (yyvsp[(3) - (4)].simbolo).n);
        free((yyvsp[(1) - (4)].simbolo).tipo); free((yyvsp[(1) - (4)].simbolo).valor); free((yyvsp[(3) - (4)].simbolo).tipo); free((yyvsp[(3) - (4)].simbolo).valor);
    ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 347 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].simbolo).valor);
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 353 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup((yyvsp[(1) - (1)].simbolo).tipo);
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).tipoBase = (yyvsp[(1) - (1)].simbolo).tipoBase ? strdup((yyvsp[(1) - (1)].simbolo).tipoBase) : NULL;
        (yyval.simbolo).tam = (yyvsp[(1) - (1)].simbolo).tam;
        (yyval.simbolo).valores = (yyvsp[(1) - (1)].simbolo).valores ? strdup((yyvsp[(1) - (1)].simbolo).valores) : strdup(""); 
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 362 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("acceso_array");
        (yyval.simbolo).valor = NULL;
        (yyval.simbolo).n = (yyvsp[(1) - (1)].simbolo).n;
        free((yyvsp[(1) - (1)].simbolo).tipo); free((yyvsp[(1) - (1)].simbolo).valor);
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 368 "Ejecutable/Bison.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", (yyvsp[(1) - (3)].simbolo).tipo, (yyvsp[(3) - (3)].simbolo).tipo, num_linea);
            exit(1);
        }
        if ((strcmp((yyvsp[(1) - (3)].simbolo).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "string") == 0)) {
            (yyval.simbolo).tipo = strdup("string");
            const char* val1 = (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "";
            const char* val2 = (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "";

            (yyval.simbolo).valor = malloc(strlen(val1) + strlen(val2) + 1);
            sprintf((yyval.simbolo).valor, "%s%s", val1, val2);

            (yyval.simbolo).n = crearNodoConcat((yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        }
        else {

            if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") == 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") == 0) {
                fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo bool (linea %d)\n", num_linea);
                exit(1);
            }
            (yyval.simbolo).tipo = strdup((yyvsp[(1) - (3)].simbolo).tipo);
            (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
            sprintf((yyval.simbolo).valor, "%s+%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
            (yyval.simbolo).n = crearNodoOperacion(NODO_SUMA, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        }
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 396 "Ejecutable/Bison.y"
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

  case 28:

/* Line 1464 of yacc.c  */
#line 411 "Ejecutable/Bison.y"
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

  case 29:

/* Line 1464 of yacc.c  */
#line 426 "Ejecutable/Bison.y"
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

  case 30:

/* Line 1464 of yacc.c  */
#line 447 "Ejecutable/Bison.y"
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

  case 31:

/* Line 1464 of yacc.c  */
#line 457 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s==%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_IGUALIGUAL, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 464 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = malloc(strlen((yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "") + strlen((yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "") + 4);
        sprintf((yyval.simbolo).valor, "%s!=%s", (yyvsp[(1) - (3)].simbolo).valor ? (yyvsp[(1) - (3)].simbolo).valor : "", (yyvsp[(3) - (3)].simbolo).valor ? (yyvsp[(3) - (3)].simbolo).valor : "");
        (yyval.simbolo).n = crearNodoOperacion(NODO_DIFERENTE, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);
        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
    ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 471 "Ejecutable/Bison.y"
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

  case 34:

/* Line 1464 of yacc.c  */
#line 486 "Ejecutable/Bison.y"
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

  case 35:

/* Line 1464 of yacc.c  */
#line 501 "Ejecutable/Bison.y"
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

  case 36:

/* Line 1464 of yacc.c  */
#line 516 "Ejecutable/Bison.y"
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

  case 37:

/* Line 1464 of yacc.c  */
#line 531 "Ejecutable/Bison.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") != 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica AND requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        (yyval.simbolo).tipo = strdup("bool");

        int val1 = (strcmp((yyvsp[(1) - (3)].simbolo).valor, "true") == 0);
        int val2 = (strcmp((yyvsp[(3) - (3)].simbolo).valor, "true") == 0);

        (yyval.simbolo).valor = strdup((val1 && val2) ? "true" : "false");

        (yyval.simbolo).n = crearNodoOperacion(NODO_AND, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);

        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo); free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 548 "Ejecutable/Bison.y"
    {
        if (strcmp((yyvsp[(1) - (3)].simbolo).tipo, "bool") != 0 || strcmp((yyvsp[(3) - (3)].simbolo).tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica OR requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        (yyval.simbolo).tipo = strdup("bool");

        int val1 = (strcmp((yyvsp[(1) - (3)].simbolo).valor, "true") == 0);
        int val2 = (strcmp((yyvsp[(3) - (3)].simbolo).valor, "true") == 0);

        (yyval.simbolo).valor = strdup((val1 || val2) ? "true" : "false");

        (yyval.simbolo).n = crearNodoOperacion(NODO_OR, (yyvsp[(1) - (3)].simbolo).n, (yyvsp[(3) - (3)].simbolo).n);

        free((yyvsp[(1) - (3)].simbolo).tipo); free((yyvsp[(3) - (3)].simbolo).tipo);
        free((yyvsp[(1) - (3)].simbolo).valor); free((yyvsp[(3) - (3)].simbolo).valor);
    ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 566 "Ejecutable/Bison.y"
    {
        if (strcmp((yyvsp[(2) - (2)].simbolo).tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica NOT requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        (yyval.simbolo).tipo = strdup("bool");

        int val = (strcmp((yyvsp[(2) - (2)].simbolo).valor, "true") != 0);

        (yyval.simbolo).valor = strdup((val) ? "true" : "false");

        (yyval.simbolo).n = crearNodoOperacion(NODO_NOT, (yyvsp[(2) - (2)].simbolo).n, NULL);

        printf((yyvsp[(2) - (2)].simbolo).valor);

        free((yyvsp[(2) - (2)].simbolo).tipo);
        free((yyvsp[(2) - (2)].simbolo).valor);
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 589 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("int");
        (yyval.simbolo).valor = malloc(12);
        sprintf((yyval.simbolo).valor, "%d", (yyvsp[(1) - (1)].enteroVal));
        (yyval.simbolo).n = crearNodoNumero((yyvsp[(1) - (1)].enteroVal));
    ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 595 "Ejecutable/Bison.y"
    {
        (yyvsp[(2) - (2)].enteroVal) = -(yyvsp[(2) - (2)].enteroVal);
        (yyval.simbolo).tipo = strdup("int");
        (yyval.simbolo).valor = malloc(12);
        sprintf((yyval.simbolo).valor, "%d", (yyvsp[(2) - (2)].enteroVal));
        (yyval.simbolo).n = crearNodoNumero((yyvsp[(2) - (2)].enteroVal));
    ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 602 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("float");
        (yyval.simbolo).valor = malloc(32);
        sprintf((yyval.simbolo).valor, "%.2f", (yyvsp[(1) - (1)].realVal));
        (yyval.simbolo).n = crearNodoFloat((yyvsp[(1) - (1)].realVal));
    ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 608 "Ejecutable/Bison.y"
    {
        (yyvsp[(2) - (2)].realVal) = -(yyvsp[(2) - (2)].realVal);
        (yyval.simbolo).tipo = strdup("float");
        (yyval.simbolo).valor = malloc(32);
        sprintf((yyval.simbolo).valor, "%.2f", (yyvsp[(2) - (2)].realVal));
        (yyval.simbolo).n = crearNodoFloat((yyvsp[(2) - (2)].realVal));
    ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 615 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("string");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].stringVal));
        (yyval.simbolo).n = crearNodoString((yyvsp[(1) - (1)].stringVal));
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 621 "Ejecutable/Bison.y"
    {
        (yyval.simbolo).tipo = strdup("bool");
        (yyval.simbolo).valor = strdup((yyvsp[(1) - (1)].stringVal));
        (yyval.simbolo).n = crearNodoBool((yyvsp[(1) - (1)].stringVal));
        free((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 627 "Ejecutable/Bison.y"
    {
        int pos = buscarTabla((yyvsp[(1) - (1)].stringVal));
        if (pos == -1){
            fprintf(stderr, "ERROR, LA VARIABLE  '%s' NO ESTA DECLARADA EN (linea %d)\n", (yyvsp[(1) - (1)].stringVal), num_linea);
            exit(1);
        }
        (yyval.simbolo).tipo = strdup(tabla[pos].tipo);
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
#line 2281 "Ejecutable/Bison.tab.c"
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
#line 644 "Ejecutable/Bison.y"


int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    }
    yyout = fopen("Pruebas/output.asm", "w");
    if (!yyout) {
        perror("Pruebas/output.asm");
        return 1;
    }
    printf("Analizando...\n");
    yyparse();
    fclose(yyout);
    return 0;
}

