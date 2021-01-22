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
    final
    
    Encarguese de apilar toda esta información para poder mejorar a la empresa.
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

void pilaDatos(nodo** pPila, empleado em);
void colaDatos(nodo** pCola, empleado em);
void filtrarDatos(nodo* pPila, nodo* pCola, int id);
void mostrarEmpleadosPila(nodo* lista);
void mostrarEmpleadosCola(nodo* lista);

int main(void) {
    nodo* pPila = NULL, *pCola = NULL;
    empleado em;

    int opcion = 0, idBuscar = 0, masDatos = 0;

    do {
        cout << "\tPIZZA PIZZA" << endl;
        cout << "1. Ingresar empleado (inicio) " << endl;
        cout << "2. Ingresar empleado (final)" << endl;
        cout << "3. Buscar empleado por ID" << endl;
        cout << "4. Ver todos los empleados" << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion: "; cin >> opcion;

        cin.clear(), cin.ignore(1000, '\n');

        switch(opcion) {
            case 1:
                do {
                    cout << "ID: "; cin >> em.id;
                    cin.clear(); cin.ignore(1000, '\n');

                    cout << "Nombre: "; cin >> em.nombre;
                    cout << "DUI: "; cin >> em.dui;
                    cout << "Cargo: "; cin >> em.cargo;

                    pilaDatos(&pPila, em);

                    cout << "Mas datos (0 = No, 1 = Si) "; cin >> masDatos;

                }while(masDatos != 0);

                break;
            case 2:
                do {
                    cout << "ID: "; cin >> em.id;
                    cin.clear(); cin.ignore(1000, '\n');

                    cout << "Nombre: "; cin >> em.nombre;
                    cout << "DUI: "; cin >> em.dui;
                    cout << "Cargo: "; cin >> em.cargo;

                    colaDatos(&pCola, em);

                    cout << "Mas datos (0 = No, 1 = Si) "; cin >> masDatos;

                }while(masDatos != 0);
                
                break;
            case 3:
                cout << "ID: "; cin >> idBuscar;
                filtrarDatos(pPila, pCola, idBuscar);
                break;
            case 4:
                cout << "\tEMPLEADOS APILADOS" << endl;
                mostrarEmpleadosPila(pPila);
                cout << endl << "\tEMPLEADOS COLA" << endl;
                mostrarEmpleadosCola(pCola);
                break;
            default:
                break;
        }

    } while(opcion != 0);

    return 0;
}

void pilaDatos(nodo** pPila, empleado em) {
    nodo* n = new nodo;
    n->datosEmpleado = em;
    n->sig = *pPila;
    *pPila = n;
}

void colaDatos(nodo** pCola, empleado em) {
    nodo* n = new nodo;
    n->datosEmpleado = em;
    n->sig = NULL;

    if(!*pCola)
        *pCola = n;
    else {
        nodo* aux = *pCola;

        while(aux->sig)
            aux = aux->sig;
        
        aux->sig = n;
    }
}

void filtrarDatos(nodo* pPila, nodo* pCola, int id) {

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

// void mostrarEmpleadosPila(nodo* pPila)
void mostrarEmpleadosPila(nodo* lista) {
    nodo* aux = lista;

    while(aux) {
        cout << "ID: " << aux->datosEmpleado.id << endl;
        cout << "Nombre: " << aux->datosEmpleado.nombre << endl;
        cout << "DUI: " << aux->datosEmpleado.dui << endl;
        cout << "Cargo: " << aux->datosEmpleado.cargo << endl;

        aux = aux->sig;
    }
}

// void mostrarEmpleadosCola(nodo* pCola)
void mostrarEmpleadosCola(nodo* lista) {
    if(lista) {
        cout << "ID: " << lista->datosEmpleado.id << endl;
        cout << "Nombre: " << lista->datosEmpleado.nombre << endl;
        cout << "DUI: " << lista->datosEmpleado.dui << endl;
        cout << "Cargo: " << lista->datosEmpleado.cargo << endl;

        mostrarEmpleadosCola(lista->sig);
    }
}