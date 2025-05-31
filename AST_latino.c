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
int tipos_vars[MAX_VARS]; // 0=int/bool, 1=float, 2=string
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
};

// Para strings en .data
int string_label_counter = 0;
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
            break;
        case NODO_FLOAT:
            if (strcmp(reg, "$f12") != 0) {
                fprintf(yyout, "    mov.s $f12, %s\n", reg);
            }
            fprintf(yyout, "    li $v0, 2\n");
            break;
        case NODO_VARIABLE: {
            const char* tipo = obtener_tipo(expresion->nombre);
            if (tipo && strcmp(tipo, "float") == 0) {
                // reg ya es el registro float correcto (de generarASM_rec)
                if (strcmp(reg, "$f12") != 0) {
                    fprintf(yyout, "    mov.s $f12, %s\n", reg);
                }
                fprintf(yyout, "    li $v0, 2\n");
            } else if (tipo && strcmp(tipo, "string") == 0) {
                fprintf(yyout, "    li $v0, 4\n");
                fprintf(yyout, "    move $a0, %s\n", reg);
            } else {
                // int o bool
                fprintf(yyout, "    li $v0, 1\n");
                fprintf(yyout, "    move $a0, %s\n", reg);
            }
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
                const char* tipo = obtener_tipo(n->nombre);  // ← Consultamos tipo desde la tabla

                registrar_variable(n->nombre); // Aseguramos que esté registrada

                if (tipo && strcmp(tipo, "float") == 0) {
                    // Asignación de float
                    if (strcmp(reg, "$f12") != 0) {
                        fprintf(yyout, "    mov.s $f12, %s\n", reg);
                    }
                    fprintf(yyout, "    s.s $f12, %s\n", n->nombre);
                    return "$f12"; // ← Mantenemos $f12 como registro por convención
                } 
                else if (tipo && strcmp(tipo, "string") == 0) {
                    // No guardamos strings en memoria (asumimos literales)
                    return reg;
                } 
                else {
                    // int o bool
                    int esta_inicializada = 0;
                    for (int i = 0; i < MAX_VARS; i++) {
                        if (inicializada[i] && strcmp(inicializada[i], n->nombre) == 0) {
                            esta_inicializada = 1;
                            break;
                        }
                    }
                    if (!esta_inicializada) {
                        fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
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

        if (strcmp(tipo, "int") == 0 || strcmp(tipo, "bool") == 0) {
            int val = (valor != NULL) ? atoi(valor) : 0;
            fprintf(yyout, "%s: .word %d\n", tabla[i].nombre, val);
            if(tabla[i].valor != NULL){
                inicializada[i] =tabla[i].nombre;
            }
        }
        else if (strcmp(tipo, "float") == 0) {
            float val = (valor != NULL) ? atof(valor) : 0.0;
            fprintf(yyout, "%s: .float %f\n", tabla[i].nombre, val);
        }
        else if (strcmp(tipo, "string") == 0) {
            fprintf(yyout, "%s: .asciiz %s\n", tabla[i].nombre, valor ? valor : "");
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