#include "funciones.h"

#define MIN_ENERGY 0.001

double calculoEnergiaAcumulada(double Ei, int Ej, int j, int i, int N){
    //Eij es la energía depositada y se calcula mediante la ecuación
    double Eij = 1000 * Ej;
    Eij = Eij/(N*sqrt(fabs(j-i)+1));
    if(Eij < MIN_ENERGY){
        Eij=0;
    }
    return Ei + Eij;
}

void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto){
    int i = posicionImpacto + 1;
    while (i < numeroDeCeldas){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas);
        i++;
    }
    
}

void calculoIzquierdo(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto){
    int i = posicionImpacto - 1;
    if(i > numeroDeCeldas){
        i = numeroDeCeldas - 1;
    }
    while (i >= 0){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas);
        i--;
    }
}

double *calculoEnergiaJoule(int numeroDeCeldas, int **listaParticulas, int cantidadParticulas){
    double *arregloJoule = calloc(numeroDeCeldas, sizeof(float));
    int i = 0;
    while(i < cantidadParticulas){
        int posicion = listaParticulas[i][0];
        int energia = listaParticulas[i][1];
        if(posicion < numeroDeCeldas){
            arregloJoule[posicion] = calculoEnergiaAcumulada(arregloJoule[posicion], energia, posicion, posicion, numeroDeCeldas);

            calculoDerecho(arregloJoule, numeroDeCeldas, posicion, energia);
        }
        calculoIzquierdo(arregloJoule, numeroDeCeldas, posicion, energia);
        i++;
    }

    return arregloJoule;
}