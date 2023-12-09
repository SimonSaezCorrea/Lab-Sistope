#include "funciones.h"

#define MIN_ENERGY 0.001
#define LOCATE "Ejemplos/"


/*
Entrada: char *nameFile: El nombre del archivo en es que se va a escribir las energias
         double *energias: La lista que contiene las energias por ser escritas en el archivo
         int numEnergias: El numero de energias por ser escritas en el archivo
         double maximo: La maxima energia que va a ser escrita en primer lugar en el archivo
         int posMaximo: La poscion de la celda con la maxima energia que va a ser escrita en primer lugar en el archivo 

Salida: void: sin salida

Descripción: Se escribe un archivo de salida cuya primera linea es la posición de la celda con la maxima energia acumulada 
seguida por la misma energia maxima acumulada, a continuacion las siguientes linas son un listado descendente de las posiciones
de celdas con su respectiva energia acumulada. 
*/
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

/*
Entrada: int Ei: La energía acumulada.
         int Ej: Energía potencial que trae.
         int j: Posición de impacto.
         int i: La posición del arreglo.
         int N: Numero de celdas.
         double *maximo: variable en la que se almacenara la maxima energia.
         int *pos: variable en la que se almacenara la posición de la celda con la maxima energia.

Salida: int: Valor resultante de la Energía acumulada, osea el Ei.

Descripción: Calculara la energía acumulada para la casilla, esta
             energía se calcula mediante una formula para el
             cálculo de Eij, como un extra tambien lleva cuenta de cual es la maxima energia y su posicion.
*/
double calculoEnergiaAcumulada(double Ei, int Ej, int j, int i, int N){
    //Eij es la energía depositada y se calcula mediante la ecuación
    double Eij = 1000 * Ej;
    double total;
    Eij = Eij/(N*sqrt(fabs(j-i)+1));
    if(Eij < MIN_ENERGY){
        Eij=0;
    }
    total = Ei + Eij;
    return total;
}

/*
Entrada: float *arregloJoule: El arreglo que contiene la energía.
         int numeroDeCeldas: La cantidad de celdas.
         int posicionImpacto: La posición de impacto.
         int energiaImpacto: La energía de impacto.
         double *maximo: variable en la que se almacenara la maxima energia.
         int *pos: variable en la que se almacenara la posición de la celda con la maxima energia.

Salida: void: nada.

Descripción: Calcula la energía hacia la derecha del arregloJoule.
*/
void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto){
    int i = posicionImpacto + 1;
    while (i < numeroDeCeldas){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas);
        i++;
    }
    
}

/*
Entrada: float *arregloJoule: El arreglo que contiene la energía.
         int numeroDeCeldas: La cantidad de celdas.
         int posicionImpacto: La posición de impacto.
         int energiaImpacto: La energía de impacto.
         double *maximo: variable en la que se almacenara la maxima energia.
         int *pos: variable en la que se almacenara la posición de la celda con la maxima energia.

Salida: void: nada.

Descripción: Calcula la energía hacia la izquierda del arregloJoule.
*/
void calculoIzquierdo(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto){
    int i = posicionImpacto - 1;
    if(i >= numeroDeCeldas){
        i = numeroDeCeldas - 1;
    }
    while (i >= 0){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas) ;
        i--;
    }
}

/*
Entrada: int numeroDeCeldas: La cantidad de celdas.
         int **listaParticulas: Lista que contiene la posición y la energía de impacto.
         int cantidadDeChunks: Es la cantidad de chunks en la lista.
         double *maximo: variable en la que se almacenara la maxima energia.
         int *pos: variable en la que se almacenara la posición de la celda con la maxima energia.

Salida: float: retorna una lista que contiene la energía depositada por los
        impactos.

Descripción: Permite calcular la enería de impacto en cada posición y como
             se distribuye en el material.
*/
double *calculoEnergiaJoule(int numeroDeCeldas, int **listaParticulas, int cantidadDeChunks){
    double *arregloJoule = calloc(numeroDeCeldas, sizeof(double));
    int i = 0;
    while(i < cantidadDeChunks && listaParticulas!=NULL){
        int posicion = listaParticulas[i][0];
        int energia = listaParticulas[i][1];
        if(posicion < numeroDeCeldas){
            arregloJoule[posicion] = calculoEnergiaAcumulada(arregloJoule[posicion], energia, posicion, posicion, numeroDeCeldas);

            calculoDerecho(arregloJoule, numeroDeCeldas, posicion, energia);
        }
        calculoIzquierdo(arregloJoule, numeroDeCeldas, posicion, energia);
        i++;
    }
    return arregloJoule;
}

/*
Entrada: double energiaPos: La energia que requiere calcular su porcentaje.
         double maximo: La energia maxima que en este caso vendria a ser el 100%.
         

Salida: int: retorna el porcentaje aproximado de la energia.

Descripción: Permite calcular el porcentaje de la energia, conociendo la energia maxima y asi usar regla de 3.
*/
int porcentajeR3(double energiaPos,double maximo){
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
void representarEnegia(int pos,double energia, int porEnergia){
    int i = 0;
    printf("%d\t%f\t|",pos,energia);
    while (i < porEnergia){
        printf("o");
        i++;
    }
    printf("\n");
}

/*
Entrada: double *energias: Lista de energias que van a ser representadas graficamente y mostradas por terminal.
         int numEnergias: Numero de energias que deben ser representadas graficamente y mostradas por terminal.
         double maximo: Energia maxima que es usada como referencia para calcualar el porcentaje a las energias mediante regla de 3.
         

Salida: void: sin salida.

Descripción: Representar graficamente las energias de una lista y las va mostrando por terminal una por una.
*/
void mostrarGrafica(double *energias, int numEnergias, double maximo){
    for (int i = 0; i < numEnergias; i++){
        int per = porcentajeR3(energias[i],maximo);
        representarEnegia(i,energias[i],per);
    }
}
