/*
    Claudia es amante de los libros y quiere empezar a armar su biblioteca.
    Su plan es comprar varios libros al mes, cada libro que compre lo apilara
    en un mueble que ha comprado especialmente para su coleccion.

    Ejemplo:

    En marzo Claudia compro 3 libros, en su mueble se han apilado de la siguiente
    manera: 
        * Tercer libro
        * Segundo libro
        * Primer libro
        * 
    Realice un programa que sea capaz de replicar el orden de Claudia

*/

#include <iostream>
using namespace std;

struct nodo {
    string libro;
    nodo* sig;
};

class biblioteca {
    private:
        nodo* pInicio;
        void funcionInsertarLibros(string libro);
    public:
        biblioteca () {
            pInicio = NULL;
        }

        ~biblioteca () {
            delete pInicio;
        }

        void insertar(string libro);
        void mostrarLibros();
};

void biblioteca::funcionInsertarLibros(string libro){
    insertar(libro);
}

void biblioteca::insertar(string libro) {
    nodo* n = new nodo;
    n->libro = libro;
    n->sig = pInicio;

    pInicio = n;
}

void biblioteca::mostrarLibros() {
    nodo* aux = pInicio;

    while(aux) {
        cout << aux->libro << endl;
        aux = aux->sig;
    }
}

int main(void) {
    biblioteca lib;

    string libro = "";
    int cantidad = 0;

    cout << "Cantidad de libros a insertar: "; cin >> cantidad;

    for(int i = 0; i < cantidad; i++) {
        cout << "Nombre: "; cin >> libro;
        lib.insertar(libro);
    }

    lib.mostrarLibros();

    return 0;
}

