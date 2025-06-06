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
        char* tipoBase;
        int tam;
        int filas; // Para matrices
        int columnas; // Para matrices
        char* valores;
        char* tipoBaseReal;
        struct ast *n;
    } simbolo;
}

%left OR AND
%right NOT
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
%token IGUALIGUAL DIFERENTE MAYORIGUAL MENORIGUAL MAYOR MENOR AND OR NOT

%type   <simbolo> programa lista_sentencias sentencia asignacion expresion valor
%type   <simbolo> array expresion_array acceso_array indices_array
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

salto: /*vacio*/
    | SALTO salto
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
    | lista_sentencias sentencia salto {
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
        $3.n->es_inicializada = 1;
        if ($3.tipo && strcmp($3.tipo, "matriz") == 0) {
            // Si tienes forma de calcular filas/columnas, ponlo aquí. Si no, déjalo en 0.
            guardar_simbolo_matriz($1, $3.tipo, $3.tipoBase, $3.filas, $3.columnas, $3.valores ? $3.valores : "NULL");
        } else if ($3.tipo && strcmp($3.tipo, "array") == 0) {
            guardar_simbolo_array($1, $3.tipo, $3.tipoBase, $3.tam, $3.valores);
        } else {
            guardar_simbolo($1, $3.tipo, $3.valor);
        }
        $$.tipo = strdup("asignacion");
        $$.valor = NULL;
        $3.n->es_inicializada = 1;
        $$.n = crearNodoAsignacion($1, $3.n);
        mostrar_tabla();
        free($1); free($3.tipo); free($3.valor);
        free($3.tipoBase); free($3.valores);
    }

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
    : CORCHETEABIERTO expresion_array CORCHETECERRADO {
        if ($2.tipoBase && strcmp($2.tipoBase, "array") == 0) {
            $$.tipo = strdup("matriz");
            // Tipo base real: el tipo base del primer subarray
            // Suponemos que $2.valores tiene los valores linealizados y $2.n guarda la estructura
            // Aquí asumimos que guardaste filas y columnas en $2.filas y $2.columnas
            $$.tipoBase = $2.tipoBaseReal ? strdup($2.tipoBaseReal) : strdup("int");
            $$.tam = $2.tam;
            $$.filas = $2.filas;
            $$.columnas = $2.columnas;
        } else {
            $$.tipo = strdup("array");
            $$.tipoBase = strdup($2.tipoBase);
            $$.tam = $2.tam;
            $$.filas = 0;
            $$.columnas = 0;
        }
        $$.valor = NULL;
        $$.valores = strdup($2.valores);
        $$.n = $2.n;
        free($2.tipoBase); free($2.valores);
        if ($2.tipoBaseReal) free($2.tipoBaseReal);
    }
    | CORCHETEABIERTO CORCHETECERRADO {
        $$.tipo = strdup("array");
        $$.valor = NULL;
        $$.tipoBase = strdup("int");
        $$.tam = 0;
        $$.filas = 0;
        $$.columnas = 0;
        $$.valores = strdup("");
        $$.n = NULL;
    }
;

expresion_array
    : expresion SEPARADOR expresion_array {
        if ($1.tipo && strcmp($1.tipo, "array") == 0) {
            $$.tipoBase = strdup($1.tipo);
            $$.tam = $3.tam + 1;
            $$.valores = malloc(strlen($1.valores) + strlen($3.valores) + 2);
            sprintf($$.valores, "%s %s", $1.valores, $3.valores);
            // Para matriz: filas = $3.filas + 1, columnas = columnas del primer subarray
            $$.filas = $3.filas + 1;
            $$.columnas = $1.tam; // Suponiendo que todos los subarrays tienen el mismo tamaño
            $$.tipoBaseReal = $1.tipoBase ? strdup($1.tipoBase) : strdup("int");
        } else {
            $$.tipoBase = strdup($1.tipo);
            $$.tam = $3.tam + 1;
            $$.valores = malloc(strlen($1.valor) + strlen($3.valores) + 2);
            sprintf($$.valores, "%s %s", $1.valor, $3.valores);
            $$.filas = 0;
            $$.columnas = 0;
            $$.tipoBaseReal = NULL;
        }
        $$.n = crearNodoArray($1.n, $3.n);
        free($1.tipo); free($1.valor); free($1.valores); free($1.tipoBase); free($3.tipoBase); free($3.valores); if ($3.tipoBaseReal) free($3.tipoBaseReal);
    }
    | expresion {
        $$.tipoBase = strdup($1.tipo);
        $$.tam = 1;
        if ($1.tipo && strcmp($1.tipo, "array") == 0) {
            $$.valores = strdup($1.valores);
            $$.filas = 1;
            $$.columnas = $1.tam;
            $$.tipoBaseReal = $1.tipoBase ? strdup($1.tipoBase) : strdup("int");
        } else {
            $$.valores = strdup($1.valor);
            $$.filas = 0;
            $$.columnas = 0;
            $$.tipoBaseReal = NULL;
        }
        $$.n = crearNodoArray($1.n, NULL);
        free($1.tipo); free($1.valor); if ($1.tipoBase) free($1.tipoBase);
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
        $$.tipo = strdup($1.tipo); // <-- Propaga "array" o "matriz"
        $$.valor = NULL;
        $$.tipoBase = $1.tipoBase ? strdup($1.tipoBase) : NULL;
        $$.tam = $1.tam;
        $$.valores = $1.valores ? strdup($1.valores) : strdup(""); // <-- Cambia esto
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
        if ((strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0)){
            // Concatenación de cadenas
            $$.tipo = strdup("string");

            // Prepara las cadenas (quita comillas si quieres, opcional)
            char* val1 = $1.valor;
            char* val2 = $3.valor;

            // Quitar comillas alrededor si necesario (opcional)
            // Aquí simplemente concatenamos las representaciones tal como están

            $$.valor = malloc(strlen(val1) + strlen(val2) + 1);
            sprintf($$.valor, "%s%s", val1, val2);

            // Crea un nodo de concatenación (usa NODO_CONCAT si tienes, o NODO_SUMA)
            $$.n = crearNodoOperacion(NODO_CONCAT, $1.n, $3.n); // o NODO_SUMA si no tienes NODO_CONCAT

            free(val1);
            free(val2);
        }
        else {
            if (strcmp($1.tipo, $3.tipo) != 0) {
                fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
                exit(1);
            }
            if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
                fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
                exit(1);
            }
            $$.tipo = strdup($1.tipo);
            // SIEMPRE guarda la expresión textual, no el resultado
            $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
            sprintf($$.valor, "%s+%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
            $$.n = crearNodoOperacion(NODO_SUMA, $1.n, $3.n);
        }
        free($1.tipo); free($3.tipo); free($1.valor); free($3.valor);
    }
    | expresion RESTA expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup($1.tipo);
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s-%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_RESTA, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MULTI expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup($1.tipo);
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s*%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_MULT, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion DIVISION expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion aritmetica no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        printf("%s\n", $3.valor);
        if ((strcmp($3.tipo, "int") == 0 && $3.n && $3.valor == 0) ||
            (strcmp($3.tipo, "float") == 0 && $3.n && $3.n->valor_float == 0.0)) {
            fprintf(stderr, "[ERROR] Division por cero (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup($1.tipo);
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s/%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
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
        $$.tipo = strdup("bool");
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s==%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_IGUALIGUAL, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion DIFERENTE expresion {
        $$.tipo = strdup("bool");
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s!=%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_DIFERENTE, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MENOR expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s<%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_MENOR, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MAYOR expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s>%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_MAYOR, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MENORIGUAL expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s<=%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_MENORIGUAL, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion MAYORIGUAL expresion {
        if (strcmp($1.tipo, $3.tipo) != 0) {
            fprintf(stderr, "[ERROR] Tipos incompatibles: %s y %s (linea %d)\n", $1.tipo, $3.tipo, num_linea);
            exit(1);
        }
        if (strcmp($1.tipo, "string") == 0 || strcmp($3.tipo, "string") == 0 || strcmp($1.tipo, "bool") == 0 || strcmp($3.tipo, "bool") == 0) {
            fprintf(stderr, "[ERROR] Operacion relacional no permitida con tipo string/bool (linea %d)\n", num_linea);
            exit(1);
        }
        $$.tipo = strdup("bool");
        $$.valor = malloc(strlen($1.valor ? $1.valor : "") + strlen($3.valor ? $3.valor : "") + 4);
        sprintf($$.valor, "%s>=%s", $1.valor ? $1.valor : "", $3.valor ? $3.valor : "");
        $$.n = crearNodoOperacion(NODO_MAYORIGUAL, $1.n, $3.n);
        free($1.tipo); free($3.tipo);
    }
    | expresion AND expresion {
        // Validación de tipos
        if (strcmp($1.tipo, "bool") != 0 || strcmp($3.tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica AND requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        $$.tipo = strdup("bool");

        // Evaluación del valor (asumiendo que los valores son "true" o "false")
        int val1 = (strcmp($1.valor, "true") == 0);
        int val2 = (strcmp($3.valor, "true") == 0);

        $$.valor = strdup((val1 && val2) ? "true" : "false");

        // Nodo del AST
        $$.n = crearNodoOperacion(NODO_AND, $1.n, $3.n);

        // Liberar memoria
        free($1.tipo); free($3.tipo); free($1.valor); free($3.valor);
    }
    | expresion OR expresion {
        // Validación de tipos
        if (strcmp($1.tipo, "bool") != 0 || strcmp($3.tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica OR requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        $$.tipo = strdup("bool");

        // Evaluación del valor (asumiendo que los valores son "true" o "false")
        int val1 = (strcmp($1.valor, "true") == 0);
        int val2 = (strcmp($3.valor, "true") == 0);

        $$.valor = strdup((val1 || val2) ? "true" : "false");

        // Nodo del AST
        $$.n = crearNodoOperacion(NODO_OR, $1.n, $3.n);

        // Liberar memoria
        free($1.tipo); free($3.tipo);
        free($1.valor); free($3.valor);
    }
    | NOT expresion {
        // Validación de tipos
        if (strcmp($2.tipo, "bool") != 0) {
            fprintf(stderr, "[ERROR] Operacion logica NOT requiere operandos bool (linea %d)\n", num_linea);
            exit(1);
        }

        $$.tipo = strdup("bool");

        // Evaluación del valor (asumiendo que los valores son "true" o "false")
        int val = (strcmp($2.valor, "true") != 0);

        $$.valor = strdup((val) ? "true" : "false");

        // Nodo del AST
        $$.n = crearNodoNot(NODO_NOT, $2.n);

        // Liberar memoria
        free($2.tipo);
        free($2.valor);
    }
    ;
    

valor
    : NUMERICO {
        $$.tipo = strdup("int");
        $$.valor = malloc(12);
        sprintf($$.valor, "%d", $1);
        $$.n = crearNodoNumero($1);
    }
    | RESTA NUMERICO {
        $2 = -$2; // Negar el número
        $$.tipo = strdup("int");
        $$.valor = malloc(12);
        sprintf($$.valor, "%d", $2);
        $$.n = crearNodoNumero($2);
    }
    | NUMERICODECIMAL {
        $$.tipo = strdup("float");
        $$.valor = malloc(32);
        sprintf($$.valor, "%.2f", $1);
        $$.n = crearNodoFloat($1);
    }
    | RESTA NUMERICODECIMAL {
        $2 = -$2; // Negar el número
        $$.tipo = strdup("float");
        $$.valor = malloc(32);
        sprintf($$.valor, "%.2f", $2);
        $$.n = crearNodoFloat($2);
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
        // Si es array o matriz, usa sus valores linealizados
        if (tabla[pos].tipo && (strcmp(tabla[pos].tipo, "array") == 0 || strcmp(tabla[pos].tipo, "matriz") == 0)) {
            $$.valor = tabla[pos].Valores ? strdup(tabla[pos].Valores) : strdup("");
        } else {
            $$.valor = tabla[pos].valor ? strdup(tabla[pos].valor) : strdup("");
        }
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
