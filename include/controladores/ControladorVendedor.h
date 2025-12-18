#ifndef CONTROLADORVENDEDOR_H
#define CONTROLADORVENDEDOR_H

#include <string>
#include <set>
#include <map>
#include <iostream>

#include "../datatype/DTProductoExt.h"
#include "../datatype/DTProducto.h"
#include "../datatype/DTCompraProducto.h"
#include "../conceptos/Vendedor.h"
#include "../conceptos/Producto.h"
#include "../conceptos/Promocion.h"
#include "../conceptos/Comentario.h"
#include "../interfaces/IControladorVendedor.h"
#include "../conceptos/Promocion-Producto.h"

#include "../interfaces/Fabrica.h"


using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class ControladorVendedor: public IControladorVendedor {
private:
    static ControladorVendedor * instancia;
    ControladorVendedor();
    map<string, Vendedor*> vendedores;
    map<int, Producto*> productos;
    set<Promocion*> promociones;
    set<DTProductoCantidad> l1;
    map<int, Producto*> l2; 
    string vendedorsel;// recuerdar vendedor selecionado en seleccionarVendedor()
    string nombrePromoIng;
    string descripcionPromoIng;
    DTFecha FechaPromoIng;
    double descuentoPromoIng;
    int productoSel;

public:
    static ControladorVendedor * getInstancia();
    ~ControladorVendedor();
    void altaVendedor(Vendedor* vendedor);
    void nuevaPromocionDatos(string nombre, string descripcion, DTFecha fechaDeVencimiento, double descuento);
    set<string> listarVendedores();
    void seleccionarVendedor(string nickname);
    set<DTProductoExt> listarProductosVendedor();
    void agregarProductos(int codigo, int cantMin);
    void altaPromocion();
    set<DTProductoExt> listarProductosExt();
    DTProducto getProductoByID(int codProducto);
    set<DTPromocion> promocionesValidas(set<DTProductoCantidad> listaCompra);
    set<string> getVendedores();
    Vendedor* findVendedor(string nickname);
    Producto* findProductoByCodigo(int codigo);
    Producto* findProductoByNombre(string nombre);
    Promocion* findPromoByNombre(string nombre);
    set<DTProducto> listarProductos();
    void seleccionarProducto(int codigo);
    set<DTComentario> listarComentariosProducto();
    void agregarComentarioAProducto(Comentario* c);
    set<DTPromocion> listarPromocionesVigentes(DTFecha fechaActual);
    set<DTCompraNoEnviada> listarComprasProductoPend();
    DTPromocion seleccionarPromocion(string nombre);
    DTProductoExt obtenerInformacionProducto(int codProducto);
    set<DTProducto> listarProductosEnviosPend();
    void enviarCompra(int codigoCompra);
    void nuevoProducto(string nombre, float precio, string descripcion, Categoria categoria,int stock);
};

#endif
