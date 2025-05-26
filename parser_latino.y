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

%token <enteroVal> NUMERICO
%token <realVal> NUMERICODECIMAL
%token <stringVal> IDENTIFICADOR CADENA BOOL 
%token SUMA RESTA MULTI DIVISION CORCHETEABIERTO CORCHETECERRADO SEPARADOR IGUAL
%token IF ELSE
%token FOR

%type <simbolo> programa lista_sentencias sentencia asignacion expresion valor
%type <stringVal> operador array array2

%start programa

%%

programa
    : lista_sentencias {
        // Al final, genera el código MIPS para el AST global
        printf("Llamando a comprobarAST\n");
        comprobarAST($1.n);

        // Limpieza opcional de memoria

    }
    ;


lista_sentencias
    : sentencia  {
        $$.tipo = strdup($1.tipo);
        $$.valor = strdup($1.valor);
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | lista_sentencias sentencia {
        $$.tipo = strdup("lista");
        $$.valor = NULL;
        $$.n = crearNodoNoTerminal($1.n, $2.n, NODO_LISTA);
        free($1.tipo); free($1.valor); free($2.tipo); free($2.valor);
    }
    ;

sentencia
    : asignacion {
        $$.tipo = strdup($1.tipo);
        $$.valor = strdup($1.valor);
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | IF expresion sentencia {
        $$.tipo = strdup("if");
        $$.valor = NULL;
        $$.n = crearNodoIf($2.n, $3.n); // Asumiendo que tienes una función para esto
        free($2.tipo); free($2.valor); free($3.tipo); free($3.valor);
    }
    | IF expresion sentencia ELSE sentencia {
        $$.tipo = strdup("if_else");
        $$.valor = NULL;
        $$.n = crearNodoIf($2.n, $3.n, $5.n);
        free($2.tipo); free($2.valor); free($3.tipo); free($3.valor);
        free($5.tipo); free($5.valor);
    }
    | FOR IDENTIFICADOR IGUAL expresion expresion sentencia {
        int pos = buscarTabla($2);
        if (pos == -1) {
            guardar_simbolo($2, "int", $4.valor);
            pos = buscarTabla($2);
        }
    }
    ;

asignacion
    : IDENTIFICADOR IGUAL expresion {
        int pos = buscarTabla($1);
        if (pos == -1) {
            guardar_simbolo($1, $3.tipo, $3.valor);
            pos = buscarTabla($1);
        }
        if (strcmp($3.tipo, "int") == 0) {
            tabla[pos].numerico = atoi($3.valor);
        } else if (strcmp($3.tipo, "float") == 0) {
            tabla[pos].numericoDecimal = atof($3.valor);
        } else {
            tabla[pos].texto = strdup($3.valor);
        }
        $$.tipo = strdup("asignacion");
        $$.valor = NULL;
        $$.n = crearNodoAsignacion(tabla[pos].registro, $3.n);
        free($1);
        free($3.tipo); free($3.valor);
    }
    ;

array
    : CORCHETEABIERTO array2 CORCHETECERRADO {
        $$ = strdup("array");
        free($2);
    }
    | CORCHETEABIERTO CORCHETECERRADO {
        $$ = strdup("array");
    }
    ;

array2
    : expresion SEPARADOR array2 {
        char* temp = malloc(strlen($1.valor) + strlen($3) + 2);
        sprintf(temp, "%s,%s", $1.valor, $3);
        $$ = temp;
        free($1.tipo); free($1.valor); free($3);
    }
    | expresion {
        $$ = strdup($1.valor);
        free($1.tipo); free($1.valor);
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
        $$.valor = strdup($1);
        $$.n = NULL;
        free($1);
    }
    | expresion operador valor {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($2, "/") == 0 && (strcmp($3.valor, "0") == 0 || strcmp($3.valor, "0.0") == 0)) {
            fprintf(stderr, "[ERROR] Division por cero (linea %d)\n", num_linea);
            exit(1);
        }
        char* new_val = malloc(strlen($1.valor) + strlen($3.valor) + strlen($2) + 2);
        sprintf(new_val, "(%s%s%s)", $1.valor, $2, $3.valor);

        $$.tipo = strdup($1.tipo);
        $$.valor = new_val;

        int tipoNodo;
        if (strcmp($2, "+") == 0) tipoNodo = NODO_SUMA;
        else if (strcmp($2, "-") == 0) tipoNodo = NODO_RESTA;
        else if (strcmp($2, "*") == 0) tipoNodo = NODO_MULT;
        else if (strcmp($2, "/") == 0) tipoNodo = NODO_DIV;
        else tipoNodo = 0;

        $$.n = crearNodoNoTerminal($1.n, $3.n, tipoNodo);

        free($1.tipo); free($1.valor); free($2); free($3.tipo); free($3.valor);
    }
    ;

operador
    : SUMA     { $$ = strdup("+"); }
    | RESTA    { $$ = strdup("-"); }
    | MULTI    { $$ = strdup("*"); }
    | DIVISION { $$ = strdup("/"); }
    ;

valor
    : NUMERICO {
        $$.tipo = strdup("int");
        $$.valor = malloc(12);
        $$.n = crearNodoTerminal($1);
        sprintf($$.valor, "%d", $1);
    }
    | NUMERICODECIMAL {
        $$.tipo = strdup("float");
        $$.valor = malloc(32);
        $$.n = crearNodoTerminal($1);
        sprintf($$.valor, "%.2f", $1);
    }
    | CADENA {
        $$.tipo = strdup("string");
        $$.valor = strdup($1);
        $$.n = NULL;
    }
    | BOOL {
        $$.tipo = strdup("bool");
        $$.valor = strdup($1);
        $$.n = NULL;
    }
    | IDENTIFICADOR {
        int pos = buscarTabla($1);
        if (pos == -1) {
            fprintf(stderr, "[ERROR] Variable '%s' no declarada (linea %d)\n", $1, num_linea);
            exit(1);
        }
        $$.tipo = strdup(tabla[pos].tipo);
        if (strcmp(tabla[pos].tipo, "int") == 0) {
            $$.valor = malloc(12);
            sprintf($$.valor, "%d", tabla[pos].numerico);
        } else if (strcmp(tabla[pos].tipo, "float") == 0) {
            $$.valor = malloc(32);
            sprintf($$.valor, "%.2f", tabla[pos].numericoDecimal);
        } else {
            $$.valor = strdup(tabla[pos].texto);
        }
        $$.n = NULL; // Si tienes nodos para variables, cámbialo por el nodo correspondiente
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
