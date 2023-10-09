#include "funciones.h"

float calculoEnergiaAcumulada(float Ei, int Ej, int j, int i, int N){
    //Eij es la energía depositada y se calcula mediante la ecuación
    float Eij = 1000 * Ej;
    double newJ = j;
    double newI = i;
    Eij = Eij/(N*sqrt(fabs(j-i)+1));
    if(Eij < 0.001){
        Eij=0;
    }
    
    return Ei + Eij;
}

void calculoDerecho(float *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto){
    int i = posicionImpacto + 1;
    while (i < numeroDeCeldas){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas);
        i++;
    }
}

void calculoIzquierdo(float *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto){
    int i = posicionImpacto - 1;
    while (i >= 0){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas);
        i--;
    }
}

float *calculoEnergiaJoule(int numeroDeCeldas, int **listaParticulas, int cantidadParticulas){
    float *arregloJoule = calloc(numeroDeCeldas, sizeof(float));
    int i = 0;
    while(i < cantidadParticulas){
        int posicion = listaParticulas[i][0];
        int energia = listaParticulas[i][1];
        if(posicion < numeroDeCeldas){
            arregloJoule[posicion] += energia;
            calculoDerecho(arregloJoule, numeroDeCeldas, posicion, energia);
        }
        calculoIzquierdo(arregloJoule, numeroDeCeldas, posicion, energia);
        i++;
    }

    return arregloJoule;
}