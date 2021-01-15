#include <iostream>
using namespace std;

/* 
Se ha tomado la temperatura en distintos puntos de una placa metálica.
Elabore una función que introduzca en un arreglo los datos correspondientes
a cada una de las temperaturas y sus coordenadas. Cada casilla del arreglo
debe contener los datos sobre la temperatura y sus coordenadas. El arreglo
se declara en la función main y se pasa como argumento. Los tipos
estructurados a utilizar son: struct coordenadas y struct datosTemp son:
*/

struct coordinate {
    int x, y;
};

struct dataTemp {
    float temp;
    struct coordinate point;
};

void leerTemperatura(struct dataTemp *data, int n);
void mostrarTemperatura(struct dataTemp *data, int n);
float calculateAverage(struct dataTemp *data, int n);
void maxTemperature(struct dataTemp *data, int n);
void minTemperature(struct dataTemp *data, int n);

/*
    Otra forma de hacerlo: 
    struct data{
        int x, y;
        float temp;
    }
*/

int main(void) {
    int numData = 0;
    dataTemp temperatures[50];

    cout << "Cuantos datos de temperatura desea ingresar? "; cin >> numData;
    cout << "\nLea los valores de temperatura de la placa " << endl;
    leerTemperatura(temperatures, numData);

    cout << "\tLos valores del arreglo son: " << endl;
    mostrarTemperatura(temperatures, numData);

    cout << "\tPromdio de temperaturas " << endl;
    cout << "Prom: " << calculateAverage(temperatures, numData);

    cout << "\n\tMayor temperatura" << endl;
    maxTemperature(temperatures, numData);

    cout << "\n\tMenor temperatura" << endl;
    minTemperature(temperatures, numData);

    return 0;
}

void leerTemperatura(struct dataTemp *data, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Introduzca x: "; cin >> (data + i)->point.x;
        cout << "Introduzca y: "; cin >> (data + i)->point.y;
        cout << "Introduzca temperatura: "; cin >> (data + i)->temp;
        cout << endl;
    }
}

/*
    Incorpore una función que muestre los datos contenidos en el arreglo: cada coordenada y su
    temperatura. 
*/

void mostrarTemperatura(struct dataTemp *data, int n) {
    for(int i = 0; i < n; i++) {
        cout << "x: " << (data + i)->point.x << endl;
        cout << "y: " << (data + i)->point.y << endl;
        cout << "Temp: " << (data + i)->temp << endl;
        cout << endl;
    }
}

/*
    Elabore una función que calcule el promedio de las temperaturas medidas en la placa metalica
*/

float calculateAverage(struct dataTemp *data, int n) {
    float temps, average = 0;

    for(int i = 0; i < n; i++) {
        temps += (data + i)->temp;
    }

    average = temps / n;

    return average;
}

/*
    Elabore también una función que busque la coordenada en la que se midió la mayor temperatura. 
    Despliegue la coordenada y el valor de temperatura medido.
*/

void maxTemperature(struct dataTemp *data, int n) {
    int aux = 0, coordinateX = 0, coordinateY = 0;
    float max = data->temp;

    for(int i = 0; i < n; i++) {
        if((data + i)->temp > max) {
            max = (data + i)->temp;
            aux = i;
        }

        coordinateX = (data + aux)->point.x;
        coordinateY = (data + aux)->point.y;
    }

    cout << "Temp: " << max << "\nCoordenadas: " << coordinateX << "," 
    << coordinateY; 
}

/* 
    Construya una función que busque la coordenada en la que se midió la menor temperatura. Despliegue
    la coordenada y el valor de temperatura medido.
*/

void minTemperature(struct dataTemp *data, int n) {
    int aux = 0, coordinateX = 0, coordinateY = 0;
    float min = data->temp;

    for(int i = 0; i < n; i++) {
        if((data + i)->temp < min) {
            min = (data + i)->temp;
            aux = i;
        }

        coordinateX = (data + aux)->point.x;
        coordinateY = (data + aux)->point.y;
    }

    cout << "Temp: " << min << "\nCoordenadas: " << coordinateX << "," 
    << coordinateY << endl; 
}