#include "../../include/datatype/DTCliente.h"

DTCliente::DTCliente(string nickname, DTFecha fecha, DTDireccion direccion) : DTUsuario(nickname, fecha){
    this->direccion = direccion;
}

string DTCliente::toString(){
    string aRet = "Nickname: " + getNickname() + "\nFecha: " + getFecha().toString() + "\nDirección: [";
    aRet += direccion.toString();
    aRet += "]";
    return aRet;
}