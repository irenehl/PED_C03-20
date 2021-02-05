#include <iostream>
using namespace std;

struct nodo {
    // Posicion en matriz (filas, columnas)
    int nFil, nCol;
    nodo *sigCol, *sigFil;

    // Tipo de dato contenido en tipoDato (solamente 1)
    // 1:caracter, 2:enero, 3:real, 4:cadena.
    int tipo; 

    union tipoDato{
        char car;
        int entero;
        float real;
        char cadena[11];
    } dato;
};

void iniHojaCalc(nodo **, int, int);
void insNodo(nodo **, int, int);

int main(void) {
    // Inicializacion de puntero de hoja de calculo
    nodo *pHojaCalc = NULL, *aux;

    // Cantidad de filas y columnas, y variables auxiliares
    int totFilas, totColumnas, fil, col;
    
    // Inicialización de la estructura base de una hoja de cálculo:
    cout << "Para inicializar la hoja de calculo proporcione la" << endl;
    cout << "cantidad de filas y columnas que contendrá:" << endl;
    cout << "Total de filas: "; cin >> totFilas;
    cout << "Total de columnas: "; cin >> totColumnas;
    
    // Inicializar hoja dee calculo con n filas y m columnas
    iniHojaCalc(&pHojaCalc, totFilas, totColumnas);

    // Cantidad de nodos base
    cout << "Cantidad de nodos de la fila base:\n";
    
    // Auxiliar para impresion de formato en columnas
    aux = pHojaCalc->sigCol;

    // Impresion de formato
    while(aux->nCol != 0) {
        cout << aux->nCol << endl;
        aux = aux->sigCol;
    }

    cout << endl << endl;
    
    cout << "Cantidad de nodos de la columna base:" << endl;

    // Auxiliar ahora imprime formato de columnas
    aux = pHojaCalc->sigFil;

    while(aux->nFil != 0) {
        cout << aux->nFil << endl;
        aux = aux->sigFil;
    }

    cout << endl << endl;
    cin.get();
    
    // Inserción de un nodo en la hoja de cálculo:
    cout << "Inserción de un nodo en la hoja de cálculo:" << endl;;
    cout << "Digite el número de fila y el número de coumna" << endl;;
    cout << "en que se insertará el nuevo nodo:" << endl;;

    cout << "Fila: "; cin >> fil;
    
    cout << "Columna: "; cin >> col;

    // Funcion de insercion de nodo
    insNodo(&pHojaCalc, fil, col);

    cin.get();

    return 0;
}

// Inicializacion de hoja de calculo
void iniHojaCalc(nodo **hojaCalculo, int totFil, int totCol) {
    // Variables a usar
    nodo *aux;
    int i;
    
    // Creacion del nodo base de la hoja electronica:
    (*hojaCalculo) = new nodo;

    // Inicializar en 0 filas y columnas
    (*hojaCalculo)->nFil = (*hojaCalculo)->nCol = 0;

    // Referencia circular
    (*hojaCalculo)->sigCol = (*hojaCalculo)->sigFil = *hojaCalculo;

    // Creacion de la fila base (nodos base de columnas):
    aux = (*hojaCalculo);
    for(i = 1; i <= totCol; i++) {
        // Creacion de elemento siguiente (actual ya existe)
        aux->sigCol = new nodo;
        
        // Cambio de posicion
        aux = aux->sigCol;
        
        // Al crear columna nueva, entonces nCol sera i (para asignar los numeros correctamente)
        aux->nCol = i;
        aux->nFil = 0;

        // Referencias circulares
        aux->sigFil = aux; 
        aux->sigCol = *hojaCalculo;
    }


    // Creacion de la columna base (nodos base de filas):
    aux = (*hojaCalculo);
    for(i = 1; i <= totFil; i++) {
        // Creacion de elemento siguiente (actual ya existe)
        aux->sigFil = new nodo;

        // Cambio de posicion
        aux = aux->sigFil;

        // Al crear fila nueva, entonces nFil sera i (para asignar los numeros correctamente)
        aux->nFil = i;
        aux->nCol = 0;

        // Referencias circulares
        aux->sigCol = aux;
        aux->sigFil = *hojaCalculo;
    }
}

void insNodo(nodo **hojaCalculo, int fil, int col) {
    // Creación de un nuevo nodo:

    nodo *nvoNodo = new nodo;
    int tipo;
    char aux;

    // Se solicita el tipo del elemento a insertar para ver que asignarle a dato
    cout << "1. Caracter\n 2. Entero\n 3. Real\n 4. Cadena"; cin >> tipo;

    switch(tipo) {
        // Caracter
        case 1:
            cout << "Digite un caracter para almacenar en el nodo: ";
            cin >> nvoNodo->dato.car;
            break;
        // Entero
        case 2:
            cout << "Digite un número entero para almacenar en el nodo: ";
            cin >> nvoNodo->dato.entero;
            break;
        // Real
        case 3:
            cout << "Digite un número real para almacenar en el nodo: ";
            cin >> nvoNodo->dato.real;
            break;
        // Cadena
        case 4:
            cout << "Digite una cadena para almacenar en el nodo: ";
            // Al ser un arreglo, debe meterse caracter por caracter 
            // C++ detecta cuando se espera un caracter, si en consola se escribe HOLA, entonces hacer cada lentra un input
            // siendo en i = 0 -> H, i = 1 -> O, i = 2 -> L, i = 3 -> A
            for(int i = 0; i < 11; i++) {
                cin >> aux;
                nvoNodo->dato.cadena[i] = aux;
            }
            break;
    }

    // Almacenar la posicion de insercion
    nvoNodo->nFil = fil;
    nvoNodo->nCol = col;
    
    // Declarando punteros a la fila y col siguiente
    nodo *pFil = (*hojaCalculo)->sigFil;
    nodo *pCol = (*hojaCalculo)->sigCol;

    // Localización de la posición sobre la fila. El puntero que salta sobre la fila
    // queda apuntando al nodo anterior.
    for(int i = 1; i <= fil; i++)
        pFil = pFil->sigFil;

    // Localización de la posición sobre la columna. El puntero que salta
    // sobre la columna queda apuntando al nodo anterior.
    for(int i = 1; i <= col; i++)
        pCol = pCol->sigCol;
    
    // Enlazar el nuevo nodo a la estructura.
    nvoNodo->sigCol = pFil->sigCol;
    pFil->sigCol = nvoNodo;

    nvoNodo->sigFil = pCol->sigFil;
    pCol->sigFil = nvoNodo;
}