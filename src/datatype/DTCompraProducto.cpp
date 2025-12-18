#include "../../include/datatype/DTCompraProducto.h"

// Default constructor
DTCompraProducto::DTCompraProducto(){}

// Parameterized constructor
DTCompraProducto::DTCompraProducto(string nickname, DTFecha fecha) {
    nombreCliente = nickname;
    fechaCompra = fecha;
}

// Destructor
DTCompraProducto::~DTCompraProducto() {}

// Getters
string DTCompraProducto::getNickname() {
    return nombreCliente;
}

DTFecha DTCompraProducto::getFecha() {
    return fechaCompra;
}

// toString method
string DTCompraProducto::toString() {
    return "Nickname: " + getNickname() + "\nFecha: " + getFecha().toString();
}

// Operators
bool DTCompraProducto::operator==(const DTCompraProducto& producto) const {
    return (fechaCompra == producto.fechaCompra) && (nombreCliente == producto.nombreCliente);
}

bool DTCompraProducto::operator<(const DTCompraProducto& producto) const {
    return (nombreCliente < producto.nombreCliente) && (fechaCompra < producto.fechaCompra);
}
