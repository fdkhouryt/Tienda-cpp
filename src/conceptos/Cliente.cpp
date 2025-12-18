#include "../../include/conceptos/Cliente.h"

Cliente::Cliente(string nickname, string password, DTFecha fecha, DTDireccion direccion): Usuario(nickname, password, fecha) {
    this->direccion = direccion;
    set<Compra*> compras;
    set<DTNotificacion> notificacion;
    set<Vendedor*> suscripciones;

}

set<string> Cliente::getSuscripciones() {
    set<string> nicknames;
    for(Vendedor* vend:this->suscripciones) nicknames.insert(vend->getNickname());
    return nicknames;
}

Cliente::Cliente(Cliente& cli): Usuario(cli.getNickname(), cli.getPassword(), cli.getFecha()) {
    this->direccion = cli.direccion;
    this->compras = cli.compras;
    notificaciones = cli.notificaciones;
    suscripciones = cli.suscripciones;
}

void Cliente::agregarCompra(Compra* nC) {
    compras.insert(nC);
}

void Cliente::notificar(DTNotificacion noti) { 
    notificaciones.insert(noti); 
}

DTUsuario* Cliente::getdtusuario(){
    return new DTCliente(this->getNickname(),this->getFecha() ,this->direccion);
}

DTUsuario* Cliente::obternerinfo(){
    set<DTCompra>rescompras;
    for(set<Compra*>::iterator it= compras.begin();it!=compras.end();++it){
        Compra* c =  *it;
        rescompras.insert(c->obtenerInfo());
    }
    DTClienteExt* res = new DTClienteExt(this->getNickname(),this->getFecha(),this->direccion,rescompras);
    return res;

}

set<Compra*> Cliente::getCompras() {
    set<Compra*> res;
    for(set<Compra*>::iterator it = compras.begin(); it != compras.end(); ++it){
        Compra * c = *it;
        res.insert(c);
    }
    return res;
}

set<DTNotificacion> Cliente:: consultarNotificaciones() {
    set<DTNotificacion> res;
    set<DTNotificacion>::iterator it;
    for(it = notificaciones.begin(); it != notificaciones.end(); ++it){
        DTNotificacion NuevaNoti = *it;
        res.insert(NuevaNoti);
    }
    notificaciones.clear();
    return res;
}

void Cliente::suscribirse(set<string> vend){
    Fabrica* fabrica = Fabrica::getInstancia();
    IControladorVendedor* iVend = fabrica->getControladorVendedor();
    set<string>::iterator it;
    for(it = vend.begin(); it != vend.end(); ++it) {
        string v = *it;
        Vendedor* vendagregar =iVend->findVendedor(v);
        this->suscripciones.insert(vendagregar);
        vendagregar->agregarSuscriptor(this);
    }
}

void Cliente::deSuscribirse(set<string> vend){
    Fabrica* fabrica = Fabrica::getInstancia();
    IControladorVendedor* iVend = fabrica->getControladorVendedor();
    set<string>::iterator it;
    for(it = vend.begin();it != vend.end();++it) {
        string v = *it;
        Vendedor* vendEliminar=iVend->findVendedor(v);
        this->suscripciones.erase(vendEliminar);
        vendEliminar->quitarSuscriptor(this);
    }
}
