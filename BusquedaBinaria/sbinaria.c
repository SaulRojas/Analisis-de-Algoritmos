
//LIBRERÍAS
#include<stdio.h>
#include<stdlib.h>
#include "math.h"
#include "tiempo.h"

void ShellSort(int *Data, int size); 

int main(int argc,char **argv){
	int i;
	int size=atoi(argv[1]);
	int *Data;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	Data=calloc(size,sizeof(int));
	for(i=0;i<size;i++){
		scanf("%d",Data+i);
	}
	uswtime(&utime0, &stime0, &wtime0);
	ShellSort(Data,size);
	uswtime(&utime1, &stime1, &wtime1);


	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	free(Data);
}

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


	


