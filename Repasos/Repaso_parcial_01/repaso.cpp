/* 
    * Mediante uso de struct represente un monomio
    * Solicite el tamaño del arreglo y llenelo con una función aparte de manera recursiva
    * Cree una función recursiva que se encarge de hacer la suma de los monomios
    * Mediante otra función, guarde ese resultado en un archivo de texto
*/

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct monomio {
    double coef, exp;
};

void llenarArregloRecursivo(monomio* arreglo, int tam, int pos); 
double calcularExpresion(monomio* arreglo, int tam, int pos);
void guardarResultado(double n);

int main(void){
    int n = 0; 
    cout << "Tam: "; cin >> n;

    monomio expresion[n];

    llenarArregloRecursivo(expresion, n, 0);

    for(int i = 0; i < n; i++) {
        cout << expresion[i].coef << "^" << expresion[i].exp << "\t";
    }

    guardarResultado(calcularExpresion(expresion, n, 0));

    return 0;
}

void llenarArregloRecursivo(monomio* arreglo, int tam, int pos) {
    if(pos == tam)
        return;
    else {
        double coef = 0, exp = 0;

        cout << "Coef: "; cin >> coef;
        cout << "Expo: "; cin >> exp;

        arreglo[pos].coef = coef;
        arreglo[pos].exp = exp;

        llenarArregloRecursivo(arreglo, tam, pos + 1);
    }
}

double calcularExpresion(monomio* arreglo, int tam, int pos) {
    if(pos == tam)
        return 0;
    else
        return pow(arreglo[pos].coef, arreglo[pos].exp) + calcularExpresion(arreglo, tam, pos + 1);
}

void guardarResultado(double n) {
    ofstream archivo("resultado.txt");
    archivo << n;
    archivo.close();
}