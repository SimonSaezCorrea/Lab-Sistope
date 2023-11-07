#include "energia.h"

/*
Entrada: energia *energia: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las energia y que 
                                 además dirijirá a otro energia, es decir es 
                                 una lista de datos 
         int posicion: Se entrega la posicion de la Energia
         int energia: Se entrega la posicion de la energia

Salida: energia: retornará el struct energia con el elemento añadido

Descripción: Función que permite guardar una particula al final de la cola
*/
energia *addEnergia(energia *P){
    energia *aux = P;

    if(aux != NULL){
        while(aux->next!=NULL){
                aux = aux->next;
        }
        aux->next = (energia *)malloc(sizeof(energia));
        aux->next->energia = 0;
        aux->next->next = NULL;
    }
    else{
        aux = (energia *)malloc(sizeof(energia));
        aux->energia = 0;
        aux->next = NULL;
        P = aux;
    }

    return P;
}

/*
Entrada: energia *energia: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las energia y que 
                                 además dirijirá a otro energia, es decir es 
                                 una lista de datos  

Salida: Nada

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
Entrada: energia *energia: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las energia y que 
                                 además dirijirá a otro energia, es decir es 
                                 una lista de datos 
Salida: Nada

Descripción: Mostrar los elementos del energia
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