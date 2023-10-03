FLAGS = -Wall -lm

lab1: lab1.c Extensiones/archivos.o Extensiones/funciones.o
		gcc $(FLAGS) -o lab1 lab1.c Extensiones/archivos.o Extensiones/funciones.o

archivos.o: Extensiones/archivos.c
		gcc -c $(FLAGS) Extensiones/archivos.c

funciones.o: Extensiones/funciones.c
		gcc -c $(FLAGS) Extensiones/funciones.c

clear:
		rm -f lab1 Extensiones/*.o