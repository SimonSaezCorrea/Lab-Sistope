#ifndef LINEAS
#define LINEAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Estructura: lineas

Descripción: Estructura que representa un elemento de una lista enlazada de 
             lineas. Cada elemento contiene una linea y un puntero 
             al siguiente elemento de la lista.

Campos: char *linea: Dato que guarda la linea
        struct lineas* next: Un puntero al siguiente elemento de la 
                                 lista enlazada, o NULL si este es el 
                                 último elemento de la lista.
*/
typedef struct lineas{
    char *linea;
    struct lineas *next;
}lineas;

lineas *addLinea(lineas *lineas, char *linea);

void liberarLineas(lineas *lineas);

void showLineas(lineas *lineas);

char *searchLineas(lineas *lineas, int position, int len);

#endif