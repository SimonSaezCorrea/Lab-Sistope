#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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

  

   /*
   Sin lista enlazada
    int pipefd[numWorker][2];
    for (int i = 0; i < numWorker; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("Error al crear la tubería");
            exit(1);
        }
    }
    */

    for ( i = 0; i < numWorker; i++) {
        int pid = fork();
        if (pid == 0) {
            // Proceso hijo
            
            int * descriptor = search(P,i,numWorker);
            
            //close(pipefd[i][0]);  // Cerramos el extremo de lectura
            close(descriptor[0]);
            
           
            //dup2(pipefd[i][1], STDOUT_FILENO);
            //close(pipefd[i][1]);  
            dup2(descriptor[1], STDOUT_FILENO); // Redirigimos la salida estándar al extremo de escritura de la tubería
            close(descriptor[1]); // Cerramos el descriptor de archivo duplicado
            // Generamos un número aleatorio
            int numero = i + 1 ;

            // Convertimos el número a una cadena (string)
            char numero_str[10];
            snprintf(numero_str, sizeof(numero_str), "%d", numero);

            // Ejecutamos el mismo código con execv
            char *argumentos[] = {"./worker", numero_str, NULL};
            execv(argumentos[0], argumentos);

            // En caso de error en execv
            perror("execv");
            exit(1);
        }
    }

    // Proceso padre
    for ( i = 0; i < numWorker; i++) {
        int * descriptor = search(P,i,numWorker);
        //close(pipefd[i][1]);  // Cerramos el extremo de escritura
        close(descriptor[1]);

        char buffer[20];
        //read(pipefd[i][0], buffer, sizeof(buffer));
        read(descriptor[0], buffer, sizeof(buffer));
        int numero_recibido = atoi(buffer);
        printf("Proceso hijo %d envió el número: %d\n", i + 1, numero_recibido);

        //close(pipefd[i][0]);  // Cerramos el extremo de lectura
        close(descriptor[0]);
    }

    

    // Esperamos a que todos los hijos terminen
    for (int i = 0; i < numWorker; i++) {
        wait(NULL);
    }

    return 0;
}


    
