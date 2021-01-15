#include <iostream>
#include <fstream>
using namespace std;

string encriptador(string cadena);
string desencriptador(string cadena);
void leerCadenaDes(string desencriptado, string encriptado);
void leerCadenaEnc(string encriptado);

int main(void) {
    leerCadenaDes("pruebaDesc.txt", "pruebaEnc.txt");
    leerCadenaEnc("pruebaEnc.txt");

    return 0;
}

// Crear una función que reciba un string y lo encripte en cable murciélago. La función
// deberá devolver este valor

string encriptador(string cadena) {
    for(int i = 0; i < cadena.length(); i++){
        switch (cadena[i])
        {
        case 'm':
        case 'M':
            cadena[i] = '0';
            break;
        case 'u':
        case 'U':
            cadena[i] = '1';
            break;
        case 'r':
        case 'R':
            cadena[i] = '2';
            break;
        case 'c':
        case 'C':
            cadena[i] = '3';
            break;
        case 'i':
        case 'I':
            cadena[i] = '4';
            break;
        case 'e':
        case 'E':
            cadena[i] = '5';
            break;
        case 'l':
        case 'L':
            cadena[i] = '6';
            break;
        case 'a':
        case 'A':
            cadena[i] = '7';
            break;
        case 'g':
        case 'G':
            cadena[i] = '8';
            break;
        case 'o':
        case 'O':
            cadena[i] = '9';
            break;
        
        default:
            break;
        }
    }

    return cadena;
}

// Crear una función que desencripte un string encriptado en clave murciélago. La
// función deberá devolver este valor

string desencriptador(string cadena) {
    for(int i = 0; i < cadena.length(); i++){
        switch (cadena[i])
        {
        case '0':
            cadena[i] = 'm';
            break;
        case '1':
            cadena[i] = 'u';
            break;
        case '2':
            cadena[i] = 'r';
            break;
        case '3':
            cadena[i] = 'c';
            break;
        case '4':
            cadena[i] = 'i';
            break;
        case '5':
            cadena[i] = 'e';
            break;
        case '6':
            cadena[i] = 'l';
            break;
        case '7':
            cadena[i] = 'a';
            break;
        case '8':
            cadena[i] = 'g';
            break;
        case '9':
            cadena[i] = 'o';
            break;
        default:
            break;
        }
    }

    return cadena;
}

// Crear una función que lea una cadena de un archivo e invoque a la función de
// encriptado, luego guarde la cadena encriptada en un nuevo archivo

void leerCadenaDes(string desencriptado, string encriptado) {
    string cadenaObtenida = ""; 

    ifstream archivoLectura;
    archivoLectura.open(desencriptado);

    // ifstream archivo(desencriptado)

    getline(archivoLectura, cadenaObtenida);

    cout << "Encriptando: " << cadenaObtenida << endl;

    // Se invoca a la primera funcion realizada
    cadenaObtenida = encriptador(cadenaObtenida);

    archivoLectura.close();

    ofstream archivoEscritura;
    archivoEscritura.open(encriptado);

    cout << "Encriptado: " << cadenaObtenida << endl;
    archivoEscritura << cadenaObtenida << "\n";

    archivoEscritura.close();
}

// Crear una función que lea una cadena de un archivo, la desencripte invocando a la
// función de desencriptado y la muestre en consola

void leerCadenaEnc(string encriptado) {
    string cadenaObtenida = "";

    ifstream archivoLectura;
    archivoLectura.open(encriptado);

    getline(archivoLectura, cadenaObtenida);

    cout << "Desencriptando: " << cadenaObtenida << endl;
    cadenaObtenida = desencriptador(cadenaObtenida);

    archivoLectura.close();

    cout << "Desencriptado: " << cadenaObtenida << endl;
}
