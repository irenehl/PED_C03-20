// El paso por valor se refiere a que se pasa una copia del valor del parámetro desde la función/método cliente. Al ser una copia, los cambios realizados directamente en la función/método sobre el valor del parámetro no serán reflejados al terminar la ejecución de la función/método.

// El paso por referencia se refiere a que se pasa el mismo valor del parámetro desde la función/método cliente. Al ser el mismo valor, los cambios realizados directamente en la función/método sobre el valor del parámetro serán reflejados al terminar la ejecución de la función/método.

#include <iostream>
using namespace std;

int pasarPorValor(int n);
void pasarPorReferencia(int *n);

int main(void) {
    int n = 10;

    pasarPorValor(n);
    cout << "Paso por valor: " << n << endl;

    pasarPorReferencia(&n);
    cout << "Paso por referencia: " << n << endl;

    return 0;
}

int pasarPorValor(int n) {
    return n = 50;
}

void pasarPorReferencia(int *n) {
    *n = -10;
}