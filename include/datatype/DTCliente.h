#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"
#include "DTCompra.h"
#include "DTDireccion.h"
#include "DTUsuario.h"

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class DTCliente : public DTUsuario {
    private:
        DTDireccion direccion;
    
    public:
        //DTCliente();
        DTCliente(string nickname, DTFecha fecha, DTDireccion direccion);
        //DTCliente(const DTCliente&);
        //~DTCliente();
        //DTDireccion getDireccion();
        //string getCiudad();
        //set<DTCompra> getCompras();
        string toString();
        //bool operator==(const DTCliente&) const;
        //bool operator<(const DTCliente&) const;  
         
};

#endif 