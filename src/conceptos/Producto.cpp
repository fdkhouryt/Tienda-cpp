#include "../../include/conceptos/Producto.h"

int Producto::numero=0;


Producto::Producto(string nombre, float precio, string descripcion, Categoria categoria, int stock, Vendedor* Vend) {
    this->nombre  = nombre;
    this->precio = precio;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->stock = stock;
    this->Vend = Vend;
    
    Producto::numero++;
    this->codigo = Producto::numero;
    this->promocion = NULL;
    map<int, CompraProducto*> compras;
    set<Comentario*> comentarios;
}

DTProductoExtVend Producto::infoProductoExt() {
    string n = this->Vend->getNickname();
    DTProductoExtVend ret = DTProductoExtVend(this->codigo,this->stock,this->precio,this->nombre,this->categoria,n);
    return ret;
}

DTProductoExt Producto::getDTProductoExt() {
     DTProductoExt produ = DTProductoExt(codigo, stock, precio, nombre, descripcion, categoria);
     return produ;
}

void Producto::agregarCompra(CompraProducto* cp) {
    compras[cp->getCompra()->getId()] = cp;
    this->stock -= cp->getCantidad();
}

void Producto::agregarPromocion(PromocionProducto* pp) { // cuando se modifique el mapa a un puntero, modificar el procedimiento, para que lo hago bien 
    promocion = pp;
}

DTProducto Producto::getDTProducto(){
    return DTProducto(codigo, nombre, precio);
}

set<DTComentario> Producto::listarComentarios(){
    set<DTComentario> comentarios;
    for (Comentario * c: this->comentarios){
        comentarios.insert(c->getDTComentario());
    }
    return comentarios;
}

void Producto::agregarComentario(Comentario* c){
    this->comentarios.insert(c);
}
void Producto::eliminarComentario(Comentario* c){
    this->comentarios.erase(c);
}

bool Producto::tieneEnvioPend(){
    for(map<int, CompraProducto*>::iterator it = this->compras.begin(); it!=this->compras.end();++it){
        CompraProducto* cp = it->second;
        if (!cp->isEntregado())
            return true;
    }
    
    return false;
}

set<DTCompraNoEnviada> Producto::listarComprasProductoPend(){
    set<DTCompraNoEnviada> cps;
    for(map<int, CompraProducto*>::iterator it = this->compras.begin(); it!=this->compras.end();++it){
        CompraProducto* cp = it->second;
        if(cp == NULL);
        else if (!cp->isEntregado())
            cps.insert(cp->getDTCompraNoEnviada());
        
    }
    return cps;
}

int Producto::getCodigo(){
    return codigo;
}

string Producto::getNombre(){
    return nombre;
}

float Producto::getPrecio(){
    return precio;
}