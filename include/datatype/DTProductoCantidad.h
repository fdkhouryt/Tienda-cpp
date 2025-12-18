#ifndef DTPRODUCTOCANTIDAD_H
#define DTPRODUCTOCANTIDAD_H


#include <iostream>
#include <string>
#include "DTProducto.h"

using namespace std;

class DTProductoCantidad {
private:
    DTProducto producto;
    unsigned int cantidad;
    
public:
    DTProductoCantidad();
    DTProductoCantidad(DTProducto producto, unsigned int cantidad);
    ~DTProductoCantidad();

    //Getters
    DTProducto getProducto();
    unsigned int getCantidad();
    //operadores
    string toString();
    bool operator==(const DTProductoCantidad&) const;
    bool operator<(const DTProductoCantidad&) const;    
};

#endif // DTPRODUCTOCANTIDAD_H
