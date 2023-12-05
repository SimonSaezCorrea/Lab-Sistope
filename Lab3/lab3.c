#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/wait.h>   
#include <pthread.h>
#include "Extensiones/funciones.h"

//VARIABLES GLOBALES

#define LOCATE "Ejemplos/"

FILE *ARCHIVO;

pthread_mutex_t lock;

double *celdasAcumulado;
int numeroCelda;
int cantidadDeParticulas;
int numeroChunk;

//FUNCIONES DE HEBRAS

int **leerArchivo(int numeroChunk){
    int **particulas = malloc(numeroChunk * sizeof(int *));

    for(int i = 0; i<numeroChunk && i<cantidadDeParticulas;i++){
        particulas[i] = malloc(2 * sizeof(int ));
        fscanf(ARCHIVO,"%d %d\n", &particulas[i][0], &particulas[i][1]);
    }

    return particulas;
}

double *calculo(int **particulas){
    double *valor = calculoEnergiaJoule(numeroCelda, particulas, cantidadDeParticulas);
    return valor;
}

void actualizarDatos(double *valores){
    for(int i = 0; i < numeroCelda; i++){
        celdasAcumulado[i] += valores[i];
    }
}

void *manejoDeHebra(){
    pthread_mutex_lock(&lock);
    int **particulas = leerArchivo(numeroChunk);
    pthread_mutex_unlock(&lock);

    double *valores = calculo(particulas);

    for(int i = 0; i < numeroCelda; i++){
        free(particulas[i]);
    }
    free(particulas);

    pthread_mutex_lock(&lock);
    actualizarDatos(valores);
    pthread_mutex_unlock(&lock);
}


//MAIN
int main(int argc, char *argv[]){
    int obligatorioEntradaNumeroCelda = 0; // Verificar que exista una entrada -N

    int numeroHebras;                   // Variable para la cantidad de workers
    int obligatorioEntradaNumeroHebras = 0; // Verificar que exista una entrada -p

    char nombreArchivoEntrada[100];                 // Variable para el archivo de entrada
    int obligatorioEntradaNombreArchivoEntrada = 0; // Verificar que exista una entrada -i

    char nombreArchivoSalida[100];                 // Variable para el archivo de salida
    int obligatorioEntradaNombreArchivoSalida = 0; // Verificar que exista una entrada -o

    int obligatorioEntradaNumeroChunk = 0;         //Verificar que existe una entrada -c

    int flag = 0; // Variable para mostrar por pantalla

    // Comienza el uso de getopt
    int option;
    while ((option = getopt(argc, argv, "N:H:i:o:c:D")) != -1){
        switch (option){
        case 'N':
            numeroCelda = atoi(optarg);
            obligatorioEntradaNumeroCelda = 1;
            break;

        case 'H':
            numeroHebras = atoi(optarg);
            obligatorioEntradaNumeroHebras = 1;
            break;

        case 'i':
            strcpy(nombreArchivoEntrada, optarg);
            obligatorioEntradaNombreArchivoEntrada = 1;
            break;

        case 'o':
            strcpy(nombreArchivoSalida, optarg);
            obligatorioEntradaNombreArchivoSalida = 1;
            break;

        case 'c':
            numeroChunk = atoi(optarg);
            obligatorioEntradaNumeroChunk = 1;
            break;
            
        case 'D':
            flag = 1;
            break;

        default:
            printf("Opción no reconocida\n");
            return 1;
        }
    }

    // Verificación del uso de las entradas necesarias
    if (obligatorioEntradaNumeroCelda == 0){
        printf("Requiere el uso de la flag -N y con su cantidad de celda respectiva\n");
        return 1;
    }
    else if(numeroCelda<=0){
        printf("Requiere que el numero de celda sea un numero natural positivo");
        return 1;
    }

    if (obligatorioEntradaNumeroHebras == 0){
        printf("Requiere el uso de la flag -P y con su cantidad de worker respectiva\n");
        return 1;
    }
    else if(numeroHebras<=0){
        printf("Requiere que el numero de hebras sea un numero natural positivo");
        return 1;
    }
    
    if (obligatorioEntradaNombreArchivoEntrada == 0){
        printf("Requiere el uso de la flag -i y con su archivo de entrada respectivo\n");
        return 1;
    }
    
    if (obligatorioEntradaNombreArchivoSalida == 0){
        printf("Requiere el uso de la flag -o y con su archivo de salida respectiva\n");
        return 1;
    }

    if (obligatorioEntradaNumeroChunk == 0){
        printf("Requiere el uso de la flag -c y con su cantidad de chunk respectiva\n");
        return 1;
    }
    else if(numeroChunk<=0){
        printf("Requiere que el numero de chunks sea un numero natural positivo");
        return 1;
    }
    
    celdasAcumulado = calloc(numeroCelda, sizeof(double));

    pthread_mutex_init(&lock, NULL);

    ARCHIVO = fopen(nombreArchivoEntrada, "r");

    if(ARCHIVO==NULL){
        char direccionReal[100] = "";
        strcat(direccionReal, LOCATE);
        strcat(direccionReal, nombreArchivoEntrada);

        ARCHIVO = fopen(direccionReal, "r");
        if(ARCHIVO==NULL){
            printf("El archivo de entrada no existe\n");
            return 1;
        }
    }

    fscanf(ARCHIVO, "%d\n", &cantidadDeParticulas);
    
    pthread_t tids[numeroHebras];

    for(int i=0;i<numeroHebras;i++){
        pthread_create(&tids[i], NULL, manejoDeHebra, NULL);
    }
    for(int i=0;i<numeroHebras;i++){
        pthread_join(tids[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    free(celdasAcumulado);
    return 0;
}