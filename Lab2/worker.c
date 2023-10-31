#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){

  char mensaje[100];
  read(STDIN_FILENO, mensaje, 100);
  
  if(!strcmp(mensaje, "FIN")){
    char mensajeSalida[100]="Llego al apartado de FIN";
    write(STDOUT_FILENO, mensajeSalida, 100);
  }
  else{
    char mensajeSalida[100]="Llego a algo que no es FIN";
    write(STDOUT_FILENO, mensajeSalida, 100);
  }


  return 0;
}