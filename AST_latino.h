#ifndef AST_LATINO_H
#define AST_LATINO_H

#include "tabla_simbolos.h"

enum tipoNodoAST {
    NODO_LISTA, NODO_ASIGNACION, NODO_SUMA, NODO_RESTA, NODO_MULT, NODO_DIV,
    NODO_NUMERO, NODO_FLOAT, NODO_STRING, NODO_BOOL, NODO_VARIABLE,
    NODO_ARRAY, NODO_ACCESO_ARRAY, NODO_PUTS, NODO_WHILE, NODO_IF, NODO_ELSE, NODO_FUNCION, NODO_LLAMADA_FUNCION,
    NODO_IGUALIGUAL,NODO_DIFERENTE, NODO_MENOR, NODO_MAYOR, NODO_MENORIGUAL, NODO_MAYORIGUAL,
};

struct ast {
    enum tipoNodoAST tipoNodo;
    struct ast *izq;
    struct ast *dcha;
    char* nombre;
    char* valor_str;
    int valor_int;
    float valor_float;
    int es_inicializada;
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
struct ast* crearNodoArray(struct ast* elemento, struct ast* siguiente);

struct ast *crearNodoPuts(struct ast *expresion);

struct ast* crearNodoWhile(struct ast* condicion, struct ast* cuerpo);

struct ast* crearNodoIf(struct ast* condicion, struct ast* cuerpo, struct ast* else_cuerpo);
struct ast* crearNodoElse(struct ast* cuerpo);

struct ast* crearNodoFuncion(const char* nombre, struct ast* parametros, struct ast* cuerpo);
struct ast* crearNodoParametro(const char* nombre, struct ast* siguiente);
struct ast* crearNodoLlamadaFuncion(const char* nombre, struct ast* argumentos);
struct ast* crearNodoArgumento(struct ast* valor, struct ast* siguiente);

void liberarAST(struct ast *n);
void generarASM(struct ast *n);

#endif
