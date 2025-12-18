#include "../../include/datatype/DTFecha.h"

using namespace std;

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

DTFecha::DTFecha(){}

int DTFecha::getDia()const{
    return this->dia;
}

int DTFecha::getMes()const{
    return this->mes;
}

int DTFecha::getAnio()const{
    return this->anio;
}

DTFecha::DTFecha(const DTFecha& fecha){
    this->dia = fecha.dia;
    this->mes = fecha.mes;
    this->anio = fecha.anio;

}

DTFecha::~DTFecha(){}

bool DTFecha::operator==(const DTFecha& fecha)const{
    return (this->dia == fecha.dia) && (this->mes == fecha.mes) && (this->anio == fecha.anio);
}

bool DTFecha::operator<(const DTFecha& fecha)const{
    return ((this->anio < fecha.anio))||
    ((this->anio == fecha.anio) && (this->mes < fecha.mes))||
    ((this->anio == fecha.anio) && (this->mes == fecha.mes) && (this->dia < fecha.dia));
}

bool DTFecha::operator!=(const DTFecha& fecha)const{
    return !(this->operator== (fecha));
}

bool DTFecha::operator>(const DTFecha& fecha)const{
    return ((this->operator!= (fecha)) && !(this->operator<(fecha)));
}

bool DTFecha::operator<=(const DTFecha& fecha)const{
    return (this->operator== (fecha)) || (this->operator<(fecha));
}

bool DTFecha::operator>=(const DTFecha& fecha)const{
    return (this->operator== (fecha)) || (this->operator>(fecha));
}

ostream &operator<<(ostream& x, DTFecha fecha){
    x << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << endl;
    return x;
}

string DTFecha::toString()const{
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}