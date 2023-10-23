#include "funciones.h"

#define MIN_ENERGY 0.001

double calculoEnergiaAcumulada(double Ei, int Ej, int j, int i, int N, double *maximo, int *pos){
    //Eij es la energía depositada y se calcula mediante la ecuación
    double Eij = 1000 * Ej;
    double total;
    Eij = Eij/(N*sqrt(fabs(j-i)+1));
    if(Eij < MIN_ENERGY){
        Eij=0;
    }
    total = Ei + Eij;
    if (total > (double)*maximo){
        *pos = i;
        *maximo = total;
    }
    return total;
}

void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto, double *maximo, int *pos){
    int i = posicionImpacto + 1;
    while (i < numeroDeCeldas){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas, maximo, pos);
        i++;
    }
    
}

void calculoIzquierdo(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto,  double *maximo, int *pos){
    int i = posicionImpacto - 1;
    if(i >= numeroDeCeldas){
        i = numeroDeCeldas - 1;
    }
    while (i >= 0){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas,maximo, pos) ;
        i--;
    }
}

double *calculoEnergiaJoule(int numeroDeCeldas, int **listaParticulas, int cantidadParticulas ,double *maximo, int *pos){
    double *arregloJoule = calloc(numeroDeCeldas, sizeof(double));
    int i = 0;
    while(i < cantidadParticulas){
        int posicion = listaParticulas[i][0];
        int energia = listaParticulas[i][1];
        if(posicion < numeroDeCeldas){
            arregloJoule[posicion] = calculoEnergiaAcumulada(arregloJoule[posicion], energia, posicion, posicion, numeroDeCeldas,maximo,pos);

            calculoDerecho(arregloJoule, numeroDeCeldas, posicion, energia,maximo,pos);
        }
        calculoIzquierdo(arregloJoule, numeroDeCeldas, posicion, energia,maximo,pos);
        i++;
    }

    return arregloJoule;
}

int porcentajeR3(double energiaPos,double maximo){
    int porcentaje;
    double x;
    x = (energiaPos * 100)/maximo;
    porcentaje = (int)(x + 0.5);
    return porcentaje;
    
}

void representarEnegia(int pos,double energia, int porEnergia){
    int i = 0;
    printf("%d\t%f\t|",pos,energia);
    while (i < porEnergia){
        printf("o");
        i++;
    }
    printf("\n");
}

void mostrarGrafica(double *energias, int numEnergias, double maximo){
    for (int i = 0; i < numEnergias; i++){
        int per = porcentajeR3(energias[i],maximo);
        representarEnegia(i,energias[i],per);
    }
}