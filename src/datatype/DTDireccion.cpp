#include "../../include/datatype/DTDireccion.h"


DTDireccion::DTDireccion(){}
DTDireccion::DTDireccion(string calle, string ciudad, int numero){
    this->calle = calle;
    this->ciudad = ciudad;
    this->numero = numero;
}

string DTDireccion::toString(){
    return "Calle: " + calle + ", " + "Cuidad: " + ciudad + ", " + "Número: " + to_string(numero);
}


