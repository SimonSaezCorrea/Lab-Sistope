#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Extensiones/listas.h"


int main(int argc, char *argv[]){

    //printf("\narchivoI:%s  CeldaI:%s    WorkerI:%s   ArchivoEntradaI:%s   ArchivoSalidaI:%s    ChunkI:%s   flagI=%s\n", argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
    
   // int numCelda = atoi(argv[1]);
    int numWorker = atoi(argv[2]);
    char ArchivoEntrada[100];
    strcpy(ArchivoEntrada, argv[3]);
    char ArchivoSalida[100];
    strcpy(ArchivoSalida, argv[4]);
    int chunk = atoi(argv[5]);
    //int flag = atoi(argv[6]);

    //printf("\narchivoF:%s  CeldaF:%d    WorkerF:%d   ArchivoEntradaF:%s   ArchivoSalidaF:%s    ChunkF:%d    flagF:%d\n", argv[0], numCelda, numWorker, ArchivoEntrada, ArchivoSalida, chunk, flag);

    int i = 0;
    pipeline *P = malloc(sizeof(pipeline));
    while(i<numWorker){
        add(P);
        i++;
    }

    show(P);

    int pid=-1;
    int con = 0;
    i = 0;
    while(pid!=0 && i < numWorker){
        printf("mi pid=%d y soy el padre      i=%d\n", getpid(), i);
        pid=fork();
        i++;
    }


    if(pid==0){
        if(con == 0){
            close(P->fd[0]);

            dup2(P->fd[1], STDOUT_FILENO); //STDOUT_FILENO se vuelve la copia de fd[1] y fd[1] anterior se cierra.
            char num1[20];
            char num2[20];
            sprintf(num1,"%d",numWorker);
            sprintf(num2,"%d",chunk);
            char* argumentos[] = {"./worker", num1,  num2 , NULL};
            execv(argumentos[0], argumentos);
            con++;
        }
        printf("Soy un Hijo\n");
    }else{
        close(P->fd[1]);
        char mensaje[100];
        read(P->fd[0], mensaje, 100);
        printf("Recibi un mensaje desde worker y es: %s\n", mensaje);
        
        liberar(P);
    }
    return 0;
}