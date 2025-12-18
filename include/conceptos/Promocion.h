#ifndef PROMOCION_H
#define PROMOCION_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include "../../include/datatype/DTFecha.h"
#include "../../include/datatype/DTPromocion.h"
#include "../../include/datatype/DTProductoCantidad.h"

#include "Promocion-Producto.h"

using namespace std;

class Vendedor;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class Promocion {
    private:
        string nombre;
        string descripcion;
        DTFecha fechaVencimiento;
        double descuento;
        map<int, PromocionProducto*> promoproductos; 
        //nombre del atributo ahora es promopodructo en vez de producto porque confunde//tiene que ser un map si o si, que la key sea el código del producto
        Vendedor* vendedor;

    public:
        Promocion(string nombre, string descripcion, DTFecha fechaVencimiento, double descuento, set<DTProductoCantidad> l1, map<int, Producto*> l2, Vendedor* vendedor);
        //~Promocion();
        DTFecha getFecha();

        string getNombre();
        DTPromocion getDTPromocion();
        bool alpicaA(set<DTProductoCantidad>);
};

#include "Vendedor.h"

#endif // PROMOCION
