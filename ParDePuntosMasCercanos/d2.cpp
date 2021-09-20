#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 110L // Número máximo de puntos.

struct punto // Estructura de un punto.
{
   double x;
   double y;
 };

void busca(struct punto *,int);
int ordenax(const void *,const void *);
double dist(struct punto,struct punto);

struct punto c1,c2; // Puntos más cercanos.
double mindist; // Mínima distancia.

int main()
{
   int a,num;
   double x,y;
   struct punto p[MAX];

   for(scanf(" %d",&num),a=0;a<num;a++) // Coge la entrada
   {
      scanf(" %lf %lf",&x,&y);
      p[a].x=x;
      p[a].y=y;
    }

   busca(p,num); // Hacer la primera búsqueda.

   printf(".3lf\n",mindist);
  
   return(0);
 }

void busca(struct punto *p,int num)
{
   double d;
   int desde,hasta,a,b;

   if(num<=1) // Si no hay pares de puntos:
      return; // salir.
   // Ordenar los puntos por la coordenada x.
   qsort(p,num,sizeof(struct punto),ordenax);
   // Mirar en el subconjunto de la izquierda.
   busca(p,num/2);
   // Mirar en el subconjunto de la derecha.
   busca(p+num/2,(num+1)/2);

   // Hallar los límites del conjunto central.
   for(desde=num/2; desde>0 && p[num/2].x-p[desde].x<mindist; desde--);
   for(hasta=num/2; hasta<num-1 && p[hasta].x-p[num/2].x<mindist; hasta++);
   
   // Búsqueda exhaustiva en el conjunto central.
   for(a=desde;a<=hasta;a++)
      for(b=a+1;b<=hasta;b++)
         if((d=dist(p[a],p[b]))<mindist)
         {
            mindist=d;
            c1.x=p[0].x;
            c1.y=p[0].y;
            c2.x=p[1].x;
            c2.y=p[1].y;
          }
 }

 // Función auxiliar del qsort.
int ordenax(const void *a,const void *b)
{
   return(((*(struct punto *)a).x<(*(struct punto *)b).x)?-1:1);
 }

 // Función que calcula la distancia entre dos puntos.
double dist(struct punto a,struct punto b)
{
   return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
 }


