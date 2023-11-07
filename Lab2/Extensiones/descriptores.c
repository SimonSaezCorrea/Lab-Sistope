#include "descriptores.h"

/*
Entrada: descriptores *descriptores: Se entrega una lista de descriptores

Salida: descriptores: retornará el struct descriptores con el elemento añadido

Descripción: Función que permite guardar un descriptor e iniciarla con el pipe 
             al final de la cola
*/
descriptores *addDescriptor(descriptores *P){
    descriptores *aux = P;

    if(aux != NULL){
        while(aux->next!=NULL){
                aux = aux->next;
        }
        aux->next = (descriptores *)malloc(sizeof(descriptores));
        pipe(aux->next->fd);
        aux->next->next = NULL;
    }
    else{
        aux = (descriptores *)malloc(sizeof(descriptores));
        pipe(aux->fd);
        aux->next = NULL;
        P = aux;
    }

    return P;
}

/*
Entrada: descriptores *descriptores: Se entrega una lista de descriptores

Salida: void

Descripción: Función que permite liberar la memoria usada
*/
void liberarDescriptor(descriptores *P){
    descriptores *aux = P;
    descriptores *aux2;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}

/*
Entrada: descriptores *descriptores: Se entrega una lista de descriptores
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de descriptores

Salida: int: El arreglo de descriptores de una posición en específica

Descripción: Permite buscar, dentro de la lista descriptores, un elemento en una
             posición X
*/
int *searchDescriptor(descriptores *P, int position, int len){
    descriptores *aux = P;
    if(len > position){
        int i = 0;
        while(i<position){
            aux = aux->next;
            i++;
        }
        return aux->fd;
    }else{
        printf("No se puede acceder a esa posición\n");
        return NULL;
    }

}