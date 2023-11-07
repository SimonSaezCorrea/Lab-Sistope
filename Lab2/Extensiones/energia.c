#include "energia.h"

/*
Entrada: energia *energia: Se entrega una lista de energia

Salida: energia: retornará el struct energia con el elemento añadido

Descripción: Función que permite guardar una energía al inicio de la lista e 
             inicializarla la energia en 0
*/
energia *addEnergia(energia *P){

    if(P != NULL){
        energia *aux;
        aux = (energia *)malloc(sizeof(energia));
        aux->energia = 0;
        aux->next = P;

        return aux;
    }
    else{
        P = (energia *)malloc(sizeof(energia));
        P->energia = 0;
        P->next = NULL;
        return P;
    }
}

/*
Entrada: energia *energia: Se entrega una lista de energia

Salida: void

Descripción: Función que permite liberar la memoria usada
*/
void liberarEnergia(energia *P){
    energia *aux = P;
    energia *aux2;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}

/*
Entrada: energia *energia: Se entrega una lista de energia
Salida: void

Descripción: Mostrar los elementos de las celdas, principalmente de la energia
*/
void showEnergia(energia *P){
    energia *aux = P;
    printf("Particula: \n");
    int i = 0;
    while(aux->next != NULL){
        printf("%d %d\n", i, aux->energia);
        aux = aux->next;
        i++;
    }
    printf("----------\n");
}

/*
Entrada: energia *energia: Se entrega una lista de energia
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de energia

Salida: int: La energia de una posición en específica de la celda

Descripción: Permite buscar, dentro de la lista energia, la energia en una
             posición X
*/
double searchEnergia(energia *P, int position, int len){
    energia *aux = P;
    int *dato = malloc(2*sizeof(int));
    if(len > position){
        int i = 0;
        while(i<position){
            aux = aux->next;
            i++;
        }
        return aux->energia;
    }else{
        printf("No se puede acceder a esa posición\n");
        return 0;
    }

}

/*
Entrada: energia *energia: Se entrega una lista de energia
         int position: Es la posición que se desea buscar
         int len: Es el largo máximo de la lista de energia
         double valor: Energia que se sumará

Salida: void

Descripción: Función que permite sumarle a la celda con energía, una
             energía que se le pase
*/
void sumarEnergia(energia *P, int position, int len, double valor){
    energia *aux = P;
    int *dato = malloc(2*sizeof(int));
    if(len > position){
        int i = 0;
        while(i<position){
            aux = aux->next;
            i++;
        }
        aux->energia = aux->energia + valor;
    }else{
        printf("No se puede acceder a esa posición\n");
    }
}