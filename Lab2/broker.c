#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Extensiones/fbroker.h"
#include "Extensiones/descriptores.h"
#include "Extensiones/lineas.h"
#include "Extensiones/energia.h"


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
    //Donde el hijo leera lo del padre y el padre escribirá
    //int fd1[numWorker][2];
    descriptores *fd1 = NULL; 
    //Donde el padre leera lo del hijo y el hijo escribirá
    //int fd2[numWorker][2]; 
    descriptores *fd2 = NULL;
    int pid;
    int i;
    printf("...Generando Hijos\n\n");
    //Ciclo para generar los hijos y ademas los pipes.
    for ( i = 0; i < numWorker; i++) {
        fd1 = addDescriptor(fd1); //Generar el pipe fd1
        fd2 = addDescriptor(fd2);; //Generar el pipe fd2
        pid = fork(); //Se crea el hijo
        //En caso de ser el hijo
        if (pid == 0) {
            close(searchDescriptor(fd1, i, i+1)[1]); //Cerrar el de escritura
            close(searchDescriptor(fd2, i, i+1)[0]); //Cerrar el de lectura
            
            dup2(searchDescriptor(fd1, i, i+1)[0], STDIN_FILENO); //permite hacer la copia de STDIN_FILENO
            dup2(searchDescriptor(fd2, i, i+1)[1], STDOUT_FILENO); //permite hacer la copia de SDOUT_FILENO

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
    printf("...Leyendo archivo\n\n");
    lineas *paqueteDeLineas = lecturaArchivoEntrada(ArchivoEntrada, &cantidadLineas); //entro al archivo y traigo las lineas
    //showLineas(paqueteDeLineas);
    int contadorChunk=0; //paras saber cuantos chunks lleva
    int selectHijo=0; //Para saber a cual hijo elije

    // Recorro todas las lineas
    printf("...Enviando mensajes de lineas\n\n");
    for ( i = 0; i < cantidadLineas; i++) {
        // En caso de que el contador sea igual al numero del chunk, reiniciar el contador a 0
        if(contadorChunk==chunk){
            contadorChunk=0;
        }
        //Caso contrario, buscar aleatoriamente a un hijo
        if(contadorChunk==0){
            int aleatorio = rand();
            selectHijo = aleatorio % numWorker;
        }
        close(searchDescriptor(fd1, selectHijo, numWorker)[0]); //Cierro el de lectura para fd1
        close(searchDescriptor(fd2, selectHijo, numWorker)[1]); //Cierro el de escritura pra fd2
        
        write(searchDescriptor(fd1, selectHijo, numWorker)[1], searchLineas(paqueteDeLineas, i, cantidadLineas), 100); //Le envio la linea al hijo
        
        /*
        char mensaje[100];
        read(fd2[selectHijo][0], mensaje, 100);
        printf("Llegó el mensaje: %s\n", mensaje);
        */

        contadorChunk++;
    }
    printf("...Generando lista de celdas para sumar\n\n");
    //Luego de enviar las lineas a los hijos, enviarle a todos un mensaje de FIN y recibir lo que calcularon
    energia *sum = NULL; //Arreglo para guardar la suma de todos los datos de los hijos
    for(i=0; i<numCelda;i++){
        sum = addEnergia(sum);
    }
    int y;
    double maximo = 0;
    int celdaMax;
    int lineasHijos[numWorker];
    char mensajeLlegada[100];
    printf("...Enviando mensaje de FIN y leyendo pipe\n\n");
    energia *aux;
    for(i=0;i<numWorker;i++){
        aux = sum;
        //Envio el mensaje FIN
        char mensajeEnvio[100] = "FIN";
        write(searchDescriptor(fd1, i, numWorker)[1], mensajeEnvio, 100);
        //Empieza a recibir muchos mensajes del broker
        printf("...Leyendo los datos del hijo %d\n\n", i);
        for(y=0;y<numCelda;y++){
            //printf("empieza el bucle -> i = %d      y=%d    numCelda=%d\n",i ,y, numCelda);
            //Se recibe el calculo de los hijos
            read(searchDescriptor(fd2, i, numWorker)[0], mensajeLlegada, 100);
            //printf("Llegó el mensaje: %s\n\n", mensajeLlegada);
            //printf("%s\n", mensajeLlegada);
            //Sumar
            //sumarEnergia(sum, y, numCelda,atof(mensajeLlegada));
            aux->energia += atof(mensajeLlegada);
            double energiaDelhijo = aux->energia;
            if (energiaDelhijo > maximo){
                maximo = energiaDelhijo;
                celdaMax = y;
            }
            aux = aux->next;
            write(searchDescriptor(fd1, i, numWorker)[1], mensajeEnvio, 100);
        }

        read(searchDescriptor(fd2, i, numWorker)[0], mensajeLlegada, 100);
        lineasHijos[i]=atoi(mensajeLlegada);
        
    }
    //printf("Celda:%d -- Maximo:%f\n",celdaMax,maximo);

    //Muestro el arreglo

    //Se escribe el archivo de salida
    printf("...Escribiendo en el archivo\n\n");
    escribirArchivoSalida(ArchivoSalida,sum,numCelda,maximo,celdaMax);
    //Se muestra el Grafico en caso de que se use el flag D
    if (flag==1){
        mostrarGrafica(sum,numCelda,maximo, lineasHijos,numWorker);
    }

    liberarDescriptor(fd1);
    liberarDescriptor(fd2);
    liberarLineas(paqueteDeLineas);
    liberarEnergia(sum);

    return 0;
}


    
