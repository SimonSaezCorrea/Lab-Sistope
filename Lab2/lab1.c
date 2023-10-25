#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char numeroCeldaString[4];             // Variable para la cantidad de celdas
    int obligatorioEntradaNumeroCelda = 0; // Verificar que exista una entrada -N

    char numeroWorker[4];                   // Variable para la cantidad de workers
    int obligatorioEntradaNumeroWorker = 0; // Verificar que exista una entrada -p

    char nombreArchivoEntrada[100];                 // Variable para el archivo de entrada
    int obligatorioEntradaNombreArchivoEntrada = 0; // Verificar que exista una entrada -i

    char nombreArchivoSalida[100];                 // Variable para el archivo de salida
    int obligatorioEntradaNombreArchivoSalida = 0; // Verificar que exista una entrada -o

    char numeroChunk[4];                           //Variable para la cantidad de chunks
    int obligatorioEntradaNumeroChunk = 0;         //Verificar que existe una entrada -c

    char flag[2] = "0"; // Variable para mostrar por pantalla

    // Comienza el uso de getopt
    int option;
    while ((option = getopt(argc, argv, "N:P:i:o:c:D")) != -1){
        switch (option){
        case 'N':
            strcpy(numeroCeldaString, optarg);
            obligatorioEntradaNumeroCelda = 1;
            break;

        case 'P':
            strcpy(numeroWorker, optarg);
            obligatorioEntradaNumeroWorker = 1;
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
            strcpy(numeroChunk, optarg);
            obligatorioEntradaNumeroChunk = 1;
            break;
        case 'D':
            strcpy(flag, "1");
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
    else if (obligatorioEntradaNumeroWorker == 0){
        printf("Requiere el uso de la flag -P y con su cantidad de worker respectiva\n");
        return 1;
    }
    else if (obligatorioEntradaNombreArchivoEntrada == 0){
        printf("Requiere el uso de la flag -i y con su archivo de entrada respectivo\n");
        return 1;
    }
    else if (obligatorioEntradaNombreArchivoSalida == 0){
        printf("Requiere el uso de la flag -o y con su archivo de salida respectiva\n");
        return 1;
    }

    else if (obligatorioEntradaNumeroChunk == 0){
        printf("Requiere el uso de la flag -c y con su cantidad de chunk respectiva\n");
        return 1;
    }

    int pid;

    pid = fork(); // Se genera un Hijo

    // En caso de ser el Hijo, ejecutrar el execv
    if (pid == 0){
        char *argvExec[] = {"./broker", numeroCeldaString, numeroWorker, nombreArchivoEntrada, nombreArchivoSalida, numeroChunk, flag, NULL};

        execv(argvExec[0], argvExec);
        printf("Despues de exec\n");
    }
    //En caso de ser el Padre
    else{
        /*
        int numeroCelda = atoi(numeroCeldaString);

        int cantidad = 0;
        double maximo = 0;
        int pos = 0;
        // printf("-----------------\n");
        int **particulas = lecturaArchivoEntrada(nombreArchivoEntrada, &cantidad);

        double *salida = calculoEnergiaJoule(numeroCelda, particulas, cantidad, &maximo, &pos);

        
        //Solo para ver que esté bien los resultados
        printf("\nMaximo: %f -- Posicion: %d\n", maximo, pos);
        printf("---------\n");
        int probar=0;
        while(probar<numeroCelda){
            printf("%d) %f\n", probar +1,salida[probar]);
            probar++;
        }
        printf("---------\n");
        

        if (strcmp(flag, "1") == 0){
            mostrarGrafica(salida, numeroCelda, maximo);
        }
        escribirArchivoSalida(nombreArchivoSalida, salida, numeroCelda, maximo, pos);

        printf("----------\nLiberando Memoria\n");
        int q = 0;
        while (q < cantidad){

            free(particulas[q]);
            q++;
        }
        free(particulas);

        free(salida);
        printf("Memoria liberada\n----------\n");
        */
    }
    return 0;
}