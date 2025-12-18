#ifndef DTCOMPRANOENVIADA_H
#define DTCOMPRANOENVIADA_H

#include <iostream>
#include <string>
#include "DTFecha.h"
#include "DTUsuario.h"

using namespace std;

class DTCompraNoEnviada{
    private:
        DTFecha fechaCompra;
        string nombreCliente;
        int id;

    public:
        DTCompraNoEnviada();
        DTCompraNoEnviada(int, string, DTFecha);
        ~DTCompraNoEnviada();
        //getters
        string getNickname();
        DTFecha getFecha();
        int getId();
        string getNickname() const;
        DTFecha getFecha() const;
        int getId() const;
        string toString();
        //operators
        bool operator==(const DTCompraNoEnviada&) const;
        bool operator<(const DTCompraNoEnviada&) const;   
};

#endif // DTCOMPRAPRODUCTO_H
