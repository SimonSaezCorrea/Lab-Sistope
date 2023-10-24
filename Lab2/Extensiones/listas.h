#ifndef LISTAS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Estructura: pipeline

Descripción: Estructura que representa un elemento de una lista enlazada de 
             descriptores. Cada elemento contiene un arreglo de descriptores 
             (fd) y un puntero al siguiente elemento de la lista.

Campos: int fd[2]: Arreglo que almacena dos descriptores. fd[0] se utiliza como el descriptor
                   de lectura y fd[1] se utiliza como el descriptor de escritura.
        struct pipeline* next: Un puntero al siguiente elemento de la lista enlazada, o NULL 
                               si este es el último elemento de la lista.
*/
typedef struct pipeline{
    int fd[2];
    struct pipeline *next;
}pipeline;

/*
Entrada: pipeline *P: Se entrega una estructura de dato en la cual contendrá un 
                      arreglo que guarda descriptores y que además dirijirá
                      a otro pipeline, es decir es una lista de datos 

Salida: pipeline: retornará el pipeline con el elemento añadido

Descripción: Función que permite guardar un arreglo de descriptores al final de la cola
*/
pipeline *add(pipeline *P);

/*
Entrada: pipeline *P: Se entrega una estructura de dato en la cual contendrá un 
                      arreglo que guarda descriptores y que además dirijirá
                      a otro pipeline, es decir es una lista de datos

Salida: Nada

Descripción: Función que permite liberar la memoria usada
*/
void *liberar(pipeline *P);

/*
Entrada: pipeline *P: Se entrega una estructura de dato en la cual contendrá un 
                      arreglo que guarda descriptores y que además dirijirá
                      a otro pipeline, es decir es una lista de datos

Salida: Nada

Descripción: Mostrar los elementos del pipeline
*/
void show(pipeline *P);

/*
Entrada: pipeline *P: Se entrega una estructura de dato en la cual contendrá un 
                      arreglo que guarda descriptores y que además dirijirá
                      a otro pipeline, es decir es una lista de datos
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de pipeline

Salida: int: El arreglo de descriptores de una posición en específica

Descripción: Permite buscar, dentro de la lista pipeline, un elemento en una
             posición X
*/
int *search(pipeline *P, int position, int len);

#endif