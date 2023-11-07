#ifndef DESCRIPTORES
#define DESCRIPTORES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Estructura: descriptores

Descripción: Estructura que representa un elemento de una lista enlazada de 
             descriptores. Cada elemento contiene una particula y un puntero 
             al siguiente elemento de la lista.

Campos: int fd[2]: Arreglo que almacena los descriptores.
        struct descriptores* next: Un puntero al siguiente elemento de la 
                                 lista enlazada, o NULL si este es el 
                                 último elemento de la lista.
*/
typedef struct descriptores{
    int fd[2];
    struct descriptores *next;
}descriptores;

descriptores *addDescriptor(descriptores *descriptores);

void liberarDescriptor(descriptores *descriptores);

int *searchDescriptor(descriptores *descriptores, int position, int len);

#endif