//*****************************************************************
//
//Curso: AnÃ¡lisis de algoritmos
//(C) Octubre 2020
//ESCOM-IPN
//Ejemplo de mediciÃ³n de tiempo en C y recepciÃ³n de parametros en C bajo UNIX
//CompilaciÃ³n: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementaciÃ³n de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//EjecuciÃ³n: "./main n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include <math.h>

//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÃ“N DE FUNCIONES
//*****************************************************************
void ShellSort(int *Data, int size);
void buscBinaria(int *A, int n, int busc);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para mediciÃ³n de tiempos
	int n; 	//n determina el tamaÃ±o del algorito dado por argumento al ejecutar
	int i; //Variables para loops3
	int busc; //

	//******************************************************************	
	//RecepciÃ³n y decodificaciÃ³n de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecuciÃ³n y cadena=n)
	if (argc!=3) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaÃ±o del algoritmo
	else
	{
		n=atoi(argv[1]);
		busc=atoi(argv[2]);
	}
	//******************************************************************	
	//Para crear 
	//******************************************************************
	int *A = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	ShellSort(A, n);
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo (llamada a funcion)
	//******************************************************************	
	buscBinaria(A, n, busc);
	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecuciÃ³n 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//CÃ¡lculo del tiempo de ejecuciÃ³n del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciÃ³nes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciÃ³nes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÃ“N DE FUNCIONES 
//************************************************************************

//************************************************************************
//DEFINICIÃ“N DE FUNCIONES 
//************************************************************************
void ShellSort(int *Data, int size){
  int k =trunc(size/2);
  while (k>=1){
    int b=1;
    while (b!=0) {
      b=0;
      for (int i = k; i <= size-1; i++) {
        if (Data[i-k]>Data[i]) {
          int temp=Data[i];
          Data[i]=Data[i-k];
          Data[i-k]=temp;
          b=b+1;
        }
      }
    }
    k=trunc(k/2);
  }

}

void buscBinaria(int *A, int n, int busc){
	int bajo = 0;
	int alto = n-1;
	int central = (bajo+alto)/2;
	
	//Busqueda binaria
	while(bajo<=alto && A[central]!=busc){
		central = (bajo+alto)/2;
		if(busc<A[central])
			alto=central-1;
		else
			bajo=central+1;
	}
	
	if(busc==A[central]){
		printf("\nEl valor se encuentra en la posicion: %d", central);
	}else{
		printf("\nEl valor no se encuentra");
	}
}


