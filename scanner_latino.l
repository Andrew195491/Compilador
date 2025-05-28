%option noyywrap

%{
#include "parser_latino.tab.h"  // generado por Bison
#include <string.h>
#include <stdlib.h>

int num_linea = 1;
%}
%x COMMENT

%%

[ \t]+                  ; // ignorar espacios
\n                      { num_linea++; return SALTO; }

"="                     { return IGUAL; }
"["                     { return CORCHETEABIERTO; }
"]"                     { return CORCHETECERRADO; }
","                     { return SEPARADOR; }
"("                     { return PARENIZQ; }
")"                     { return PARENDER; }

"+"                     { yylval.stringVal = strdup("+"); return SUMA; }
"-"                     { yylval.stringVal = strdup("-"); return RESTA; }
"*"                     { yylval.stringVal = strdup("*"); return MULTI; }
"/"                     { yylval.stringVal = strdup("/"); return DIVISION; }
"true"                  { yylval.stringVal = strdup("true"); return BOOL; }
"false"                 { yylval.stringVal = strdup("false"); return BOOL; }
"if"                    { return IF; }
"else"                  { return ELSE; }
"for"                   { return FOR; }
"#".*                   ;
"=begin"                {BEGIN(COMMENT);}
<COMMENT>[^=]*[\r\n]+   ;
<COMMENT>"=end"         {BEGIN(INITIAL);}
"puts"                  { return PUTS; }       



[0-9]+                  { yylval.enteroVal = atoi(yytext); return NUMERICO; }
[0-9]+\.[0-9]+          { yylval.realVal = atof(yytext); return NUMERICODECIMAL; }
\"[^\"]*\"              { yylval.stringVal = strdup(yytext); return CADENA; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.stringVal = strdup(yytext); return IDENTIFICADOR; }

       

.                       { printf("[LEX] Caracter no reconocido: %s (linea %d)\n", yytext, num_linea); }

%%

/*
    NOTAS Y CURIOSIDADES:
        - "yylval" es la forma de llamar a "%union" en el bison, haciendo que se le asigne un tipo de dato. Es como una clase que llama a un atributo, y ese atributo es de un tipo de dato.
        - "strdup" dice que algo es un String, "atoi" dice que algo es un Int
        - Todos devuelven su identificador, haciendo que se pueda utilizar en Bison, diciendo que el tipo de dato es al atibuto de "%union" que tengan
*/
