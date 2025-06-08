#include "Arbol_ABS.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "Tabla_Simbolos.h"

extern FILE *yyout;

#define MAX_VARS 100
char *lista_vars[MAX_VARS];
char* inicializada[MAX_VARS];
static int label_counter = 0;
int num_vars = 0;
int primera_concat = 1;
const char* nombres_nodo[] = {
    "NODO_LISTA",
    "NODO_ASIGNACION",
    "NODO_SUMA",
    "NODO_RESTA",
    "NODO_MULT",
    "NODO_DIV",
    "NODO_NUMERO",
    "NODO_FLOAT",
    "NODO_STRING",
    "NODO_BOOL",
    "NODO_VARIABLE",
    "NODO_PUTS",
    "NODO_WHILE",
    "NODO_IF",
    "NODO_ELSE",
    "NODO_IGUALIGUAL",
    "NODO_DIFERENTE",
    "NODO_MENOR",
    "NODO_MENORIGUAL",
    "NODO_MAYOR",
    "NODO_MAYORIGUAL",
    "NODO_AND",
    "NODO_OR",
    "NODO_NOT"
};

int float_label_counter = 0;

static char* strdup_safe(const char* s) {
    if (!s) return NULL;
    char* copy = malloc(strlen(s) + 1);
    if (copy) strcpy(copy, s);
    return copy;
}

void registrar_variable(const char *nombre) {
    if (!nombre) return;
    for (int i = 0; i < num_vars; i++) {
        if (lista_vars[i] && strcmp(lista_vars[i], nombre) == 0){
            printf("Vars: %s\n", lista_vars[i]);
            return;
        }
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
    n->es_inicializada = 0;
    return n;
}

struct ast *crearNodoFloat(float valor) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_FLOAT;
    n->valor_float = valor;
    n->izq = n->dcha = NULL;
    n->nombre = NULL; 
    n->valor_str = malloc(32);
    n->es_inicializada = 0;
    
    sprintf(n->valor_str, "float_%d", float_label_counter++);
    return n;
}

struct ast *crearNodoString(const char* valor) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_STRING;
    n->valor_str = strdup(valor);
    n->izq = n->dcha = NULL;
    n->nombre = NULL;
    n->es_inicializada = 0;
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

struct ast *crearNodoPuts(struct ast *expresion) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_PUTS;
    n->izq = expresion;
    n->nombre = NULL;
    n->dcha = NULL;
    n->valor_str = NULL;
    return n;
}

struct ast* crearNodoIf(struct ast* condicion, struct ast* cuerpo, struct ast* else_cuerpo) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipoNodo = NODO_IF;
    nodo->izq = condicion;

    nodo->dcha = crearNodoLista(cuerpo, else_cuerpo);
    return nodo;
}

struct ast* crearNodoWhile(struct ast* condicion, struct ast* cuerpo) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipoNodo = NODO_WHILE;
    nodo->izq = condicion;
    nodo->dcha = cuerpo;
    nodo->nombre = NULL;
    nodo->valor_str = NULL;
    nodo->valor_int = 0;
    nodo->valor_float = 0.0f;
    return nodo;
}


struct ast* crearNodoConcat(struct ast* izq, struct ast* dcha) {
    struct ast* n = malloc(sizeof(struct ast));
    n->tipoNodo = NODO_CONCAT;
    n->izq = izq;
    n->dcha = dcha;
    n->nombre = NULL;
    n->valor_str = NULL;
    n->es_inicializada = 0;
    return n;
}


struct ast* crearNodoArray(struct ast* elemento, struct ast* siguiente) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipoNodo = NODO_ARRAY;
    nodo->izq = elemento;
    nodo->dcha = siguiente;
    nodo->nombre = NULL;
    nodo->valor_str = NULL;
    nodo->valor_int = 0;
    nodo->valor_float = 0.0f;
    nodo->es_inicializada = 0;
    return nodo;
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

// ======== Generación de ensamblador ========

static int temp_counter = 0;

const char* nuevo_temp() {
    static char buffer[10][5];
    int idx = temp_counter % 10;
    sprintf(buffer[idx], "$t%d", idx);
    temp_counter++;
    return buffer[idx];
}

const char* nuevo_temp_float() {
    static int temp_float_counter = 12;
    static char buffer[10][6];
    int idx = (temp_float_counter - 12) % 10;
    sprintf(buffer[idx], "$f%d", temp_float_counter);
    temp_float_counter++;
    if (temp_float_counter > 19) temp_float_counter = 12;
    return buffer[idx];
}


const char* nuevo_label() {
    static char buffer[10][16];
    int idx = label_counter % 10;
    sprintf(buffer[idx], "L%d", label_counter++);
    return buffer[idx];
}

const char* generarASM_rec(struct ast *n);

void generar_puts(struct ast *expresion) {
    if (!expresion) return;

    const char* reg = generarASM_rec(expresion);
    int pos = -1;

    switch (expresion->tipoNodo) {
        case NODO_STRING:
            for (int i = 0; i < indice; i++) {
                if (tabla[i].valor && strcmp(tabla[i].valor, expresion->valor_str) == 0) {
                    pos = i;
                    break;
                }
            }
            if (pos >= 0) {
                fprintf(yyout, "    la $a0, %s\n", tabla[pos].nombre);
                fprintf(yyout, "    li $v0, 4\n");
            }
            break;
        case NODO_NUMERO:
            fprintf(yyout, "    li $a0, %d\n", expresion->valor_int);
            fprintf(yyout, "    li $v0, 1\n");
            fprintf(yyout, "    syscall\n");
            break;
        case NODO_FLOAT:
            if (strcmp(reg, "$f12") != 0) {
                fprintf(yyout, "    mov.s $f12, %s\n", reg);
            }
            fprintf(yyout, "    li $v0, 2\n");
            fprintf(yyout, "    syscall\n");
            break;
        case NODO_VARIABLE: {
            const char* tipo = obtener_tipo(expresion->nombre);
                if (tipo && strcmp(tipo, "float") == 0) {
                    if (strcmp(reg, "$f12") != 0) {
                        fprintf(yyout, "    mov.s $f12, %s\n", reg);
                    }
                    fprintf(yyout, "    li $v0, 2\n");
                    fprintf(yyout, "    syscall\n");
                    return;
                } else if (tipo && strcmp(tipo, "string") == 0) {
                    int pos = buscarTabla(expresion->nombre);
                    if (pos >= 0 && tabla[pos].valor && strcmp(tabla[pos].valor, "buffer_concat") == 0) {
                        fprintf(yyout, "    la $a0, buffer_concat\n");
                    } else {
                        fprintf(yyout, "    move $a0, %s\n", reg);
                    }
                    fprintf(yyout, "    li $v0, 4\n");
                    fprintf(yyout, "    syscall\n");
                    return;
                }
                else if (tipo && (strcmp(tipo, "array") == 0)) {
                    int pos = buscarTabla(expresion->nombre);
                    if (pos >= 0 && tabla[pos].tipoBase) {
                        int tam = tabla[pos].Tamanio;
                        if (strcmp(tabla[pos].tipoBase, "float") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n");
                            fprintf(yyout, "    li $t2, %d\n", tam);
                            fprintf(yyout, "print_%s_loop:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t2, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    sll $t3, $t1, 2\n");
                            fprintf(yyout, "    add $t4, $t0, $t3\n");
                            fprintf(yyout, "    lwc1 $f12, 0($t4)\n");
                            fprintf(yyout, "    li $v0, 2\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    li $a0, 10\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t1, $t1, 1\n");
                            fprintf(yyout, "    j print_%s_loop\n", expresion->nombre);
                            fprintf(yyout, "print_%s_end:\n", expresion->nombre);
                        }
                        else if (strcmp(tabla[pos].tipoBase, "int") == 0 || strcmp(tabla[pos].tipoBase, "bool") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n");
                            fprintf(yyout, "    li $t2, %d\n", tam);
                            fprintf(yyout, "print_%s_loop:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t2, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    sll $t3, $t1, 2\n");
                            fprintf(yyout, "    add $t4, $t0, $t3\n");
                            fprintf(yyout, "    lw $a0, 0($t4)\n");
                            fprintf(yyout, "    li $v0, 1\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    li $a0, 10\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t1, $t1, 1\n");
                            fprintf(yyout, "    j print_%s_loop\n", expresion->nombre);
                            fprintf(yyout, "print_%s_end:\n", expresion->nombre);
                        }
                        else if (strcmp(tabla[pos].tipoBase, "string") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n");
                            fprintf(yyout, "    li $t2, %d\n", tam);
                            fprintf(yyout, "print_%s_loop:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t2, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    sll $t3, $t1, 2\n");
                            fprintf(yyout, "    add $t4, $t0, $t3\n");
                            fprintf(yyout, "    lw $a0, 0($t4)\n");
                            fprintf(yyout, "    li $v0, 4\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    li $a0, 10\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t1, $t1, 1\n");
                            fprintf(yyout, "    j print_%s_loop\n", expresion->nombre);
                            fprintf(yyout, "print_%s_end:\n", expresion->nombre);
                        }
                    }
                    return;
                }
                else if (tipo && strcmp(tipo, "matriz") == 0) {
                    int pos = buscarTabla(expresion->nombre);
                    if (pos >= 0 && tabla[pos].tipoBase) {
                        int filas = tabla[pos].Filas;
                        int columnas = tabla[pos].Columnas;
                        if (strcmp(tabla[pos].tipoBase, "int") == 0 || strcmp(tabla[pos].tipoBase, "bool") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n"); 
                            fprintf(yyout, "    li $t3, %d\n", filas);
                            fprintf(yyout, "    li $t4, %d\n", columnas);
                            fprintf(yyout, "print_%s_outer:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t3, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    li $t2, 0\n");
                            fprintf(yyout, "print_%s_inner:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t2, $t4, print_%s_next_row\n", expresion->nombre);
                            fprintf(yyout, "    mul $t5, $t1, $t4\n");
                            fprintf(yyout, "    add $t5, $t5, $t2\n");
                            fprintf(yyout, "    sll $t5, $t5, 2\n");
                            fprintf(yyout, "    add $t6, $t0, $t5\n");
                            fprintf(yyout, "    lw $a0, 0($t6)\n");
                            fprintf(yyout, "    li $v0, 1\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    li $a0, 32\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t2, $t2, 1\n");
                            fprintf(yyout, "    j print_%s_inner\n", expresion->nombre);
                            fprintf(yyout, "print_%s_next_row:\n", expresion->nombre);
                            fprintf(yyout, "    li $a0, 10\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t1, $t1, 1\n");
                            fprintf(yyout, "    j print_%s_outer\n", expresion->nombre);
                            fprintf(yyout, "print_%s_end:\n", expresion->nombre);
                        }
                        else if (strcmp(tabla[pos].tipoBase, "float") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n");
                            fprintf(yyout, "    li $t3, %d\n", filas);
                            fprintf(yyout, "    li $t4, %d\n", columnas);
                            fprintf(yyout, "print_%s_outer:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t3, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    li $t2, 0\n");
                            fprintf(yyout, "print_%s_inner:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t2, $t4, print_%s_next_row\n", expresion->nombre);
                            fprintf(yyout, "    mul $t5, $t1, $t4\n");
                            fprintf(yyout, "    add $t5, $t5, $t2\n");
                            fprintf(yyout, "    sll $t5, $t5, 2\n");
                            fprintf(yyout, "    add $t6, $t0, $t5\n");
                            fprintf(yyout, "    lwc1 $f12, 0($t6)\n");
                            fprintf(yyout, "    li $v0, 2\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    li $a0, 32\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t2, $t2, 1\n");
                            fprintf(yyout, "    j print_%s_inner\n", expresion->nombre);
                            fprintf(yyout, "print_%s_next_row:\n", expresion->nombre);
                            fprintf(yyout, "    li $a0, 10\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t1, $t1, 1\n");
                            fprintf(yyout, "    j print_%s_outer\n", expresion->nombre);
                            fprintf(yyout, "print_%s_end:\n", expresion->nombre);
                        }
                        else if (strcmp(tabla[pos].tipoBase, "string") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n");
                            fprintf(yyout, "    li $t3, %d\n", filas);
                            fprintf(yyout, "    li $t4, %d\n", columnas);
                            fprintf(yyout, "print_%s_outer:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t3, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    li $t2, 0\n");
                            fprintf(yyout, "print_%s_inner:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t2, $t4, print_%s_next_row\n", expresion->nombre);
                            fprintf(yyout, "    mul $t5, $t1, $t4\n");
                            fprintf(yyout, "    add $t5, $t5, $t2\n");
                            fprintf(yyout, "    sll $t5, $t5, 2\n");
                            fprintf(yyout, "    add $t6, $t0, $t5\n");
                            fprintf(yyout, "    lw $a0, 0($t6)\n");
                            fprintf(yyout, "    li $v0, 4\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    li $a0, 32\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t2, $t2, 1\n");
                            fprintf(yyout, "    j print_%s_inner\n", expresion->nombre);
                            fprintf(yyout, "print_%s_next_row:\n", expresion->nombre);
                            fprintf(yyout, "    li $a0, 10\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    addi $t1, $t1, 1\n");
                            fprintf(yyout, "    j print_%s_outer\n", expresion->nombre);
                            fprintf(yyout, "print_%s_end:\n", expresion->nombre);
                        }
                    }
                    return;
                }
                fprintf(yyout, "    li $v0, 1\n");
                fprintf(yyout, "    move $a0, %s\n", reg);
                break;
            }
                    case NODO_BOOL:
                        fprintf(yyout, "    li $v0, 1\n");
                        fprintf(yyout, "    move $a0, %s\n", reg);
                        break;
                    default:
                        if (reg) {
                            fprintf(yyout, "    li $v0, 1\n");
                            fprintf(yyout, "    move $a0, %s\n", reg);
                            fprintf(yyout, "    syscall\n");
                            fprintf(yyout, "    li $a0, 10\n");
                            fprintf(yyout, "    li $v0, 11\n");
                            fprintf(yyout, "    syscall\n");
                        }
                        return;
                }

    fprintf(yyout, "    syscall\n");

    fprintf(yyout, "    li $a0, 10\n");
    fprintf(yyout, "    li $v0, 11\n");
    fprintf(yyout, "    syscall\n");
}

const char* generarASM_rec(struct ast *n) {
    if (!n) return NULL;
    printf("DEBUG: tipoNodo = %d → %s\n", n->tipoNodo, nombres_nodo[n->tipoNodo]);
        switch(n->tipoNodo) {
            case NODO_NUMERO: {
                const char* reg = nuevo_temp();
                fprintf(yyout, "    li %s, %d\n", reg, n->valor_int);
                return reg;
            }
            case NODO_BOOL: {
                const char* reg = nuevo_temp();
                int val = strcmp(n->valor_str, "true") == 0 ? 1:0;
                fprintf(yyout, "    li %s, %d\n", reg, val);
                return reg;
            }
            case NODO_STRING: {
                for (int i = 0; i < indice; i++) {
                    if (tabla[i].tipo && strcmp(tabla[i].tipo, "string") == 0 &&
                        tabla[i].valor && strcmp(tabla[i].valor, n->valor_str) == 0) {
                        n->nombre_literal = strdup(tabla[i].nombre);
                        const char* reg = nuevo_temp();
                        fprintf(yyout, "    la %s, %s\n", reg, tabla[i].nombre);
                        return reg;
                    }
                }
                return "ERROR_STRING_NO_ENCONTRADO";
            }

            case NODO_VARIABLE: {
                const char* tipo = obtener_tipo(n->nombre);

                if (tipo && strcmp(tipo, "float") == 0) {
                    const char* reg = nuevo_temp_float();
                    fprintf(yyout, "    l.s %s, %s\n", reg, n->nombre);
                    return reg;
                } else if (tipo && strcmp(tipo, "string") == 0) {
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    la %s, %s\n", reg, n->nombre);
                    return reg;
                } else if (tipo && strcmp(tipo, "bool") == 0) {
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    lw %s, %s\n", reg, n->nombre);
                    return reg;
                } else {
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    lw %s, %s\n", reg, n->nombre);
                    return reg;
                }
            }

            case NODO_FLOAT: {
                const char* reg = nuevo_temp_float();

                int pos = -1;
                for (int i = 0; i < indice; i++) {
                    if (tabla[i].tipo && strcmp(tabla[i].tipo, "float") == 0 && tabla[i].valor) {
                        if (fabs(atof(tabla[i].valor) - n->valor_float) < 0.0001f) {
                            pos = i;
                            break;
                        }
                    }
                }

                if (pos != -1) {
                    fprintf(yyout, "    l.s %s, %s\n", reg, tabla[pos].nombre);
                } else {
                    fprintf(stderr, "Error: Literal float no encontrado en tabla\n");
                }
                
                return reg;
            }

            case NODO_ARRAY: {
                return NULL;
            }
            case NODO_SUMA: {
                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;
                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) ||
                            (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp_float();
                    fprintf(yyout, "    add.s %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                } else {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    add %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                }
            }
            case NODO_RESTA: {
                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;
                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) ||
                            (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp_float();
                    fprintf(yyout, "    sub.s %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                } else {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    sub %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                }
            }
            case NODO_MULT: {
                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;
                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) ||
                            (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp_float();
                    fprintf(yyout, "    mul.s %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                } else {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    mul %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                }
            }
            case NODO_DIV: {
                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;
                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) ||
                            (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp_float();
                    fprintf(yyout, "    div.s %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                } else {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    div %s, %s\n", reg_izq, reg_dcha);
                    fprintf(yyout, "    mflo %s\n", reg);
                    return reg;
                }
            }
            case NODO_IGUALIGUAL: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* reg = nuevo_temp();

                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;

                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";
                else if (n->izq->tipoNodo == NODO_STRING)
                    tipo_izq = "string";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";
                else if (n->dcha->tipoNodo == NODO_STRING)
                    tipo_dcha = "string";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) || (tipo_dcha && strcmp(tipo_dcha, "float") == 0);
                int es_string = (tipo_izq && strcmp(tipo_izq, "string") == 0) && (tipo_dcha && strcmp(tipo_dcha, "string") == 0);

                if (es_string) {
                    fprintf(yyout, "    move $a0, %s\n", reg_izq);
                    fprintf(yyout, "    move $a1, %s\n", reg_dcha);
                    fprintf(yyout, "    jal strcmp\n");
                    fprintf(yyout, "    seq %s, $v0, $zero\n", reg);
                } else if (es_float) {
                    fprintf(yyout, "    c.eq.s %s, %s\n", reg_izq, reg_dcha);
                } else {
                    fprintf(yyout, "    seq %s, %s, %s\n", reg, reg_izq, reg_dcha);
                }

                return reg;
            }

            case NODO_DIFERENTE: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* reg = nuevo_temp();

                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;

                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";
                else if (n->izq->tipoNodo == NODO_STRING)
                    tipo_izq = "string";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";
                else if (n->dcha->tipoNodo == NODO_STRING)
                    tipo_dcha = "string";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) || (tipo_dcha && strcmp(tipo_dcha, "float") == 0);
                int es_string = (tipo_izq && strcmp(tipo_izq, "string") == 0) && (tipo_dcha && strcmp(tipo_dcha, "string") == 0);

                if (es_string) {
                    fprintf(yyout, "    move $a0, %s\n", reg_izq);
                    fprintf(yyout, "    move $a1, %s\n", reg_dcha);
                    fprintf(yyout, "    jal strcmp\n");
                    fprintf(yyout, "    sne %s, $v0, $zero\n", reg);
                } else if (es_float) {
                    fprintf(yyout, "    c.eq.s %s, %s\n", reg_izq, reg_dcha);
                    return "FLOAT_CMP_NEQ";
                } else {
                    fprintf(yyout, "    sne %s, %s, %s\n", reg, reg_izq, reg_dcha);
                }

                return reg;
            }

            case NODO_MENOR: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* reg = nuevo_temp();

                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;

                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) || (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    fprintf(yyout, "    c.lt.s %s, %s\n", reg_izq, reg_dcha);
                    return "FLOAT_CMP_LT";
                } else {
                    fprintf(yyout, "    slt %s, %s, %s\n", reg, reg_izq, reg_dcha);
                }

                return reg;
            }

            case NODO_MENORIGUAL: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* reg = nuevo_temp();

                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;

                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) || (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    fprintf(yyout, "    c.le.s %s, %s\n", reg_izq, reg_dcha);
                    return "FLOAT_CMP_LE";
                } else {
                    fprintf(yyout, "    sgt $at, %s, %s\n", reg_izq, reg_dcha);
                    fprintf(yyout, "    xori %s, $at, 1\n", reg);
                }

                return reg;
            }

            case NODO_MAYOR: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* reg = nuevo_temp();

                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;

                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) || (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    fprintf(yyout, "    c.le.s %s, %s\n", reg_izq, reg_dcha);
                    return "FLOAT_CMP_GT";
                } else {
                    fprintf(yyout, "    sgt %s, %s, %s\n", reg, reg_izq, reg_dcha);
                }

                return reg;
            }

            case NODO_MAYORIGUAL: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* reg = nuevo_temp();

                const char* tipo_izq = NULL;
                const char* tipo_dcha = NULL;

                if (n->izq->tipoNodo == NODO_VARIABLE)
                    tipo_izq = obtener_tipo(n->izq->nombre);
                else if (n->izq->tipoNodo == NODO_FLOAT)
                    tipo_izq = "float";

                if (n->dcha->tipoNodo == NODO_VARIABLE)
                    tipo_dcha = obtener_tipo(n->dcha->nombre);
                else if (n->dcha->tipoNodo == NODO_FLOAT)
                    tipo_dcha = "float";

                int es_float = (tipo_izq && strcmp(tipo_izq, "float") == 0) || (tipo_dcha && strcmp(tipo_dcha, "float") == 0);

                if (es_float) {
                    fprintf(yyout, "    c.lt.s %s, %s\n", reg_izq, reg_dcha);
                    return "FLOAT_CMP_GE";
                } else {
                    fprintf(yyout, "    sgt $at, %s, %s\n", reg_dcha, reg_izq);
                    fprintf(yyout, "    xori %s, $at, 1\n", reg);
                }

                return reg;
            }
            case NODO_AND: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* temp = nuevo_temp();

                const char* label_false = nuevo_label();
                const char* label_end = nuevo_label();

                fprintf(yyout, "    beq %s, $zero, %s\n", reg_izq, label_false);
                fprintf(yyout, "    beq %s, $zero, %s\n", reg_dcha, label_false);
                fprintf(yyout, "    li %s, 1\n", temp);
                fprintf(yyout, "    j %s\n", label_end);
                fprintf(yyout, "%s:\n", label_false);
                fprintf(yyout, "    li %s, 0\n", temp);
                fprintf(yyout, "%s:\n", label_end);

                return temp;
            }
            case NODO_OR: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* temp = nuevo_temp();

                const char* label_true = nuevo_label();
                const char* label_end = nuevo_label();

                fprintf(yyout, "    bne %s, $zero, %s\n", reg_izq, label_true);
                fprintf(yyout, "    bne %s, $zero, %s\n", reg_dcha, label_true);
                fprintf(yyout, "    li %s, 0\n", temp);
                fprintf(yyout, "    j %s\n", label_end);
                fprintf(yyout, "%s:\n", label_true);
                fprintf(yyout, "    li %s, 1\n", temp);
                fprintf(yyout, "%s:\n", label_end);

                return temp;
            }

            case NODO_NOT: {
                printf("SDAFADFAS");
                const char* reg_izq = generarASM_rec(n->izq);
                const char* temp = nuevo_temp();
                fprintf(yyout, "    seq %s, %s, $zero\n", temp, reg_izq);
                return temp;
            }


        case NODO_ASIGNACION: {
            const char* reg = generarASM_rec(n->izq);
            const char* tipo = obtener_tipo(n->nombre);
            printf("Nodo ASIGNACION con hijo tipo: %s\n", nombres_nodo[n->izq->tipoNodo]);

            if (n->izq->tipoNodo == NODO_CONCAT) {
                int pos = buscarTabla(n->nombre);
                if (pos >= 0) {
                    tabla[pos].valor = strdup("buffer_concat");
                }
            }

                if (tipo && strcmp(tipo, "float") == 0) {
                    if (reg && strcmp(reg, "$f12") != 0) {
                        fprintf(yyout, "    mov.s $f12, %s\n", reg);
                    }
                    fprintf(yyout, "    s.s $f12, %s\n", n->nombre);
                    return "$f12";
                }

                else if (tipo && strcmp(tipo, "string") == 0) {
                    return reg;
                }

                else if (tipo && (strcmp(tipo, "array") == 0 || strcmp(tipo, "matriz") == 0)) {
                    return NULL;
                }

                else {
                    if (reg) {
                        fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
                        n->es_inicializada = 1;
                        printf("Asignación para '%s' → sw generado\n", n->nombre);
                    }
                    return reg;
                }
            }


            case NODO_IF: {
                const char* label_else = nuevo_label();
                const char* label_end = nuevo_label();

                const char* tipo = NULL;

                if (n->izq->tipoNodo == NODO_IGUALIGUAL || n->izq->tipoNodo == NODO_DIFERENTE ||
                    n->izq->tipoNodo == NODO_MENOR || n->izq->tipoNodo == NODO_MENORIGUAL ||
                    n->izq->tipoNodo == NODO_MAYOR || n->izq->tipoNodo == NODO_MAYORIGUAL) {

                    struct ast* op_izq = n->izq->izq;
                    struct ast* op_dcha = n->izq->dcha;

                    const char* tipo_izq = (op_izq && op_izq->tipoNodo == NODO_VARIABLE) ? obtener_tipo(op_izq->nombre) :
                                        (op_izq && op_izq->tipoNodo == NODO_FLOAT) ? "float" :
                                        (op_izq && op_izq->tipoNodo == NODO_STRING) ? "string" : "int";

                    const char* tipo_dcha = (op_dcha && op_dcha->tipoNodo == NODO_VARIABLE) ? obtener_tipo(op_dcha->nombre) :
                                            (op_dcha && op_dcha->tipoNodo == NODO_FLOAT) ? "float" :
                                            (op_dcha && op_dcha->tipoNodo == NODO_STRING) ? "string" : "int";

                    if (strcmp(tipo_izq, "float") == 0 || strcmp(tipo_dcha, "float") == 0)
                        tipo = "float";
                    else if (strcmp(tipo_izq, "string") == 0 || strcmp(tipo_dcha, "string") == 0)
                        tipo = "string";
                    else
                        tipo = "int";

                } else {
                    if (n->izq->tipoNodo == NODO_VARIABLE)
                        tipo = obtener_tipo(n->izq->nombre);
                    else if (n->izq->tipoNodo == NODO_FLOAT)
                        tipo = "float";
                    else if (n->izq->tipoNodo == NODO_STRING)
                        tipo = "string";
                    else
                        tipo = "int";
                }

                const char* reg_cond = generarASM_rec(n->izq);

                if (!reg_cond) {
                    return NULL;
                }

                if (strcmp(tipo, "float") == 0) {
                    fprintf(yyout, "    bc1f %s\n", label_else);
                } else if (strcmp(tipo, "string") == 0) {
                    fprintf(yyout, "    bnez %s, %s\n", reg_cond, label_else);
                } else {
                    fprintf(yyout, "    beqz %s, %s\n", reg_cond, label_else);
                }

                if (n->dcha && n->dcha->izq)
                    generarASM_rec(n->dcha->izq);

                if (n->dcha && n->dcha->dcha)
                    fprintf(yyout, "    j %s\n", label_end);

                fprintf(yyout, "%s:\n", label_else);
                if (n->dcha && n->dcha->dcha)
                    generarASM_rec(n->dcha->dcha);

                fprintf(yyout, "%s:\n", label_end);

                return NULL;
            }

            case NODO_WHILE: {
                const char* label_start = nuevo_label();
                const char* label_end = nuevo_label();

                fprintf(yyout, "%s:\n", label_start);

                const char* tipo = NULL;

                if (n->izq->tipoNodo == NODO_IGUALIGUAL || n->izq->tipoNodo == NODO_DIFERENTE ||
                    n->izq->tipoNodo == NODO_MENOR || n->izq->tipoNodo == NODO_MENORIGUAL ||
                    n->izq->tipoNodo == NODO_MAYOR || n->izq->tipoNodo == NODO_MAYORIGUAL) {

                    struct ast* op_izq = n->izq->izq;
                    struct ast* op_dcha = n->izq->dcha;

                    const char* tipo_izq = (op_izq && op_izq->tipoNodo == NODO_VARIABLE) ? obtener_tipo(op_izq->nombre) :
                                        (op_izq && op_izq->tipoNodo == NODO_FLOAT) ? "float" :
                                        (op_izq && op_izq->tipoNodo == NODO_STRING) ? "string" : "int";

                    const char* tipo_dcha = (op_dcha && op_dcha->tipoNodo == NODO_VARIABLE) ? obtener_tipo(op_dcha->nombre) :
                                            (op_dcha && op_dcha->tipoNodo == NODO_FLOAT) ? "float" :
                                            (op_dcha && op_dcha->tipoNodo == NODO_STRING) ? "string" : "int";

                    if (strcmp(tipo_izq, "float") == 0 || strcmp(tipo_dcha, "float") == 0)
                        tipo = "float";
                    else if (strcmp(tipo_izq, "string") == 0 || strcmp(tipo_dcha, "string") == 0)
                        tipo = "string";
                    else
                        tipo = "int";

                } else {
                    if (n->izq->tipoNodo == NODO_VARIABLE)
                        tipo = obtener_tipo(n->izq->nombre);
                    else if (n->izq->tipoNodo == NODO_FLOAT)
                        tipo = "float";
                    else if (n->izq->tipoNodo == NODO_STRING)
                        tipo = "string";
                    else
                        tipo = "int";
                }

                const char* reg_cond = generarASM_rec(n->izq);
                if (!reg_cond) {
                    return NULL;
                }

                if (strcmp(tipo, "float") == 0) {
                    fprintf(yyout, "    bc1f %s\n", label_end);
                } else if (strcmp(tipo, "string") == 0) {
                    fprintf(yyout, "    beqz %s, %s\n", reg_cond, label_end);
                } else {
                    fprintf(yyout, "    beqz %s, %s\n", reg_cond, label_end);
                }

                if (n->dcha)
                    generarASM_rec(n->dcha);

                fprintf(yyout, "    j %s\n", label_start);

                fprintf(yyout, "%s:\n", label_end);

                return NULL;
            }

            case NODO_CONCAT: {
                generarASM_rec(n->izq);
                generarASM_rec(n->dcha);

                const char* reg_izq = NULL;
                const char* reg_dcha = NULL;

                if (n->izq->tipoNodo == NODO_VARIABLE) {
                    reg_izq = n->izq->nombre;
                } else {
                    reg_izq = n->izq->nombre_literal;
                    if(reg_izq == NULL){
                        reg_izq = n->dcha->nombre_literal;
                    }
                }

                if (n->dcha->tipoNodo == NODO_VARIABLE) {
                    reg_dcha = n->dcha->nombre;
                } else {
                    reg_dcha = n->dcha->nombre_literal;
                }


                int id = temp_counter++;

                fprintf(yyout, "    la $t0, %s\n", reg_izq);
                if (primera_concat) {
                    fprintf(yyout, "    la $t1, buffer_concat\n");
                    fprintf(yyout, "copy_str1_loop_%d:\n", id);
                    fprintf(yyout, "    lb $t2, 0($t0)\n");
                    fprintf(yyout, "    beqz $t2, copy_str2_start_%d\n", id);
                    fprintf(yyout, "    sb $t2, 0($t1)\n");
                    fprintf(yyout, "    addiu $t0, $t0, 1\n");
                    fprintf(yyout, "    addiu $t1, $t1, 1\n");
                    fprintf(yyout, "    j copy_str1_loop_%d\n", id);

                    fprintf(yyout, "copy_str2_start_%d:\n", id);
                    fprintf(yyout, "    la $t0, %s\n", reg_dcha);
                    primera_concat = 0;
                }


                fprintf(yyout, "copy_str2_loop_%d:\n", id);
                fprintf(yyout, "    lb $t2, 0($t0)\n");
                fprintf(yyout, "    beqz $t2, end_concat_%d\n", id);
                fprintf(yyout, "    sb $t2, 0($t1)\n");
                fprintf(yyout, "    addiu $t0, $t0, 1\n");
                fprintf(yyout, "    addiu $t1, $t1, 1\n");
                fprintf(yyout, "    j copy_str2_loop_%d\n", id);

                fprintf(yyout, "end_concat_%d:\n", id);
                fprintf(yyout, "    sb $zero, 0($t1)\n");

                return "buffer_concat";
            }

            case NODO_LISTA: {
                generarASM_rec(n->izq);
                generarASM_rec(n->dcha);
                return NULL;
            }
            case NODO_PUTS: {
                generar_puts(n->izq);
                return NULL;
            }
            default:
                break;
            }
        
        return NULL;
    }

// ======== Declaración de variables en .data según tipo ========

void recolectar_vars_tipos(struct ast *nodo) {
    if (!nodo) return;
    printf("Recolectando variable: %s, tipo: %d\n", nodo->nombre, nodo->tipoNodo);
    if (nodo->tipoNodo == NODO_ASIGNACION) {
        registrar_variable(nodo->nombre);
    }
    recolectar_vars_tipos(nodo->izq);
    recolectar_vars_tipos(nodo->dcha);
}

void recolectar_strings_literal(struct ast *nodo) {
    if (!nodo) return;
    if (nodo->tipoNodo == NODO_STRING) {
        int ya_existe = 0;
        for (int i = 0; i < indice; i++) {
            if (tabla[i].tipo && strcmp(tabla[i].tipo, "string") == 0 &&
                tabla[i].valor && strcmp(tabla[i].valor, nodo->valor_str) == 0) {
                ya_existe = 1;
                break;
            }
        }
        if (!ya_existe) {
            char nombre[32];
            sprintf(nombre, "str%d", indice);
            tabla[indice].nombre = strdup(nombre);
            tabla[indice].tipo = strdup("string");
            tabla[indice].valor = strdup(nodo->valor_str);
            indice++;
        }
    }
    recolectar_strings_literal(nodo->izq);
    recolectar_strings_literal(nodo->dcha);
}

void recolectar_floats_literal(struct ast *n) {
    if (n == NULL) return;
    
    if (n->tipoNodo == NODO_FLOAT) {
        int pos = -1;
        char buffer[32];
        sprintf(buffer, "%.4f", n->valor_float);

        for (int i = 0; i < indice; i++) {
            if (tabla[i].tipo && strcmp(tabla[i].tipo, "float") == 0 && tabla[i].valor) {
                if (fabs(atof(tabla[i].valor) - n->valor_float) < 0.0001f) {
                    pos = i;
                    break;
                }
            }
        }

        if (pos == -1) {
            tabla[indice].nombre = strdup(n->valor_str);
            tabla[indice].tipo = strdup("float");
            tabla[indice].valor = strdup(buffer);
            n->es_inicializada = 1;
            indice++;
        }
    }
    
    recolectar_floats_literal(n->izq);
    recolectar_floats_literal(n->dcha);
}
// ======== Función principal de generación de ensamblador ========

void generarASM(struct ast *n) {
    temp_counter = 0;
    limpiar_variables();

    recolectar_vars_tipos(n);
    recolectar_strings_literal(n);
    recolectar_floats_literal(n); 

    fprintf(yyout, ".data\n");
    fprintf(yyout, "buffer_concat: .space 256\n");

    char* ya_inicializadas[256];
    int num_inicializadas = 0;

    for (int i = 0; i < indice; i++) {
        const char* nombre = tabla[i].nombre;

        int repetida = 0;
        for (int j = 0; j < num_inicializadas; j++) {
            if (strcmp(nombre, ya_inicializadas[j]) == 0) {
                repetida = 1;
                break;
            }
        }
        if (repetida) continue;

        const char* tipo = tabla[i].tipo;
        const char* valor = tabla[i].valor;
        const char* tipoBase = tabla[i].tipoBase;
        const char* valores = tabla[i].Valores;

        int es_expresion = (valor && (
            strchr(valor, '+') || strchr(valor, '-') || strchr(valor, '*') || strchr(valor, '/') ||
            strstr(valor, "==") || strstr(valor, "!=") || strstr(valor, "<") || strstr(valor, "<=") ||
            strstr(valor, ">") || strstr(valor, ">=") ));

        if (strcmp(tipo, "int") == 0 || strcmp(tipo, "bool") == 0) {
            if (!es_expresion) {
                int val = valor ? atoi(valor) : 0;
                fprintf(yyout, "%s: .word %d\n", nombre, val);
                ya_inicializadas[num_inicializadas++] = strdup(nombre);
            } else {
                fprintf(yyout, "%s: .word 0\n", nombre);
            }
        }

        else if (strcmp(tipo, "float") == 0) {
            float val = valor ? atof(valor) : 0.0;
            if (!es_expresion) {              
                fprintf(yyout, "%s: .float %f\n", nombre, val);
                ya_inicializadas[num_inicializadas++] = strdup(nombre);
            } else {
                fprintf(yyout, "%s: .float %f\n", nombre, val);
            }
        }

        else if (strcmp(tipo, "string") == 0) {
            fprintf(yyout, "%s: .asciiz %s\n", nombre, valor ? valor : "");
            ya_inicializadas[num_inicializadas++] = strdup(nombre);
        }

        else if (strcmp(tipo, "array") == 0 || strcmp(tipo, "matriz") == 0) {
            if (tipoBase && strcmp(tipoBase, "string") == 0) {
                char* valores_copia = strdup(valores ? valores : "");
                char* token = strtok(valores_copia, " ");
                int idx = 0;
                char* nombres_aux[256];
                while (token) {
                    char nombre_aux[64];
                    sprintf(nombre_aux, "%s_str%d", nombre, idx);
                    nombres_aux[idx] = strdup(nombre_aux);
                    fprintf(yyout, "%s: .asciiz %s\n", nombre_aux, token);
                    idx++;
                    token = strtok(NULL, " ");
                }
                free(valores_copia);
                fprintf(yyout, "%s: .word", nombre);
                for (int j = 0; j < idx; j++) {
                    fprintf(yyout, " %s", nombres_aux[j]);
                    free(nombres_aux[j]);
                }
                fprintf(yyout, "\n");
                ya_inicializadas[num_inicializadas++] = strdup(nombre);
            }
            else if (tipoBase && strcmp(tipoBase, "float") == 0) {
                fprintf(yyout, "%s: .float", nombre);
                if (valores && strlen(valores) > 0) {
                    char* valores_copia = strdup(valores);
                    char* token = strtok(valores_copia, " ");
                    while (token) {
                        fprintf(yyout, " %s", token);
                        token = strtok(NULL, " ");
                    }
                    free(valores_copia);
                }
                fprintf(yyout, "\n");
                ya_inicializadas[num_inicializadas++] = strdup(nombre);
            }
            else {
                fprintf(yyout, "%s: .word", nombre);
                if (valores && strlen(valores) > 0) {
                    char* valores_copia = strdup(valores);
                    char* token = strtok(valores_copia, " ");
                    while (token) {
                        if (strcmp(token, "true") == 0) {
                            fprintf(yyout, " 1");
                        } else if (strcmp(token, "false") == 0) {
                            fprintf(yyout, " 0");
                        } else {
                            fprintf(yyout, " %s", token);
                        }
                        token = strtok(NULL, " ");
                    }
                    free(valores_copia);
                }
                fprintf(yyout, "\n");
                ya_inicializadas[num_inicializadas++] = strdup(nombre);
            }
        }
    }
    fprintf(yyout, "\n");

    fprintf(yyout, ".text\n.globl main\nmain:\n");

    primera_concat = 1;
    generarASM_rec(n);

    fprintf(yyout, "    li $v0, 10\n    syscall\n");
}