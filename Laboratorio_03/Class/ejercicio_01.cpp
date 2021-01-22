/*
    La empresa PizzaPizza ha decidido contratarlo a usted para apoyar con 
    la administración del personal. El gerente ha sido un poco desordenado y 
    ha perdido algunos de los datos de los empleados que se encuentran trabajando
    en dicha empresa, por lo tanto le toca a usted recuperar esos datos y mantenerlos 
    en orden.

    Los datos a recolectar son: 
        * Nombre completo
        * ID empleado
        * DUI
        * Cargo

    Su programa deberá ser capaz de insertar empleados al inicio, al final, filtrar
    a un empleado por ID y mostrar tanto a los empleados insertados al inicio como al 
    final en una sola opcion
    
    Encarguese de recolectar toda esta información para poder mejorar a la empresa.
*/

#include <iostream>
using namespace std;

struct empleado {
    string nombre, dui, cargo;
    int id;
};

struct nodo {
    empleado datosEmpleado;
    nodo* sig;
};

class manejoEmpleados {
    private: 
        nodo *pPila, *pCola;
        /*
            nodo *pPila;
            nodo *pCola;
        */

        void pilaDatosIns(empleado em);
        void colaDatosIns(empleado em);

        void mostrarEmpleadosRec(nodo* pCola);
    
    public:
        manejoEmpleados() {
            pPila = NULL;
            pCola = NULL;
        }
        ~manejoEmpleados() {
            delete pPila;
            delete pCola;
        }

        void pilaDatos();
        void colaDatos();

        void filtrarDatos(int id);
        void mostrarEmpleadosIterativo();
        void mostrarEmpleadosRecursivo();
        
};

void manejoEmpleados::pilaDatos() {
    empleado em;
    int masDatos = 0;

    do {
        cout << "ID: "; cin >> em.id;
        cin.clear(); cin.ignore(1000, '\n');

        cout << "Nombre: "; cin >> em.nombre;
        cout << "DUI: "; cin >> em.dui;
        cout << "Cargo: "; cin >> em.cargo;

        pilaDatosIns(em);

        cout << "Mas datos (0 = No, 1 = Si) "; cin >> masDatos;

    }while(masDatos != 0);
}

void manejoEmpleados::pilaDatosIns(empleado em) {
    nodo* n = new nodo;
    n->datosEmpleado = em;
    n->sig = pPila;
    pPila = n;
}

void manejoEmpleados::colaDatos () {
    empleado em;
    int masDatos = 0;

    do {
        cout << "ID: "; cin >> em.id;
        cin.clear(); cin.ignore(1000, '\n');

        cout << "Nombre: "; cin >> em.nombre;
        cout << "DUI: "; cin >> em.dui;
        cout << "Cargo: "; cin >> em.cargo;

        colaDatosIns(em);

        cout << "Mas datos (0 = No, 1 = Si) "; cin >> masDatos;

    }while(masDatos != 0);
}

void manejoEmpleados::colaDatosIns(empleado em) {
    nodo* n = new nodo;
    n->datosEmpleado = em;
    n->sig = NULL;

    if(!pCola)
        pCola = n;
    else {
        nodo* aux = pCola;

        while(aux->sig)
            aux = aux->sig;
        
        aux->sig = n;
    }
}

void manejoEmpleados::filtrarDatos(int id) {
    bool encontrado = false;

    nodo* aux = pPila;

    while(aux) {
        if(aux->datosEmpleado.id == id) {
            cout << "Nombre: " << aux->datosEmpleado.nombre << endl;
            cout << "DUI: " << aux->datosEmpleado.dui << endl;
            cout << "Cargo: " << aux->datosEmpleado.cargo << endl;

            encontrado = true;
            break;
        }
        aux = aux->sig;
    }

    if(encontrado)
        return;
    
    aux = pCola;

    while(aux) {
        if(aux->datosEmpleado.id == id) {
            cout << "Nombre: " << aux->datosEmpleado.nombre << endl;
            cout << "DUI: " << aux->datosEmpleado.dui << endl;
            cout << "Cargo: " << aux->datosEmpleado.cargo << endl;

            encontrado = true;
            break;
        }
        aux = aux->sig;
    }

    if(!encontrado)
        cout << "No se ha encontrado ese empleado" << endl;
} 

void manejoEmpleados::mostrarEmpleadosIterativo() {
    nodo* aux = pPila;

    while(aux) {
        cout << "ID: " << aux->datosEmpleado.id << endl;
        cout << "Nombre: " << aux->datosEmpleado.nombre << endl;
        cout << "DUI: " << aux->datosEmpleado.dui << endl;
        cout << "Cargo: " << aux->datosEmpleado.cargo << endl;

        aux = aux->sig;
    }
}

void manejoEmpleados::mostrarEmpleadosRecursivo() {
    mostrarEmpleadosRec(pCola);
}

void manejoEmpleados::mostrarEmpleadosRec(nodo* pCola) {
    if(pCola) {
        cout << "ID: " << pCola->datosEmpleado.id << endl;
        cout << "Nombre: " << pCola->datosEmpleado.nombre << endl;
        cout << "DUI: " << pCola->datosEmpleado.dui << endl;
        cout << "Cargo: " << pCola->datosEmpleado.cargo << endl;

        mostrarEmpleadosRec(pCola->sig);
    }
}

int main(void) {
    manejoEmpleados me;

    int opcion = 0, idBuscar = 0;

    do{
        cout << "\tPIZZA PIZZA" << endl;
        cout << "1. Ingresar empleado (inicio) " << endl;
        cout << "2. Ingresar empleado (final)" << endl;
        cout << "3. Buscar empleado por ID" << endl;
        cout << "4. Ver todos los empleados" << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion: "; cin >> opcion;

        cin.clear(), cin.ignore(1000, '\n');

        switch (opcion) {
        case 1:
            me.pilaDatos();
            break;
        case 2:
            me.colaDatos();
            break;
        case 3:
            cout << "ID: "; cin >> idBuscar;
            me.filtrarDatos(idBuscar);
            break;
        case 4:
            cout << "\tEMPLEADOS APILADOS" << endl;
            me.mostrarEmpleadosIterativo();
            cout << endl << "\tEMPLEADOS EN COLA" << endl;
            me.mostrarEmpleadosRecursivo();
            break;
        default:
            break;
        }
    } while(opcion != 0);

    return 0;
}

