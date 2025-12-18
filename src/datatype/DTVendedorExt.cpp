#include "../../include/datatype/DTVendedorExt.h"

DTVendedorExt::DTVendedorExt(string nickname, DTFecha fecha, string RUT, set<DTPromocion> promociones, set<DTProductoExt> productos)
    :DTUsuario(nickname, fecha){
        this->RUT = RUT;
        this->productos = productos;
        this->promociones = promociones;
}

string DTVendedorExt::toString(){
    string aRet = "Nickname: " + getNickname() + "\nFecha: [" + getFecha().toString() + "]";
    aRet += "\n RUT:" + this->RUT;
    aRet += "\n\n --PRODUCTOS--";
    for(DTProductoExt producto: this->productos){
        aRet += "\n " + producto.toString();
    }
    aRet += "\n\n --PROMOCIONES--";
    for (DTPromocion promo:this->promociones){
        aRet += "\n " + promo.toString();
    }
    
    return aRet;
}