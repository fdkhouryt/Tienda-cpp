#ifndef DTCLIENTEEXT_H
#define DTCLIENTEEXT_H

#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"
#include "DTCompra.h"
#include "DTDireccion.h"
#include "DTUsuario.h"

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class DTClienteExt : public DTUsuario {
    private:
        DTDireccion direccion;
        set<DTCompra> compras;
    
    public:
        //DTClienteExt();
        DTClienteExt(string nickname, DTFecha fecha, DTDireccion direccion, set<DTCompra> compras);
       // DTClienteExt(const DTClienteExt&);
        //~DTClienteExt();
        //DTDireccion getDireccion();
        //string getCiudad();
        //set<DTCompra> getCompras();
        string toString();
        //bool operator==(const DTClienteExt&) const;
        //bool operator<(const DTClienteExt&) const;  
         
};

#endif 