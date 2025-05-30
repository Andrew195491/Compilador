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

%left IGUALIGUAL DIFERENTE MAYORIGUAL MENORIGUAL MAYOR MENOR
%left SUMA RESTA
%left MULTI DIVISION
%left PARENIZQ PARENDER

%token <enteroVal> NUMERICO
%token <realVal> NUMERICODECIMAL
%token <stringVal> IDENTIFICADOR CADENA BOOL


%token  SUMA RESTA MULTI DIVISION
%token  CORCHETEABIERTO CORCHETECERRADO
%token  SEPARADOR IGUAL SALTO
%token  PARENIZQ PARENDER
%token  IF ELSE WHILE FOR
%token  PUTS
%token  END DEF
%token  INTERP_INI INTERP_FIN
%token IGUALIGUAL DIFERENTE MAYORIGUAL MENORIGUAL MAYOR MENOR

%type   <simbolo> programa lista_sentencias sentencia asignacion expresion valor
%type   <simbolo> array array2 acceso_array indices_array
%type   <simbolo> if_else_end while_end funcion_definicion llamada_funcion parametros parametros_opt argumentos argumentos_opt


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
    | SALTO
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
    | PUTS expresion  {
        $$.tipo = strdup("puts");
        $$.valor = NULL;
        $$.n = crearNodoPuts($2.n);
        free($2.tipo); free($2.valor);
    }
    | if_else_end {
        $$.tipo = strdup("if_else");
        $$.valor = NULL;
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | while_end {
        $$.tipo = strdup("while");
        $$.valor = NULL;
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | funcion_definicion {
        $$.tipo = strdup("funcion_definicion");
        $$.valor = NULL;
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    | llamada_funcion {
        $$.tipo = strdup("llamada_funcion");
        $$.valor = NULL;
        $$.n = $1.n;
        free($1.tipo); free($1.valor);
    }
    ;

asignacion
    : IDENTIFICADOR IGUAL expresion {
        guardar_simbolo($1,$3.tipo, $3.valor);
        $$.tipo = strdup("asignacion");
        $$.valor = NULL;
        $$.n = crearNodoAsignacion($1, $3.n);
        mostrar_tabla();
        free($1); free($3.tipo); free($3.valor);
        
    }
    ;

if_else_end
    : IF expresion salto lista_sentencias END {
        // if sin else
        $$.tipo = strdup("if");
        $$.valor = NULL;
        $$.n = crearNodoIf($2.n, $4.n, NULL);
        free($2.tipo); free($2.valor); free($4.tipo); free($4.valor);
    }
    | IF expresion salto lista_sentencias ELSE salto lista_sentencias END {
        // if con else
        $$.tipo = strdup("if_else");
        $$.valor = NULL;
        $$.n = crearNodoIf($2.n, $4.n, $7.n);
        free($2.tipo); free($2.valor); free($4.tipo); free($4.valor); free($7.tipo); free($7.valor);
    }
    ;


while_end
    : WHILE expresion salto lista_sentencias END {
        $$.tipo = strdup("while");
        $$.valor = NULL;
        $$.n = crearNodoWhile($2.n, $4.n);
        free($2.tipo); free($2.valor); free($4.tipo); free($4.valor);
    }
    ;

funcion_definicion
    : DEF IDENTIFICADOR PARENIZQ parametros_opt PARENDER salto lista_sentencias END {
        $$.tipo = strdup("funcion");
        $$.valor = strdup($2);
        $$.n = crearNodoFuncion($2, $4.n, $7.n); // nombre, parámetros, cuerpo
        free($2); free($4.tipo); free($4.valor); free($7.tipo); free($7.valor);
    }
    | DEF IDENTIFICADOR salto lista_sentencias END {
        // Definición sin paréntesis ni parámetros
        $$.tipo = strdup("funcion");
        $$.valor = strdup($2);
        $$.n = crearNodoFuncion($2, NULL, $4.n);
        free($2); free($4.tipo); free($4.valor);
    }
    ;


parametros_opt
    : /* vacío */ { $$.tipo = strdup("parametros"); $$.valor = NULL; $$.n = NULL; }
    | parametros
    ;

parametros
    : IDENTIFICADOR {
        $$.tipo = strdup("parametros");
        $$.valor = NULL;
        $$.n = crearNodoParametro($1, NULL);
        free($1);
    }
    | parametros SEPARADOR IDENTIFICADOR {
        $$.tipo = strdup("parametros");
        $$.valor = NULL;
        $$.n = crearNodoParametro($3, $1.n);
        free($3);
    }
    ;


llamada_funcion
    : IDENTIFICADOR argumentos_opt {
        $$.tipo = strdup("llamada_funcion");
        $$.valor = strdup($1);
        $$.n = crearNodoLlamadaFuncion($1, $2.n);
        free($1); free($2.tipo); free($2.valor);
    }
    ;

argumentos_opt
    : /* vacío */ { $$.tipo = strdup("argumentos"); $$.valor = NULL; $$.n = NULL; }
    | PARENIZQ argumentos PARENDER { $$.tipo = strdup("argumentos"); $$.valor = NULL; $$.n = $2.n; free($2.tipo); free($2.valor);}
    ;

argumentos
    : expresion {
        $$.tipo = strdup("argumentos");
        $$.valor = NULL;
        $$.n = crearNodoArgumento($1.n, NULL);
        free($1.tipo); free($1.valor);
    }
    | argumentos SEPARADOR expresion {
        $$.tipo = strdup("argumentos");
        $$.valor = NULL;
        $$.n = crearNodoArgumento($3.n, $1.n);
        free($3.tipo); free($3.valor);
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
       // $$.tipo = strdup("array");
        //$$.valor = NULL;
        //$$.n = crearNodoArray($1.n, $3.n);
        //free($1.tipo); free($1.valor); free($3.tipo); free($3.valor);
    }
    | expresion {
        //$$.tipo = strdup("array");
        //$$.valor = NULL;
        //$$.n = crearNodoArray($1.n, NULL);
        //free($1.tipo); free($1.valor);
    }
    ;

acceso_array
    : IDENTIFICADOR indices_array {
        //$$.tipo = strdup("acceso_array");
        //$$.valor = NULL;
        //$$.n = crearNodoAccesoArray($1, $2.n);
        //free($1); free($2.tipo); free($2.valor);
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
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
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
         if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
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
         if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
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
         if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0) {
            fprintf(stderr, "[ERROR] Operación aritmética no permitida con tipo string (línea %d)\n", num_linea);
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
    | expresion IGUALIGUAL expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_IGUALIGUAL, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion DIFERENTE expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_DIFERENTE, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MENOR expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_MENOR, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MAYOR expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_MAYOR, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MENORIGUAL expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_MENORIGUAL, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MAYORIGUAL expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = NULL;
        $$.n = crearNodoOperacion(NODO_MAYORIGUAL, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
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
        int pos = buscarTabla($1);
        if (pos == -1){
            fprintf(stderr, "ERROR, LA VARIABLE  '%s' NO ESTA DECLARADA EN (linea %d)\n", $1, num_linea);
            exit(1);
        }
        $$.tipo = strdup(tabla[pos].tipo);
        $$.valor = strdup(tabla[pos].valor);
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
