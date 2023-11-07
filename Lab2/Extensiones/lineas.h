#ifndef LINEAS
#define LINEAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Estructura: lineas

Descripción: Estructura que representa un elemento de una lista enlazada de 
             lineas. Cada elemento contiene una particula y un puntero 
             al siguiente elemento de la lista.

Campos: int posicion: Dato de posicion de una particula.
        int energia: Dato de energía de una particula.
        struct lineas* next: Un puntero al siguiente elemento de la 
                                 lista enlazada, o NULL si este es el 
                                 último elemento de la lista.
*/
typedef struct lineas{
    char *linea;
    struct lineas *next;
}lineas;

/*
Entrada: lineas *lineas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las lineas y que 
                                 además dirijirá a otro lineas, es decir es 
                                 una lista de datos 
         int posicion: Se entrega la posicion de la particula
         int energia: Se entrega la posicion de la energia

Salida: lineas: retornará el struct lineas con el elemento añadido

Descripción: Función que permite guardar una particula al final de la cola
*/
lineas *addLinea(lineas *lineas, char *linea);

/*
Entrada: lineas *lineas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las lineas y que 
                                 además dirijirá a otro lineas, es decir es 
                                 una lista de datos  

Salida: Nada

Descripción: Función que permite liberar la memoria usada
*/
void liberarLineas(lineas *lineas);

/*
Entrada: lineas *lineas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las lineas y que 
                                 además dirijirá a otro lineas, es decir es 
                                 una lista de datos 
Salida: Nada

Descripción: Mostrar los elementos del lineas
*/
void showLineas(lineas *lineas);

/*
Entrada: lineas *lineas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las lineas y que 
                                 además dirijirá a otro lineas, es decir es 
                                 una lista de datos 
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de lineas

Salida: int: El arreglo de descriptores de una posición en específica

Descripción: Permite buscar, dentro de la lista lineas, un elemento en una
             posición X
*/
char *searchLineas(lineas *lineas, int position, int len);

#endif