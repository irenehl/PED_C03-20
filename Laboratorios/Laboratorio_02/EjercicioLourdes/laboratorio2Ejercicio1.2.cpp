#include <iostream>
#include <string>
#include <cstring>

using namespace std;
using std::string;
int main()
{

    /*
   Código Murciélago
   
*/
    char clave[10] = {'m', 'u', 'r', 'c', 'i', 'e', 'l', 'a', 'g', 'o'};
    char claveIndex[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    //char buffer [10];
    string palabra;
    cout << "Ingrese la palabra para cifrar:  ";
    cin >> palabra;
    string cifrado;

    //CIFRANDO LA PALABRA
    for (int i = 0; i < palabra.length(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (palabra[i] == clave[j])
            {
                palabra[i] = claveIndex[j];
                /* char *intString = _itoa(j, buffer, 10);
                string  str = string(intString);*/
            }
        }
    }
    cout << "La palabra cifrada es:  " << palabra << endl;
    cout << "Desifrando la palabra" << endl;

    //DESIFRANDO LA PALABRA
    for (int i = 0; i < palabra.length(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (palabra[i] == claveIndex[j])
            {
                palabra[i] = clave[j];
            }
        }
    }
    cout << "La palabra descifrada es:  " << palabra << endl;

    return 0;
}