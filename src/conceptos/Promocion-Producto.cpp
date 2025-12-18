#include "../../include/conceptos/Promocion-Producto.h"

PromocionProducto::PromocionProducto(Promocion* p, DTProductoCantidad dtprodu, Producto* producto) {
    this->producto = producto;
    this->cantidadMinima = dtprodu.getCantidad();
    this->promocion = p;
    this->producto->agregarPromocion(this);
}

Producto* PromocionProducto::getProducto() {
    return producto;
}

unsigned int PromocionProducto::getCantidad() {
    return cantidadMinima;
}

/*
bool PromocionProducto::operator==(DTProductoCantidad produ) {
    return (cantidadMinima == produ.getCantidad()) && (producto->getcodigo() == produ.getProducto().getCodigo());
}
*/