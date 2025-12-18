#ifndef DTUSUARIO_CPP
#define DTUSUARIO_CPP

#include "../../include/datatype/DTUsuario.h"
#include <iostream>
#include <string>

using namespace std;

DTUsuario::DTUsuario(){}

DTUsuario::DTUsuario(string nickname, DTFecha fecha){
    this->fecha = fecha;
    this->nickname = nickname;
}

DTUsuario::~DTUsuario(){}

//getters
string DTUsuario::getNickname(){
    return this->nickname;
}

DTFecha DTUsuario::getFecha(){
    return this->fecha;
}
/*
string DTUsuario::toString(){
    return "Nickname: " + nickname + ", " + "Fecha: [" + fecha.toString() + "]";
}
*/

bool DTUsuario::operator==(const DTUsuario& usu) const {
    return (this->nickname == nickname);
}

bool DTUsuario::operator<(const DTUsuario& usu) const {
    if (this->fecha < usu.fecha) return true;
    if (this->nickname < usu.nickname) return true;
    return false;
}

#endif

