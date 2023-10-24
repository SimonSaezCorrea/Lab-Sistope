#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Extensiones/listas.h"


int main(int argc, char *argv[]){

    printf("archivo:%s  Celda:%s    Worker:%s   ArchivoEntrada:%s   ArchivoSalida:%s    flag=%s\n", argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
    
    int numCelda = atoi(argv[1]);
    int numWorker = atoi(argv[2]);
    char ArchivoEntrada[100];
    strcpy(ArchivoEntrada, argv[3]);
    char ArchivoSalida[100];
    strcpy(ArchivoSalida, argv[4]);
    int flag = atoi(argv[5]);

    printf("archivo:%s  Celda:%d    Worker:%d   ArchivoEntrada:%s   ArchivoSalida:%s    flag=%d\n", argv[0], numCelda, numWorker, ArchivoEntrada, ArchivoSalida, flag);

    int i = 0;
    pipeline *P = malloc(sizeof(pipeline));
    while(i<numWorker){
        add(P);
        i++;
    }

    show(P);

    int pid=-1;

    i = 0;
    while(pid!=0 && i < numWorker){
        printf("mi pid=%d y soy el padre      i=%d\n", getpid(), i);
        pid=fork();
        i++;
    }
    if(pid==0){
        printf("Soy un Hijo\n");
    }else{
        liberar(P);
    }
    return 0;
}