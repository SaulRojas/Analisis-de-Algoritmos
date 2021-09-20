//*****************************************************************
//arbolBB.h
//*****************************************************************
//*****************************************************************
//ESCOM-IPN
//Compilación de la libreria: "gcc -c arbolBB.c " 
//*****************************************************************


//*****************************************************************
//struct nodo 
//*****************************************************************
//Descripción: Estructura para el nodo de un arbol binario de búsqueda.
//*****************************************************************
struct nodo{
    int dato;
    struct nodo *hijoIzq; //Referencia a nodo que se tiene como hijo derecho.
    struct nodo *hijoDer; //Referencia al nodo que se tiene como hijo izquierdo.
};
//*****************************************************************
//struct arbolBB 
//*****************************************************************
//Descripción: Estructura para un árbol binario de búsqueda.

//*****************************************************************
struct arbolBB{
    struct nodo *raiz; //Referencia al nodo que se tiene como raíz del árbol.
};

//*****************************************************************
//crearABB 
//*****************************************************************
//Descripción: Crea árbol binario con una raíz vacía.
//
//Recibe:
//Devuelve: Referencia del árbol creado.
//*****************************************************************
struct arbolBB *crearABB();


//*****************************************************************
//crearNodo 
//*****************************************************************
//Descripción: Crea un nuevo nodo de árbol binario.
//
//Recibe: El numero entero que se guardara
//Devuelve: Referencia del nodo creado.
//*****************************************************************
struct nodo *crearNodo(int dato);

//*****************************************************************
//insertar 
//*****************************************************************
//Descripción: Función que inserta un dato en un árbol binario de manera
//iterativa.
//
//Recibe: Referencia a un árbol binario de búsqueda y un dato a ingresar.
//Devuelve: 
//*****************************************************************
void insertar(struct arbolBB *arbol, int dato);


//*****************************************************************
//guardarRecorridoInorden 
//*****************************************************************
//Descripción: Almacena en un arreglo  los datos de un
//árbol binario de búsqueda con recorrido en inorden.
//
//Recibe: Referencia al arbol binario de busqueda con la informacion y un arreglo de enteros.
//Devuelve: 
//*****************************************************************
void guardarRecorridoInorden(struct arbolBB *arbol, int *A, int n);




//*****************************************************************
//buscar 
//*****************************************************************
//Descripción: Función que busca un dato en un árbol binario de manera
//iterativa.
//
//Recibe: Referencia a un árbol binario de búsqueda y un dato a buscar.
//Devuelve: 
//*****************************************************************
int  buscar(struct arbolBB *arbol, int dato);