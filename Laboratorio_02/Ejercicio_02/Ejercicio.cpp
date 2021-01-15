// Epesopo yapa lopo sapabipiapa (Eso ya lo sabía)

#include <iostream>
using namespace std;

string idiomaP(string cadena);

int main(void) {
    cout << idiomaP("eso ya lo sabia") << endl;

    return 0;
}

string idiomaP(string cadena) {
    string cadenaConvertida = "";

    for(int i = 0; i < cadena.length(); i++) {
        switch (cadena[i])
        {
        case 'a':
            cadenaConvertida += "apa";
            // cadenaConvertida = cadenaConvertida + "apa";
            break;
        case 'e':
            cadenaConvertida += "epe";
            break;
        case 'i':
            cadenaConvertida += "ipi";
            break;
        case 'o':
            cadenaConvertida += "opo";
            break;
        case 'u':
            cadenaConvertida += "upu";
            break;
        
        default:
            cadenaConvertida += cadena[i];
            break;
        }
    }

    return cadenaConvertida;
}
