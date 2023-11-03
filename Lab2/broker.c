#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Extensiones/fbroker.h"


int main(int argc, char *argv[]){
    srand(getpid());
    // Guardo los datos que me trae lab2 mediante argumento
    int numCelda = atoi(argv[1]);
    int numWorker = atoi(argv[2]);
    char ArchivoEntrada[100];
    strcpy(ArchivoEntrada, argv[3]);
    char ArchivoSalida[100];
    strcpy(ArchivoSalida, argv[4]);
    int chunk = atoi(argv[5]);
    int flag = atoi(argv[6]);

    
    //printf("\narchivoF:%s  CeldaF:%d    WorkerF:%d   ArchivoEntradaF:%s   ArchivoSalidaF:%s    ChunkF:%d    flagF:%d\n", argv[0], numCelda, numWorker, ArchivoEntrada, ArchivoSalida, chunk, flag);

    //El arreglo para los pipe del padre y de los hijos
    int fd1[numWorker][2]; //Donde el hijo leera lo del padre y el padre escribirá
    int fd2[numWorker][2]; //Donde el padre leera lo del hijo y el hijo escribirá
    int pid;
    int i;
    //Ciclo para generar los hijos y ademas los pipes.
    for ( i = 0; i < numWorker; i++) {
        pipe(fd1[i]); //Generar el pipe fd1
        pipe(fd2[i]); //Generar el pipe fd2
        pid = fork(); //Se crea el hijo
        //En caso de ser el hijo
        if (pid == 0) {
            close(fd1[i][1]); //Cerrar el de escritura
            close(fd2[i][0]); //Cerrar el de lectura
            
            dup2(fd1[i][0], STDIN_FILENO); //permite hacer la copia de STDIN_FILENO
            dup2(fd2[i][1], STDOUT_FILENO); //permite hacer la copia de SDOUT_FILENO

            // Se ejecuta el exexv para dirijir al hijo al programa de worker con un argumento de las celdas
            char *argumentos[] = {"./worker", argv[1],NULL};
            execv(argumentos[0], argumentos);

            // En caso de error en execv
            perror("execv");
            exit(1);
        }
    }

    // ---- A partir de aquí corresponde al padre ----

    int cantidadLineas; // Para guardar el dato de la cantidad de lineas
    char **lineas = lecturaArchivoEntrada(ArchivoEntrada, &cantidadLineas); //entro al archivo y traigo las lineas
    
    /*
    for(i=0;i<cantidadLineas;i++){
        printf("linea %d = %s\n", i, lineas[i]);
    }
    */
    int lineasHijos[numWorker];

    for (i = 0; i < numWorker; i++){
        lineasHijos[i] = 0;
    }

    int contadorChunk=0; //paras saber cuantos chunks lleva
    int selectHijo=0; //Para saber a cual hijo elije

    // Recorro todas las lineas
    for ( i = 0; i < cantidadLineas; i++) {
        // En caso de que el contador sea igual al numero del chunk, reiniciar el contador a 0
        if(contadorChunk==chunk){
            contadorChunk=0;
        }
        //Caso contrario, buscar aleatoriamente a un hijo
        if(contadorChunk==0){
            int aleatorio = rand();
            selectHijo = aleatorio % numWorker;
            printf("Selected = %d\n", selectHijo);
        }
        close(fd1[selectHijo][0]); //Cierro el de lectura para fd1
        close(fd2[selectHijo][1]); //Cierro el de escritura pra fd2
        
        write(fd1[selectHijo][1], lineas[i], 100); //Le envio la linea al hijo
        
        /*
        char mensaje[100];
        read(fd2[selectHijo][0], mensaje, 100);
        printf("Llegó el mensaje: %s\n", mensaje);
        */

        contadorChunk++;
        lineasHijos[selectHijo]++;
    }

    //Luego de enviar las lineas a los hijos, enviarle a todos un mensaje de FIN y recibir lo que calcularon
    double *sum = calloc(numCelda, sizeof(double)); //Arreglo para guardar la suma de todos los datos de los hijos
    int y = 0;
    double maximo = 0;
    int celdaMax;
    for(i=0;i<numWorker;i++){
        //Envio el mensaje FIN
        char mensajeEnvio[100] = "FIN";
        write(fd1[i][1], mensajeEnvio, 100);

        //Se recibe el calculo de los hijos
        char mensajeLlegada[10000];
        read(fd2[i][0], mensajeLlegada, 10000);
        //printf("Llegó el mensaje: %s\n", mensajeLlegada);

        //Empiezo a leer el string traido separandolo y agregandolo al arreglo sum
        char delimitador[] = ";";
        char *token = strtok(mensajeLlegada, delimitador);
        
        while(token != NULL){
            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
            sum[y] = sum[y] + atof(token);
            if (sum[y] > maximo){
                maximo = sum[y];
                celdaMax = y;
            }
            token = strtok(NULL, delimitador);
            y++;
        }
        y=0;
    }
    printf("Celda:%d -- Maximo:%f\n",celdaMax,maximo);

    //Muestro el arreglo
    /*
    for(i=0;i<numCelda;i++){
        printf("%f\n", sum[i]);
    }
    */

    //Se escribe el archivo de salida

    escribirArchivoSalida(ArchivoSalida,sum,numCelda,maximo,celdaMax);
    //Se muestra el Grafico en caso de que se use el flag D
    if (flag==1){
        mostrarGrafica(sum,numCelda,maximo, lineasHijos,numWorker);
    }

    return 0;
}


    
