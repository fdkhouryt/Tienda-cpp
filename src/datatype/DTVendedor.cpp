#include "../../include/datatype/DTVendedor.h"

// Default constructor
DTVendedor::DTVendedor() : DTUsuario() {}

// Parameterized constructor
DTVendedor::DTVendedor(string nickname, DTFecha fecha, string RUT) : DTUsuario(nickname, fecha) {
    this->RUT = RUT;
}

// Destructor
DTVendedor::~DTVendedor() {}

// Getters
string DTVendedor::getNickname() {
    return DTUsuario::getNickname();
}

DTFecha DTVendedor::getFecha() {
    return DTUsuario::getFecha();
}

string DTVendedor::getRUT() {
    return this->RUT;
}

// toString method
string DTVendedor::toString() {
    return "Nickname: " + getNickname() + "\nFecha: " + getFecha().toString() + "\nRUT: " + this->RUT;
}

// Operators
bool DTVendedor::operator==(const DTVendedor& vendedor) const {
    return this->RUT == vendedor.RUT && DTUsuario::operator==(vendedor);
}

bool DTVendedor::operator<(const DTVendedor& vendedor) const {
    return this->RUT < vendedor.RUT || (this->RUT == vendedor.RUT && DTUsuario::operator<(vendedor));
}
