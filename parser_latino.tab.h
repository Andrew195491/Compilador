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
     INTERP_FIN = 291
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
        char* tipoBase;
        int tam;
        int filas; // Para matrices
        int columnas; // Para matrices
        char* valores;
        char* tipoBaseReal;
        struct ast *n;
    } simbolo;



/* Line 1685 of yacc.c  */
#line 106 "parser_latino.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


