#include "../../include/datatype/DTProductoCantidad.h"


using namespace std;

DTProductoCantidad::DTProductoCantidad(){}

DTProductoCantidad::DTProductoCantidad(DTProducto producto, unsigned int cantidad){
    this->producto = producto;
    this->cantidad = cantidad;
}

DTProductoCantidad::~DTProductoCantidad(){}

//getters
DTProducto DTProductoCantidad::getProducto(){
    return producto;
}

unsigned int DTProductoCantidad::getCantidad(){
    return cantidad;
}

//operadores
string DTProductoCantidad::toString(){
    return producto.toString() + ", Cantidad: " + to_string(cantidad);
}

bool DTProductoCantidad::operator==(const DTProductoCantidad& produC) const{
    return (producto == produC.producto) && (produC.cantidad == cantidad);
}

bool DTProductoCantidad::operator<(const DTProductoCantidad& produC) const{
    if(producto < produC.producto) return true;
    if(producto == produC.producto && cantidad < produC.cantidad) return true;
    return false;
}
