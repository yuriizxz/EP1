#include "Data.h"

Data::Data(int hora, int minuto, int segundo, int dia, int mes, int ano):
    hora (hora), minuto (minuto), segundo (segundo), dia (dia), mes (mes), ano (ano){
    data->tm_hour = hora;
    data->tm_min = minuto;
    data->tm_sec = segundo;
    data->tm_isdst = 0;
    data->tm_mday = dia;
    data->tm_mon = mes - 1;
    data->tm_year = ano - 1900;
    
    }
Data::~Data(){
}

int Data::getHora(){
    return hora;
}

int Data::getMinuto(){
    return minuto;
}

int Data::getSegundo(){
    return segundo;
}

int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}

int Data::diferenca(Data* d){
    time_t t1 = mktime(data);
    time_t t2 = mktime(d->data);
    int diferenca = (int) difftime(t1, t2);
    return diferenca;

}