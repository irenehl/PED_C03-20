#include <iostream>
using namespace std;

// Estructura que contiene los elementos que componen al nodo:
// informacion que se va a recibir y puntero que conecta a los nodos entre
struct nodo {
    int dato;
    nodo* sig;
};

/*
    Clase agrupa funciones del manejo de la lista, y contiene el puntero de tipo nodo
    que se encarga de ser el inicio o la referencia inicial de la lista
*/
class manejoLista {
    /*
        No se pueden acceder / referenciar afuera de la clase, o en funciones que no 
        corresponden a la clase
    */
    private:
        nodo* pInicio;
        void funcionInsertarInicio(int dato);
    /*
        Se pueden referenciar tanto dentro o fuera de la clase
    */
    public:
        /*
            Constructor 
            Se ejecuta por defecto en tiempo de ejecucion cuando se debe crear la variable 
            de tipo de clase. No pueden retornar valores, pero pueden recibir argumentos
        */
        manejoLista() {
            pInicio = NULL;
        }

        /*
            Destructor 
            Se ejecuta por defecto en tiempo de ejecucion, lo hace cuando la variable de tipo 
            clase deja de existir. Su fin es limpiar variables / punteros
        */
        ~manejoLista() {
            delete pInicio;
        }
    
        void insertar(int dato);
        void mostrarDatos();

};

void manejoLista::insertar(int dato) {
    funcionInsertarInicio(dato);
}

void manejoLista::funcionInsertarInicio(int dato) {
    nodo* n = new nodo;
    n->dato = dato;
    n->sig = pInicio;

    pInicio = n;
}

void manejoLista::mostrarDatos() {
    nodo* aux = pInicio;

    while(aux) {
        cout << aux->dato << endl;
        aux = aux->sig;
    }
}

int main(void) {
    manejoLista lm;

    int n = 0, cantidad = 0;

    cout << "Cantidad de num a ingresar: "; cin >> cantidad;

    for(int i = 0; i < cantidad; i++) {
        cout << "Num " << (i + 1) << ": "; cin >> n;
        lm.insertar(n);
    }

    lm.mostrarDatos();
    
    return 0;
}


