#include "fbroker.h"

/*
Entrada: char *nameFile: El nombre del archivo con las particulas
         int *cantidad: la variable en la que se almacenará el dato 
                        de cantidad de particulas

Salida: int**: Una lista de lineas

Descripción: Se retornará una lista de lineas en la cual contendrá, 
             las lineas del archivo. Además se almacenará el valor 
             de la cantidad de particulass en la variable "*cantidad"
*/
lineas *lecturaArchivoEntrada(char *nameFile, int *cantidad){
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
    lineas *paqueteDeLineas=NULL;
    int i;

    for(i=0;i<cantidadDeParticulas;i++){
        fgets(linea, 100, file);
        paqueteDeLineas = addLinea(paqueteDeLineas, linea);
    }

    return paqueteDeLineas;
}

/*
Entrada: char *nameFile: El nombre del archivo en es que se va a escribir las energias
         energia *energias: La lista que contiene las energias por ser escritas en el archivo
         int numEnergias: El numero de energias por ser escritas en el archivo
         double maximo: La maxima energia que va a ser escrita en primer lugar en el archivo
         int posMaximo: La poscion de la celda con la maxima energia que va a ser escrita en primer lugar en el archivo 

Salida: void

Descripción: Se escribe un archivo de salida cuya primera linea es la posición de la celda con la maxima energia acumulada 
seguida por la misma energia maxima acumulada, a continuacion las siguientes linas son un listado descendente de las posiciones
de celdas con su respectiva energia acumulada. 
*/
void escribirArchivoSalida(char *nameFile, energia *energias, int numEnergias, double maximo, int posMaximo){
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
        fprintf(file,"%d\t%lf\n",i,searchEnergia(energias, i, numEnergias));
        i++;
    }
    
    //Se cierra el archivo
    fclose(file);
}

/*
Entrada: double energiaPos: La energia que requiere calcular su porcentaje.
         double maximo: La energia maxima que en este caso vendria a ser el 100%.
         

Salida: int: retorna el porcentaje aproximado de la energia.

Descripción: Permite calcular el porcentaje de la energia, conociendo la energia maxima y asi usar regla de 3.
*/
int porcentajeR3(double energiaPos, double maximo){
    int porcentaje;
    double x;
    x = (energiaPos * 100)/maximo;
    porcentaje = (int)(x + 0.5);
    return porcentaje;
    
}

/*
Entrada: int pos: La posicion que se desea mostrar por terminal como parte de una representacion grafica de las energia.
         double energia: La energia que se desea mostrar por terminal como parte de una representacion visual de las energia.
         int porEnergia: Porcentaje de energia que se utiliza para graficar la energia y representarla.

Salida: void: sin salida.

Descripción: Permite representar graficamente una posicion de celda con su respectiva energia y una ayuda visiual, luego imprime por terminal
dicha representación. 
*/
void representarEnegia(int pos, double energia, int porEnergia){
    int i = 0;
    printf("%d\t%f\t|",pos,energia);
    while (i < porEnergia){
        printf("o");
        i++;
    }
    printf("\n");
}

/*
Entrada: energia *energias: Lista de energias que van a ser representadas graficamente y mostradas por terminal.
         int numEnergias: Numero de energias que deben ser representadas graficamente y mostradas por terminal.
         double maximo: Energia maxima que es usada como referencia para calcualar el porcentaje a las energias mediante regla de 3.
         int lineasProcesos[]: Lista de enteros que son los contadores para cada proceso hijo que llevaban la cuenta de cuantas lineas proceso cada uno.
         int nProcesos: Numero de procesos que fueron procesando las lineas enviadas por el broker.
   
Salida: void.

Descripción: Representar graficamente las energias de una lista y las va mostrando por terminal una por una.
*/
void mostrarGrafica(energia *energias, int numEnergias, double maximo, int lineasProcesos[], int nProcesos ){
    printf("\n--------------------------------------------------------------\n");
    printf("Lineas Procesadas por proceso:\n\n");
    for (int i = 0; i < nProcesos; i++){
        printf("Proceso Hijo %d : %d lineas\n", i, lineasProcesos[i]);
    }
    printf("\n--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("\nGrafico de Energias:\n\n");
    for (int i = 0; i < numEnergias; i++){
        int per = porcentajeR3(searchEnergia(energias, i, numEnergias),maximo);
        representarEnegia(i,searchEnergia(energias, i, numEnergias),per);
    }
    printf("\n--------------------------------------------------------------\n");
}