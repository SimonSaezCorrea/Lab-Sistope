#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){

  char mensaje[100];
  int esperando=1;
  while(esperando){
    read(STDIN_FILENO, mensaje, 100);
    if(!strcmp(mensaje, "FIN")){
      int pid = getpid();
      char pidS[100];
      sprintf(pidS, "%d", pid);
      char mensajeSalida[100]="Soy el hijo ";
      strcat(mensajeSalida, pidS);
      strcat(mensajeSalida, "y he llegado al apartado de FIN");
      write(STDOUT_FILENO, mensajeSalida, 100);
      esperando = 0;
    }
    else{
      int pid = getpid();
      char pidS[100];
      sprintf(pidS, "%d", pid);
      char mensajeSalida[100]="Soy el hijo ";
      strcat(mensajeSalida, pidS);
      strcat(mensajeSalida, " y me llego el mensaje:   ");
      strcat(mensajeSalida, mensaje);
      write(STDOUT_FILENO, mensajeSalida, 100);
    }
  }
  
  


  return 0;
}