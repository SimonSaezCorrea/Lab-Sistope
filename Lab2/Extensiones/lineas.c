#include "lineas.h"

lineas *addLineas(lineas *P, char *linea){
    lineas *aux = P;

    if(aux != NULL){
        while(aux->next!=NULL){
                aux = aux->next;
        }
        aux->next = (lineas *)malloc(sizeof(lineas));
        strcpy(aux->linea, linea);
        aux->next->next = NULL;
    }
    else{
        aux = (lineas *)malloc(sizeof(lineas));
        strcpy(aux->linea, linea);
        aux->next = NULL;
        P = aux;
    }

    return P;
}

void *liberarLineas(lineas *P){
    lineas *aux = P;
    lineas *aux2;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}

void showLineas(lineas *P){
    lineas *aux = P;
    printf("Descriptor de stdin: %d\n", fileno(stdin));
    printf("Descriptor de stdout: %d\n", fileno(stdout));
    printf("Descriptor de stderr: %d\n", fileno(stderr));
    while(aux->next != NULL){
        printf("Descriptor de archivo de lectura: %d\n", aux->linea);
        printf("----------\n");
        aux = aux->next;
    }
    printf("\n");
}

char *searchLineas(lineas *P, int position, int len){
    lineas *aux = P;
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