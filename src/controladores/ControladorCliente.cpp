#include "../../include/controladores/ControladorCliente.h"

ControladorCliente* ControladorCliente::instancia = NULL;
ControladorCliente::ControladorCliente(){}
ControladorCliente* ControladorCliente::getInstancia(){
    if(instancia == NULL) 
        instancia = new ControladorCliente;
    return instancia;
}

ControladorCliente::~ControladorCliente(){}

set<string> ControladorCliente::listarNicknameClientes(){
    set<string> bolsaDeNombres;
    for(Cliente *cli: clientes) bolsaDeNombres.insert(cli->getNickname());
    return bolsaDeNombres;
}

void ControladorCliente::seleccionarCliente(string nick) {
    this->nombreClienteCompra = nick;
}

void ControladorCliente::altaCliente(Cliente* cliente) {
    clientes.insert(cliente);
}

set<string> ControladorCliente::listarVendedoresNoCliente() {
    Cliente* cl = this->buscarCliente(this->clientes,this->nombreClienteCompra);
    set<string> res;
    set<string>::iterator it;
    for(string nick:cl->getSuscripciones()) 
        res.insert(nick);
    
    Fabrica* fabrica = Fabrica::getInstancia();
    IControladorVendedor* iVend = fabrica->getControladorVendedor();
    set<string> vendedores= iVend->getVendedores();
    set<string> diff;
    set_difference(vendedores.begin(),vendedores.end(),res.begin(),res.end(),inserter(diff,diff.begin()));
    return diff;
}

void ControladorCliente::eliminarSuscripciones() {
    Cliente* cl=this->buscarCliente(this->clientes,this->nombreClienteCompra);
    cl->deSuscribirse(this->vendedores);
    this->vendedores.clear();
}

void ControladorCliente::agregarVendedor(string nick) {
    this->vendedores.insert(nick);
}

void ControladorCliente::suscribirAVendedores(){
    Cliente* cl = this->buscarCliente(this->clientes,this->nombreClienteCompra);
    cl->suscribirse(this->vendedores);
    this->vendedores.clear();
}

set<DTNotificacion> ControladorCliente::consultaNotificacionesCliente() {
    Cliente* cl = this->buscarCliente(this->clientes, this->nombreClienteCompra);
    return cl->consultarNotificaciones();
}

set<string> ControladorCliente::listarSuscripciones() {
    Cliente* cl=this->buscarCliente(this->clientes, this->nombreClienteCompra);
    return cl->getSuscripciones();
}


void ControladorCliente::comprarProducto(int codProducto, int cantidad){
    Fabrica* fabrica = Fabrica::getInstancia();
    IControladorVendedor* cVendedor = fabrica->getControladorVendedor();
    DTProductoCantidad pc = DTProductoCantidad(cVendedor->getProductoByID(codProducto), cantidad);
    listaCompra.insert(pc);
}


//terminar esta funcion
DTCompra ControladorCliente::listarCompra(){
    Fabrica* fabrica = Fabrica::getInstancia();
    IControladorVendedor* cVendedor = fabrica->getControladorVendedor();
    set<DTPromocion> promosDeCompra = cVendedor->promocionesValidas(listaCompra);
    setPromocionesEnCompra(promosDeCompra);
    float montoFinal = calcularMonto(promosDeCompra, listaCompra);
    setMontoCompra(montoFinal);
    DTCompra nC = DTCompra(FechaActual::getInstancia()->get(), listaCompra, montoFinal, promosDeCompra);
    return nC;
}

float ControladorCliente::calcularMonto(set<DTPromocion> promociones, set<DTProductoCantidad> productos){
    float final = 0;
    set<DTProductoCantidad> copia = productos;
    for(DTPromocion promo: promociones){
        for(DTProductoCantidad produ: productos){
            final += produ.getCantidad()*
                    produ.getProducto().getPrecio()*
                    (1-promo.getDescuento());
            copia.erase(produ);
        }
    }
    for(DTProductoCantidad produ: copia){
        final += produ.getCantidad()*
                 produ.getProducto().getPrecio();
    }
    return final;
}

void ControladorCliente::setPromocionesEnCompra(set<DTPromocion> promos){
    promocionesEnCompra = promos;
}

void ControladorCliente::setMontoCompra(float monto){
    montoCompra = monto;
}

//falta terminar
void ControladorCliente::confirmarCompra(){
    Cliente* c = buscarCliente(clientes, nombreClienteCompra);
    Compra* nC = new Compra(montoCompra, FechaActual::getInstancia()->get(), listaCompra, c, promocionesEnCompra);
    compras[nC->getId()] = nC;
    listaCompra.clear();
    promocionesEnCompra.clear();
    nombreClienteCompra = "";
}

Cliente* ControladorCliente::buscarCliente(set<Cliente*> lista, string nom){
    set<Cliente*>::iterator i = lista.begin();
    while(i != lista.end() && (*i)->getNickname() != nom) i++;
    return (*i);
}

void ControladorCliente::enviarCompra(int codigoCompra,int codigoProducto){
    map<int,Compra*>::iterator it = this->compras.find(codigoCompra);
    Compra* compra = it->second;
    compra->marcarProductoEnviado(codigoProducto);
}

int ControladorCliente::findIDCompra(DTFecha fecha, string nombre){
    map<int, Compra*>::iterator it = compras.begin();
    while(it != compras.end()){
        if((it->second->getFecha() == fecha) && (it->second->getNicknameCliente() == nombre)) return it->second->getId();
        it++;
    }
    return -1;
}