#include "catraca.h"
#include <iostream>
#include <string>

using namespace std;

GerenciadorDeUsuario *g = new GerenciadorDeUsuario(10);
Catraca *catraca1 = new Catraca(g);
Catraca *catraca2 = new Catraca(g);
int registros = 10;

void Entrada();
void Saida();
void Registro(int *id, int *hora, int *minuto, int *segundo, int *dia, int *mes, int *ano);
void Manual();
void Cadastro();
void Relatorio();

int opcao;
void menu()
{

    do
    {
        cout << "Acesso ao predio" << endl;
        cout << "1) Entrada" << endl
             << "2) Saida" << endl
             << "3) Registro Manual" << endl
             << "4) Cadastro de usuario" << endl
             << "5) Relatorio" << endl
             << "0) Sair" << endl
             << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            Entrada();
        }
        if (opcao == 2)
        {
            Saida();
        }
        if (opcao == 3)
        {
            Manual();
        }

        if (opcao == 4)
        {
            Cadastro();
        }
        if ( opcao == 5)
        {
            Relatorio();
        }

    } while (opcao != 0);
}

void Entrada()
{
    int catraca;
    int id;
    int hora;
    int minuto;
    int segundo;
    int dia;
    int mes;
    int ano;

    cout << "Catraca: ";
    cin >> catraca;
    Registro(&id, &hora, &minuto, &segundo, &dia, &mes, &ano);
    Data *d = new Data(hora, minuto, segundo, dia, mes, ano);
    if (catraca1->entrar(id, d))
    {
        cout << "[Entrada] Catraca " << catraca << " abriu: id " << id << endl
             << endl;
    }
    else
    {
        cout << "[Entrada] Catraca " << catraca << " travada" << endl
             << endl;
    }
}

void Registro(int *id, int *hora, int *minuto, int *segundo, int *dia, int *mes, int *ano)
{
    cout << "Id: ";
    cin >> *id;
    cout << "Hora: ";
    cin >> *hora;
    cout << "Minuto: ";
    cin >> *minuto;
    cout << "Segundo: ";
    cin >> *segundo;
    cout << "Dia: ";
    cin >> *dia;
    cout << "Mes: ";
    cin >> *mes;
    cout << "Ano: ";
    cin >> *ano;
}

void Cadastro()
{
    int id;
    string nome;
    cout << "Id: ";
    cin >> id;
    cout << "Nome: ";
    cin >> nome;

    Usuario *u = new Usuario(id, nome, registros);
    if (g->adicionar(u))
    {
        cout << "Usuario cadastrado com sucesso" << endl
             << endl;
    }
    else
    {
        cout << "Erro ao cadastrar o usuario" << endl
             << endl;
    }
}
void Saida()
{
    int catraca;
    int id;
    int hora;
    int minuto;
    int segundo;
    int dia;
    int mes;
    int ano;

    cout << "Catraca: ";
    cin >> catraca;
    Registro(&id, &hora, &minuto, &segundo, &dia, &mes, &ano);
    Data *d = new Data(hora, minuto, segundo, dia, mes, ano);
    if (catraca1->sair(id, d))
    {
        cout << "[Saida] Catraca " << catraca << " abriu: id " << id << endl
             << endl;
    }
    else
    {
        cout << "[Saida] Catraca " << catraca << " travada" << endl
             << endl;
    }
}

void Manual()
{
    char c;
    int id;
    int hora;
    int minuto;
    int segundo;
    int dia;
    int mes;
    int ano;

    cout << "Entrada (e) ou Saida (s): ";
    cin >> c;
    Registro(&id, &hora, &minuto, &segundo, &dia, &mes, &ano);
    Data *d = new Data(hora, minuto, segundo, dia, mes, ano);

    if (c == 'e')
    {
        if (g->getUsuario(id) == nullptr)
        {
            cout << "Erro ao registrar entrada manual" << endl << endl;
        }
        else
        {
            if (g->getUsuario(id)->registrarEntradaManual(d))
            {
                cout << "Entrada manual registrada: id " << id << endl << endl;
            }
            else
            {
                cout << "Erro ao registrar entrada manual" << endl << endl;
            }
        }
    }
    if (c == 's')
    {
        if (g->getUsuario(id) == nullptr)
        {
            cout << "Erro ao registrar saida manual" << endl << endl;
        }
        else
        {
            if (g->getUsuario(id)->registrarSaidaManual(d))
            {
                cout << "Saida manual registrada: id " << id << endl << endl;
            }
            else
            {
                cout << "Erro ao registrar saida manual" << endl << endl;
            }
        }
    }
}

void Relatorio()
{
    int mes, ano;
    cout << "Mes: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;

    cout << "Relatorio de horas trabalhadas" << endl;
    for (int i = 0; i < g->getQuantidade(); i++)
    {
       cout << g->getUsuarios()[i]->getNome() << ": " << g->getUsuarios()[i]->getHorasTrabalhadas(mes, ano) << endl;
    }
    cout<< endl;
}