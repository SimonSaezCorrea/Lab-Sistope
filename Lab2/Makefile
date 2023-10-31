lab2: lab2.c worker broker
		gcc -o lab2 lab2.c -Wall -lm

worker: worker.c Extensiones/fworker.o Extensiones/lineas.o Extensiones/fworker.o
		gcc -o worker worker.c Extensiones/lineas.o Extensiones/fworker.o -Wall -lm

broker: broker.c Extensiones/lineas.o Extensiones/fbroker.o
		gcc -o broker broker.c Extensiones/lineas.o Extensiones/fbroker.o -Wall -lm

archivos.o: Extensiones/archivos.c
		gcc -c Extensiones/archivos.c -Wall -lm

fbroker.o: Extensiones/fbroker.c
		gcc -c Extensiones/fbroker.c -Wall -lm

fworker.o: Extensiones/fworker.c
		gcc -c Extensiones/fworker.c -Wall -lm

lineas.o: Extensiones/lineas.c
		gcc -c Extensiones/lineas.c -Wall -lm

clear:
		rm -f lab1 worker broker Extensiones/*.o