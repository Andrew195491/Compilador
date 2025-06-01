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
    nodo->dcha = cuerpo;
    nodo->nombre = NULL;
    nodo->valor_str = NULL;
    nodo->valor_int = 0;
    nodo->valor_float = 0.0f;
    // Puedes usar izq/dcha para if/else, o agregar un campo extra si lo prefieres
    if (else_cuerpo) {
        // Si quieres guardar el else como dcha->dcha, por ejemplo:
        nodo->dcha->dcha = else_cuerpo;
    }
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

// Prototipo necesario para evitar error:
const char* generarASM_rec(struct ast *n);

void generar_puts(struct ast *expresion) {
    if (!expresion) return;

    const char* reg = generarASM_rec(expresion);

    switch (expresion->tipoNodo) {
        case NODO_STRING:
            fprintf(yyout, "    li $v0, 4\n");
            fprintf(yyout, "    move $a0, %s\n", reg);
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
        case NODO_NUMERO:
        case NODO_BOOL:
            fprintf(yyout, "    li $v0, 1\n");
            fprintf(yyout, "    move $a0, %s\n", reg);
            break;
        default:
            fprintf(yyout, "    # tipo no soportado en puts\n");
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

                if (!n->es_inicializada) {
                    fprintf(yyout, "    li %s, %d\n", reg, n->valor_int);
                    n->es_inicializada = 1;  // Lo marcamos como inicializado después de generarlo
                } else {
                    fprintf(yyout, "    # %s ya inicializado, se reutiliza\n", reg);
                }

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
                    if (tabla[i].tipo && strcmp(tabla[i].tipo, "string") == 0 && tabla[i].valor && strcmp(tabla[i].valor, n->valor_str) == 0) {
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
                    fprintf(yyout, "    la %s, %s\n", reg, n->nombre);
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
                int pos = -1;
                for (int i = 0; i < indice; i++) {
                    if (tabla[i].tipo && strcmp(tabla[i].tipo, "float") == 0 && tabla[i].valor) {
                        float val = atof(tabla[i].valor);
                        if (fabsf(val - n->valor_float) < 0.0001f) {
                            pos = i;
                            break;
                        }
                    }
                }
                if (pos >= 0) {
                    fprintf(yyout, "    l.s %s, %s\n", reg, tabla[pos].nombre);
                } else {
                    fprintf(yyout, "    # ERROR: float literal no encontrado en tabla de símbolos\n");
                }
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

                fprintf(yyout, "    seq %s, %s, %s\n", reg, reg_izq, reg_dcha);

                return reg;
            }
case NODO_ASIGNACION: {
    const char* reg = generarASM_rec(n->izq);
    const char* tipo = obtener_tipo(n->nombre);

    registrar_variable(n->nombre);

    if (tipo && strcmp(tipo, "float") == 0) {
        if (reg && strcmp(reg, "$f12") != 0) {
            fprintf(yyout, "    mov.s $f12, %s\n", reg);
        }
        fprintf(yyout, "    s.s $f12, %s\n", n->nombre);
        return "$f12";
    } else if (tipo && strcmp(tipo, "string") == 0) {
        // No generes sw para strings
        return reg;
    } else if (tipo && (strcmp(tipo, "array") == 0 || strcmp(tipo, "matriz") == 0)) {
        // No generes sw para arrays/matrices
        return NULL;
    } else {
        // int o bool
        int esta_inicializada = 0;
        for (int i = 0; i < MAX_VARS; i++) {
            if (inicializada[i] && strcmp(inicializada[i], n->nombre) == 0) {
                esta_inicializada = 1;
                break;
            }
        }
        if (!esta_inicializada && reg) {
            fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
        } else if (!reg) {
            fprintf(yyout, "    # No se genera sw para %s (no es int/float/bool)\n", n->nombre);
        } else {
            fprintf(yyout, "    # %s ya inicializado (int/bool), se omite sw\n", n->nombre);
        }
        return reg;
    }
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
    if (nodo->tipoNodo == NODO_ASIGNACION) {
        registrar_variable(nodo->nombre);
    }
    recolectar_vars_tipos(nodo->izq);
    recolectar_vars_tipos(nodo->dcha);
}

// ======== Función principal de generación de ensamblador ========

void generarASM(struct ast *n) {
    temp_counter = 0;
    limpiar_variables();

    // 1. Recolectar variables y tipos del AST
    recolectar_vars_tipos(n);

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
                strchr(tabla[i].valor, '/') != NULL   ));

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
                strchr(tabla[i].valor, '/') != NULL  ));

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