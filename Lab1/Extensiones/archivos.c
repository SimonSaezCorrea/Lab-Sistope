#include "archivos.h"

#define LOCATE "Ejemplos/"

int **lecturaArchivoEntrada(char *nameFile, int *cantidad){
    //Establecer lugar en el que se encuentro los archivos
    char direccionReal[100] = "";
    strcat(direccionReal, LOCATE);
    strcat(direccionReal, nameFile);

    //Abrir el archivo
    FILE * file = fopen(direccionReal, "r");

    //Comprobrar existencia
    if(file==NULL){
        printf("El archivo de entrada no existe\n");
        return NULL;
    }

    //Guardar cantidad de particulas
    int cantidadDeParticulas;
    fscanf(file, "%d\n", &cantidadDeParticulas);

    //Generar el arreglo dinámico el cual permita almacenar eñ impacto y la energía
    int **listaParticulas = calloc(cantidadDeParticulas, sizeof(int*));
    int i = 0;
    while(i < cantidadDeParticulas){
        listaParticulas[i] = calloc(2, sizeof(int));
        i++;
    }

    i=0;
    while(i<cantidadDeParticulas){
        fscanf(file,"%d %d\n",&listaParticulas[i][0], &listaParticulas[i][1]);
        i++;
    }

    /*
    //Solo para ver si saca bien los datos del archivo
    printf("El archivo contiene:\n");
    i=0;
    while(i<cantidadDeParticulas){
        printf("%d  %d\n",listaParticulas[i][0], listaParticulas[i][1]);
        i++;
    }
    printf("\n\n");
    */

    //Cerrar archivo
    fclose(file);

    //Guardo la cantidad de particulas en una variable
    *cantidad = cantidadDeParticulas;

    // Retorno la lista de particulas
    return listaParticulas;
}

void escribirArchivoSalida(char *nameFile,double *energias, int numEnergias,double maximo, int posMaximo){
     //Establecer lugar en el que se crea/modifica el archivo
    char direccionReal[100] = "";
    strcat(direccionReal, LOCATE);
    strcat(direccionReal, nameFile);

    //Abrir el archivo
    FILE * file = fopen(direccionReal, "w");

    //Se comprueba si se abrio correctamente el archivo
    if(file==NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    //Se imprime en el archivo la posición de celda con la maxima energia seguida por dicha energia
    fprintf(file,"%d\t%lf\n",posMaximo,maximo);


    //Se usa un ciclo while para imprimir en el archivo las posiciones de celdas en orden con sus respectivas energias
    int i = 0;
    while (i < numEnergias){
        fprintf(file,"%d\t%lf\n",i,energias[i]);
        i++;
    }
    
    //Se cierra el archivo
    fclose(file);
}

