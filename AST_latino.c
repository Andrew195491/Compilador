#include "AST_latino.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Variable global para el archivo de salida
extern FILE *yyout;

#define MAX_VARS 100
char *lista_vars[MAX_VARS];
int num_vars = 0;

void registrar_variable(const char *nombre) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(lista_vars[i], nombre) == 0)
            return;
    }
    if (num_vars < MAX_VARS) {
        lista_vars[num_vars++] = strdup(nombre);
    }
}

void limpiar_variables() {
    for (int i = 0; i < num_vars; i++)
        free(lista_vars[i]);
    num_vars = 0;
}

// ======== Construcción del AST ========

struct ast *crearNodoLista(struct ast *izq, struct ast *dcha) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_LISTA;
    n->izq = izq;
    n->dcha = dcha;
    n->nombre = NULL; n->valor_str = NULL;
    return n;
}

struct ast *crearNodoAsignacion(const char* nombre, struct ast *valor) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_ASIGNACION;
    n->nombre = strdup(nombre);
    n->izq = valor;
    n->dcha = NULL;
    n->valor_str = NULL;
    return n;
}

struct ast *crearNodoOperacion(enum tipoNodoAST tipo, struct ast *izq, struct ast *dcha) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = tipo;
    n->izq = izq;
    n->dcha = dcha;
    n->nombre = NULL; n->valor_str = NULL;
    return n;
}

struct ast *crearNodoNumero(int valor) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_NUMERO;
    n->valor_int = valor;
    n->izq = n->dcha = NULL;
    n->nombre = NULL; n->valor_str = NULL;
    return n;
}

struct ast *crearNodoFloat(float valor) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_FLOAT;
    n->valor_float = valor;
    n->izq = n->dcha = NULL;
    n->nombre = NULL; n->valor_str = NULL;
    return n;
}

struct ast *crearNodoString(const char* valor) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_STRING;
    n->valor_str = strdup(valor);
    n->izq = n->dcha = NULL;
    n->nombre = NULL;
    return n;
}

struct ast *crearNodoBool(const char* valor) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_BOOL;
    n->valor_str = strdup(valor);
    n->izq = n->dcha = NULL;
    n->nombre = NULL;
    return n;
}

struct ast *crearNodoVariable(const char* nombre) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_VARIABLE;
    n->nombre = strdup(nombre);
    n->izq = n->dcha = NULL;
    n->valor_str = NULL;
    return n;
}

// Array de 1D o anidado (array de arrays)
struct ast *crearNodoArray(struct ast *elemento, struct ast *siguiente) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_ARRAY;
    n->izq = elemento;   // primer elemento (puede ser número o array)
    n->dcha = siguiente; // resto de la lista
    n->nombre = NULL; n->valor_str = NULL;
    return n;
}

// Acceso a array: para arr[i] o arr[i][j] (anidado)
struct ast *crearNodoAccesoArray(const char *nombre, struct ast *indice) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_ACCESO_ARRAY;
    n->nombre = strdup(nombre);
    n->izq = indice;  // Para 1D: índice; para 2D: nodo NODO_ACCESO_ARRAY anidado
    n->dcha = NULL;
    n->valor_str = NULL;
    return n;
}

// ======== Liberación del AST ========

void liberarAST(struct ast *n) {
    if (!n) return;
    if (n->nombre) free(n->nombre);
    if (n->valor_str) free(n->valor_str);
    liberarAST(n->izq);
    liberarAST(n->dcha);
    free(n);
}

// ======== Recorrido para impresión (opcional) ========

void recorrerAST(struct ast *n) {
    if (!n) return;
    switch(n->tipoNodo) {
        case NODO_LISTA:
            recorrerAST(n->izq);
            recorrerAST(n->dcha);
            break;
        case NODO_ASIGNACION:
            printf("%s = ", n->nombre);
            recorrerAST(n->izq);
            printf(";\n");
            break;
        case NODO_SUMA:
            printf("("); recorrerAST(n->izq); printf(" + "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_RESTA:
            printf("("); recorrerAST(n->izq); printf(" - "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_MULT:
            printf("("); recorrerAST(n->izq); printf(" * "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_DIV:
            printf("("); recorrerAST(n->izq); printf(" / "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_NUMERO:
            printf("%d", n->valor_int);
            break;
        case NODO_FLOAT:
            printf("%f", n->valor_float);
            break;
        case NODO_STRING:
            printf("\"%s\"", n->valor_str);
            break;
        case NODO_BOOL:
            printf("%s", n->valor_str);
            break;
        case NODO_VARIABLE:
            printf("%s", n->nombre);
            break;
        case NODO_ARRAY: {
            printf("[");
            struct ast *elem = n;
            while (elem) {
                recorrerAST(elem->izq);
                if (elem->dcha) printf(", ");
                elem = elem->dcha;
            }
            printf("]");
            break;
        }
        case NODO_ACCESO_ARRAY:
            printf("%s[", n->nombre);
            recorrerAST(n->izq);
            printf("]");
            break;
    }
}

// ======== Recolectar variables del AST ========

void recolectar_vars(struct ast *nodo) {
    if (!nodo) return;
    if (nodo->tipoNodo == NODO_ASIGNACION || nodo->tipoNodo == NODO_VARIABLE)
        registrar_variable(nodo->nombre);
    recolectar_vars(nodo->izq);
    recolectar_vars(nodo->dcha);
}

// ======== Generación de ensamblador ========

static int temp_counter = 0;
const char* nuevo_temp() {
    static char buffer[10][5];
    int idx = temp_counter % 10;
    sprintf(buffer[idx], "$t%d", idx);
    temp_counter++;
    return buffer[idx];
}

// Cuenta elementos de un array (útil para reservar espacio)
int contar_elementos_array(struct ast *n) {
    int count = 0;
    struct ast *elem = n;
    while (elem) {
        count++;
        elem = elem->dcha;
    }
    return count;
}

// Generación de ensamblador para arrays (acceso 1D y 2D)
const char* generarASM_rec(struct ast *n) {
    if (!n) return NULL;

    switch(n->tipoNodo) {
        case NODO_NUMERO: {
            const char* reg = nuevo_temp();
            fprintf(yyout, "    li %s, %d\n", reg, n->valor_int);
            return reg;
        }
        case NODO_BOOL: {
            const char* reg = nuevo_temp();
            int val = (strcmp(n->valor_str, "true") == 0) ? 1 : 0;
            fprintf(yyout, "    li %s, %d\n", reg, val);
            return reg;
        }
        case NODO_VARIABLE: {
            const char* reg = nuevo_temp();
            registrar_variable(n->nombre);
            fprintf(yyout, "    lw %s, %s\n", reg, n->nombre);
            return reg;
        }
        case NODO_SUMA: {
            const char* reg_izq = generarASM_rec(n->izq);
            const char* reg_dcha = generarASM_rec(n->dcha);
            const char* reg = nuevo_temp();
            fprintf(yyout, "    add %s, %s, %s\n", reg, reg_izq, reg_dcha);
            return reg;
        }
        case NODO_RESTA: {
            const char* reg_izq = generarASM_rec(n->izq);
            const char* reg_dcha = generarASM_rec(n->dcha);
            const char* reg = nuevo_temp();
            fprintf(yyout, "    sub %s, %s, %s\n", reg, reg_izq, reg_dcha);
            return reg;
        }
        case NODO_MULT: {
            const char* reg_izq = generarASM_rec(n->izq);
            const char* reg_dcha = generarASM_rec(n->dcha);
            const char* reg = nuevo_temp();
            fprintf(yyout, "    mul %s, %s, %s\n", reg, reg_izq, reg_dcha);
            return reg;
        }
        case NODO_DIV: {
            const char* reg_izq = generarASM_rec(n->izq);
            const char* reg_dcha = generarASM_rec(n->dcha);
            const char* reg = nuevo_temp();
            fprintf(yyout, "    div %s, %s, %s\n", reg, reg_izq, reg_dcha);
            return reg;
        }
        case NODO_ASIGNACION: {
            const char* reg = generarASM_rec(n->izq);
            registrar_variable(n->nombre);
            fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
            return reg;
        }
        case NODO_ARRAY: {
            // Solo recorre los elementos, útil para depuración
            struct ast *elem = n;
            while (elem) {
                generarASM_rec(elem->izq);
                elem = elem->dcha;
            }
            return NULL;
        }
        case NODO_ACCESO_ARRAY: {
            // Soporta acceso 1D: arr[i]
            // Y acceso 2D: arr[i][j] (n->izq es otro NODO_ACCESO_ARRAY)
            // Acceso 2D: arr[i][j] -> NODO_ACCESO_ARRAY(nombre=arr, izq=NODO_ACCESO_ARRAY(nombre=NULL, izq=fila, dcha=columna))
            if (n->izq && n->izq->tipoNodo == NODO_ACCESO_ARRAY) {
                // 2D: arr[i][j]
                // n->nombre = "arr"
                // n->izq->izq = fila, n->izq->dcha = columna
                const char* reg_fila = generarASM_rec(n->izq->izq);
                const char* reg_col = generarASM_rec(n->izq->dcha);
                const int NUM_COLUMNAS = 10; // Cambia esto según tu array real
                const char* reg_cols = nuevo_temp();
                fprintf(yyout, "    li %s, %d\n", reg_cols, NUM_COLUMNAS);
                const char* reg_ofs = nuevo_temp();
                fprintf(yyout, "    mul %s, %s, %s\n", reg_ofs, reg_fila, reg_cols);
                fprintf(yyout, "    add %s, %s, %s\n", reg_ofs, reg_ofs, reg_col);
                fprintf(yyout, "    mul %s, %s, 4\n", reg_ofs, reg_ofs);
                const char* reg_base = nuevo_temp();
                fprintf(yyout, "    la %s, %s\n", reg_base, n->nombre);
                const char* reg_dir = nuevo_temp();
                fprintf(yyout, "    add %s, %s, %s\n", reg_dir, reg_base, reg_ofs);
                const char* reg_val = nuevo_temp();
                fprintf(yyout, "    lw %s, 0(%s)\n", reg_val, reg_dir);
                return reg_val;
            } else {
                // 1D: arr[i]
                const char* reg_indice = generarASM_rec(n->izq);
                const char* reg_ofs = nuevo_temp();
                fprintf(yyout, "    mul %s, %s, 4\n", reg_ofs, reg_indice);
                const char* reg_base = nuevo_temp();
                fprintf(yyout, "    la %s, %s\n", reg_base, n->nombre);
                const char* reg_dir = nuevo_temp();
                fprintf(yyout, "    add %s, %s, %s\n", reg_dir, reg_base, reg_ofs);
                const char* reg_val = nuevo_temp();
                fprintf(yyout, "    lw %s, 0(%s)\n", reg_val, reg_dir);
                return reg_val;
            }
        }
        case NODO_LISTA: {
            generarASM_rec(n->izq);
            generarASM_rec(n->dcha);
            return NULL;
        }
        default:
            break;
    }
    return NULL;
}

// ======== Función principal de generación de ensamblador ========

void generarASM(struct ast *n) {
    temp_counter = 0;
    limpiar_variables();

    // 1. Recolectar variables del AST
    recolectar_vars(n);

    // 2. Sección .data
    fprintf(yyout, ".data\n");
    for (int i = 0; i < num_vars; i++)
        fprintf(yyout, "%s: .word 0:100\n", lista_vars[i]); // Reserva 100 elementos por defecto
    fprintf(yyout, "\n");

    // 3. Sección .text y main
    fprintf(yyout, ".text\n.globl main\nmain:\n");

    // 4. Código de instrucciones
    generarASM_rec(n);

    // 5. Salida limpia de MIPS
    fprintf(yyout, "    li $v0, 10\n    syscall\n");
}
