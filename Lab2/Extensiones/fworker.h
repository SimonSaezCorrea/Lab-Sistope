#ifndef FWORKER

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "particulas.h"

/*
Entrada: int Ei: La energía acumulada.
         int Ej: Energía potencial que trae.
         int j: Posición de impacto.
         int i: La posición del arreglo.
         int N: Numero de celdas.

Salida: int: Valor resultante de la Energía acumulada, osea el Ei.

Descripción: Calculara la energía acumulada para la casilla, esta
             energía se calcula mediante una formula para el
             cálculo de Eij.
*/
double calculoEnergiaAcumulada(double Ei, int Ej, int j, int i, int N);

/*
Entrada: float *arregloJoule: El arreglo que contiene la energía.
         int numeroDeCeldas: La cantidad de celdas.
         int posicionImpacto: La posición de impacto.
         int energiaImpacto: La energía de impacto.

Salida: void: nada.

Descripción: Calcula la energía hacia la derecha del arregloJoule.
*/
void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto);

/*
Entrada: float *arregloJoule: El arreglo que contiene la energía.
         int numeroDeCeldas: La cantidad de celdas.
         int posicionImpacto: La posición de impacto.
         int energiaImpacto: La energía de impacto.

Salida: void: nada.

Descripción: Calcula la energía hacia la izquierda del arregloJoule.
*/
void calculoIzquierdo(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto);

/*
Entrada: int numeroDeCeldas: La cantidad de celdas.
         particulas *listaParticulas: Lista que contiene la posición y la energía de impacto.
         int cantidadParticulas: Es la cantidad de particulas en la lista.
Salida: float: retorna una lista que contiene la energía depositada por los
        impactos.

Descripción: Permite calcular la enería de impacto en cada posición y como
             se distribuye en el material.
*/
double *calculoEnergiaJoule(int numeroDeCeldas, particulas *listaParticulas, int cantidadParticulas);

/*
Entrada: double *arregloJoule: El arreglo que contiene la energía.
         int cantidad: Es la cantidad de particulas en la lista.

Salida: char: retorna una cadena de caracteres, la cual contiene cada elemento
              del arregloJoule.

Descripción: Permite transformar cada elemento del arregloJoule en una cadena
             de caracteres separados mendiante un ';'.
*/
char *juntar(double *arregloJoule,int cantidad);



#endif