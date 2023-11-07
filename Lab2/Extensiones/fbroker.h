#ifndef FBROKER

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "lineas.h"
#include "energia.h"

#define LOCATE "Ejemplos/"


lineas *lecturaArchivoEntrada(char *nameFile, int *cantidad);

void escribirArchivoSalida(char* nameFile, energia *energias, int numEnergias, double maximo, int posMaximo);

int porcentajeR3(double energiaPos, double maximo);

void representarEnegia(int pos, double energia, int porEnergia);

void mostrarGrafica(energia *energias, int numEnergias, double maximo, int lineasProcesos[], int nProcesos);


#endif