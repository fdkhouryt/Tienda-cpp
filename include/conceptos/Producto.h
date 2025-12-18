#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include "../datatype/Categoria.h"
#include "../datatype/DTProductoExtVend.h"
#include "../datatype/DTCompraNoEnviada.h"
#include "../datatype/DTProductoExt.h"
#include "../datatype/DTComentario.h"

#include "Promocion-Producto.h"
#include "Comentario.h"

using namespace std;

class Vendedor;
class CompraProducto;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class Producto {
    private:
        static int numero;
        int codigo;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        Categoria categoria;
        Vendedor* Vend;
        PromocionProducto* promocion; // falta por modificar, no debe ser un map
        map<int, CompraProducto*> compras; 
        //falta terminar
        set<Comentario*> comentarios;

    public:
        Producto(string nombre, float precio, string descripcion, Categoria categoria, int stock, Vendedor* Vend);// No cambiar plis, terminado (by Bruno)
        //~Producto();
        int getCodigo();
        string getNombre();
        float getPrecio();
        void agregarPromocion(PromocionProducto* pp);
        DTProducto getDTProducto();
        DTProductoExt getDTProductoExt();
        void agregarCompra(CompraProducto*);
        DTProductoExtVend infoProductoExt();
        void agregarComentario(Comentario* c);
        void eliminarComentario(Comentario* c);
        set<DTComentario> listarComentarios();
        bool tieneEnvioPend();
        set<DTCompraNoEnviada> listarComprasProductoPend();
        

        //operadores
        //bool operator==(const Producto&) const;
       // bool operator<(const Producto&) const;
};

#include "Vendedor.h"
#include "Compra-Producto.h"

#endif // PRODUCTO_H