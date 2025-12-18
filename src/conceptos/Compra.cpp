#include "../../include/conceptos/Compra.h"

int Compra::number = 0;

Compra::Compra(float monto, DTFecha fecha, set<DTProductoCantidad> listaCompra, Cliente* cli, set<DTPromocion> promos){
    Compra::number++;
    this->id = Compra::number;
    this->monto = monto;
    this->fecha = fecha;
    this->cliente = cli;
    Fabrica* fabrica = Fabrica::getInstancia();
    IControladorVendedor* iVend = fabrica->getControladorVendedor();
    for(DTProductoCantidad pc: listaCompra){
        Producto* produ = iVend->findProductoByCodigo(pc.getProducto().getCodigo());
        CompraProducto* cp = new CompraProducto(produ, this, pc.getCantidad());
        produ->agregarCompra(cp);
        productos.insert(cp);
    }
    cli->agregarCompra(this);
    for(DTPromocion promo: promos)
        promociones.insert(iVend->findPromoByNombre(promo.getNombre()));

}

DTCompra Compra::obtenerInfo(){
    set<DTProductoCantidad> compps;

    for(set<CompraProducto*>::iterator it = productos.begin(); it!=productos.end();it++){
        CompraProducto* compp = *it;
        compps.insert(compp->infoCantidad());        
    }
    set<DTPromocion> promos;
    for(Promocion* promo: promociones){
        DTPromocion dtPromo = promo->getDTPromocion();
        promos.insert(dtPromo);
    }
    DTCompra res = DTCompra(this->fecha, compps, monto, promos);
    return res;
}

int Compra::getId(){
    return this->id;
}
string Compra::getNicknameCliente(){
    return this->cliente->getNickname();
}

void Compra::marcarProductoEnviado(int codigoProducto){
    for(set<CompraProducto*>::iterator it = productos.begin(); it!=productos.end();it++){
        CompraProducto* compp = *it;
        if (compp->getIdProducto() == codigoProducto){
            compp->setEntregado(true);
            return;
        }
    }
}

DTFecha Compra::getFecha(){
    return fecha;
}