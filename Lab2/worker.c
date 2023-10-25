#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    //printf("\narchivoI:%s  CeldaI:%s    WorkerI:%s   ArchivoEntradaI:%s   ArchivoSalidaI:%s    ChunkI:%s   flagI=%s\n", argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
    
  int nWorkers = atoi(argv[1]);
  int nChunk = atoi(argv[2]);
    
    
    char buffer[100];
    
    sprintf(buffer, "Workers= %d y Chunk= %d",nWorkers ,nChunk);

    write(STDOUT_FILENO, buffer, 100);
    
    return 0;
}