#include "GerenciadorDeUsuario.h"

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo): maximo (maximo)
{
    usuarios = new Usuario*[maximo];
}

GerenciadorDeUsuario::~GerenciadorDeUsuario(){
    for (int i = 0 ; i < maximo; i++)
    {
        delete usuarios[i];
    }

    delete[] usuarios;
}

bool GerenciadorDeUsuario::adicionar( Usuario* u)
{
    if ( quantidade >= maximo){
        return false;
    }
    for(int i = 0; i < quantidade; i++)
    {
        if ( usuarios[i]->getId() == u->getId() ){
            return false;
        }
    }
    quantidade++;
    usuarios[quantidade - 1] = u;
}

Usuario* GerenciadorDeUsuario::getUsuario(int id)
{
    for (int i = 0; i < quantidade; i++)
    {
        if ( usuarios[i]->getId() == id)
        {
            return usuarios[i];
        }
    }
return nullptr;
}

Usuario** GerenciadorDeUsuario::getUsuarios()
{
    return usuarios;
}

int GerenciadorDeUsuario::getQuantidade()
{
    return quantidade;
}