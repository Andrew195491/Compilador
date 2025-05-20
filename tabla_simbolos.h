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
} tSimbolos;

/* Tabla global */
extern tSimbolos tabla[MAX_SIMBOLOS]; // Con su tamaño máximo
extern int indice; // Posición de cada símbolo

/* Prototipos */
void guardar_simbolo(const char* nombre, const char* tipo);
const char* obtener_tipo(const char* nombre);
void mostrar_tabla(void);
int buscarTabla(const char* nombre);

#endif // TABLA_SIMBOLOS_H
