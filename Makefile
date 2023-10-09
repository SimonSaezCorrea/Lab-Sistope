lab1: lab1.c Extensiones/archivos.o Extensiones/funciones.o
		gcc -o lab1 lab1.c Extensiones/archivos.o Extensiones/funciones.o -Wall -lm

archivos.o: Extensiones/archivos.c
		gcc -c Extensiones/archivos.c -Wall -lm

funciones.o: Extensiones/funciones.c
		gcc -c Extensiones/funciones.c -Wall -lm

clear:
		rm -f lab1 Extensiones/*.o