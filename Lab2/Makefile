lab2: lab2.c worker broker
		gcc -o lab2 lab2.c -Wall -lm

worker: worker.c Extensiones/fworker.o Extensiones/fworker.o Extensiones/particulas.o
		gcc -o worker worker.c Extensiones/fworker.o Extensiones/particulas.o -Wall -lm

broker: broker.c Extensiones/fbroker.o
		gcc -o broker broker.c Extensiones/fbroker.o -Wall -lm

fbroker.o: Extensiones/fbroker.c
		gcc -c Extensiones/fbroker.c -Wall -lm

fworker.o: Extensiones/fworker.c Extensiones/particulas.o
		gcc -c Extensiones/fworker.c Extensiones/particulas.o -Wall -lm

particulas.o: Extensiones/particulas.c
		gcc -c Extensiones/particulas.c -Wall -lm

clear:
		rm -f lab2 worker broker Extensiones/*.o