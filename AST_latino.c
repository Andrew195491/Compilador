    #include "AST_latino.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    #include "tabla_simbolos.h"

    // Variable global para el archivo de salida
    extern FILE *yyout;

    #define MAX_VARS 100
    char *lista_vars[MAX_VARS];
    int tipos_vars[MAX_VARS]; // 0=int/bool, 1=float, 2=string
    char* inicializada[MAX_VARS]; // SE METEN LOS VALORES INICIALIZADOS EN EL ARRAY
    int num_vars = 0;

    // Para strings en .data
    int string_label_counter = 0;

    void registrar_variable(const char *nombre) {
        if (!nombre) return;
        for (int i = 0; i < num_vars; i++) {
            if (lista_vars[i] && strcmp(lista_vars[i], nombre) == 0)
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

    struct ast *crearNodoPuts(struct ast *expresion) {
        struct ast *n = malloc(sizeof(struct ast));
        n->tipoNodo = NODO_PUTS;
        n->izq = expresion;
        n->nombre = NULL;
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

    
    const char* nuevo_temp(const char* tipo) {  
        static char buffer[20][6];
        static int temp_counter_float = 0; // Contador para temporales de tipo float
        static int temp_counter_int = 0; // Contador para temporales de tipo int
        int idx;
        if (strcmp(tipo, "float") == 0) {
        idx = temp_counter_float % 10;
        sprintf(buffer[idx], "$f%d", 12 + idx);  // Float temporals: $f12–$f21
        temp_counter_float++;
        } else {
        idx = temp_counter_int % 10;
        sprintf(buffer[10 + idx], "$t%d", idx);  // Int temporals: $t0–$t9
        temp_counter_int++;
        }

        return (strcmp(tipo, "float") == 0) ? buffer[idx] : buffer[10 + idx];

    }

    // Función para crear un nuevo registro temporal, diferenciando entre enteros y flotantes
    const char* nuevo_temp1(const char* tipo) {
    static char buffer[20][6]; // hasta 20 registros, más espacio para "$f10", etc.
    static int temp_counter_int = 0;
    static int temp_counter_float = 0;

    int idx;

    if (strcmp(tipo, "int") == 0) {
        idx = temp_counter_int % 10;
        sprintf(buffer[idx], "$t%d", idx);  // registros temporales enteros
        temp_counter_int++;
        return buffer[idx];
    }
    else if (strcmp(tipo, "float") == 0) {
        idx = temp_counter_float % 10;
        sprintf(buffer[10 + idx], "$f%d", idx * 2);  // registros flotantes ($f0, $f2, etc.)
        temp_counter_float++;
        return buffer[10 + idx];
    }
    else {
        return "ERROR"; // tipo desconocido
    }
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
                fprintf(yyout, "    mov.s $f12, %s\n", reg);
                fprintf(yyout, "    li $v0, 2\n");
                break;
            case NODO_NUMERO:
            case NODO_BOOL:
            case NODO_VARIABLE:
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
        for(int pos = 0; pos < indice; pos++) { // RECORRE LAS POSICIONES DE LA TABLA DE SIMBOLOS
            switch(n->tipoNodo) {
                case NODO_NUMERO: {
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    return reg;
                }
                case NODO_BOOL: {
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    return reg;
                }
                case NODO_STRING: {
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    fprintf(yyout, "    la %s, str_%d\n", reg, string_label_counter);
                    string_label_counter++;
                    return reg;
                }
                case NODO_VARIABLE: {
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    registrar_variable(n->nombre);
                    fprintf(yyout, "    lw %s, %s\n", reg, n->nombre);
                    return reg;
                }
                case NODO_FLOAT: {
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    fprintf(yyout, "    l.s %s, %f\n", reg, n->valor_float);
                    return reg;
                }
                case NODO_SUMA: {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    if(strcmp(tabla[pos].tipo, "int") == 0) { // SI EL VALOR ES ENTERO, HACE ADD
                        fprintf(yyout, "    add %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    }
                    else if(strcmp(tabla[pos].tipo, "float") == 0) { // SI EL VALOR ES FLOAT, HACE ADD.S
                        fprintf(yyout, "    add.s %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    }
                    return reg;
                }
                case NODO_RESTA: {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    if(strcmp(tabla[pos].tipo, "int") == 0) { // SI EL VALOR ES ENTERO, HACE SUB
                        fprintf(yyout, "    sub %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    }
                    else if(strcmp(tabla[pos].tipo, "float") == 0) { // SI EL VALOR ES FLOAT, HACE SUB.S
                        fprintf(yyout, "    sub.s %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    }
                    return reg;
                }
                case NODO_MULT: {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    fprintf(yyout, "    mul %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                }
                case NODO_DIV: {
                    const char* reg_izq = generarASM_rec(n->izq);
                    const char* reg_dcha = generarASM_rec(n->dcha);
                    const char* reg = nuevo_temp(tabla[pos].tipo);
                    fprintf(yyout, "    div %s, %s, %s\n", reg, reg_izq, reg_dcha);
                    return reg;
                }
                case NODO_ASIGNACION: {
                    const char* reg = generarASM_rec(n->izq);

                    // Detecta el tipo de la expresión derecha
                    int tipo = -1;
                    switch (n->izq->tipoNodo) {
                        case NODO_NUMERO:
                        case NODO_BOOL:
                            tipo = 0; // int/bool
                            break;
                        case NODO_FLOAT:
                            tipo = 1; // float
                            break;
                        case NODO_STRING:
                            tipo = 2; // string
                            break;
                        default:
                            tipo = 0;
                    }

                    registrar_variable(n->nombre);

                    if (tipo == 1) {
                        // float
                        fprintf(yyout, "    s.s %s, %s\n", reg, n->nombre);
                    } else if (tipo == 2) {
                        // string: reg debe ser la dirección del string
                        fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
                    } else {
                        // int/bool
                        for(int i = 0; i < MAX_SIMBOLOS; i++) {
                            if (inicializada[i] && strcmp(inicializada[i], n->nombre) == 0) { // SI UN ID NO ESTÁ INICIALIZADO (NO ESTÁ EN LA TABLA DE INICIALIZADA), SALE EL SW
                                fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
                                break;
                            }
                        }
                    }
                    return reg;
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
                for(int j = 0; j < MAX_SIMBOLOS; j++){ // INTRODUZCO CADA NOMBRE DE LA ID EN EL ARRAY SIEMPRE QUE SE HAYA INICIALIZADO ANTES
                    inicializada[j] = tabla[i].nombre;
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