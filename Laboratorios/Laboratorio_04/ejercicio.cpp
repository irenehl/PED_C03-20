/*
CON POP Y LISTA SIMPLE
Lista original: 
0 2 4 6 8 10

Lista copia (invertida):
10 8 6 4 2 0

SIN POP Y CON LISTA DOBLE

Lista original:
0 2 4 6 8 10

Lista copia(invertida):
10 8 6 4 2 0
*/

#include <iostream>
using namespace std;

// Para lista simplemente enlazada
struct nodo {
    int dato;
    nodo* sig;
};

// Para lista doblemente enlazada 
struct nodoDoble {
    int dato;
    nodoDoble* sig, *ant;
};

void pushFront(nodo** lista, int dato);
void pushBack(nodo** lista, int dato);
void pushFrontDoble(nodoDoble** lista, int dato);
void pushBackDoble(nodoDoble** lista, int dato);
void mostrarLista(nodo* lista);
void mostrarListaDoble(nodoDoble* lista);
void pop(nodo** lista);

int main(void) {
    nodo* pInicio = NULL, *pCopia = NULL;
    nodoDoble* pInicioD = NULL, *pFinalD = NULL, *pCopiaD = NULL;

    // Llenado de lista simple y doble con num pares
    for(int i = 0; i <= 10; i += 2) {
        // Insercion como cola
        pushBack(&pInicio, i);
        pushBackDoble(&pInicioD, i);

        /*
        Primera corrida for
        pushBack(&pInicio, 0);  pInicio = 0

        Segunda corrida for
        pushBack(&pInicio, 2); pInicio = 0 2

        Tercera corrida for
        pushBack(&pInicio, 4); pInicio = 0 2 4

        Cuarta corrida for
        pushBack(&pInicio, 6); pInicio = 0 2 4 6

        Quinta corrida for
        pushBack(&pInicio, 8); pInicio = 0 2 4 6 8 

        Sexta corrida for
        pushBack(&pInicio, 10); pInicio = 0 2 4 6 8 10

        pInicioD = 0 2 4 6 8 10
        */
    }

    cout << "Lista original: " << endl;
    mostrarLista(pInicio);
    cout << endl;

    // 1. Recorrer la lista 
    while(pInicio != NULL) {
        // pInicio = 0 2 4 6 8 10
 
        // 2. Insertar elemento pInicio->dato (0,2,4,6,8,10) con el pushFront
        pushFront(&pCopia, pInicio->dato);
        // pushFront(&pCopia, 0); pCopia = 0 
        // pushFront(&pCopia, 2); pCopia = 2 0
        // pushFront(&pCopia, 4); pCopia = 4 2 0
        // pushFront(&pCopia, 6); pCopia = 6 4 2 0
        // pushFront(&pCopia, 8); pCopia = 8 6 4 2 0
        // pushFront(&pCopia, 10); pCopia = 10 8 6 4 2 0


        /*  
            10 ultimo elemento insertado 
            8
            6
            4
            2
            0 primer elemento insertado 
        */

        pop(&pInicio);
        // pInicio 2 4 6 8 10
        // pInicio 4 6 8 10
        // pInicio 6 8 10
        // pInicio 8 10
        // pInicio 10
        // pInicio
    }

    cout << "Lista copia (invertida)" << endl;
    mostrarLista(pCopia);
    cout << endl;

    cout << "----------- LSITA DOBLE --------------" << endl;

    // 1. Voy a encontrar el ultimo nodo de la lista

    nodoDoble *aux = pInicioD;
    // pInicioD = 0 2 4 6 8 10

    while(aux->sig)
        aux = aux->sig;

    pFinalD = aux;
    // pFinalD = 10 (no se queda exactamente con el valor de 10, si no con la direccion donde esta)

    cout << "Lista original: " << endl;
    mostrarListaDoble(pInicioD);
    cout << endl;

    // Recorrer de atras hacia adelante la lista

    while(pFinalD != NULL) {
        pushBackDoble(&pCopiaD, pFinalD->dato);
        //pushBackDoble(&pCopiaD, 10); pCopia 10
        //pushBackDoble(&pCopiaD, 8); pCopia 10 8
        //pushBackDoble(&pCopiaD, 6); pCopia 10 8 6
        //pushBackDoble(&pCopiaD, 4); pCopia 10 8 6 4
        //pushBackDoble(&pCopiaD, 2); pCopia 10 8 6 4 2
        //pushBackDoble(&pCopiaD, 0); pCopia 10 8 6 4 2 0     

        pFinalD = pFinalD->ant;
        // pFInal = 8 (guarda la direccion donde esta 8)
        // pFInal = 6 (guarda la direccion donde esta 6)
        // pFInal = 4 (guarda la direccion donde esta 4)
        // pFInal = 2 (guarda la direccion donde esta 2)
        // pFInal = 0 (guarda la direccion donde esta 0)
        // pFinal = NULL

    }

    cout << "Lista copia (invertida)" << endl;
    mostrarListaDoble(pCopiaD);
    cout << endl;

    return 0;
}


// Push para listas simplemente enlazadas
void pushFront(nodo** lista, int dato) {
    nodo* n = new nodo;
    n->dato = dato;
    n->sig = *lista;

    *lista = n;
}

void pushBack(nodo** lista, int dato) {
    nodo* n = new nodo;
    n->dato = dato;
    n->sig = NULL;

    if(!*lista)
        *lista = n;
    else {
        nodo* aux = *lista;

        while(aux->sig) 
            aux = aux->sig;
        
        aux->sig = n;
    } 
}

// Push para listas doblemente enlazadas

void pushFrontDoble(nodoDoble** lista, int dato) {
    // lista tiene
    // 57 95
    nodoDoble* n = new nodoDoble;
    n->dato = dato;
    // 12
    n->ant = NULL;
    // NULL <- 12
    n->sig = *lista;
    // 12 -> 57
    if(!*lista)
        *lista;
    
    (*lista)->ant = n;
    *lista = n;
}

void pushBackDoble(nodoDoble** lista, int dato) {
    nodoDoble* n = new nodoDoble;
    n->dato = dato;
    n->sig = NULL;
    n->ant = NULL;

    if(!*lista)
        *lista = n;
    else{
        nodoDoble* aux = *lista;

        while(aux->sig)
            aux = aux->sig;
        
        n->ant = aux;
        aux->sig = n;
    }
}

void mostrarLista(nodo* lista) {
    if(lista) {
        cout << lista->dato << "\t";
        mostrarLista(lista->sig);
    }
}

void mostrarListaDoble(nodoDoble* lista) {
    if(lista) {
        cout << lista->dato << "\t";
        mostrarListaDoble(lista->sig);
    }
}

void pop(nodo** lista) {
    if((*lista)->sig)
        *lista = (*lista)->sig;
    else
        *lista = NULL;
}