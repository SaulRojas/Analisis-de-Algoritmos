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
int fibMonaccianSearch(int arr[], int x, int n);
int min(int x, int y);
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
	fibMonaccianSearch(A, busc, n);
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

// Utility function to find minimum of two elements 
int min(int x, int y) { return (x<=y)? x : y; } 
  
/* Returns index of x if present,  else returns -1 */
int fibMonaccianSearch(int arr[], int x, int n) 
{ 
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0;   // (m-2)'th Fibonacci No. 
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci 
  
    /* fibM is going to store the smallest Fibonacci 
       Number greater than or equal to n */
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
  
    // Marks the eliminated range from front 
    int offset = -1; 
  
    /* while there are elements to be inspected. Note that 
       we compare arr[fibMm2] with x. When fibM becomes 1, 
       fibMm2 becomes 0 */
    while (fibM > 1) 
    { 
        // Check if fibMm2 is a valid location 
        int i = min(offset+fibMMm2, n-1); 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray array from offset to i */
        if (arr[i] < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray after i+1  */
        else if (arr[i] > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 
  
        /* element found. return index */
        else{
			printf("\nEl valor se encuentra en la posicion: %d", i );
			return 1;	
		} 
    } 
  
    /* comparing the last element with x */
    if(fibMMm1 && arr[offset+1]==x){
		
		printf("\nEl valor se encuentra en la posicion: %d", offset+1 );
		return offset+1;

	} 
  
    /*element not found. return -1 */
	printf("\nEl valor no se encuentra");	
    return -1; 
} 


