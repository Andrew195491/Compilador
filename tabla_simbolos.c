#include "tabla_simbolos.h"
#include <stdbool.h>
#include <string.h>

/* Definición de variables globales */
tSimbolos tabla[MAX_SIMBOLOS]; // Máximo de valores en la tabla
int indice = 0; // Llevamos la cuenta

/* Busca un símbolo por nombre; devuelve posición o -1 si no existe */
int buscarTabla(const char* nombre) {
    bool encontrado = false;
    int i = 0;
    while (i < indice && encontrado == false){
        if (strcmp(tabla[i].nombre, nombre) == 0) { // Compara (strcmp -> Compara strings) cada nombre de la tabla por orden (tabla[i].nombre) con nuestro nombre
            encontrado = true;
        }else{
            i++;
        }
    }
    if (encontrado == false){
        return -1; // Si no lo encuentra, devuelve -1
    }else{
        return i; // Si lo encuentra, devuelve su posición
    }
}

/* Inserta un símbolo si no existe; si existe, actualiza su tipo */
void guardar_simbolo(const char* nombre, const char* tipo, const char* valor) {
    int pos = buscarTabla(nombre); // Primero mira si el simbolo ya estaba en la tabla
    if (pos >= 0) { // Si existe, limpia su tipo y lo modifica con el nuevo
        /* Actualizar tipo si necesario */
        free(tabla[pos].tipo);
        free(tabla[pos].valor);

        tabla[pos].tipo = strdup(tipo);
        tabla[pos].valor = strdup(valor);
    } else {
        if (indice >= MAX_SIMBOLOS) { // Si no existe, comprueba que haya espacio en la tabla
            fprintf(stderr, "[ERROR] Tabla de simbolos llena.\n"); // Si no hay espacio, salta error
            exit(EXIT_FAILURE);
        }
        /* Si hay espacio */
        tabla[indice].nombre = strdup(nombre); // En la posición del índice, columna del nombre, pone el nombre
        tabla[indice].tipo = strdup(tipo);
        tabla[indice].valor = strdup(valor);
        tabla[indice].registro = indice; // Guarda la posición en la que ha quedado en la tabla
        indice++;
    }
}

/* Retorna el tipo de un identificador o NULL si no está declarado */
const char* obtener_tipo(const char* nombre) {
    int pos = buscarTabla(nombre); // Mira si el simbolo ya estaba en la tabla
    if (pos >= 0) {
        return tabla[pos].tipo; // Si lo encuentra, devuelve de la tabla, de la posición que encontró, lo que hay en la columna "tipo"
    }
    return NULL;
}

/* Muestra la tabla de símbolos por consola */
void mostrar_tabla(void) {
    printf("\n[Tabla de simbolos]\n");
    printf("%-5s | %-15s | %-7s | %-10s\n", "Reg", "Nombre", "Tipo", "Valor");
    // %-5s -> Imprime una cadena (s) en un campo de anchura máxima de 5 alineado a la izquierda (-)
    // Reg   | Nombre          | Tipo         | Valor
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < indice; ++i) {
        printf("%-5d | %-15s | %-7s | %-10s\n",
               tabla[i].registro, // Saca la posición de cada variable
               tabla[i].nombre, // Su nombre
               tabla[i].tipo, // El tipo de dato
               tabla[i].valor); // El tipo de dato
    }
    printf("--------------------------------------------------------------------------------\n\n");
}