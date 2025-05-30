/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RESTA = 258,
     SUMA = 259,
     DIVISION = 260,
     MULTI = 261,
     PARENDER = 262,
     PARENIZQ = 263,
     NUMERICO = 264,
     NUMERICODECIMAL = 265,
     IDENTIFICADOR = 266,
     CADENA = 267,
     BOOL = 268,
     CORCHETEABIERTO = 269,
     CORCHETECERRADO = 270,
     SEPARADOR = 271,
     IGUAL = 272,
     SALTO = 273,
     IF = 274,
     ELSE = 275,
     WHILE = 276,
     FOR = 277,
     PUTS = 278,
     END = 279,
     DEF = 280,
     INTERP_INI = 281,
     INTERP_FIN = 282
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 19 "parser_latino.y"

    int enteroVal;
    float realVal;
    char* stringVal;
    struct {
        char* tipo;
        char* valor;
        struct ast *n;
    } simbolo;



/* Line 1685 of yacc.c  */
#line 91 "parser_latino.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


