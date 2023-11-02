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

/*
Entrada: particulas *particulas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las particulas y que 
                                 además dirijirá a otro particulas, es decir es 
                                 una lista de datos 
         int posicion: Se entrega la posicion de la particula
         int energia: Se entrega la posicion de la energia

Salida: particulas: retornará el struct particulas con el elemento añadido

Descripción: Función que permite guardar una particula al final de la cola
*/
particulas *addParticula(particulas *particulas, int posicion, int energia);

/*
Entrada: particulas *particulas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las particulas y que 
                                 además dirijirá a otro particulas, es decir es 
                                 una lista de datos  

Salida: Nada

Descripción: Función que permite liberar la memoria usada
*/
void liberarParticulas(particulas *particulas);

/*
Entrada: particulas *particulas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las particulas y que 
                                 además dirijirá a otro particulas, es decir es 
                                 una lista de datos 
Salida: Nada

Descripción: Mostrar los elementos del particulas
*/
void showLineas(particulas *particulas);

/*
Entrada: particulas *particulas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las particulas y que 
                                 además dirijirá a otro particulas, es decir es 
                                 una lista de datos 
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de particulas

Salida: int: El arreglo de descriptores de una posición en específica

Descripción: Permite buscar, dentro de la lista particulas, un elemento en una
             posición X
*/
int *searchLineas(particulas *particulas, int position, int len);

#endif