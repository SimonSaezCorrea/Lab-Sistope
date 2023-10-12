#ifndef ARCHIVOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCATE "Ejemplos/"

/*
Entrada: char  *nameFile: El nombre del archivo con las particulas
         int *cantidad: la variable en la que se almacenará el dato 
                        de cantidad de particulas

Salida: int**: Una lista de Particulas

Descripción: Se retornará una lista de particulas en la cual contendrá, 
para cada particula, su impacto y energía. Además se almacenará el valor 
de la cantidad de particulass en la variable "*cantidad"
*/
int **lecturaArchivoEntrada(char *nameFile, int *cantidad);


void escribirArchivoSalida(char* nameFile,double *energias, int numEnergias,double maximo, int posMaximo);

#endif