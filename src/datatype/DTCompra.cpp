#include "../../include/datatype/DTCompra.h"


using namespace std;

DTCompra::DTCompra() {}
DTCompra::DTCompra(DTFecha fecha, set<DTProductoCantidad> productos, float monto, set<DTPromocion> promociones) {
    this->monto = monto;
    this->fecha = fecha;
    this->productos = productos;
    this->promociones = promociones;
}
DTCompra::~DTCompra() {}
//getters
DTFecha DTCompra::getFecha(){
    return fecha;
}

set<DTProductoCantidad> DTCompra::getProductos(){
    return productos;
}

float DTCompra::getMonto(){
    return monto;
}

//operadores
bool DTCompra::operator==(const DTCompra& compra) const {
    return (this->fecha == compra.fecha) && (this->productos == compra.productos);
}

bool DTCompra::operator<(const DTCompra& compra) const {
    if (this->fecha < compra.fecha) return true;
    if (this->fecha == compra.fecha) return true;
    if ((this->fecha == compra.fecha) && (this->productos < compra.productos)) return true;
    return false;
}

string DTCompra::toString() {
    string resultado = "\nFecha: " + fecha.toString() + "\nMonto :" + to_string(monto) +"\nProductos: \n";
    int i = 0;
    int numProductos = productos.size();
    for (DTProductoCantidad produ : productos) {
        resultado += "      " + produ.toString();
        if (i < numProductos - 1) {
            resultado += "\n";
        }
        ++i;
    }
    resultado += "\n";
    resultado += "Promociones: \n";
    i = 0;
    for (DTPromocion promo : promociones) {
        resultado += "      " + promo.getNombre() + "\n";
        for(DTProductoCantidad produ: promo.getProductos())
            resultado += "          " + produ.toString() + "\n";
        i++;
    }
    resultado += "\n";
    return resultado;
}
