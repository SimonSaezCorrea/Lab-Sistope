#include "particulas.h"

/*
Entrada: particulas *particulas: Se entrega una lista de particulas
         int posicion: Se entrega la posicion de la particula
         int energia: Se entrega la posicion de la energia

Salida: particulas: retornará el struct particulas con el elemento añadido

Descripción: Función que permite guardar una particula al inicio de la lista
*/
particulas *addParticula(particulas *P, int posicion, int energia){
    if(P != NULL){
        particulas *aux;
        aux = (particulas *)malloc(sizeof(particulas));
        aux->posicion = posicion;
        aux->energia = energia;
        aux->next = P;

        return aux;
    }
    else{
        P = (particulas *)malloc(sizeof(particulas));
        P->posicion = posicion;
        P->energia = energia;
        P->next = NULL;
        return P;
    }
}

/*
Entrada: particulas *particulas: Se entrega una lista de particulas

Salida: void

Descripción: Función que permite liberar la memoria usada
*/
void liberarParticulas(particulas *P){
    particulas *aux = P;
    particulas *aux2;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}

/*
Entrada: particulas *particulas: Se entrega una lista de particulas

Salida: void

Descripción: Mostrar los elementos del particulas
*/
void showParticulas(particulas *P){
    particulas *aux = P;
    printf("Particula: \n");
    while(aux->next != NULL){
        printf("%d %d\n", aux->posicion, aux->energia);
        aux = aux->next;
    }
    printf("----------\n");
}
