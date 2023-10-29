#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    //printf("\narchivoI:%s  CeldaI:%s    WorkerI:%s   ArchivoEntradaI:%s   ArchivoSalidaI:%s    ChunkI:%s   flagI=%s\n", argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
   /*
  int nWorkers = atoi(argv[1]);
  int nChunk = atoi(argv[2]);
    
    
    char buffer[100];
    
    sprintf(buffer, "Workers= %d y Chunk= %d",nWorkers ,nChunk);

    write(STDOUT_FILENO, buffer, 100);
   */ 

  //Prueba de proceso hijo
  if (argc != 2) {
        fprintf(stderr, "Uso: %s <numero>\n", argv[0]);
        return 1;
    }

  // Convertir el argumento (número) en un entero
  int numero = atoi(argv[1]);

  // Realizar la operación (sumar 1)
  int resultado = numero + 1;

  // Convertir el resultado a una cadena
  char resultado_str[20];
  snprintf(resultado_str, sizeof(resultado_str), "%d", resultado);

  // Enviar el resultado al proceso padre a través de la salida estándar (STDOUT)
  write(STDOUT_FILENO, resultado_str, sizeof(resultado_str));


    return 0;
}