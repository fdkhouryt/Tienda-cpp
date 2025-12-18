#ifndef DTPROMOCION_H
#define DTPROMOCION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTProductoCantidad.h"
#include "DTVendedor.h"

using namespace std;

class DTPromocion {
private:
    string nombre;
    string descripcion;
    DTFecha fechaVencimiento;
    double descuento;
    set<DTProductoCantidad> productos;
    DTVendedor vendedor;

public:
    DTPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, double descuento, set<DTProductoCantidad> productos, DTVendedor vendedor); 
    //getters
    string getNombre();
    string getDescripcion();
    DTFecha getFechaVencimiento();
    double getDescuento();
    set<DTProductoCantidad> getProductos();
    DTVendedor getVendedor();
    //Operadores
    string toString();
    bool operator==(const DTPromocion&) const;
    bool operator<(const DTPromocion&) const;
};


#endif // DTPROMOCION_H
