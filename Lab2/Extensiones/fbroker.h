#ifndef FBROKER

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lineas.h"


char **lecturaArchivoEntrada(char *nameFile, int *cantidad);

void procesoChunks(int numWorkers, int workerPipes[][2], char** linea, int numLineas);

#endif