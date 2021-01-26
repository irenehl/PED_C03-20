/*
    Anita ha pensado en poner su primera tienda de artículos varios. Ella esta un poco perdida
    en cuanto al manejo de la tienda, es decir, es como administrar los productos, los precios, 
    los proveedores, etc. 

    Anita le ha solicitado su ayuda para llevar una administración efectiva de su tienda. Las
    acciones que Anita desea hacer son:

        * Administrar productos
        * Administrar proveedores
    
    En la administración de productos, lo que se espera que su programa sea capaz de realizar es:

        * Ingresar un nuevo producto 
        * Ver todos los productos disponibles (con su precio)
    
    En la administración de proveedores lo que se espera que su programa sea capaz de realizar es:
        * Agregar un proveedor
        * Ver todos los proveedores registrados
    
*/
#include <iostream>
using namespace std;

void menuPrincipal();
void menuAdminProd();
void menuAdminProv();
void ingresarProd(string arreglo[100]);
void mostrarProductos(string arreglo[100]);
void ingresarProv(string arreglo[100]);
void mostrarProveedores(string arreglo[100]);

int contadorProductos = 0, contadorProveedores = 0;

int main(void) {
    // Declaracion de variables
    int opcionPrincipal = 0, opcionProductos = 0, opcionProveedores = 0;

    // Declaracion de arreglos
    string productos[100], proveedores[100];

    do {
        menuPrincipal();
        cout << "Su opcion: "; cin >> opcionPrincipal;
        cin.ignore(1000, '\n'); cin.clear();

        switch (opcionPrincipal) {
            case 1:
                menuAdminProd();
                cout << "Su opcion: "; cin >> opcionProductos;
                cin.ignore(1000, '\n'); cin.clear();
                
                switch(opcionProductos) {
                    case 1:
                        ingresarProd(productos);
                        break;
                    case 2:
                        cout << "\n\tPRODUCTOS INGRESADOS" << endl;
                        mostrarProductos(productos);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                menuAdminProv();
                cout << "Su opcion: "; cin >> opcionProveedores;
                cin.ignore(1000, '\n'); cin.clear();
                
                switch(opcionProveedores) {
                    case 1:
                        ingresarProv(proveedores);
                        break;
                    case 2:
                        cout << "\n\tPROVEEDORES INGRESADOS" << endl;
                        mostrarProveedores(proveedores);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    } while(opcionPrincipal != 0);

    return 0;
}

void menuPrincipal() {
    cout << endl << "\tTIENDA DE ANITA" << endl;
    cout << "1. Administrar productos" << endl;
    cout << "2. Administrar proveedores" << endl;
    cout << "0. Salir " << endl;
}

void menuAdminProd() {
    cout << "\n\tADMINISTRANDO PRODUCTOS" << endl;
    cout << "1. Ingresar un nuevo producto" << endl;
    cout << "2. Ver todos los productos" << endl;
    cout << "0. Salir" << endl;
}

void menuAdminProv() {
    cout << "\n\tADMINISTRANDO PROVEEDORES" << endl;
    cout << "1. Agregar un proveedor" << endl;
    cout << "2. Ver todos los proveedores" << endl;
    cout << "0. Salir " << endl;
}

void ingresarProd(string arreglo[100]) {
    if(contadorProductos == 100) {
        cout << "Memoria llena" << endl;
        return;
    }

    string producto = "", precio = "";

    cout << "\nProducto: "; getline(cin, producto);
    cout << "Precio: "; getline(cin, precio);

    arreglo[contadorProductos] = producto + ", $" + precio;
    contadorProductos++;
    // contadorProductos += 1;
    // contadorProductos = contadorProductos + 1;
}

void mostrarProductos(string arreglo[100]) {
    for(int i = 0; i < contadorProductos; i++) {
        cout << arreglo[i] << endl;
    }
}

void ingresarProv(string arreglo[100]) {
    if(contadorProveedores == 100) {
        cout << "Memoria llena" << endl;
        return;
    }

    string proveedor = "", id = "";

    cout << "\nProveedor: "; getline(cin, proveedor);
    cout << "ID: "; getline(cin, id);

    arreglo[contadorProveedores] = proveedor + ", " + id;
    contadorProveedores++;
}

void mostrarProveedores(string arreglo[100]) {
    for(int i = 0; i < contadorProveedores; i++) {
        cout << arreglo[i] << endl;
    }
}


