#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "Extensiones/archivos.h"
#include "Extensiones/funciones.h"

int main(int argc, char *argv[]){
    int numeroCelda = 0; //Variable para la cantidad de celdas
    int obligatorioEntradaNumeroCelda = 0; //Verificar que exista una entrada -N

    char nombreArchivoEntrada[100]; //Variable para el archivo de entrada
    int obligatorioEntradaNombreArchivoEntrada = 0; //Verificar que exista una entrada -i

    char nombreArchivoSalida[100]; //Variable para el archivo de salida
    int obligatorioEntradaNombreArchivoSalida = 0; //Verificar que exista una entrada -o

    int flag = 0; // Variable para mostrar por pantalla

    //Comienza el uso de getopt
    int option;
    while((option = getopt(argc, argv, "N:i:o:D"))!=-1){
        switch (option)
        {
        case 'N':
            numeroCelda = atoi(optarg);
            obligatorioEntradaNumeroCelda = 1;
            break;
        
        case 'i':
            strcpy(nombreArchivoEntrada, optarg);
            obligatorioEntradaNombreArchivoEntrada=1;
            break;
        
        case 'o':
            strcpy(nombreArchivoSalida, optarg);
            obligatorioEntradaNombreArchivoSalida=1;
            break;
        
        case 'D':
            flag = 1;
            break;
        }
    }

    // Verificación del uso de las entradas necesarias
    if(obligatorioEntradaNumeroCelda==0){
        printf("Requiere el uso de la flag -N y con su cantidad de celda respectiva\n");
        return 1;
    }
    else if(obligatorioEntradaNombreArchivoEntrada==0){
        printf("Requiere el uso de la flag -i y con su archivo de entrada respectivo\n");
        return 1;
    }
    else if(obligatorioEntradaNombreArchivoSalida==0){
        printf("Requiere el uso de la flag -o y con su archivo de salida respectiva\n");
        return 1;
    }
    int cantidad=0;
    printf("-----------------\n");
    int**particulas = lecturaArchivoEntrada(nombreArchivoEntrada, &cantidad);

    double *salida = calculoEnergiaJoule(numeroCelda, particulas, cantidad);

    /*
    //Solo para ver que esté bien los resultados
    printf("---------\n");
    int probar=0;
    while(probar<numeroCelda){
        printf("%f\n", salida[probar]);
        probar++;
    }
    printf("---------\n");
    */

    if(flag==1){
        printf("Se muestra por pantalla N = %d, cantidad = %d\n", numeroCelda, cantidad);
    }

    printf("----------\nLiberando Memoria\n");
    int q=0;
    while(q<cantidad){
        free(particulas[q]);
        q++;
    }
    free(particulas);
    free(salida);
    printf("Memoria liberada\n----------\n");
    return 0;
}