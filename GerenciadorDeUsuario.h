#include "Usuario.h"
#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIDAORDEUSUARIO_H

class GerenciadorDeUsuario
{
private:
    int quantidade = 0;
    int maximo = 0;
    Usuario** usuarios;
public:
    GerenciadorDeUsuario(int maximo);
    virtual ~GerenciadorDeUsuario();

    bool adicionar(Usuario* u);
    Usuario* getUsuario(int id);
    Usuario** getUsuarios();
    int getQuantidade();
};

#endif