#ifndef PARTICULAS
#define PARTICULAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Estructura: particulas

Descripción: Estructura que representa un elemento de una lista enlazada de 
             particulas. Cada elemento contiene una particula y un puntero 
             al siguiente elemento de la lista.

Campos: int posicion: Dato de posicion de una particula.
        int energia: Dato de energía de una particula.
        struct particulas* next: Un puntero al siguiente elemento de la 
                                 lista enlazada, o NULL si este es el 
                                 último elemento de la lista.
*/
typedef struct particulas{
    int posicion;
    int energia;
    struct particulas *next;
}particulas;

particulas *addParticula(particulas *particulas, int posicion, int energia);

void liberarParticulas(particulas *particulas);

void showParticulas(particulas *particulas);

#endif