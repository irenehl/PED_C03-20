#include <iostream>
using namespace std;

int sumatoria(int n);

int main(void) {
    int n = 0;

    cout << "Digite un numero: "; cin >> n;
    cout << "Sumatoria de digitos: " << sumatoria(n) << endl;

    return 0;
}

int sumatoria(int n) {
    int suma = 0, digito = 0;

    while(n != 0) {
        digito = n % 10;
        n /= 10;
        suma += digito;
    }

    return suma;
}