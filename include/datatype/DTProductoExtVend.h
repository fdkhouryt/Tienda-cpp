#ifndef DTPRODUCTOEXTVEND_H
#define DTPRODUCTOEXTVEND_H

#include <string>
#include "Categoria.h"
#include "DTProducto.h"

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class DTProductoExtVend {
    private:
        int codigo;
        int stock;
        float precio;
        string nombre;
        Categoria categ;
        string nombreVendedor;

    public:
        DTProductoExtVend(int Codigo, int Stock, float Precio, string Nombre, Categoria Categ, string nombreVendedor);
        //DTProductoExtVend(const DTProductoExtVend&);
        //~DTProductoExtVend();
        //int getCodigo();
        //int getStock();
        //float getPrecio();
        //string getNombre();
        //Categoria getCateg();
        //string getnombreVendedor();
        //string toString();
        //bool operator==(const DTProducto&) const;
        //bool operator<(const DTProducto&) const;
};

#endif