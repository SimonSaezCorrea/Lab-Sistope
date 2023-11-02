#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Extensiones/fworker.h"
#include "Extensiones/particulas.h"

int main(int argc, char *argv[]){
  int celdas = atoi(argv[1]); //Guardo el dato del argumento del programa
  int chunkTotales = 0; //Declaro como los chunks totales del hijo en 0
  
  char *lineasSplit; //Variable para guardar los datos separados de la linea que entrega el padre
  char delimitador[] = " "; //El delimitador por el cual están separados
  
  char lineas[100];
  particulas *particula=NULL; //Genero la estructura a la cual están ligados

  char mensaje[100]; //Variable de la cual llegae el mensaje del padre
  int esperando=1; //Para declarar un bucle infinito, hasta que llegue la palabra FIN
  while(esperando){
    read(STDIN_FILENO, mensaje, 100); //Leo lo que envio

    //Compruebo si llegó la palabra FIN
    if(!strcmp(mensaje, "FIN")){
      double *arregloJoule = calculoEnergiaJoule(celdas, particula, chunkTotales); //Calculo el arregloJoule
      char *mensajeSalida = juntar(arregloJoule, celdas); //Genero el mensaje de Salida para enviar al padre

      write(STDOUT_FILENO, mensajeSalida, strlen(mensajeSalida)+1); //Se lo envio al padre
      
      //Libero la memoria
      free(arregloJoule);
      liberarParticulas(particula);
      esperando = 0;
    }
    //En caso contrario
    else{
      strcpy(lineas, mensaje); //Copio el mensaje

      //LO empiezo a separar y a guardar
      lineasSplit = strtok(lineas, delimitador);
      int posicion = atoi(lineasSplit);
      lineasSplit = strtok(NULL, delimitador);
      int energia = atoi(lineasSplit);
      particula = addParticula(particula, posicion, energia);
      //Aumento el contador de chunks para saber cuantos chunks tiene en total (Por si se repite el hijo)
      chunkTotales++;
    }
  }
  
  


  return 0;
}