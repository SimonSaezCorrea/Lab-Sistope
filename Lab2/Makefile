lab1: lab1.c worker broker
		gcc -o lab1 lab1.c Extensiones/archivos.o -Wall -lm

worker: worker.c Extensiones/fworker.o
		gcc -o worker worker.c -Wall -lm

broker: broker.c Extensiones/archivos.o Extensiones/listas.o Extensiones/fbroker.o
		gcc -o broker broker.c Extensiones/archivos.o Extensiones/listas.o Extensiones/fbroker.o -Wall -lm

archivos.o: Extensiones/archivos.c
		gcc -c Extensiones/archivos.c -Wall -lm

fbroker.o: Extensiones/fbroker.c
		gcc -c Extensiones/fbroker.c -Wall -lm

listas.o: Extensiones/listas.c
		gcc -c Extensiones/listas.c -Wall -lm

clear:
		rm -f lab1 Extensiones/*.o