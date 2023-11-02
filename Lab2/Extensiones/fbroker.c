#include "fbroker.h"

char **lecturaArchivoEntrada(char *nameFile, int *cantidad){
    //Se define la localidad del archivo
    char direccionReal[100] = "";
    strcat(direccionReal, LOCATE);
    strcat(direccionReal, nameFile);

    FILE * file = fopen(direccionReal, "r"); // Se abre el archivo

    //En caso de que exista algun problema
    if(file==NULL){
        printf("El archivo de entrada no existe\n");
        return NULL;
    }

    //Se saca la primera linea, la de la cantidad de particulas para usarse
    int cantidadDeParticulas;
    fscanf(file, "%d\n", &cantidadDeParticulas);

    *cantidad = cantidadDeParticulas; //Se guarda el dato 

    //Se lee las demás lineas y se guardan, para luego ser usadas
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