#include "particulas.h"

particulas *addParticula(particulas *P, int posicion, int energia){
    particulas *aux = P;

    if(aux != NULL){
        while(aux->next!=NULL){
                aux = aux->next;
        }
        aux->next = (particulas *)malloc(sizeof(particulas));
        aux->next->posicion = posicion;
        aux->next->energia = energia;
        aux->next->next = NULL;
    }
    else{
        aux = (particulas *)malloc(sizeof(particulas));
        aux->posicion = posicion;
        aux->energia = energia;
        aux->next = NULL;
        P = aux;
    }

    return P;
}

void liberarParticulas(particulas *P){
    particulas *aux = P;
    particulas *aux2;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}

void showParticulas(particulas *P){
    particulas *aux = P;
    printf("Particula: \n");
    while(aux->next != NULL){
        printf("%d %d\n", aux->posicion, aux->energia);
        aux = aux->next;
    }
    printf("----------\n");
}

int *searchParticulas(particulas *P, int position, int len){
    particulas *aux = P;
    int *dato = malloc(2*sizeof(int));
    if(len > position){
        int i = 0;
        while(i<position){
            aux = aux->next;
            i++;
        }
        dato[0] = aux->posicion;
        dato[1] = aux->energia;
        return dato;
    }else{
        printf("No se puede acceder a esa posición\n");
        return NULL;
    }

}