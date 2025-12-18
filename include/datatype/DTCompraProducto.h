#ifndef DTCOMPRAPRODUCTO_H
#define DTCOMPRAPRODUCTO_H

#include <iostream>
#include <string>
#include "DTFecha.h"
#include "DTUsuario.h"

using namespace std;

class DTCompraProducto{
    private:
        DTFecha fechaCompra;
        string nombreCliente;

    public:
        DTCompraProducto();
        DTCompraProducto(string, DTFecha);
        ~DTCompraProducto();
        //getters
        string getNickname();
        DTFecha getFecha();
        string toString();
        //operators
        bool operator==(const DTCompraProducto&) const;
        bool operator<(const DTCompraProducto&) const;   
};

#endif // DTCOMPRAPRODUCTO_H
