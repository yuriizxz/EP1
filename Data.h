#include <ctime>
#ifndef DATA_H
#define DATA_H

class Data: public tm{
    private: 
    int hora = 0;
    int minuto = 0;
    int segundo = 0;
    int dia = 1;
    int mes = 0;
    int ano = 1900;
    tm* data = new tm;

    public:

    Data(int hora, int minuto, int segundo, int dia, int mes, int ano);
    virtual ~Data();

    int getHora();
    int getMinuto();
    int getSegundo();
    int getDia();
    int getMes();
    int getAno();

    int diferenca(Data* d);
    
};

#endif