#ifndef FWORKER

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "particulas.h"


double calculoEnergiaAcumulada(double Ei, int Ej, int j, int i, int N);

void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto);

void calculoIzquierdo(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto);

double *calculoEnergiaJoule(int numeroDeCeldas, particulas *listaParticulas, int cantidadParticulas);

#endif