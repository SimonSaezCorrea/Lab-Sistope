#include "archivos.h"

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
    int **listaParticulas = malloc(sizeof(int*)*cantidadDeParticulas);
    int i = 0;
    while(i < cantidadDeParticulas){
        listaParticulas[i] = malloc(sizeof(int)*2);
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
    char direccionReal[100] = "";
    strcat(direccionReal, LOCATE);
    strcat(direccionReal, nameFile);

    
    FILE * file = fopen(direccionReal, "w");

    
    if(file==NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    //printf("%f\n",energias[0]);
    //printf("Se intenta imprimir: %d\t%lf\n",posMaximo,maximo);
    fprintf(file,"%d %lf\n",posMaximo,maximo);
    /*
    int i = 0;
    while (i < numEnergias){
        //printf("Se intenta imprimir:%d\t%f\n",i,energias[i]);
        fprintf(file,"%d %lf\n",i,energias[i]);
        i++;
    }
    */
    fclose(file);
}

