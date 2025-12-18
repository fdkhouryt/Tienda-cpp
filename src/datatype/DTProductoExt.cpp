#include "../../include/datatype/DTProductoExt.h"


using namespace std;

DTProductoExt::DTProductoExt() {}

DTProductoExt::DTProductoExt(int codigo, int stock, float precio, string nombre, string descripcion, Categoria categoria) {
    this->codigo = codigo;
    this->stock = stock;
    this->precio = precio;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
}

DTProductoExt::~DTProductoExt() {}

//getters
int DTProductoExt::getCodigo() const {
    return codigo;
}

int DTProductoExt::getStock() const {
    return stock;
}

float DTProductoExt::getPrecio() const {
    return precio;
}

string DTProductoExt::getNombre() const {
    return nombre;
}

string DTProductoExt::getDescripcion() const {
    return descripcion;
}

Categoria DTProductoExt::getCategoria() const {
    return categoria;
}

//operadores
bool DTProductoExt::operator==(const DTProductoExt& producto) const {
    return (this->codigo == producto.codigo) &&
           (this->stock == producto.stock) &&
           (this->precio == producto.precio) &&
           (this->nombre == producto.nombre) &&
           (this->descripcion == producto.descripcion) &&
           (this->categoria == producto.categoria);
}

bool DTProductoExt::operator<(const DTProductoExt& producto) const {
    if (this->codigo < producto.codigo) return true;
    if (this->codigo == producto.codigo && this->stock < producto.stock) return true;
    if (this->codigo == producto.codigo && this->stock == producto.stock && this->precio < producto.precio) return true;
    if (this->codigo == producto.codigo && this->stock == producto.stock && this->precio == producto.precio && this->nombre < producto.nombre) return true;
    if (this->codigo == producto.codigo && this->stock == producto.stock && this->precio == producto.precio && this->nombre == producto.nombre && this->descripcion < producto.descripcion) return true;
    if (this->codigo == producto.codigo && this->stock == producto.stock && this->precio == producto.precio && this->nombre == producto.nombre && this->descripcion == producto.descripcion && this->categoria < producto.categoria) return true;
    return false;
}

string DTProductoExt::toString() const {
    string categoriaStr;
    switch (categoria) {
        case Electrodomesticos: categoriaStr = "Electrodomésticos"; break;
        case Ropa: categoriaStr = "Ropa"; break;
        case Otro: categoriaStr = "Otro"; break;
    }
    return "Codigo: " + to_string(codigo) + ", Stock: " + to_string(stock) + ", Precio: " + to_string(precio) + ", Nombre: " + nombre + ", Descripcion: " + descripcion + ", Categoria: " + categoriaStr;
}

