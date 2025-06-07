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

        tabla[pos].tipo = strdup(tipo);
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

void guardar_simbolo_array(const char* nombre, const char* tipo, const char* tipoBase, int Tam, const char* Valores) {
    int pos = buscarTabla(nombre);
    const char* valores_final = Valores ? Valores : "NULL"; // Si Valores es NULL, guarda "NULL"
    if (pos >= 0) {
        free(tabla[pos].tipo);
        free(tabla[pos].tipoBase);
        free(tabla[pos].Valores);

        tabla[pos].tipo = strdup(tipo);
        tabla[pos].tipoBase = strdup(tipoBase);
        tabla[pos].Tamanio = Tam;
        tabla[pos].Valores = strdup(valores_final);
        tabla[pos].valor = NULL;
    } else {
        if (indice >= MAX_SIMBOLOS) {
            fprintf(stderr, "[ERROR] Tabla de simbolos llena.\n");
            exit(EXIT_FAILURE);
        }
        tabla[indice].nombre = strdup(nombre);
        tabla[indice].tipo = strdup(tipo);
        tabla[indice].tipoBase = strdup(tipoBase);
        tabla[indice].Tamanio = Tam;
        tabla[indice].Valores = strdup(valores_final);
        tabla[indice].valor = NULL;
        tabla[indice].registro = indice;
        indice++;
    }
}

void guardar_simbolo_matriz(const char* nombre, const char* tipo, const char* tipoBase, int Filas, int Columnas, const char* Valores) {
    int pos = buscarTabla(nombre);
    if (pos >= 0) {
        free(tabla[pos].tipo);
        free(tabla[pos].tipoBase);
        free(tabla[pos].Valores);

        tabla[pos].tipo = strdup(tipo);
        tabla[pos].tipoBase = strdup(tipoBase);
        tabla[pos].Filas = Filas;
        tabla[pos].Columnas = Columnas;
        tabla[pos].Valores = strdup(Valores);
        tabla[pos].valor = NULL;
    } else {
        if (indice >= MAX_SIMBOLOS) {
            fprintf(stderr, "[ERROR] Tabla de simbolos llena.\n");
            exit(EXIT_FAILURE);
        }
        tabla[indice].nombre = strdup(nombre);
        tabla[indice].tipo = strdup(tipo);
        tabla[indice].tipoBase = strdup(tipoBase);
        tabla[indice].Filas = Filas;
        tabla[indice].Columnas = Columnas;
        tabla[indice].Valores = strdup(Valores);
        tabla[indice].valor = NULL;
        tabla[indice].registro = indice;
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
    printf("%-5s | %-15s | %-10s | %-10s | %-7s | %-7s | %-7s | %-10s | %-10s\n", "Reg", "Nombre", "Tipo", "TipoBase", "Tam", "Filas", "Columnas", "Valor", "Valores");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < indice; ++i) {
        printf("%-5d | %-15s | %-10s | %-10s | %-7d | %-7d | %-7d | %-10s | %-10s\n",
            tabla[i].registro,
            tabla[i].nombre,
            tabla[i].tipo ? tabla[i].tipo : "",
            tabla[i].tipoBase ? tabla[i].tipoBase : "",
            tabla[i].Tamanio ? tabla[i].Tamanio : 0,
            tabla[i].Filas > 0 ? tabla[i].Filas : 0,
            tabla[i].Columnas ? tabla[i].Columnas : 0,
            tabla[i].valor ? tabla[i].valor : "",
            tabla[i].Valores ? tabla[i].Valores : ""
        );
    }
    printf("---------------------------------------------------------------------------------------------------------\n\n");
}