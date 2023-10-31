#include "fbroker.h"

#define LOCATE "Ejemplos/"

char **lecturaArchivoEntrada(char *nameFile, int *cantidad){
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

    
    char linea[100];
    char **lineaConcadenada=malloc(cantidadDeParticulas*sizeof(char *));
    int i;
    for(i=0;i<cantidadDeParticulas;i++){
        lineaConcadenada[i]=malloc(100*sizeof(char));
    }

    for(i=0;i<cantidadDeParticulas;i++){
        fgets(linea, 100, file);
        strcpy(lineaConcadenada[i], linea);
    }

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