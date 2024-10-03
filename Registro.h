#include "Data.h"
#ifndef REGSITRO_H
#define REGISTRO_H

class Registro {
    private:
    Data* data;
    bool manual = false;
    bool entrada = false;
    
    public:
    Registro(Data* d, bool entrada, bool manual);
    virtual ~Registro();

    Data* getData();
    bool isEntrada();
    bool isManual();

    void imprimir();
};
#endif