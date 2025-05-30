#ifndef AST_LATINO_H
#define AST_LATINO_H

#include "tabla_simbolos.h"

enum tipoNodoAST {
    NODO_LISTA, NODO_ASIGNACION, NODO_SUMA, NODO_RESTA, NODO_MULT, NODO_DIV,
    NODO_NUMERO, NODO_FLOAT, NODO_STRING, NODO_BOOL, NODO_VARIABLE,
    NODO_ARRAY, NODO_ACCESO_ARRAY, NODO_PUTS
};

struct ast {
    enum tipoNodoAST tipoNodo;
    struct ast *izq;
    struct ast *dcha;
    char* nombre;
    char* valor_str;
    int valor_int;
    float valor_float;
};

// Prototipos de funciones
struct ast *crearNodoLista(struct ast *izq, struct ast *dcha);
struct ast *crearNodoAsignacion(const char* nombre, struct ast *valor);
struct ast *crearNodoOperacion(enum tipoNodoAST tipo, struct ast *izq, struct ast *dcha);
struct ast *crearNodoNumero(int valor);
struct ast *crearNodoFloat(float valor);
struct ast *crearNodoString(const char* valor);
struct ast *crearNodoBool(const char* valor);
struct ast *crearNodoVariable(const char* nombre);
struct ast *crearNodoPuts(struct ast *expresion);
void liberarAST(struct ast *n);
void generarASM(struct ast *n);

#endif
