#include "../../include/datatype/DTClienteExt.h"

DTClienteExt::DTClienteExt(string nickname, DTFecha fecha, DTDireccion direccion, set<DTCompra> compras)
    :DTUsuario(nickname, fecha)
{
    this->direccion = direccion;
    this->compras = compras;
}

string DTClienteExt::toString(){
    string aRet = "Nickname: " + getNickname() + "\nFecha: [" + getFecha().toString() + "]";
    aRet += "\n " + direccion.toString();
    aRet += "\n\n --COMPRAS--";
    for(DTCompra compra: compras){
        aRet += "\n " + compra.toString();
    }
    return aRet;
}