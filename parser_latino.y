%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

extern int yylex();
extern int num_linea;
extern FILE* yyin;

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
    } simbolo;
}

%token <enteroVal> NUMERICO
%token <realVal> NUMERICODECIMAL
%token <stringVal> IDENTIFICADOR CADENA BOOL 
%token SUMA RESTA MULTI DIVISION CORCHETEABIERTO CORCHETECERRADO SEPARADOR IGUAL

%type <simbolo> valor expresion
%type <stringVal> operador array array2

%start axioma

%%

//S -> lambda | S A Sa
axioma:
    /* vacio */
  | axioma asignacion salto
  ;

salto:
    '\n' 
  | /* vacio */
  ;

asignacion:
    IDENTIFICADOR IGUAL expresion {
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
        
        printf("[OK] Asignacion valida -> %s = %s (tipo: %s)\n", $1, $3.valor, $3.tipo);
        mostrar_tabla();
        free($1);
        free($3.tipo);
        free($3.valor);
    }
  ;

array:
    CORCHETEABIERTO array2 CORCHETECERRADO {
        $$ = strdup("array");  
        free($2);
    }
  | CORCHETEABIERTO CORCHETECERRADO {
        $$ = strdup("array");
    }
  ;

array2:
    expresion SEPARADOR array2 {
        char* temp = malloc(strlen($1.valor) + strlen($3) + 2);
        sprintf(temp, "%s,%s", $1.valor, $3);
        $$ = temp;
        free($1.tipo);
        free($1.valor);
        free($3);
    }
  | expresion {
        $$ = strdup($1.valor);
        free($1.tipo);
        free($1.valor);
    }
  ;

expresion:
    valor {
        $$.tipo = strdup($1.tipo);
        $$.valor = strdup($1.valor);
    }
  | array {
        $$.tipo = strdup("array");
        $$.valor = strdup($1);
        free($1);
    }
  | expresion operador valor {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr,
                    "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n",
                    $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        
        if (strcmp($2, "/") == 0) {
            if (strcmp($3.valor, "0") == 0 || strcmp($3.valor, "0.0") == 0) {
                fprintf(stderr, "[ERROR] Division por cero (linea %d)\n", num_linea);
                exit(1);
            }
        }
        
        char* new_val = malloc(strlen($1.valor) + strlen($3.valor) + strlen($2) + 2);
        sprintf(new_val, "(%s%s%s)", $1.valor, $2, $3.valor);
        
        $$.tipo = strdup($1.tipo);
        $$.valor = new_val;
        
        free($1.tipo);
        free($1.valor);
        free($2);
        free($3.tipo);
        free($3.valor);
    }
  ;

operador:
    SUMA     { $$ = strdup("+"); }
  | RESTA    { $$ = strdup("-"); }
  | MULTI    { $$ = strdup("*"); }
  | DIVISION { $$ = strdup("/"); }
  ;

valor:
    NUMERICO {
        $$.tipo = strdup("int");
        $$.valor = malloc(12);
        sprintf($$.valor, "%d", $1);
    }
  | NUMERICODECIMAL {
        $$.tipo = strdup("float");
        $$.valor = malloc(32);
        sprintf($$.valor, "%.2f", $1);
    }
  | CADENA {
        $$.tipo = strdup("string");
        $$.valor = strdup($1);
    }
  | BOOL {
        $$.tipo = strdup("bool");
        $$.valor = strdup($1);
    }
  | IDENTIFICADOR {
        int pos = buscarTabla($1);
        if (pos == -1) {
            fprintf(stderr,
                    "[ERROR] Variable '%s' no declarada (linea %d)\n",
                    $1, num_linea);
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
    printf("Analizando...\n");
    yyparse();
    return 0;
}