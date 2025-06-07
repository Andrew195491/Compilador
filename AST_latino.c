#include "AST_latino.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "tabla_simbolos.h"

// Variable global para el archivo de salida
extern FILE *yyout;

#define MAX_VARS 100
char *lista_vars[MAX_VARS];
char* inicializada[MAX_VARS];
int ya_asignado[MAX_VARS] = {0};
int num_vars = 0;
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
    "NODO_FUNCION",
    "NODO_LLAMADA_FUNCION",
    "NODO_IGUALIGUAL",
    "NODO_DIFERENTE",
    "NODO_MENOR",
    "NODO_MENORIGUAL",
    "NODO_MAYOR",
    "NODO_MAYORIGUAL",
    "NODO_GRUPO",
    "NODO_AND",
    "NODO_OR",
    "NODO_NOT"
};

// Para strings en .data
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

struct ast *crearNodoNot(enum tipoNodoAST tipo, struct ast *izq) {
    struct ast *n = malloc(sizeof(struct ast));
    n->tipoNodo = tipo;
    n->izq = izq;
    n->dcha = NULL;
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

    nodo->dcha = crearNodoLista(cuerpo, else_cuerpo); // O crea el nodo manualmente
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

struct ast* crearNodoFuncion(const char* nombre, struct ast* parametros, struct ast* cuerpo) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipoNodo = NODO_FUNCION;
    nodo->izq = parametros;
    nodo->dcha = cuerpo;
    nodo->nombre = strdup_safe(nombre);
    nodo->valor_str = NULL;
    nodo->valor_int = 0;
    nodo->valor_float = 0.0f;
    return nodo;
}

struct ast* crearNodoParametro(const char* nombre, struct ast* siguiente) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipoNodo = NODO_VARIABLE;
    nodo->izq = siguiente;
    nodo->dcha = NULL;
    nodo->nombre = strdup_safe(nombre);
    nodo->valor_str = NULL;
    nodo->valor_int = 0;
    nodo->valor_float = 0.0f;
    return nodo;
}

struct ast* crearNodoLlamadaFuncion(const char* nombre, struct ast* argumentos) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipoNodo = NODO_LLAMADA_FUNCION;
    nodo->izq = argumentos;
    nodo->dcha = NULL;
    nodo->nombre = strdup_safe(nombre);
    nodo->valor_str = NULL;
    nodo->valor_int = 0;
    nodo->valor_float = 0.0f;
    return nodo;
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

struct ast* crearNodoArgumento(struct ast* valor, struct ast* siguiente) {
    struct ast* nodo = malloc(sizeof(struct ast));
    nodo->tipoNodo = NODO_VARIABLE; // o puedes crear NODO_ARGUMENTO si lo agregas
    nodo->izq = valor;
    nodo->dcha = siguiente;
    nodo->nombre = NULL;
    nodo->valor_str = NULL;
    nodo->valor_int = 0;
    nodo->valor_float = 0.0f;
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

// ======== Recorrido para impresión (opcional) ========

void recorrerAST(struct ast *n) {
    if (!n) return;
    switch(n->tipoNodo) {
        case NODO_LISTA:
            recorrerAST(n->izq);
            if (n->dcha) { printf(", "); recorrerAST(n->dcha); }
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
        case NODO_IGUALIGUAL:
            printf("("); recorrerAST(n->izq); printf(" == "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_DIFERENTE:
            printf("("); recorrerAST(n->izq); printf(" != "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_MENOR:
            printf("("); recorrerAST(n->izq); printf(" < "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_MAYOR:
            printf("("); recorrerAST(n->izq); printf(" > "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_MENORIGUAL:
            printf("("); recorrerAST(n->izq); printf(" <= "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_MAYORIGUAL:
            printf("("); recorrerAST(n->izq); printf(" >= "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_AND:
            printf("("); recorrerAST(n->izq); printf(" && "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_OR:
            printf("("); recorrerAST(n->izq); printf(" || "); recorrerAST(n->dcha); printf(")");
            break;
        case NODO_VARIABLE:
            printf("%s", n->nombre);
            break;
        case NODO_PUTS:
            printf("puts ");
            recorrerAST(n->izq);
            break;
        default:
            break;
    }
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
    if (temp_float_counter > 19) temp_float_counter = 12; // Rango seguro para temporales
    return buffer[idx];
}

// Agrega esto arriba, cerca de temp_counter
static int label_counter = 0;
const char* nuevo_label() {
    static char buffer[10][16];
    int idx = label_counter % 10;
    sprintf(buffer[idx], "L%d", label_counter++);
    return buffer[idx];
}
// Prototipo necesario para evitar error:
const char* generarASM_rec(struct ast *n);

void generar_puts(struct ast *expresion) {
    if (!expresion) return;

    const char* reg = generarASM_rec(expresion);
    int pos = -1;

    switch (expresion->tipoNodo) {
        case NODO_STRING:
            for (int i = 0; i < indice; i++) {
                if (tabla[i].tipo && strcmp(tabla[i].tipo, "string") == 0 && tabla[i].valor && strcmp(tabla[i].valor, expresion->valor_str) == 0) {
                    pos = i;
                    break;
                }
            }
            if (pos >= 0) {
                fprintf(yyout, "    la $a0, %s\n", tabla[pos].nombre);
                fprintf(yyout, "    li $v0, 4\n");
            } else {
                fprintf(yyout, "    # ERROR: string literal no encontrado\n");
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
                    fprintf(yyout, "    syscall\n"); // <-- Añade esto
                    return;
                } else if (tipo && strcmp(tipo, "string") == 0) {
                    fprintf(yyout, "    li $v0, 4\n");
                    fprintf(yyout, "    move $a0, %s\n", reg);
                    fprintf(yyout, "    syscall\n");
                    return;    
                } else if (tipo && (strcmp(tipo, "array") == 0)) {
                    int pos = buscarTabla(expresion->nombre);
                    if (pos >= 0 && tabla[pos].tipoBase) {
                        int tam = tabla[pos].Tamanio;
                        // --- FLOAT ---
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
                        // --- INT / BOOL ---
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
                        // --- STRING ---
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
                // --- MATRIZ ---
                else if (tipo && strcmp(tipo, "matriz") == 0) {
                    int pos = buscarTabla(expresion->nombre);
                    if (pos >= 0 && tabla[pos].tipoBase) {
                        int filas = tabla[pos].Filas;
                        int columnas = tabla[pos].Columnas;
                        // --- INT / BOOL ---
                        if (strcmp(tabla[pos].tipoBase, "int") == 0 || strcmp(tabla[pos].tipoBase, "bool") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n"); // i = 0
                            fprintf(yyout, "    li $t3, %d\n", filas);
                            fprintf(yyout, "    li $t4, %d\n", columnas);
                            fprintf(yyout, "print_%s_outer:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t3, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    li $t2, 0\n"); // j = 0
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
                        // --- FLOAT ---
                        else if (strcmp(tabla[pos].tipoBase, "float") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n"); // i = 0
                            fprintf(yyout, "    li $t3, %d\n", filas);
                            fprintf(yyout, "    li $t4, %d\n", columnas);
                            fprintf(yyout, "print_%s_outer:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t3, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    li $t2, 0\n"); // j = 0
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
                        // --- STRING ---
                        else if (strcmp(tabla[pos].tipoBase, "string") == 0) {
                            fprintf(yyout, "    la $t0, %s\n", expresion->nombre);
                            fprintf(yyout, "    li $t1, 0\n"); // i = 0
                            fprintf(yyout, "    li $t3, %d\n", filas);
                            fprintf(yyout, "    li $t4, %d\n", columnas);
                            fprintf(yyout, "print_%s_outer:\n", expresion->nombre);
                            fprintf(yyout, "    bge $t1, $t3, print_%s_end\n", expresion->nombre);
                            fprintf(yyout, "    li $t2, 0\n"); // j = 0
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
                // int o bool simple
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
                        } else {
                            fprintf(yyout, "    # tipo no soportado o reg nulo en puts\n");
                        }
                        return;
                }

    fprintf(yyout, "    syscall\n");

    // salto de línea
    fprintf(yyout, "    li $a0, 10\n");
    fprintf(yyout, "    li $v0, 11\n");
    fprintf(yyout, "    syscall\n");
}

const char* generarASM_rec(struct ast *n) {
    if (!n) return NULL;
    printf("Tipo Nodo: %s\n", nombres_nodo[n->tipoNodo]);
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
                const char* reg = nuevo_temp();
                // Busca el string literal en la tabla de símbolos por su valor
                int pos = -1;
                for (int i = 0; i < indice; i++) {
                    if (tabla[i].tipo && strcmp(tabla[i].tipo, "string") == 0 && 
                        tabla[i].valor && strcmp(tabla[i].valor, n->valor_str) == 0) {
                        pos = i;
                        break;
                    }
                }
                if (pos >= 0) {
                    fprintf(yyout, "    la %s, %s\n", reg, tabla[pos].nombre);
                } else {
                    fprintf(yyout, "    # ERROR: string literal no encontrado en tabla de símbolos\n");
                }
                return reg;
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
                    // int o bool
                    const char* reg = nuevo_temp();
                    fprintf(yyout, "    lw %s, %s\n", reg, n->nombre);
                    return reg;
                }
            }

            case NODO_FLOAT: {
                const char* reg = nuevo_temp_float();

                // Verifica si ya existe el literal en la tabla de símbolos
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
                    // No está, lo añadimos a la tabla
                    tabla[indice].nombre = strdup(n->valor_str); // "float_0"
                    tabla[indice].tipo = strdup("float");
                    tabla[indice].valor = strdup(buffer);        // "2.0"
                    n->es_inicializada = 1;
                    pos = indice++;
                    
                    // Escribimos en .data (yyout o yyout_data según cómo lo tengas)
                    fprintf(yyout, "%s: .float %s\n", n->valor_str, buffer);
                }

                // Cargamos ese literal en un registro float
                fprintf(yyout, "    l.s %s, %s\n", reg, tabla[pos].nombre);
                return reg;
            }

            case NODO_ARRAY: {
                // Los arrays/matrices ya están declarados e inicializados en .data
                // No se genera código en .text para ellos
                return NULL;
            }
            case NODO_SUMA: {
                // Detecta si alguno de los operandos es float
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
                 // Detecta si alguno de los operandos es float
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
                    fprintf(yyout, "    div.s %s, %s\n", reg_izq, reg_dcha);
                    fprintf(yyout, "    mflo %s\n", reg);
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
                    fprintf(yyout, "    jal strcmp\n");       // strcmp devuelve 0 si iguales
                    fprintf(yyout, "    seq %s, $v0, $zero\n", reg);
                } else if (es_float) {
                    fprintf(yyout, "    c.eq.s %s, %s\n", reg_izq, reg_dcha);
                    // Indicamos que es comparación float para manejar salto después
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
                    // x > y <=> !(x <= y)
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
                    // a >= b <=> !(a < b)
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

                fprintf(yyout, "    # AND\n");
                fprintf(yyout, "    beq %s, $zero, %s\n", reg_izq, label_false);  // si izq es false → resultado 0
                fprintf(yyout, "    beq %s, $zero, %s\n", reg_dcha, label_false); // si der es false → resultado 0
                fprintf(yyout, "    li %s, 1\n", temp);                           // ambos son true → resultado 1
                fprintf(yyout, "    j %s\n", label_end);
                fprintf(yyout, "%s:\n", label_false);
                fprintf(yyout, "    li %s, 0\n", temp);                           // alguno es false → resultado 0
                fprintf(yyout, "%s:\n", label_end);

                return temp;
            }
            case NODO_OR: {
                const char* reg_izq = generarASM_rec(n->izq);
                const char* reg_dcha = generarASM_rec(n->dcha);
                const char* temp = nuevo_temp();

                const char* label_true = nuevo_label();
                const char* label_end = nuevo_label();

                fprintf(yyout, "    # OR\n");
                fprintf(yyout, "    bne %s, $zero, %s\n", reg_izq, label_true);  // si izq es true --> salto
                fprintf(yyout, "    bne %s, $zero, %s\n", reg_dcha, label_true);  // si der es true --> salto
                fprintf(yyout, "    li %s, 0\n", temp);                          // ambos son false → resultado 0
                fprintf(yyout, "    j %s\n", label_end);
                fprintf(yyout, "%s:\n", label_true);
                fprintf(yyout, "    li %s, 1\n", temp);                          // si al menos uno true → resultado 1
                fprintf(yyout, "%s:\n", label_end);

                return temp;
            }
            case NODO_NOT: {
                const char* reg_izq = generarASM_rec(n->izq);  // condición
                const char* temp = nuevo_temp();

                fprintf(yyout, "    # NOT\n");
                fprintf(yyout, "    seq %s, %s, $zero\n", temp, reg_izq);  // temp = (reg_izq == 0) → NOT lógico

                return temp;
            }

            case NODO_ASIGNACION: {
                const char* reg = generarASM_rec(n->izq);
                const char* tipo = obtener_tipo(n->nombre);
                printf("Nodo ASIGNACION con hijo tipo: %s\n", nombres_nodo[n->izq->tipoNodo]);

                // Ya está registrada antes, no la registres de nuevo
                // registrar_variable(n->nombre); <-- ¡no es necesario aquí!

                // Float
                if (tipo && strcmp(tipo, "float") == 0) {
                    if (reg && strcmp(reg, "$f12") != 0) {
                        fprintf(yyout, "    mov.s $f12, %s\n", reg);
                    }
                    fprintf(yyout, "    s.s $f12, %s\n", n->nombre);
                    return "$f12";
                }

                // String → sin `sw`
                else if (tipo && strcmp(tipo, "string") == 0) {
                    return reg;
                }

                // Array o matriz → sin `sw`
                else if (tipo && (strcmp(tipo, "array") == 0 || strcmp(tipo, "matriz") == 0)) {
                    return NULL;
                }

                // Int o bool
                else {
                    if (reg) {
                        fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
                        n->es_inicializada = 1;  // ✅ Ya está inicializada correctamente
                        printf("Asignación para '%s' → sw generado\n", n->nombre);
                    } else {
                        fprintf(yyout, "    # No se genera sw para %s (registro nulo)\n", n->nombre);
                    }
                    return reg;
                }
            }


            case NODO_IF: {
                const char* label_else = nuevo_label();
                const char* label_end = nuevo_label();

                // 🔍 1. Determinar el tipo de la condición
                const char* tipo = NULL;

                // Si la condición es una comparación (como ==, !=, <, etc.)
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
                    // Si la condición no es una comparación
                    if (n->izq->tipoNodo == NODO_VARIABLE)
                        tipo = obtener_tipo(n->izq->nombre);
                    else if (n->izq->tipoNodo == NODO_FLOAT)
                        tipo = "float";
                    else if (n->izq->tipoNodo == NODO_STRING)
                        tipo = "string";
                    else
                        tipo = "int";
                }

                // 🧠 2. Generar el ASM de la condición
                const char* reg_cond = generarASM_rec(n->izq);

                if (!reg_cond) {
                    fprintf(yyout, "    # Error: condición no generó registro\n");
                    return NULL;
                }

                // 🎯 3. Generar salto condicional según tipo
                if (strcmp(tipo, "float") == 0) {
                    // Asumimos que el flag de comparación se puso ya en generarASM_rec
                    fprintf(yyout, "    bc1f %s\n", label_else);  // Salta si la condición es falsa
                } else if (strcmp(tipo, "string") == 0) {
                    // strcmp ya compara y devuelve resultado en $v0, convertido a bool en reg_cond
                    fprintf(yyout, "    bnez %s, %s\n", reg_cond, label_else);
                } else {
                    // int o bool
                    fprintf(yyout, "    beqz %s, %s\n", reg_cond, label_else);
                }

                // ✅ THEN
                if (n->dcha && n->dcha->izq)
                    generarASM_rec(n->dcha->izq);

                if (n->dcha && n->dcha->dcha)
                    fprintf(yyout, "    j %s\n", label_end);

                // ❌ ELSE
                fprintf(yyout, "%s:\n", label_else);
                if (n->dcha && n->dcha->dcha)
                    generarASM_rec(n->dcha->dcha);

                // 🔚 END
                fprintf(yyout, "%s:\n", label_end);

                return NULL;
            }

            case NODO_WHILE: {
                const char* label_start = nuevo_label();
                const char* label_end = nuevo_label();

                fprintf(yyout, "%s:\n", label_start);  // 🔁 Inicio del while

                // 1. Determinar tipo de la condición
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

                // 2. Generar ASM de la condición
                const char* reg_cond = generarASM_rec(n->izq);
                if (!reg_cond) {
                    fprintf(yyout, "    # Error: condición del while no generó registro\n");
                    return NULL;
                }

                // 3. Salto si condición es falsa
                if (strcmp(tipo, "float") == 0) {
                    fprintf(yyout, "    bc1f %s\n", label_end);  // Falso → salir del while
                } else if (strcmp(tipo, "string") == 0) {
                    fprintf(yyout, "    beqz %s, %s\n", reg_cond, label_end);  // strcmp devuelve 0 si iguales
                } else {
                    fprintf(yyout, "    beqz %s, %s\n", reg_cond, label_end);  // condición booleana falsa
                }

                // 4. Cuerpo del while
                if (n->dcha)
                    generarASM_rec(n->dcha);

                // 5. Volver al inicio
                fprintf(yyout, "    j %s\n", label_start);

                // 6. Fin del bucle
                fprintf(yyout, "%s:\n", label_end);

                return NULL;
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
        // Verifica si ya está en la tabla
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

// ======== Función principal de generación de ensamblador ========

void generarASM(struct ast *n) {
    temp_counter = 0;
    limpiar_variables();

    // 1. Recolectar variables y tipos del AST
    recolectar_vars_tipos(n);
    recolectar_strings_literal(n);

    // 2. Sección .data 
    fprintf(yyout, ".data\n");
    for (int i = 0; i < indice; i++) {
        const char* tipo = tabla[i].tipo;
        const char* valor = tabla[i].valor;
        const char* tipoBase = tabla[i].tipoBase;
        const char* valores = tabla[i].Valores;

        if (strcmp(tipo, "int") == 0 || strcmp(tipo, "bool") == 0) {
            // Si contiene operación, no inicializar
            int es_expresion = (tabla[i].valor && (
                strchr(tabla[i].valor, '+') != NULL || 
                strchr(tabla[i].valor, '-') != NULL ||
                strchr(tabla[i].valor, '*') != NULL || 
                strchr(tabla[i].valor, '/') != NULL || 
                strstr(tabla[i].valor, "==") != NULL ||
                strstr(tabla[i].valor, "!=") != NULL ||
                strstr(tabla[i].valor, "<") != NULL ||
                strstr(tabla[i].valor, "<=") != NULL ||
                strstr(tabla[i].valor, ">") != NULL ||
                strstr(tabla[i].valor, ">=") != NULL ));

            if (!es_expresion) {
                int val = (valor != NULL) ? atoi(valor) : 0;
                fprintf(yyout, "%s: .word %d\n", tabla[i].nombre, val);
                if (tabla[i].valor != NULL) {
                    inicializada[i] = tabla[i].nombre;
                }
            } else {
                // No inicializar, reservar espacio para la variable
                fprintf(yyout, "%s: .word 0\n", tabla[i].nombre); // o usa solo `.space 4`
            }
        }

        else if (strcmp(tipo, "float") == 0) {
            int es_expresion = (tabla[i].valor && (
                strchr(tabla[i].valor, '+') != NULL || 
                strchr(tabla[i].valor, '-') != NULL ||
                strchr(tabla[i].valor, '*') != NULL || 
                strchr(tabla[i].valor, '/') != NULL || 
                strstr(tabla[i].valor, "==") != NULL || 
                strstr(tabla[i].valor, "!=") != NULL ||
                strstr(tabla[i].valor, "<") != NULL ||
                strstr(tabla[i].valor, "<=") != NULL ||
                strstr(tabla[i].valor, ">") != NULL ||
                strstr(tabla[i].valor, ">=") != NULL ));

            if (!es_expresion) {    
                float val = (valor != NULL) ? atof(valor) : 0.0;
                fprintf(yyout, "%s: .float %f\n", tabla[i].nombre, val);
            } else {
                // No inicializar, reservar espacio para la variable
                fprintf(yyout, "%s: .float 0.0\n", tabla[i].nombre); // o usa solo `.space 4`
            }
        }
        else if (strcmp(tipo, "string") == 0) {
            fprintf(yyout, "%s: .asciiz %s\n", tabla[i].nombre, valor ? valor : "");
        }
        else if (strcmp(tipo, "array") == 0 || strcmp(tipo, "matriz") == 0) {
            if (tipoBase && strcmp(tipoBase, "string") == 0) {
                // 1. Declarar cada string como strX
                char* valores_copia = strdup(valores ? valores : "");
                char* token = strtok(valores_copia, " ");
                int idx = 0;
                char* nombres_aux[256]; // Máximo 256 strings por array
                while (token) {
                    char nombre_aux[64];
                    sprintf(nombre_aux, "%s_str%d", tabla[i].nombre, idx);
                    nombres_aux[idx] = strdup(nombre_aux);
                    fprintf(yyout, "%s: .asciiz %s\n", nombre_aux, token);
                    idx++;
                    token = strtok(NULL, " ");
                }
                free(valores_copia);

                // 2. Declarar el array de punteros
                fprintf(yyout, "%s: .word", tabla[i].nombre);
                for (int j = 0; j < idx; j++) {
                    fprintf(yyout, " %s", nombres_aux[j]);
                    free(nombres_aux[j]);
                }
                fprintf(yyout, "\n");
                continue;
            } else if (tipoBase && strcmp(tipoBase, "float") == 0) {
                // Array/matriz de float
                fprintf(yyout, "%s: .float", tabla[i].nombre);
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
            } else {
                // Por defecto, array/matriz de int o bool
                fprintf(yyout, "%s: .word", tabla[i].nombre);
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
            }
        }
    }
    fprintf(yyout, "\n");

    // 3. Sección .text y main
    fprintf(yyout, ".text\n.globl main\nmain:\n");

    // 4. Código de instrucciones
    generarASM_rec(n);

    // 5. Salida limpia de MIPS
    fprintf(yyout, "    li $v0, 10\n    syscall\n");
}