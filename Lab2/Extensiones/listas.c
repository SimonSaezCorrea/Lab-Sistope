#include "listas.h"

pipeline *add(pipeline *P){
    pipeline *aux = P;

    if(aux != NULL){
        while(aux->next!=NULL){
                aux = aux->next;
        }
        aux->next = (pipeline *)malloc(sizeof(pipeline));
        if(pipe(aux->fd)==-1){
            exit;
        }
        aux->next->next = NULL;
    }
    else{
        aux = (pipeline *)malloc(sizeof(pipeline));
        if(pipe(aux->fd)==-1){
            exit;
        }
        aux->next = NULL;
        P = aux;
    }

    return P;
}

void *liberar(pipeline *P){
    pipeline *aux = P;
    pipeline *aux2;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}

void show(pipeline *P){
    pipeline *aux = P;
    printf("Descriptor de stdin: %d\n", fileno(stdin));
    printf("Descriptor de stdout: %d\n", fileno(stdout));
    printf("Descriptor de stderr: %d\n", fileno(stderr));
    while(aux->next != NULL){
        printf("Descriptor de archivo de lectura: %d\n", aux->fd[0]);
        printf("Descriptor de archivo de escritura: %d\n", aux->fd[1]);
        printf("----------\n");
        aux = aux->next;
    }
    printf("\n");
}

int *search(pipeline *P, int position, int len){
    pipeline *aux = P;
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