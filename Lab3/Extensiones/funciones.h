#ifndef FUNCIONES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double calculoEnergiaAcumulada(double Ei, int Ej, int j, int i, int N);


void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto);


void calculoIzquierdo(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto);


double *calculoEnergiaJoule(int numeroDeCeldas, int **listaParticulas, int cantidadParticulas);


int porcentajeR3(double energiaPos,double maximo);


void representarEnegia(int pos,double energia, int porEnergia);


void mostrarGrafica(double *energias, int numEnergias ,double maximo);

#endif