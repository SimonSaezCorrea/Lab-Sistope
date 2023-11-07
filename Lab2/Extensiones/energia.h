#ifndef ENERGIA
#define ENERGIA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Estructura: energia

Descripción: Estructura que representa un elemento de una lista enlazada de 
             energia. Cada elemento tiene la energia de la celda y un puntero 
             al siguiente elemento de la lista.

Campos: int energia: Dato de energía de la celda.
        struct energia* next: Un puntero al siguiente elemento de la 
                                 lista enlazada, o NULL si este es el 
                                 último elemento de la lista.
*/
typedef struct energia{
    double energia;
    struct energia *next;
}energia;


energia *addEnergia(energia *energia);

void liberarEnergia(energia *energia);

void showEnergia(energia *energia);

double searchEnergia(energia *energia, int position, int len);

void sumarEnergia(energia *P, int position, int len, double valor);
#endif