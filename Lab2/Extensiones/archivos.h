#ifndef ARCHIVOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Entrada: char *nameFile: El nombre del archivo con las particulas
         int *cantidad: la variable en la que se almacenará el dato 
                        de cantidad de particulas

Salida: int**: Una lista de Particulas

Descripción: Se retornará una lista de particulas en la cual contendrá, 
para cada particula, su impacto y energía. Además se almacenará el valor 
de la cantidad de particulass en la variable "*cantidad"
*/
int **lecturaArchivoEntrada(char *nameFile, int *cantidad);




/*
Entrada: char  *nameFile: El nombre del archivo en es que se va a escribir las energias
         double *energias: La lista que contiene las energias por ser escritas en el archivo
         int numEnergias: El numero de energias por ser escritas en el archivo
         double maximo: La maxima energia que va a ser escrita en primer lugar en el archivo
         int posMaximo: La poscion de la celda con la maxima energia que va a ser escrita en primer lugar en el archivo 

Salida: void: sin salida.

Descripción: Se escribe un archivo de salida cuya primera linea es la posición de la celda con la maxima energia acumulada 
seguida por la misma energia maxima acumulada, a continuacion las siguientes linas son un listado descendente de las posiciones
de celdas con su respectiva energia acumulada. 
*/
void escribirArchivoSalida(char* nameFile,double *energias, int numEnergias,double maximo, int posMaximo);

#endif