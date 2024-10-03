#include "Registro.h"
#include <string>
#ifndef USUARIO_H
#define USUARIO_H 
using namespace std;

class Usuario
{
private:
    int id;
    string nome;
    int maximo;
    int numeroRegistros;
    Registro** registros;

public:
    Usuario(int id, string nome, int maximo);
    virtual ~Usuario();

    string getNome();
    int getId();

    bool entrar(Data *d);
    bool sair(Data *d);

    bool registrarEntradaManual(Data *d);
    bool registrarSaidaManual(Data *d);

    int getHorasTrabalhadas(int mes, int ano);
    Registro **getRegistros();
    int getQuantidade();
};

#endif