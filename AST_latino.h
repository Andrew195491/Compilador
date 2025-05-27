#ifndef AST_LATINO_H
#define AST_LATINO_H

enum tipoNodoAST {
    NODO_LISTA,
    NODO_ASIGNACION,
    NODO_SUMA,
    NODO_RESTA,
    NODO_MULT,
    NODO_DIV,
    NODO_NUMERO,
    NODO_FLOAT,
    NODO_STRING,
    NODO_BOOL,
    NODO_VARIABLE,
    NODO_ARRAY,
    NODO_ACCESO_ARRAY
};

struct ast {
    enum tipoNodoAST tipoNodo;
    int valor_int;
    float valor_float;
    char* valor_str;
    char* nombre;
    struct ast *izq, *dcha;
};

struct ast *crearNodoLista(struct ast *izq, struct ast *dcha);
struct ast *crearNodoAsignacion(const char* nombre, struct ast *valor);
struct ast *crearNodoOperacion(enum tipoNodoAST tipo, struct ast *izq, struct ast *dcha);
struct ast *crearNodoNumero(int valor);
struct ast *crearNodoFloat(float valor);
struct ast *crearNodoString(const char* valor);
struct ast *crearNodoBool(const char* valor);
struct ast *crearNodoVariable(const char* nombre);
struct ast *crearNodoArray(struct ast *elemento, struct ast *siguiente);
struct ast *crearNodoAccesoArray(const char *nombre, struct ast *indice);


void recorrerAST(struct ast *n);
void liberarAST(struct ast *n);
void generarASM(struct ast *n);

#endif
