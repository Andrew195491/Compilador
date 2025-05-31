#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIMBOLOS 256

typedef struct {
    int numerico;           // valor int
    float numericoDecimal;  // valor float
    char* texto;            // valor char*
    char* nombre;           // identificador
    char* tipo;             // "int", "string", "bool"
    int registro;           // posición en la tabla
    char* valor;             // valor de la variable
    char* tipoBase;
    int Tamanio;
    char* Valores;
    int Filas;
    int Columnas;
} tSimbolos;

/* Tabla global */
extern tSimbolos tabla[MAX_SIMBOLOS]; // Con su tamaño máximo
extern int indice; // Posición de cada símbolo

/* Prototipos */
void guardar_simbolo(const char* nombre, const char* tipo, const char* valor);
void guardar_simbolo_array(const char* nombre, const char* tipo, const char* tipoBase, int Tam, const char* Valores);
void guardar_simbolo_matriz(const char* nombre, const char* tipo, const char* tipoBase, int Filas, int Columnas, const char* Valores);
const char* obtener_tipo(const char* nombre);
void mostrar_tabla(void);
int buscarTabla(const char* nombre);

#endif // TABLA_SIMBOLOS_H
