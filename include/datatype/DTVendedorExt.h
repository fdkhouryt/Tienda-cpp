#ifndef DTVENDEDOREXT_H
#define DTVENDEDOREXT_H

#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"
#include "DTPromocion.h"
#include "DTProducto.h"
#include "DTUsuario.h"
#include "DTProductoExt.h"

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class DTVendedorExt : public DTUsuario {
    private:
        string RUT;
        set<DTPromocion> promociones;
        set<DTProductoExt> productos;
    
    public:
        //DTVendedorExt();
        DTVendedorExt(string Nickname, DTFecha Fecha, string RUT, set<DTPromocion> Promociones, set<DTProductoExt> Productos);
        //DTVendedorExt(const DTVendedorExt&);
        //~DTVendedorExt();
        //string getRUT();
        //set<DTPromocion> getPromociones();
        //set<DTProductoExt> getProductos();
        string toString();
        //bool operator==(const DTVendedorExt&) const;
        //bool operator<(const DTVendedorExt&) const;   
        
};

#endif  