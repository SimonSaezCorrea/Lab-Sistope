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

/*
Entrada: descriptores *descriptores: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las descriptores y que 
                                 además dirijirá a otro descriptores, es decir es 
                                 una lista de dato

Salida: descriptores: retornará el struct descriptores con el elemento añadido

Descripción: Función que permite guardar una particula al final de la cola
*/
descriptores *addDescriptor(descriptores *descriptores);

/*
Entrada: descriptores *descriptores: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las descriptores y que 
                                 además dirijirá a otro descriptores, es decir es 
                                 una lista de datos  

Salida: Nada

Descripción: Función que permite liberar la memoria usada
*/
void liberarDescriptor(descriptores *descriptores);

/*
Entrada: descriptores *descriptores: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las descriptores y que 
                                 además dirijirá a otro descriptores, es decir es 
                                 una lista de datos 
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de descriptores

Salida: int: El arreglo de descriptores de una posición en específica

Descripción: Permite buscar, dentro de la lista descriptores, un elemento en una
             posición X
*/
int *searchDescriptor(descriptores *descriptores, int position, int len);

#endif