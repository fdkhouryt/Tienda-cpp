#ifndef PROMOCIONPRODUCTO_H
#define PROMOCIONPRODUCTO_H

#include <iostream>
#include <string>
#include <set>
#include "../../include/datatype/DTFecha.h"
#include "../../include/datatype/DTProductoCantidad.h"

using namespace std;

class Promocion;
class Producto;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class PromocionProducto {
    private:
        unsigned int cantidadMinima;
        Producto* producto;
        Promocion* promocion;

    public:
        PromocionProducto(Promocion* p ,DTProductoCantidad dtprodu, Producto* producto);
        //~PromocionProducto();

        //getters
        Producto* getProducto();
        unsigned int getCantidad();

        //operadores
        //bool operator==(const PromocionProducto&) const;
        //bool operator<(const PromocionProducto&) const;
};

#include "Promocion.h"
#include "Producto.h"

#endif // PROMOCIONPRODUCTO_H