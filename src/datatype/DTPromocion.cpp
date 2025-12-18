#include "../../include/datatype/DTPromocion.h"

// Constructor
DTPromocion::DTPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, double descuento, set<DTProductoCantidad> productos, DTVendedor vendedor)
    : nombre(nombre), descripcion(descripcion), fechaVencimiento(fechaVencimiento), descuento(descuento), productos(productos), vendedor(vendedor) {}

// Getters
string DTPromocion::getNombre() {
    return nombre;
}

string DTPromocion::getDescripcion() {
    return descripcion;
}

DTFecha DTPromocion::getFechaVencimiento() {
    return fechaVencimiento;
}

double DTPromocion::getDescuento() {
    return descuento;
}

set<DTProductoCantidad> DTPromocion::getProductos() {
    return productos;
}

DTVendedor DTPromocion::getVendedor() {
    return vendedor;
}

// Métodos adicionales
string DTPromocion::toString() {
    string result = "Nombre: " + nombre + "\n" +
                    "Descripcion: " + descripcion + "\n" +
                    "Fecha de Vencimiento: " + fechaVencimiento.toString() + "\n" +
                    "Descuento: " + to_string(descuento*100) + "%\n" +
                    "Productos: \n";
    for (DTProductoCantidad produ : productos) {
        result += produ.toString() + "\n";
    }
    result += "Vendedor: " + vendedor.toString() + "\n";
    return result;
}

// Operadores
bool DTPromocion::operator==(const DTPromocion& other) const {
    return nombre == other.nombre && 
           descripcion == other.descripcion &&
           fechaVencimiento == other.fechaVencimiento &&
           descuento == other.descuento &&
           productos == other.productos &&
           vendedor == other.vendedor;
}

bool DTPromocion::operator<(const DTPromocion& other) const {
    if (nombre != other.nombre) return nombre < other.nombre;
    if (descripcion != other.descripcion) return descripcion < other.descripcion;
    if (fechaVencimiento != other.fechaVencimiento) return fechaVencimiento < other.fechaVencimiento;
    if (descuento != other.descuento) return descuento < other.descuento;
    if (productos != other.productos) return productos < other.productos;
    return vendedor < other.vendedor;
}