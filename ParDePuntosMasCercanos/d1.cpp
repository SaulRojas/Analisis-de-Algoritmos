#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int divideMSS(int *arreglo, int inicio, int fin){
    
	if(inicio == fin){
        return arreglo[inicio];
    }

    int mitad = trunc((inicio+fin)/2);
    
    int sumaIzquierda = 0;
    int    sumaDerecha = 0;
    int    sumaCentral = 0;
    int    suma;
    int izq = divideMSS(arreglo, inicio, mitad);
    int der = divideMSS(arreglo, mitad+1, fin);
    
    suma = 0;
    sumaIzquierda = arreglo[mitad];
    for (int i = mitad; i >= inicio ; i--){
        suma += arreglo[i];
        if(suma > sumaIzquierda){
            sumaIzquierda = suma;
        }
    }
    
    suma = 0;
    sumaDerecha = arreglo[mitad+1];
    for (int i = mitad + 1; i <= fin; i++){
        suma += arreglo[i];
        if(suma>sumaDerecha){
            sumaDerecha = suma;
        }
    }
    sumaCentral = sumaIzquierda + sumaDerecha;
    
	if (izq>der && izq>sumaCentral )
	suma= izq;
	
	else if (der>izq && der>sumaCentral )
	suma= der;
	
	else
	suma=sumaCentral;
	
	return suma;
	
};


int main() 
{ 
int n, max, i;
int *arreglo;


scanf("%d",&n);


if(n<100001 && n>0)    
{
arreglo = (int*)malloc(n*sizeof(int));


    for( i=0;i<n;i++)
    {
	       scanf("%d",&arreglo[i]);
			if(arreglo[i] > 1000000001)break;

    }

if(i == n)max=divideMSS(arreglo, 0, n-1), printf("%d", max);
else  printf("error dato demasido grande");

free(arreglo);

}

else printf("error n demasiado grande");

    return 0; 
} 
 
