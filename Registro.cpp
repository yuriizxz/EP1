#include "Registro.h"
#include <iostream>
#include <string>
using namespace std;

Registro::Registro(Data* d, bool entrada, bool manual) :
    data (d), entrada (entrada), manual (manual){};


Registro::~Registro(){
    data->~Data();
}
Data* Registro::getData(){
    return data;
}

bool Registro::isEntrada(){
    return entrada;
}

bool Registro::isManual(){
    return manual;
}

void Registro::imprimir(){
    time_t t1 = mktime(data);
    cout << "data: " << t1 <<endl;
    cout << "Entrada: " << entrada << endl;
    cout << "Manual: " << manual << endl;

}
