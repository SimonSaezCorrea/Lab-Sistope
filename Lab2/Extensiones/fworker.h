#ifndef FWORKER

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
double calculoEnergiaAcumulada(double Ei, int Ej, int j, int i, int N, double *maximo, int *pos);

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
void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto,double *maximo, int *pos);

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
void calculoIzquierdo(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto,double *maximo, int *pos);

/*
Entrada: int numeroDeCeldas: La cantidad de celdas.
         int **listaParticulas: Lista que contiene la posición y la energía de impacto.
         int cantidadParticulas: Es la cantidad de particulas en la lista.
         double *maximo: variable en la que se almacenara la maxima energia.
         int *pos: variable en la que se almacenara la posición de la celda con la maxima energia.

Salida: float: retorna una lista que contiene la energía depositada por los
        impactos.

Descripción: Permite calcular la enería de impacto en cada posición y como
             se distribuye en el material.
*/
double *calculoEnergiaJoule(int numeroDeCeldas, int **listaParticulas, int cantidadParticulas,double *maximo, int *pos);


/*
Entrada: double energiaPos: La energia que requiere calcular su porcentaje.
         double maximo: La energia maxima que en este caso vendria a ser el 100%.
         

Salida: int: retorna el porcentaje aproximado de la energia.

Descripción: Permite calcular el porcentaje de la energia, conociendo la energia maxima y asi usar regla de 3.
*/
int porcentajeR3(double energiaPos,double maximo);

/*
Entrada: int pos: La posicion que se desea mostrar por terminal como parte de una representacion grafica de las energia.
         double energia: La energia que se desea mostrar por terminal como parte de una representacion visual de las energia.
         int porEnergia: Porcentaje de energia que se utiliza para graficar la energia y representarla.

Salida: void: sin salida.

Descripción: Permite representar graficamente una posicion de celda con su respectiva energia y una ayuda visiual, luego imprime por terminal
dicha representación. 
*/
void representarEnegia(int pos,double energia, int porEnergia);

/*
Entrada: double *energias: Lista de energias que van a ser representadas graficamente y mostradas por terminal.
         int numEnergias: Numero de energias que deben ser representadas graficamente y mostradas por terminal.
         double maximo: Energia maxima que es usada como referencia para calcualar el porcentaje a las energias mediante regla de 3.
         

Salida: void: sin salida.

Descripción: Representar graficamente las energias de una lista y las va mostrando por terminal una por una.
*/
void mostrarGrafica(double *energias, int numEnergias ,double maximo);

#endif