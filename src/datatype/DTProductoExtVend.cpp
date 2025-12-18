#include "../../include/datatype/DTProductoExtVend.h"

DTProductoExtVend::DTProductoExtVend(int codigo, int stock, float precio, string nombre, Categoria categ, string nombreVendedor){
    this->codigo = codigo;
    this->stock = stock;
    this->precio = precio;
    this->nombre = nombre;
    this->categ = categ;
    this->nombreVendedor = nombreVendedor;
}