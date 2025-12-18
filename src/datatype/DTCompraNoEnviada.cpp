#include "../../include/datatype/DTCompraNoEnviada.h"

// Default constructor
DTCompraNoEnviada::DTCompraNoEnviada(){}

// Parameterized constructor
DTCompraNoEnviada::DTCompraNoEnviada(int id,string nickname, DTFecha fecha) {
    this->id = id;
    nombreCliente = nickname;
    fechaCompra = fecha;
}

// Destructor
DTCompraNoEnviada::~DTCompraNoEnviada() {}

// Getters
string DTCompraNoEnviada::getNickname() {
    return nombreCliente;
}

DTFecha DTCompraNoEnviada::getFecha() {
    return fechaCompra;
}

int DTCompraNoEnviada::getId() {
    return id;
}

string DTCompraNoEnviada::getNickname() const {
    return nombreCliente;
}

DTFecha DTCompraNoEnviada::getFecha() const {
    return fechaCompra;
}

int DTCompraNoEnviada::getId() const {
    return id;
}

// toString method
string DTCompraNoEnviada::toString() {
    return "Nickname: " + getNickname() + "\nFecha: " + getFecha().toString();
}

// Operators
bool DTCompraNoEnviada::operator==(const DTCompraNoEnviada& producto) const {
    return (fechaCompra == producto.fechaCompra) && (nombreCliente == producto.nombreCliente);
}

bool DTCompraNoEnviada::operator<(const DTCompraNoEnviada& producto) const {
    return (nombreCliente < producto.nombreCliente) && (fechaCompra < producto.fechaCompra);
}
