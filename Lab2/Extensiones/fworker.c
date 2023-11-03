#include "fworker.h"

#define MIN_ENERGY 0.001

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

void calculoDerecho(double *arregloJoule, int numeroDeCeldas, int posicionImpacto, int energiaImpacto){
    int i = posicionImpacto + 1;
    while (i < numeroDeCeldas){
        arregloJoule[i]=calculoEnergiaAcumulada(arregloJoule[i], energiaImpacto, posicionImpacto, i, numeroDeCeldas);
        i++;
    }
    
}

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

char *juntar(double *arregloJoule,int cantidad){
    int i;
    char *mensajeSalida=NULL;
    int longitud = 0;
    char palabra[100];
    char delimitador[] = ";";
    for(i=0; i<cantidad;i++){
        sprintf(palabra, "%f", arregloJoule[i]);

        int nuevaLongitud = longitud + strlen(palabra) + strlen(delimitador);
        mensajeSalida = (char *)realloc(mensajeSalida, nuevaLongitud + 1);
        
        strcat(mensajeSalida, palabra);
        strcat(mensajeSalida, delimitador);

        longitud = nuevaLongitud;
    }
    return mensajeSalida;
}

