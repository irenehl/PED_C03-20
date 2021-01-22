/*
    Han pasado muchos meses desde que Claudia empezo a construir su libreria,
    ahora se siente un poco frustrada porque no está segura de que libros tiene 
    y cuáles se podría comprar. 

    Hablando con una amiga, esta le ha recomendado que primero identifique sus 
    libros por: 
        * ISBN (id de un libro)
        * Titulo
        * Autor 
        * Editorial
        * 
    Claudia ha considerado que la idea de su amiga es excelente, ahora ha 
    solicitado tu ayuda para poder ordenar todos sus libros
*/

#include <string>
#include <iostream>
using namespace std;

struct libro {
    int ISBN;
    string tiutlo, autor, editorial;
};

struct nodo {
    libro librosComprados;
    nodo* sig;
};

void mostrarLibrosRec(nodo* lista);
void insertarLibros(nodo** pInicio, libro lb);

int main(void) {
    nodo* pInicio = NULL;
    libro lb;

    string titulo, autor, editorial = "";
    int ISBN, cantidad = 0;

    cout << "Cantidad de libros a ingresar: "; cin >> cantidad;

    for(int i = 0; i < cantidad; i++) {
        cout << "ISBN: "; cin >> ISBN;
        cin.clear(); cin.ignore(1000, '\n');

        cout << "Titulo: "; getline(cin, titulo);
        cout << "Autor: "; getline(cin, autor);
        cout << "Editorial: "; getline(cin, editorial);

        lb.ISBN = ISBN;
        lb.tiutlo = titulo;
        lb.autor = autor;
        lb.editorial = editorial;
    }

    insertarLibros(&pInicio, lb);
    mostrarLibrosRec(pInicio);

    return 0;
}

void insertarLibros(nodo** pInicio, libro lb) {
    nodo* n = new nodo;
    n->librosComprados = lb;
    n->sig = *pInicio;
    *pInicio = n;
}

void mostrarLibrosRec(nodo* lista) {
    if(lista) {
        cout << "ISBN: " << lista->librosComprados.ISBN << endl;
        cout << "Titulo: " << lista->librosComprados.tiutlo << endl;
        cout << "Autor: " << lista->librosComprados.autor << endl;
        cout << "Editorial: " << lista->librosComprados.editorial << endl;
    
        mostrarLibrosRec(lista->sig);
    }
}