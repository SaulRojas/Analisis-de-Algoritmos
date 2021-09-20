//*****************************************************************
//arbolBB.c
//*****************************************************************
//*****************************************************************
//Curso: Análisis de algoritmos
//(C) Octubre 2020
//ESCOM-IPN
//Compilación de la libreria: "gcc -c arbolBB.c " (Generación del código objeto)
//*****************************************************************



//*****************************************************************
//Bibliotecas 
//*****************************************************************
#include <stdlib.h>
#include "arbolBB.h"



//*****************************************************************
//crearABB 
//*****************************************************************
//Descripción: Crea árbol binario con una raíz vacía.
//
//Recibe:
//Devuelve: Referencia del árbol creado.
//*****************************************************************
struct arbolBB *crearABB(){
    struct arbolBB *newArbol = (struct arbolBB *)malloc(sizeof(struct arbolBB));
    newArbol->raiz = NULL;

    return newArbol;
}

//*****************************************************************
//crearNodo 
//*****************************************************************
//Descripción: Crea un nuevo nodo de árbol binario.
//
//Recibe: El numero entero que se guardara
//Devuelve: Referencia del nodo creado.
//*****************************************************************
struct nodo *crearNodo(int dato){
    struct nodo *newNodo = (struct nodo *)malloc(sizeof(struct nodo));
    newNodo->dato = dato;
    newNodo->hijoIzq = NULL;
    newNodo->hijoDer = NULL;

    return newNodo;
}

//*****************************************************************
//insertar 
//*****************************************************************
//Descripción: Función que inserta un dato en un árbol binario de manera
//iterativa.
//
//Recibe: Referencia a un árbol binario de búsqueda y un dato a ingresar.
//Devuelve: 
//*****************************************************************
void insertar(struct arbolBB *arbol, int dato){
    struct nodo *x = arbol->raiz;  // inicializar x como nodo raiz para recorrer el árbol
    struct nodo *y = NULL; //Varuable auxuliar como nodo de seguimiento para que se pueda modificar del árbol
    struct nodo *newNodo = crearNodo(dato); //nodo con la informacion a insertar
    //******************************************************************

    //******************************************************************    
    //Algoritmo
    //******************************************************************
    while(x != NULL){
        y = x;
        if(newNodo->dato < x->dato)
            x = x->hijoIzq;
        else
            x = x->hijoDer;
    }
    if(y == NULL)
    {
        arbol->raiz = newNodo;
    }
    else if(newNodo->dato < y->dato)
    {
        y->hijoIzq = newNodo;
    }
    else
    {
        y->hijoDer = newNodo;
    }
    
  
}
//*****************************************************************
//guardarRecorridoInorden 
//*****************************************************************
//Descripción: Almacena en un arreglo  los datos de un
//árbol binario de búsqueda con recorrido en inorden.
//
//Recibe: Referencia al arbol binario de busqueda con la informacion y un arreglo de enteros.
//Devuelve: 
//*****************************************************************
void guardarRecorridoInorden(struct arbolBB *arbol, int *A, int n){
    struct nodo *actual; //varieble pasa saber la posicion actual en el arbol durante el recorrido
    struct nodo *pre;  //varieble auxiliar para el recorrido
    int i = 0; 
 
    if(arbol->raiz == NULL)
        return;
    
    actual = arbol->raiz;
    while(actual != NULL && i < n){
        if(actual->hijoIzq == NULL){
            A[i] = actual->dato;
            i++;
            actual = actual->hijoDer;
        }
        else{
            pre = actual->hijoIzq;
            while(pre->hijoDer != NULL && pre->hijoDer != actual)
                pre = pre->hijoDer;
            if(pre -> hijoDer == NULL){
                pre->hijoDer = actual;
                actual = actual->hijoIzq;
            }
            else{
                pre->hijoDer = NULL;
                A[i] = actual->dato;
                i++;
                actual = actual->hijoDer;
            }
        }
    }
  
}


//*****************************************************************
//buscar 
//*****************************************************************
//Descripción: Función que busca un dato en un árbol binario de manera
//iterativa.
//
//Recibe: Referencia a un árbol binario de búsqueda y un dato a buscar.
//Devuelve: 
//*****************************************************************

int buscar(struct arbolBB *arbol, int dato){
    struct nodo *x = arbol->raiz;  // inicializar x como nodo raiz para recorrer el árbol
    struct nodo *y = NULL; //Varuable auxuliar como nodo de seguimiento para que se pueda modificar del árbol
    struct nodo *newNodo = crearNodo(dato); //nodo con la informacion a insertar
    //******************************************************************

    //******************************************************************    
    //Algoritmo
    //******************************************************************
    
    while(x != NULL && x->dato != newNodo->dato  ){
        y = x;
        if(newNodo->dato < x->dato)
            x = x->hijoIzq;
        else
            x = x->hijoDer;
    }

    if(x == NULL)
    {
        struct nodo *Nodo = crearNodo(-1);
        x=Nodo;
    }

    return x->dato;
  
}