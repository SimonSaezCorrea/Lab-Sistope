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

int porcentajeR3(double energiaPos,double maximo){
    int porcentaje;
    double x;
    x = (energiaPos * 100)/maximo;
    porcentaje = (int)(x + 0.5);
    return porcentaje;
    
}

void representarEnegia(int pos,double energia, int porEnergia){
    int i = 0;
    printf("%d\t%f\t|",pos,energia);
    while (i < porEnergia){
        printf("o");
        i++;
    }
    printf("\n");
}

void mostrarGrafica(double *energias, int numEnergias, double maximo, int lineasProcesos[],int nProcesos ){
    printf("Lineas Procesadas por proceso:\n");
    for (int i = 0; i < nProcesos; i++){
        printf("Proceso Hijo %d : %d lineas\n", i, lineasProcesos[i]);
    }
    printf("\nGrafico de Energias:\n\n");
    for (int i = 0; i < numEnergias; i++){
        int per = porcentajeR3(energias[i],maximo);
        representarEnegia(i,energias[i],per);
    }
}