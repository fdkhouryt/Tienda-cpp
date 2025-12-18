#include "../../include/interfaces/Fabrica.h"

Fabrica* Fabrica::singleton = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if(singleton == NULL) 
        singleton = new Fabrica();
    return singleton;
}

IControladorCliente* Fabrica::getControladorCliente(){
    return ControladorCliente::getInstancia();
}

IControladorVendedor* Fabrica::getControladorVendedor(){
    return ControladorVendedor::getInstancia();
}

IControladorUsuario* Fabrica::getControladorUsuario(){
    return ControladorUsuario::getInstancia();
}