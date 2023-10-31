#include "fbroker.h"

#define LOCATE "Ejemplos/"

char *lecturaArchivoEntrada(char *nameFile, int *cantidad, int *lineasLeidas, int chunks){
    char direccionReal[100] = "";
    strcat(direccionReal, LOCATE);
    strcat(direccionReal, nameFile);
    FILE * file = fopen(direccionReal, "r");

    if(file==NULL){
        printf("El archivo de entrada no existe\n");
        return NULL;
    }

    int cantidadDeParticulas;
    fscanf(file, "%d\n", &cantidadDeParticulas);
    *cantidad = cantidadDeParticulas;

    int contadorChunks=0;
    int contadorLineas=*lineasLeidas;
    printf("lineas leidas = %d || %d\n", *lineasLeidas, contadorLineas);
    char linea[100];
    char *lineaConcadenada=malloc(100*sizeof(char));
    while(contadorLineas<*cantidad){
        if(contadorChunks>=chunks){
            break;
        }
        fgets(linea, 100, file);
        printf("%s\n", linea);
        strcat(lineaConcadenada, linea);

        contadorChunks++;
        contadorLineas++;
    }

    *lineasLeidas = contadorLineas;
    printf("lineas leidas = %d || %d\n", *lineasLeidas, contadorLineas);

    return lineaConcadenada;
}


void procesoChunks(int numWorkers, int workerPipes[][2], char** linea, int numLineas) {
    int workerID = rand() % numWorkers;
    // Distribuir líneas entre los workers
    for (int i = 0; i < numLineas; i++) {
        write(workerPipes[workerID][1], &i, sizeof(int));
        write(workerPipes[workerID][1], linea[i], strlen(linea[i]) + 1);
    }
}