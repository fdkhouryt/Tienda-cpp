#include "../../include/conceptos/Vendedor.h"

void Vendedor::agregarProducto(Producto* p) {
    productosVend[p->getCodigo()] = p;
}
Vendedor::Vendedor(string nickname, string password, DTFecha fecha, string RUT): Usuario(nickname, password, fecha) {
    this->RUT =  RUT;
    set<Promocion> promociones;
    set<Producto> productos;
}

set<DTProductoExt> Vendedor::listarProductos() {
    set<DTProductoExt> setProdu;
    map<int, Producto*>:: iterator it;
    for(it = productosVend.begin(); it != productosVend.end(); ++it) {
        DTProductoExt DtProdu = it->second->getDTProductoExt();
        setProdu.insert(DtProdu);
    }
    return setProdu;
    
}

void Vendedor::agregarPromoVendedor(Promocion* promo) {
    promociones.insert(promo);
}

void Vendedor::notificarSus(string nombrePromo, set<DTProductoCantidad> productos) {
    DTNotificacion noti = DTNotificacion(this->getNickname(), nombrePromo, productos);

    for(set<ISuscriptor*> :: iterator it = suscriptores.begin();it!=suscriptores.end(); ++it){
        ISuscriptor* s = *it;
        s->notificar(noti);
    }
}

DTUsuario* Vendedor::getdtusuario(){
    return new DTVendedor(this->getNickname(),this->getFecha() ,this->RUT);
}

DTUsuario* Vendedor::obternerinfo(){
    set<DTPromocion>respromos;
    for(set<Promocion*>::iterator it= promociones.begin();it!=promociones.end();++it){
        Promocion* p =  *it;
        respromos.insert(p->getDTPromocion());
    }
    set<DTProductoExt>resProd;
    for(map<int, Producto*>::iterator it = productosVend.begin(); it!=productosVend.end();++it){
        resProd.insert(it->second->getDTProductoExt());
    }

    return new DTVendedorExt(this->getNickname(),this->getFecha(),this->RUT,respromos,resProd);
}

set<DTProducto> Vendedor::listarProductosEnviosPendientes(){
    set<DTProducto> productosConEnvios;
    for(map<int, Producto*>::iterator it = productosVend.begin(); it!=productosVend.end();++it){
        Producto* producto = it->second;
        if (producto->tieneEnvioPend())
            productosConEnvios.insert(producto->getDTProducto());        
    }
    return productosConEnvios;
}

string Vendedor::getRUT(){
    return this->RUT;
}

void Vendedor :: agregarSuscriptor(Cliente* cli){
    this->suscriptores.insert(cli);
}

void Vendedor::quitarSuscriptor(Cliente* cli) {
    this->suscriptores.erase(cli);
}