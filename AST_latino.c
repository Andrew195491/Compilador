    #include "AST_latino.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    // Variable global para el archivo de salida
    extern FILE *yyout;

    #define MAX_VARS 100
    char *lista_vars[MAX_VARS];
    int tipos_vars[MAX_VARS]; // 0=int/bool, 1=float, 2=string
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

    // Array heterogéneo (lista de nodos de cualquier tipo)
    struct ast *crearNodoArray(struct ast *elemento, struct ast *siguiente) {
        struct ast *n = malloc(sizeof(struct ast));
        n->tipoNodo = NODO_ARRAY;
        n->izq = elemento;
        n->dcha = siguiente;
        n->nombre = NULL; n->valor_str = NULL;
        return n;
    }

    // Acceso multidimensional: nombre + lista de índices
    struct ast *crearNodoAccesoArray(const char *nombre, struct ast *indices) {
        struct ast *n = malloc(sizeof(struct ast));
        n->tipoNodo = NODO_ACCESO_ARRAY;
        n->nombre = nombre ? strdup(nombre) : NULL;
        n->izq = indices; // lista de índices (NODO_LISTA)
        n->dcha = NULL;
        n->valor_str = NULL;
        return n;
    }

    struct ast *crearNodoPuts(struct ast *expresion) {
        struct ast *n = malloc(sizeof(struct ast));
        n->tipoNodo = NODO_PUTS; // Usamos NODO_PUTS para simplificar
        n->izq = expresion;
        n->nombre = NULL;;
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
            case NODO_ACCESO_ARRAY: {
                printf("%s", n->nombre ? n->nombre : "");
                printf("[");
                struct ast *idx = n->izq;
                while (idx) {
                    recorrerAST(idx->izq);
                    if (idx->dcha) printf(", ");
                    idx = idx->dcha;
                }
                printf("]");
                break;
            }
            case NODO_PUTS: {
                printf("puts(%s, ", n->nombre);
                recorrerAST(n->izq);
                printf(");\n");
                break;
            }
        }
    }

    // ======== Detección de tipo principal del array ========
    // 0 = enteros/bools, 1 = floats, 2 = strings
    int detectar_tipo_array(struct ast* array) {
        struct ast* elem = array;
        while (elem) {
            if (!elem->izq) { elem = elem->dcha; continue; }
            switch (elem->izq->tipoNodo) {
                case NODO_ARRAY: {
                    int sub = detectar_tipo_array(elem->izq);
                    if (sub != 0) return sub;
                    break;
                }
                case NODO_FLOAT: return 1;
                case NODO_STRING: return 2;
                case NODO_NUMERO:
                case NODO_BOOL:
                    return 0;
                default: break;
            }
            elem = elem->dcha;
        }
        return 0;
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



    // Inicializa un array multidimensional de enteros, floats o strings en memoria (aplanado)
    void generar_inicializacion_array(const char* base_reg, struct ast* array, int* offset, int modo) {
        struct ast* elem = array;
        while (elem) {
            if (!elem->izq) {
                fprintf(yyout, "    # WARNING: Nodo sin valor en array\n");
                (*offset)++;
                elem = elem->dcha;
                continue;
            }

            switch (elem->izq->tipoNodo) {
                case NODO_ARRAY:
                    // Recursión para sub-arrays (aplanado)
                    generar_inicializacion_array(base_reg, elem->izq, offset, modo);
                    break;

                case NODO_NUMERO:
                    if (modo == 0) { // enteros
                        const char* reg = nuevo_temp();
                        fprintf(yyout, "    li %s, %d\n", reg, elem->izq->valor_int);
                        fprintf(yyout, "    sw %s, %d(%s)\n", reg, (*offset) * 4, base_reg);
                    }
                    (*offset)++;
                    break;

                case NODO_BOOL:
                    if (modo == 0) { // enteros
                        const char* reg = nuevo_temp();
                        int val = (strcmp(elem->izq->valor_str, "true") == 0) ? 1 : 0;
                        fprintf(yyout, "    li %s, %d\n", reg, val);
                        fprintf(yyout, "    sw %s, %d(%s)\n", reg, (*offset) * 4, base_reg);
                    }
                    (*offset)++;
                    break;

                case NODO_FLOAT:
                    if (modo == 1) { // floats
                        // Usamos $f0 como registro temporal de float
                        fprintf(yyout, "    li.s $f0, %.8f\n", elem->izq->valor_float);
                        fprintf(yyout, "    s.s $f0, %d(%s)\n", (*offset) * 4, base_reg);
                    }
                    (*offset)++;
                    break;

                case NODO_STRING:
                    if (modo == 2) { // strings
                        // Declara string en .data y guarda la dirección
                        fprintf(yyout, ".data\nstr_%d: .asciiz %s\n.text\n", string_label_counter, elem->izq->valor_str);
                        const char* reg = nuevo_temp();
                        fprintf(yyout, "    la %s, str_%d\n", reg, string_label_counter);
                        fprintf(yyout, "    sw %s, %d(%s)\n", reg, (*offset) * 4, base_reg);
                        string_label_counter++;
                    }
                    (*offset)++;
                    break;

                default:
                    fprintf(yyout, "    # WARNING: Tipo no soportado en inicialización de arrays\n");
                    (*offset)++;
                    break;
            }
            elem = elem->dcha;
        }
    }

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
            case NODO_STRING: {
                const char* reg = nuevo_temp();
                fprintf(yyout, "    la %s, str_%d\n", reg, string_label_counter);
                string_label_counter++;
                return reg;
            }
            case NODO_VARIABLE: {
                const char* reg = nuevo_temp();
                registrar_variable(n->nombre);
                fprintf(yyout, "    lw %s, %s\n", reg, n->nombre);
                return reg;
            }
            case NODO_FLOAT: {
                const char* reg = nuevo_temp();
                fprintf(yyout, "    li.s %s, %d\n", reg, n->valor_int);
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
                if (n->izq && n->izq->tipoNodo == NODO_ARRAY) {
                    // Detecta tipo del array: 0=int/bool, 1=float, 2=string
                    int tipo = detectar_tipo_array(n->izq);
                    registrar_variable(n->nombre);
                    fprintf(yyout, "    la $a0, %s\n", n->nombre);
                    int offset = 0;
                    generar_inicializacion_array("$a0", n->izq, &offset, tipo);
                    return "$a0";
                } else {
                    // Asignación simple: detecta tipo y usa la instrucción adecuada
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
                        fprintf(yyout, "    sw %s, %s\n", reg, n->nombre);
                    }
                    return reg;
                }
            }
            case NODO_ARRAY: {
                // No genera código, solo sirve para el AST
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

    void declarar_arrays_data() {
        for (int i = 0; i < num_vars; i++) {
            int tipo = tipos_vars[i];
            if (tipo == 1) // float
                fprintf(yyout, "%s: .float 0:100\n", lista_vars[i]);
            else // int/bool/string puntero
                fprintf(yyout, "%s: .word 0:100\n", lista_vars[i]);
        }
    }

    void declarar_string(const char *nombre, const char *valor) {
        fprintf(yyout, "%s: .asciiz \"%s\"\n", nombre, valor);
    }

    void declarar_integer(const char *nombre, int valor) {
        fprintf(yyout, "%s: .word %d\n", nombre, valor);
    }
    void declarar_float(const char *nombre, float valor) {
        fprintf(yyout, "%s: .float %f\n", nombre, valor);
    }
    void declarar_bool(const char *nombre, const char *valor) {
        int val = (strcmp(valor, "true") == 0) ? 1 : 0;
        fprintf(yyout, "%s: .word %d\n", nombre, val);
    }
    // ======== Recolectar variables y tipos del AST ========

    void recolectar_vars_tipos(struct ast *nodo) {
        if (!nodo) return;
        if (nodo->tipoNodo == NODO_ASIGNACION) {
            registrar_variable(nodo->nombre);
            // Detecta tipo del array si es array
            if (nodo->izq && nodo->izq->tipoNodo == NODO_ARRAY) {
                int tipo = detectar_tipo_array(nodo->izq);
                for (int i = 0; i < num_vars; i++) {
                    if (strcmp(lista_vars[i], nodo->nombre) == 0) {
                        tipos_vars[i] = tipo;
                        break;
                    }
                }
            }
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
        //declarar_arrays_data();
        //declarar_bool();
        //declarar_integer();
        //declarar_float();  
        //declarar_string();  
        fprintf(yyout, "\n");

        // 3. Sección .text y main
        fprintf(yyout, ".text\n.globl main\nmain:\n");
       // generar_puts(n);

        // 4. Código de instrucciones
        generarASM_rec(n);

        // 5. Salida limpia de MIPS
        fprintf(yyout, "    li $v0, 10\n    syscall\n");
    }
