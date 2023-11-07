#ifndef FBROKER

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "lineas.h"
#include "energia.h"

#define LOCATE "Ejemplos/"

/*
Entrada: char *nameFile: El nombre del archivo con las particulas
         int *cantidad: la variable en la que se almacenará el dato 
                        de cantidad de particulas

Salida: int**: Una lista de Particulas

Descripción: Se retornará una lista de particulas en la cual contendrá, 
para cada particula, su impacto y energía. Además se almacenará el valor 
de la cantidad de particulass en la variable "*cantidad"
*/
lineas *lecturaArchivoEntrada(char *nameFile, int *cantidad);

/*
Entrada: char *nameFile: El nombre del archivo en es que se va a escribir las energias
         double *energias: La lista que contiene las energias por ser escritas en el archivo
         int numEnergias: El numero de energias por ser escritas en el archivo
         double maximo: La maxima energia que va a ser escrita en primer lugar en el archivo
         int posMaximo: La poscion de la celda con la maxima energia que va a ser escrita en primer lugar en el archivo 

Salida: void: sin salida.

Descripción: Se escribe un archivo de salida cuya primera linea es la posición de la celda con la maxima energia acumulada 
seguida por la misma energia maxima acumulada, a continuacion las siguientes linas son un listado descendente de las posiciones
de celdas con su respectiva energia acumulada. 
*/
void escribirArchivoSalida(char* nameFile, energia *energias, int numEnergias, double maximo, int posMaximo);

/*
Entrada: double energiaPos: La energia que requiere calcular su porcentaje.
         double maximo: La energia maxima que en este caso vendria a ser el 100%.
         

Salida: int: retorna el porcentaje aproximado de la energia.

Descripción: Permite calcular el porcentaje de la energia, conociendo la energia maxima y asi usar regla de 3.
*/
int porcentajeR3(double energiaPos, double maximo);

/*
Entrada: int pos: La posicion que se desea mostrar por terminal como parte de una representacion grafica de las energia.
         double energia: La energia que se desea mostrar por terminal como parte de una representacion visual de las energia.
         int porEnergia: Porcentaje de energia que se utiliza para graficar la energia y representarla.

Salida: void: sin salida.

Descripción: Permite representar graficamente una posicion de celda con su respectiva energia y una ayuda visiual, luego imprime por terminal
dicha representación. 
*/
void representarEnegia(int pos, double energia, int porEnergia);

/*
Entrada: double *energias: Lista de energias que van a ser representadas graficamente y mostradas por terminal.
         int numEnergias: Numero de energias que deben ser representadas graficamente y mostradas por terminal.
         double maximo: Energia maxima que es usada como referencia para calcualar el porcentaje a las energias mediante regla de 3.
         int lineasProcesos[]: Lista de enteros que son los contadores para cada proceso hijo que llevaban la cuenta de cuantas lineas proceso cada uno.
         int nProcesos: Numero de procesos que fueron procesando las lineas enviadas por el broker.
   
Salida: void: sin salida.

Descripción: Representar graficamente las energias de una lista y las va mostrando por terminal una por una.
*/
void mostrarGrafica(energia *energias, int numEnergias, double maximo, int lineasProcesos[], int nProcesos);


#endif