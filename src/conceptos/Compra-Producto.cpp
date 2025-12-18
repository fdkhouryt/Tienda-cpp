#include "../../include/conceptos/Compra-Producto.h"

//Faltan operadores??

CompraProducto::CompraProducto(Producto* produ, Compra* compra, int cant){
    entregado = false;
    cantidad = cant;
    producto = produ;
    this->compra = compra;
}

Compra* CompraProducto::getCompra(){
    return compra;
}

Producto* CompraProducto::getProducto(){
    return this->producto;
}

DTProductoCantidad CompraProducto::infoCantidad(){
    DTProducto dtp = producto->getDTProducto();
    return DTProductoCantidad(dtp,cantidad);
}

DTCompraNoEnviada CompraProducto::getDTCompraNoEnviada(){
    return DTCompraNoEnviada(this->compra->getId(),this->compra->getNicknameCliente(),this->compra->getFecha());
}

int CompraProducto::getIdProducto(){
    return this->producto->getCodigo();
}

void CompraProducto::setEntregado(bool entregado){
    this->entregado = entregado;
}

bool CompraProducto::isEntregado(){
    return entregado;
}

int CompraProducto::getCantidad(){
    return this->cantidad;
}
//Faltan operadores??

