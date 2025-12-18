#include "../../include/datatype/DTProducto.h"


using namespace std;

DTProducto::DTProducto(){};

DTProducto::DTProducto(int codigo, string nombre, float precio){
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
}

DTProducto::~DTProducto(){};

//Getters
int DTProducto::getCodigo(){
    return this->codigo;
}

string DTProducto::getNombre(){
    return this->nombre;
}

float DTProducto::getPrecio(){
    return precio;
}

//Operadores
string DTProducto::toString(){
    return "Código: " + to_string(codigo) + ", Nombre: " + nombre + ", Precio: " + to_string(precio);
}
bool DTProducto::operator==(const DTProducto& produ) const {
    return (this->codigo == produ.codigo);
}
bool DTProducto::operator<(const DTProducto& produ) const{
    return (this->codigo < produ.codigo);
}