// Elabore un programa que lea una cadena desde teclado, invierta su contenido y muestre el
// resultado en pantalla. Por ejemplo:

#include <iostream>
using namespace std;

string invertirCadena(string cadena);
string invertirCadenaRecursivo(string cadena);

int main(void) {
    string cadena = "";

    cout << "Digite una oracion: "; cin >> cadena;
    // cout << "Cadena invertida: " << invertirCadena(cadena) << endl;
    cout << "Cadena invertida: " << invertirCadenaRecursivo(cadena) << endl;

    return 0;
}

string invertirCadena(string cadena) {
    string cadenaInvertida = "";

    for(int i = cadena.length(); i >=0; i--){
        cadenaInvertida += cadena[i];
    }

    return cadenaInvertida;
}

string invertirCadenaRecursivo(string cadena) {
    if(cadena.length() < 1)
        return cadena;
    else
        return invertirCadena(cadena.substr(1)) + cadena.at(0);
}