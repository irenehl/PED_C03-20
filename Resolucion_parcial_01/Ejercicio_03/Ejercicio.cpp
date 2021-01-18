#include <iostream>
#include <fstream>
using namespace std;

int calculo(int n);
void guardarArchivo(int suma, int n);

int main(void) {
    int cantidad = 0;

    cout << "Cantidad de num a digitar: "; cin >> cantidad;

    guardarArchivo(calculo(cantidad), cantidad);

    return 0;
}

int calculo(int n) {
    int sumatoria = 0, num = 0;
    float prom = 0;

    for(int i = 0; i < n; i++){
        cout << "Num " << (i + 1) << ": "; cin >> num;
        sumatoria += num;
    }

    return sumatoria; 
}

void guardarArchivo(int suma, int n) {
    float prom = 0;

    prom = suma / n;

    ofstream archivo("resultado.txt");
    archivo << suma << "\n" << prom;
    archivo.close();
}

