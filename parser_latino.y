%{
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
%}

%union {
    int enteroVal;
    float realVal;
    char* stringVal;
    struct {
        char* tipo;
        char* valor;
        struct ast *n;
    } simbolo;
}

%left SUMA RESTA
%left MULTI DIVISION
%left PARENIZQ PARENDER

%token <enteroVal> NUMERICO
%token <realVal> NUMERICODECIMAL
%token <stringVal> IDENTIFICADOR CADENA BOOL
%token SUMA RESTA MULTI DIVISION CORCHETEABIERTO CORCHETECERRADO SEPARADOR IGUAL SALTO PARENIZQ PARENDER IF ELSE FOR

%type <simbolo> programa lista_sentencias sentencia asignacion expresion valor
%type <simbolo> array array2 acceso_array indices_array

%start programa

%%

programa
    : lista_sentencias {
        printf("Llamando a recorrerAST\n");
        generarASM($1.n);
        liberarAST($1.n);
    }
    ;

salto:
    |
    SALTO
    ;

lista_sentencias
    : sentencia salto {
        $$.tipo = strdup($1.tipo);
        if ($1.valor != NULL) {
            $$.valor = strdup($1.valor);
        } else {
            $$.valor = NULL;
        }
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | lista_sentencias sentencia SALTO {
        $$.tipo = strdup("lista");
        $$.valor = NULL;
        $$.n = crearNodoLista($1.n, $2.n);
        free($1.tipo); free($1.valor); free($2.tipo); free($2.valor);
    }
    ;

sentencia
    : asignacion {
        $$.tipo = strdup($1.tipo);
        $$.valor = NULL;
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    ;

asignacion
    : IDENTIFICADOR IGUAL expresion {
        // La tabla de símbolos solo sirve para ejecución/interprete, no para el AST ni para arrays heterogéneos
        $$.tipo = strdup("asignacion");
        $$.valor = NULL;
        $$.n = crearNodoAsignacion($1, $3.n);
        free($1); free($3.tipo); free($3.valor);
    }
    ;

array
    : CORCHETEABIERTO array2 CORCHETECERRADO {
        $$.tipo = strdup("array");
        $$.valor = NULL;
        $$.n = $2.n;
        free($2.tipo); free($2.valor);
    }
    | CORCHETEABIERTO CORCHETECERRADO {
        $$.tipo = strdup("array");
        $$.valor = NULL;
        $$.n = NULL;
    }
    ;

array2
    : expresion SEPARADOR array2 {
        $$.tipo = strdup("array");
        $$.valor = NULL;
        $$.n = crearNodoArray($1.n, $3.n);
        free($1.tipo); free($1.valor); free($3.tipo); free($3.valor);
    }
    | expresion {
        $$.tipo = strdup("array");
        $$.valor = NULL;
        $$.n = crearNodoArray($1.n, NULL);
        free($1.tipo); free($1.valor);
    }
    ;

acceso_array
    : IDENTIFICADOR indices_array {
        $$.tipo = strdup("acceso_array");
        $$.valor = NULL;
        $$.n = crearNodoAccesoArray($1, $2.n);
        free($1); free($2.tipo); free($2.valor);
    }
    ;

indices_array
    : CORCHETEABIERTO expresion CORCHETECERRADO {
        $$.tipo = strdup("lista");
        $$.valor = NULL;
        $$.n = crearNodoLista($2.n, NULL);
        free($2.tipo); free($2.valor);
    }
    | indices_array CORCHETEABIERTO expresion CORCHETECERRADO {
        $$.tipo = strdup("lista");
        $$.valor = NULL;
        $$.n = crearNodoLista($1.n, $3.n);
        free($1.tipo); free($1.valor); free($3.tipo); free($3.valor);
    }
    ;

expresion
    : valor {
        $$.tipo = strdup($1.tipo);
        $$.valor = strdup($1.valor);
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | array {
        $$.tipo = strdup("array");
        $$.valor = NULL;
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | acceso_array {
        $$.tipo = strdup("acceso_array");
        $$.valor = NULL;
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | expresion SUMA expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup($1.tipo);
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_SUMA, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion RESTA expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup($1.tipo);
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_RESTA, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MULTI expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup($1.tipo);
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_MULT, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion DIVISION expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if ((strcmp($3.tipo, "int") == 0 && $3.n && $3.n->valor_int == 0) ||
            (strcmp($3.tipo, "float") == 0 && $3.n && $3.n->valor_float == 0.0)) {
            fprintf(stderr, "[ERROR] Division por cero (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup($1.tipo);
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_DIV, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | PARENIZQ expresion PARENDER {
        $$.tipo = strdup($2.tipo);
        if ($2.valor != NULL) {
            $$.valor = strdup($2.valor);
        } else {
            $$.valor = NULL;
        }
        $$.n = $2.n;
        free($2.tipo); free($2.valor);
    }
    ;

valor
    : NUMERICO {
        $$.tipo = strdup("int");
        $$.valor = malloc(12);
        sprintf($$.valor, "%d", $1);
        $$.n = crearNodoNumero($1);
    }
    | NUMERICODECIMAL {
        $$.tipo = strdup("float");
        $$.valor = malloc(32);
        sprintf($$.valor, "%.2f", $1);
        $$.n = crearNodoFloat($1);
    }
    | CADENA {
        $$.tipo = strdup("string");
        $$.valor = strdup($1);
        $$.n = crearNodoString($1);
        free($1);
    }
    | BOOL {
        $$.tipo = strdup("bool");
        $$.valor = strdup($1);
        $$.n = crearNodoBool($1);
        free($1);
    }
    | IDENTIFICADOR {
        // Solo para ejecución/interprete, no para el AST puro
        $$.tipo = strdup("var");
        $$.valor = strdup($1);
        $$.n = crearNodoVariable($1);
        free($1);
    }
    ;

%%

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
