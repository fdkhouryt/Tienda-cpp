#ifndef ICONTROLADORVENDEDOR_H
#define ICONTROLADORVENDEDOR_H

#include <string>
#include <set>
#include <iostream>

#include "../datatype/DTProductoExt.h"
#include "../datatype/DTCompraProducto.h"
#include "../conceptos/Vendedor.h"
#include "../conceptos/Producto.h"
#include "../conceptos/Promocion.h"
#include "../conceptos/Comentario.h"
#include "../conceptos/Promocion-Producto.h"

using namespace std;

class IControladorVendedor{
public:
    virtual ~IControladorVendedor(){};
    virtual void altaVendedor(Vendedor* vendedor)=0;
    virtual void nuevaPromocionDatos(string nombre, string descripcion, DTFecha fechaDeVencimiento, double descuento)=0;
    virtual set<string> listarVendedores()=0;
    virtual void seleccionarVendedor(string nickname)=0;
    virtual set<DTProductoExt> listarProductosVendedor()=0;
    virtual void agregarProductos(int codigo, int cantMin)=0;
    virtual void altaPromocion()=0;
    virtual set<DTProductoExt> listarProductosExt()=0;
    virtual DTProducto getProductoByID(int codProducto)=0;
    virtual set<DTPromocion> promocionesValidas(set<DTProductoCantidad> listaCompra)=0;
    virtual set<string> getVendedores()=0;
    virtual Vendedor* findVendedor(string nickname)=0;
    virtual Producto* findProductoByCodigo(int codigo)=0;
    virtual Producto* findProductoByNombre(string nombre)=0;
    virtual Promocion* findPromoByNombre(string nombre)=0;
    virtual set<DTProducto> listarProductos()=0;
    virtual void seleccionarProducto(int codigo)=0;
    virtual set<DTComentario> listarComentariosProducto()=0;
    virtual void agregarComentarioAProducto(Comentario* c)=0;
    virtual set<DTPromocion> listarPromocionesVigentes(DTFecha fechaActual)=0;
    virtual set<DTCompraNoEnviada> listarComprasProductoPend()=0;
    virtual DTPromocion seleccionarPromocion(string nombre)=0;
    virtual DTProductoExt obtenerInformacionProducto(int codProducto)=0;
    virtual set<DTProducto> listarProductosEnviosPend()=0;
    virtual void enviarCompra(int codigoCompra)=0;
    virtual void nuevoProducto(string nombre, float precio, string descripcion, Categoria categoria,int stock)=0;
};

#endif