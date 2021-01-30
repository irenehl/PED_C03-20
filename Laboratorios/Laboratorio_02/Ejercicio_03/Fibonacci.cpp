#include <iostream>
using namespace std;

int fibonacci(int n);

int main(void) {
    int num = 0;

    cout << "Digite un numero: "; cin >> num;

    cout << "\nSucesion de Fibonacci " << endl;

    for(int i = 0; i < num; i++){
        cout << fibonacci(i) << " ";
    }

    return 0;
}

// 0,1,1,2,3,5,8,13,21,34…


int fibonacci(int n) {
    if(n == 0)
        return 0;
    
    if(n == 1)
        return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}