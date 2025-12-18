#ifndef DTCOMPRA_H
#define DTCOMPRA_H

#include <iostream>
#include <string>
#include <set>
#include "DTProductoCantidad.h"
#include "DTCliente.h"
#include "DTFecha.h"
#include "DTPromocion.h"

using namespace std;

class DTCompra {
private:
    //int idCompra;
    //en el dcd y la mayorias de casos de uso no lleva ningun nombre, si se necesita con nombre para algun caso crear otro dt
    //El nombre del cliente tampoco deberia de necesitarse en realizarcompra ya que antes, ya se selecciono un cliente en particular
    float monto;
    DTFecha fecha;
    set<DTProductoCantidad> productos;
    set<DTPromocion> promociones;

public:
    DTCompra();
    DTCompra(DTFecha fecha, set<DTProductoCantidad> productos, float, set<DTPromocion>);
    virtual ~DTCompra();
    //getters
    DTFecha getFecha();
    set<DTProductoCantidad> getProductos();
    float getMonto();
    //operadores
    string toString();
    bool operator==(const DTCompra& compra) const;
    bool operator<(const DTCompra& compra) const;
};

#endif // DTCOMPRA_H

