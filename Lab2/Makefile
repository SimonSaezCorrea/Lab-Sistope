lab2: lab2.c worker broker
		gcc -o lab2 lab2.c -Wall -lm

worker: worker.c Extensiones/fworker.o Extensiones/fworker.o Extensiones/particulas.o
		gcc -o worker worker.c Extensiones/fworker.o Extensiones/particulas.o -Wall -lm

broker: broker.c Extensiones/fbroker.o Extensiones/descriptores.o Extensiones/lineas.o Extensiones/energia.o
		gcc -o broker broker.c Extensiones/fbroker.o Extensiones/descriptores.o Extensiones/lineas.o Extensiones/energia.o -Wall -lm

fbroker.o: Extensiones/fbroker.c Extensiones/lineas.o Extensiones/energia.o 
		gcc -c Extensiones/fbroker.c Extensiones/lineas.o Extensiones/energia.o -Wall -lm

fworker.o: Extensiones/fworker.c Extensiones/particulas.o
		gcc -c Extensiones/fworker.c Extensiones/particulas.o -Wall -lm

particulas.o: Extensiones/particulas.c
		gcc -c Extensiones/particulas.c -Wall -lm

descriptores.o: Extensiones/descriptores.c
		gcc -c Extensiones/descriptores.c -Wall -lm

lineas.o: Extensiones/lineas.c
		gcc -c Extensiones/lineas.c -Wall -lm

energia.o: Extensiones/energia.c
		gcc -c Extensiones/energia.c -Wall -lm

clear:
		rm -f lab2 worker broker Extensiones/*.o