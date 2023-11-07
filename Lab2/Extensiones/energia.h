#ifndef ENERGIA
#define ENERGIA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Estructura: energia

Descripción: Estructura que representa un elemento de una lista enlazada de 
             energia. Cada elemento contiene una particula y un puntero 
             al siguiente elemento de la lista.

Campos: int posicion: Dato de posicion de una particula.
        int energia: Dato de energía de una particula.
        struct energia* next: Un puntero al siguiente elemento de la 
                                 lista enlazada, o NULL si este es el 
                                 último elemento de la lista.
*/
typedef struct energia{
    double energia;
    struct energia *next;
}energia;

/*
Entrada: energia *energia: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las energia y que 
                                 además dirijirá a otro energia, es decir es 
                                 una lista de datos 
         int posicion: Se entrega la posicion de la particula
         int energia: Se entrega la posicion de la energia

Salida: energia: retornará el struct energia con el elemento añadido

Descripción: Función que permite guardar una particula al final de la cola
*/
energia *addEnergia(energia *energia);

/*
Entrada: energia *energia: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las energia y que 
                                 además dirijirá a otro energia, es decir es 
                                 una lista de datos  

Salida: Nada

Descripción: Función que permite liberar la memoria usada
*/
void liberarEnergia(energia *energia);

/*
Entrada: energia *energia: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las energia y que 
                                 además dirijirá a otro energia, es decir es 
                                 una lista de datos 
Salida: Nada

Descripción: Mostrar los elementos del energia
*/
void showEnergia(energia *energia);

/*
Entrada: energia *energia: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las energia y que 
                                 además dirijirá a otro energia, es decir es 
                                 una lista de datos 
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de energia

Salida: int: El arreglo de descriptores de una posición en específica

Descripción: Permite buscar, dentro de la lista energia, un elemento en una
             posición X
*/
double searchEnergia(energia *energia, int position, int len);

void sumarEnergia(energia *P, int position, int len, double valor);
#endif