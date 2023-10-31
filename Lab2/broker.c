#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){


    int numCelda = atoi(argv[1]);
    int numWorker = atoi(argv[2]);
    char ArchivoEntrada[100];
    strcpy(ArchivoEntrada, argv[3]);
    char ArchivoSalida[100];
    strcpy(ArchivoSalida, argv[4]);
    int chunk = atoi(argv[5]);
    int flag = atoi(argv[6]);

    printf("\narchivoF:%s  CeldaF:%d    WorkerF:%d   ArchivoEntradaF:%s   ArchivoSalidaF:%s    ChunkF:%d    flagF:%d\n", argv[0], numCelda, numWorker, ArchivoEntrada, ArchivoSalida, chunk, flag);

    int pid=-1;

    int fd1[numWorker][2];
    int fd2[numWorker][2];
    int i;
    for ( i = 0; i < numWorker; i++) {
        pipe(fd1[i]);
        pipe(fd2[i]);
        int pid = fork();
        if (pid == 0) {
            // Proceso hijo
            close(fd1[i][1]);
            close(fd2[i][0]);
            
            dup2(fd1[i][0], STDIN_FILENO);
            dup2(fd2[i][1], STDOUT_FILENO);

            // Ejecutamos el mismo código con execv
            char *argumentos[] = {"./worker", NULL};
            execv(argumentos[0], argumentos);

            // En caso de error en execv
            perror("execv");
            exit(1);
        }
        else{
            close(fd1[i][0]);
            close(fd2[i][1]);

            char numero1[100] = "FIN";
            write(fd1[i][1], numero1, 100);
            

            char mensaje[100];
            read(fd2[i][0], mensaje, 100);
            printf("Llegó el mensaje: %s\n", mensaje);
        }
    }

    return 0;
}


    
