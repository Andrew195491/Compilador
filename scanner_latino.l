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

"=begin"                { BEGIN(COMMENT); }
<COMMENT>[^=]*[\r\n]+   ;
<COMMENT>"=end"         { BEGIN(INITIAL); }

"def"                   { return DEF; }
"end"                   { return END; }
"if"                    { return IF; }
"else"                  { return ELSE; }
"for"                   { return FOR; }
"while"                 { return WHILE; }
"puts"                  { return PUTS; }
"true"                  { yylval.stringVal = strdup("true"); return BOOL; }
"false"                 { yylval.stringVal = strdup("false"); return BOOL; }

"="                     { return IGUAL; }
"["                     { return CORCHETEABIERTO; }
"]"                     { return CORCHETECERRADO; }
","                     { return SEPARADOR; }
"("                     { return PARENIZQ; }
")"                     { return PARENDER; }
"#{"                    { return INTERP_INI; }
"}"                     { return INTERP_FIN; }
"+"                     { yylval.stringVal = strdup("+"); return SUMA; }
"-"                     { yylval.stringVal = strdup("-"); return RESTA; }
"*"                     { yylval.stringVal = strdup("*"); return MULTI; }
"/"                     { yylval.stringVal = strdup("/"); return DIVISION; }
"=="                    { return IGUALIGUAL; }
"!="                    { return DIFERENTE; }
">="                    { return MAYORIGUAL; }
"<="                    { return MENORIGUAL; }
">"                     { return MAYOR; }
"<"                         { return MENOR; }

"#".*                   ; // comentarios de una línea estilo Ruby

[0-9]+\.[0-9]+          { yylval.realVal = atof(yytext); return NUMERICODECIMAL; }
[0-9]+                  { yylval.enteroVal = atoi(yytext); return NUMERICO; }
\"[^\"]*\"              { yylval.stringVal = strdup(yytext); return CADENA; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.stringVal = strdup(yytext); return IDENTIFICADOR; }

.                       { printf("[LEX] Caracter no reconocido: %s (linea %d)\n", yytext, num_linea); }

%%

/*
    NOTAS:
    - Las palabras reservadas deben ir antes que la regla de IDENTIFICADOR para evitar que sean reconocidas como identificadores.
    - El token "#{" (INTERP_INI) y "}" (INTERP_FIN) están listos para interpolación de cadenas.
    - Los comentarios de línea y bloque están soportados al estilo Ruby.
    - Las cadenas se reconocen como un solo token (puedes mejorar esto para interpolación real si lo necesitas).
*/
