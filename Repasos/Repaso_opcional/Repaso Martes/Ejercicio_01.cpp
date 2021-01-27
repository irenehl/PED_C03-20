#include <iostream>
using namespace std;

struct nodo {
    int dato;
    nodo* sig;
};

void insertarDespues(int dato, int datoRef, nodo** lista);
void insertarAntes(int dato, int datoRef, nodo** lista);
bool busquedaLista(int dato, nodo* lista);
void colaDatos(nodo** lista, int dato);
void mostrarLista(nodo* lista);
int suma();

int main(void) {
    nodo* pInicio = NULL;

    colaDatos(&pInicio, 1);
    colaDatos(&pInicio, 3);
    colaDatos(&pInicio, 5);
    colaDatos(&pInicio, 7);

    insertarAntes(2, 3, &pInicio);
    insertarDespues(4, 3, &pInicio);

    mostrarLista(pInicio);

    if(suma() == 8)
        cout << "El numero si se encuentra" << endl;
    else
        cout << "No se encontro ese dato" << endl;

    return 0;
}

int suma() {
    return 2 + 3;
}

void insertarDespues(int n, int datoRef, nodo** lista) {
    nodo* nuevo = new nodo;
    nuevo->dato = n;

    if(!*lista) {
        *lista = nuevo;
        (*lista)->sig = NULL;
    } 
    else {
        nodo *p = *lista;

        while(p->sig && p->dato != datoRef) 
            p = p->sig;
        
        nuevo->sig = p->sig;
        p->sig = nuevo;
    }
}

void insertarAntes(int dato, int datoRef, nodo** lista) {
    nodo *n = new nodo;
    n->dato = dato;

    if(!*lista) {
        *lista = n;
        (*lista)->sig = NULL;
    }
    else {
        nodo* auxAnt = NULL;
        nodo* aux = *lista;

        while(aux->sig && aux->dato != datoRef) {
            auxAnt = aux;
            aux = aux->sig;
        }

        auxAnt->sig = n;
        n->sig = aux;
    }
}

bool busquedaLista(int dato, nodo* lista) {
    nodo* s;

    s = lista;

    while(s != NULL && s->dato != dato) 
        s = s->sig;
    
    if(s)
        return true;
    else
        return false;
}

void colaDatos(nodo** lista, int dato) {
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

void mostrarLista(nodo* lista) {
    if(lista) {
        cout << lista->dato << endl;

        mostrarLista(lista->sig);
    }
}