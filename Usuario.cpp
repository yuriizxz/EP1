#include <iostream>
#include <string>
#include "Usuario.h"
using namespace std;

Usuario::Usuario(int id, string nome, int maximo) : id(id), nome(nome), maximo(maximo), numeroRegistros(0)
{
    registros = new Registro *[maximo];
}
Usuario::~Usuario()
{
    for (int i = 0; i < numeroRegistros; i++)
    {
        delete registros[i];
    }
    delete[] registros;
}

string Usuario::getNome()
{
    return nome;
}
int Usuario::getId()
{
    return id;
}

bool Usuario::entrar(Data *d)
{
    if (numeroRegistros == 0)
    {
        numeroRegistros++;
        registros[numeroRegistros - 1] = new Registro(d, true, false);
        return true;
    }
    if (numeroRegistros >= maximo)
    {
        return false;
    }
    if (d->diferenca(registros[numeroRegistros - 1]->getData()) < 0)
    {
        return false;
    }
    if (registros[numeroRegistros - 1]->isEntrada() == true)
    {
        return false;
    }

    numeroRegistros++;
    registros[numeroRegistros - 1] = new Registro(d, true, false);

    return true;
}
bool Usuario::sair(Data *d)
{
    if (numeroRegistros == 0)
    {
        numeroRegistros++;
        registros[numeroRegistros - 1] = new Registro(d, false, false);
        return true;
    }
    if (numeroRegistros >= maximo)
    {
        return false;
    }
    if (d->diferenca(registros[numeroRegistros - 1]->getData()) < 0)
    {
        return false;
    }
    if (registros[numeroRegistros - 1]->isEntrada() == false)
    {
        return false;
    }

    numeroRegistros++;
    registros[numeroRegistros - 1] = new Registro(d, false, false);
    return true;
}

bool Usuario::registrarEntradaManual(Data *d)
{
    if (entrar(d))
    {
        registros[numeroRegistros - 1] = new Registro(d, true, true);
        return true;
    }
    else
    {
        return false;
    }
}
bool Usuario::registrarSaidaManual(Data *d)
{
    if (sair(d))
    {
        registros[numeroRegistros - 1] = new Registro(d, false, true);
        return true;
    }
    else
    {
        return false;
    }
}

int Usuario::getHorasTrabalhadas(int mes, int ano)
{
    float horas = 0;
    for (int i = 0; i < numeroRegistros - 1; i++)
    {
        if (registros[i]->isEntrada() == true)
        {
            if (registros[i]->getData()->getMes() == mes && registros[i]->getData()->getAno() == ano)
            {
        
                horas += registros[i + 1]->getData()->diferenca(registros[i]->getData());
            }
        }
    }
    int total = (horas / 3600);
    return total;
}

Registro **Usuario::getRegistros()
{
    return registros;
}
int Usuario::getQuantidade()
{
    return numeroRegistros;
}