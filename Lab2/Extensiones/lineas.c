#include "lineas.h"

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
lineas *addLinea(lineas *P, char *linea){
    lineas *aux = P;

    if(aux != NULL){
        while(aux->next!=NULL){
                aux = aux->next;
        }
        aux->next = (lineas *)malloc(sizeof(lineas));
        aux->next->linea = (char *)malloc(100*sizeof(char));
        strcpy(aux->next->linea, linea);
        aux->next->next = NULL;
    }
    else{
        aux = (lineas *)malloc(sizeof(lineas));
        aux->linea = (char *)malloc(100*sizeof(char));
        strcpy(aux->linea, linea);
        aux->next = NULL;
        P = aux;
    }

    return P;
}

/*
Entrada: lineas *lineas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las lineas y que 
                                 además dirijirá a otro lineas, es decir es 
                                 una lista de datos  

Salida: Nada

Descripción: Función que permite liberar la memoria usada
*/
void liberarLineas(lineas *P){
    lineas *aux = P;
    lineas *aux2;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux->linea);
        free(aux);
        aux = aux2;
    }
}

/*
Entrada: lineas *lineas: Se entrega una estructura de dato en la cual 
                                 contendrá un arreglo que las lineas y que 
                                 además dirijirá a otro lineas, es decir es 
                                 una lista de datos 
Salida: Nada

Descripción: Mostrar los elementos del lineas
*/
void showLineas(lineas *P){
    lineas *aux = P;
    printf("Particula: \n");
    while(aux != NULL){
        printf("%s\n", aux->linea);
        aux = aux->next;
    }
    printf("----------\n");
}

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
char *searchLineas(lineas *P, int position, int len){
    lineas *aux = P;
    int *dato = malloc(2*sizeof(int));
    if(len > position){
        int i = 0;
        while(i<position){
            aux = aux->next;
            i++;
        }
        return aux->linea;
    }else{
        printf("No se puede acceder a esa posición\n");
        return NULL;
    }

}