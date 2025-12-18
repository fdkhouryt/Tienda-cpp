#ifndef DTPRODUCTOEXT_H
#define DTPRODUCTOEXT_H

#include <string>
#include "Categoria.h"

using namespace std;

class DTProductoExt {
private:
    int codigo;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    Categoria categoria;

public:
    DTProductoExt();
    DTProductoExt(int codigo, int stock, float precio, string nombre, string descripcion, Categoria categoria);
    virtual ~DTProductoExt();

    //getters
    int getCodigo() const;
    int getStock() const;
    float getPrecio() const;
    string getNombre() const;
    string getDescripcion() const;
    Categoria getCategoria() const;
    //operadores
    string toString() const;
    bool operator==(const DTProductoExt& producto) const;
    bool operator<(const DTProductoExt& producto) const;
};

#endif // DTPRODUCTOEXT_H
