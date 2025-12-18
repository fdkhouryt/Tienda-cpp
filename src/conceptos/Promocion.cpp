#include "../../include/conceptos/Promocion.h"

Promocion::Promocion(string nombre, string descripcion, DTFecha fechaVencimiento, double descuento, set<DTProductoCantidad> l1, map<int, Producto*> l2, Vendedor* vendedor) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaVencimiento = fechaVencimiento;
    this->descuento = descuento;
    this->vendedor = vendedor;
    set<DTProductoCantidad> :: iterator it1 = l1.begin();
    map<int, Producto*> :: iterator it2 = l2.begin();
    while (it1!=l1.end() && it2!=l2.end()){
        PromocionProducto* pp = new PromocionProducto(this,*it1,it2->second);
        promoproductos.insert(make_pair((it2->second->getCodigo()), pp));
        ++it1;
        ++it2;
    }
}

bool estaEnLista(map<int, PromocionProducto*> lista, DTProductoCantidad pc) {
    if (lista.find(pc.getProducto().getCodigo()) == lista.end()) return false; 
    PromocionProducto* pp = lista.find(pc.getProducto().getCodigo())->second;
    return pp->getCantidad() <= pc.getCantidad();
}

bool Promocion::alpicaA(set<DTProductoCantidad> lista) {
    set<DTProductoCantidad> copia = lista;
    FechaActual* fActual = FechaActual::getInstancia();
    DTFecha fecha = fActual->get();
    for(DTProductoCantidad pc: lista)
        if (!estaEnLista(promoproductos, pc)) copia.erase(pc);
    return (promoproductos.size() == copia.size() && (fecha < this->fechaVencimiento));
}

string Promocion::getNombre() {
    return nombre;
}

DTFecha Promocion::getFecha(){
    return this->fechaVencimiento;
}

DTPromocion Promocion::getDTPromocion(){
    DTVendedor dTVend = DTVendedor(this->vendedor->getNickname(), this->vendedor->getFecha(), this->vendedor->getRUT());
    set<DTProductoCantidad> dTprodus;
    for(pair<const int, PromocionProducto *> i : promoproductos){
        dTprodus.insert(DTProductoCantidad(i.second->getProducto()->getDTProducto(), i.second->getCantidad()));
    }
    return DTPromocion(nombre, descripcion, fechaVencimiento, descuento, dTprodus, dTVend);
}
