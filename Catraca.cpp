#include "Catraca.h"

Catraca::Catraca(GerenciadorDeUsuario* g): g (g)
{}

Catraca::~Catraca()
{}

bool Catraca::entrar(int id, Data* d)
{
    if ( g->getUsuario(id) != nullptr)
    {
        return g->getUsuario(id)->entrar(d);
    }
    else{
        return false;
    }
}

bool Catraca::sair(int id, Data* d)
{
    if ( g->getUsuario(id) != nullptr)
    {
        return g->getUsuario(id)->sair(d);
    }
    else{
        return false;
    }
}