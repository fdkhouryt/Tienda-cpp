#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H

#include <string>
#include "../../include/datatype/DTProductoCantidad.h"
#include "../../include/datatype/DTCompraNoEnviada.h"
#include "Producto.h"

using namespace std;

class Compra;

class CompraProducto {
private:
    int cantidad;
    bool entregado;
    Compra* compra;
    Producto* producto;
public:
    //CompraProducto();
    CompraProducto(Producto*, Compra*, int);
    //virtual ~CompraProducto();

    //getters
    //int getCantidad();
    bool isEntregado();
    Producto* getProducto();
    Compra* getCompra();
    DTProductoCantidad infoCantidad();
    DTCompraNoEnviada getDTCompraNoEnviada();
    int getIdProducto();
    int getCantidad();

    //setters
    //void setCantidad(int cantidad);
    void setEntregado(bool entregado);

    //operadores
    //bool operator==(const CompraProducto& compraProducto) const;
    //bool operator<(const CompraProducto& compraProducto) const;
};

#include "Compra.h"

#endif //COMPRAPRODUCTO_H

