#include <iostream>
using namespace std;

struct nodo {
    int dato;
    nodo* sig, *ant;
};

void pushFront(int dato, nodo** lista);
void pushBack(int dato, nodo** lista);
void mostrarLista(nodo* lista);

int main(void) {
    nodo* pInicio = NULL;

    pushFront(4, &pInicio);
    pushFront(3, &pInicio);
    pushFront(2, &pInicio);
    pushFront(1, &pInicio);

    pushBack(5, &pInicio);
    pushBack(6, &pInicio);
    pushBack(7, &pInicio);

    mostrarLista(pInicio);

    return 0;
}

void pushFront(int dato, nodo** lista) {
    nodo* n = new nodo;
    n->dato = dato;
    n->ant = NULL;
    n->sig = *lista;

    *lista = n;
}

void pushBack(int dato, nodo** lista) {
    nodo* n = new nodo;
    n->dato = dato;
    n->sig = NULL;
    n->ant = NULL;

    if(!*lista)
        *lista = n;
    else {
        nodo* aux = *lista;

        while(aux->sig)
            aux = aux->sig;
        
        // Aqui es donde conectamos todo
        n->ant = aux;
        aux->sig = n;
    } 
}

void mostrarLista(nodo* lista) {
    if(lista) {
        cout << lista->dato << endl;

        mostrarLista(lista->sig);
    }
}