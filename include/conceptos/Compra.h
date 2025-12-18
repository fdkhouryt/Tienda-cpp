#ifndef COMPRA_H
#define COMPRA_H

#include "../datatype/DTFecha.h"
#include "../datatype/DTCompra.h"
#include "../datatype/DTPromocion.h"
#include "../interfaces/Fabrica.h"
#include <set>

using namespace std;

class Promocion;
class Cliente;
class CompraProducto;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class Compra {
private:
    float monto;
    DTFecha fecha;
    Cliente* cliente;
    set<CompraProducto*> productos;
    set<Promocion*> promociones;
    int id;
    static int number;
public:
    //Compra();
    Compra(float monto, DTFecha fecha, set<DTProductoCantidad> listaProdu, Cliente* cliente, set<DTPromocion> promociones);
    //virtual ~Compra();

    //getters
    //float getMonto();
    DTFecha getFecha();
    //set<CompraProducto> getProductos();
    DTCompra getCompra();
    DTCompra obtenerInfo();
    int getId();
    string getNicknameCliente();

    //setters
    //void setMonto(float monto);
    //void setFecha(DTFecha fecha);
    //void setProductos(set<CompraProducto> productos);

    void marcarProductoEnviado(int codigoProducto);

    //operadores
    //string toString();
    //bool operator==(const Compra& compra) const;
    //bool operator<(const Compra& compra) const;
};

#include "Cliente.h"
#include "Compra-Producto.h"

#endif // COMPRA_H