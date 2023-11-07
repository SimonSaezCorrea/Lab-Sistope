#include "fworker.h"

#define MIN_ENERGY 0.001

/*
Entrada: int Ei: La energía acumulada
         int Ej: Energía potencial que trae
         int j: Posición de impacto
         int i: La posición del arreglo
         int N: Numero de celdas

Salida: int: Valor resultante de la Energía acumulada, osea el Ei

Descripción: Calculara la energía acumulada para la casilla, esta
             energía se calcula mediante una formula para el
             cálculo de Eij
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
Entrada: double *arregloJoule: El arreglo que contiene la energí
         int numeroDeCeldas: La cantidad de celdas
         int posicionImpacto: La posición de impacto
         int energiaImpacto: La energía de impacto

Salida: void

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
Entrada: double *arregloJoule: El arreglo que contiene la energía
         int numeroDeCeldas: La cantidad de celdas
         int posicionImpacto: La posición de impacto
         int energiaImpacto: La energía de impacto

Salida: void

Descripción: Calcula la energía hacia la izquierda del arregloJoule
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
Entrada: int numeroDeCeldas: La cantidad de celdas
         particulas *listaParticulas: Lista que contiene la posición y la energía de impacto
         int cantidadParticulas: Es la cantidad de particulas en la lista
Salida: double: retorna una lista que contiene la energía depositada por los
                impactos

Descripción: Permite calcular la enería de impacto en cada posición y como
             se distribuye en el material
*/
double *calculoEnergiaJoule(int numeroDeCeldas, particulas *listaParticulas, int cantidadParticulas){
    double *arregloJoule = calloc(numeroDeCeldas, sizeof(double));
    int i = 0;
    particulas *aux = listaParticulas;
    if(aux!=NULL){
        while(i < cantidadParticulas){
            int posicion = aux->posicion;
            int energia = aux->energia;
            if(posicion < numeroDeCeldas){
                arregloJoule[posicion] = calculoEnergiaAcumulada(arregloJoule[posicion], energia, posicion, posicion, numeroDeCeldas);

                calculoDerecho(arregloJoule, numeroDeCeldas, posicion, energia);
            }
            calculoIzquierdo(arregloJoule, numeroDeCeldas, posicion, energia);
            aux = aux->next;
            i++;
        }
    }
    return arregloJoule;
}


