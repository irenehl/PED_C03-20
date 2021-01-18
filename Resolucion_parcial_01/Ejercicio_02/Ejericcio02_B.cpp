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
    if (n == 0)
        return 0;
    else 
        return sumatoria(n / 10) + n % 10;
}