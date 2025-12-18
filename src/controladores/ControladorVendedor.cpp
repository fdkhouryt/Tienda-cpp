
#include "../../include/controladores/ControladorVendedor.h"

ControladorVendedor*ControladorVendedor::instancia=NULL;

ControladorVendedor::ControladorVendedor(){}

ControladorVendedor*ControladorVendedor::getInstancia() {
    if(instancia == NULL)
        instancia = new ControladorVendedor();
    return instancia;
}

ControladorVendedor::~ControladorVendedor(){}

void ControladorVendedor::nuevaPromocionDatos(string nombre, string descripcion, DTFecha fechaDeVencimiento, double descuento) {
    this->nombrePromoIng = nombre;
    this->descripcionPromoIng = descripcion;
    this->FechaPromoIng = fechaDeVencimiento;
    this->descuentoPromoIng = descuento;
}



void ControladorVendedor::nuevoProducto(string nombre, float precio, string descripcion, Categoria categoria,int stock) {
    map<string, Vendedor*>::iterator it = vendedores.find(this->vendedorsel);
    Vendedor* v = it->second;
    Producto* p = new Producto(nombre,precio, descripcion,categoria, stock, v);
    v->agregarProducto(p);
    this->productos.insert(make_pair(p->getCodigo(),p));
    
    this->vendedorsel = ""; //se deja vacio el parametro "se libera la memoria"

}// No cambiar, terminado (by Bruno)

void ControladorVendedor::seleccionarVendedor(string nickname){
    this->vendedorsel = nickname;

}// No cambiar, terminado (by Bruno)

set<string> ControladorVendedor::listarVendedores() {
    set<string> nombres;
    map<string, Vendedor*>::iterator it;
    for (it= this->vendedores.begin(); it!=this->vendedores.end(); ++it) {
        nombres.insert(it->first);
    }
    return nombres;
}// No cambiar, terminado (by Bruno)

void ControladorVendedor::altaVendedor(Vendedor* vendedor){
    vendedores.insert(make_pair(vendedor->getNickname(), vendedor));
} 

set<DTProducto> ControladorVendedor::listarProductos(){
    set<DTProducto> sproductos;
    map<int, Producto*>::iterator it;
    for (it=this->productos.begin(); it!=this->productos.end(); ++it) {
        DTProducto dtp= it->second->getDTProducto();
        sproductos.insert(dtp);
    }
    return sproductos;
}

set<DTProductoExt> ControladorVendedor::listarProductosExt(){
    set<DTProductoExt> sproductos;
    map<int, Producto*>::iterator it;
    for (it=this->productos.begin(); it!=this->productos.end(); ++it) {
        DTProductoExt dtp = it->second->getDTProductoExt();
        sproductos.insert(dtp);   
    }
    return sproductos;
}


//Esta función que debría devolver exactamente?
DTProductoExt ControladorVendedor::obtenerInformacionProducto(int codProducto) {
    map<int, Producto*>::iterator it = productos.find(codProducto);
    Producto* produ = it->second;
    DTProductoExt res = produ->getDTProductoExt();//produ->infoProductoExt();
    return res;
} 

DTProducto ControladorVendedor::getProductoByID(int codProducto) {
    map<int, Producto*>::iterator it = productos.find(codProducto);
    Producto* produ = it->second;
    DTProducto res = produ->getDTProducto();
    return res;
}

set<string> ControladorVendedor::getVendedores() {
    set<string> nickname;
    map<string, Vendedor*>::iterator it;
    for (it= this->vendedores.begin(); it!=this->vendedores.end(); ++it) {
        nickname.insert(it->second->getNickname());
    }
    return nickname;
}

set<DTPromocion> ControladorVendedor::promocionesValidas(set<DTProductoCantidad> listaCompra) {
    set<DTPromocion> promocionesEnCompra;
    for (Promocion* promo: promociones) 
        if(promo->alpicaA(listaCompra)) promocionesEnCompra.insert(promo->getDTPromocion());
    return promocionesEnCompra;
}

Producto* ControladorVendedor::findProductoByCodigo(int codigo) {
    return productos[codigo];
}

Producto* ControladorVendedor::findProductoByNombre(string nombre) {
    map<int, Producto*>::iterator it = productos.begin();
    while((it != productos.end()) && (it->second->getNombre() != nombre)) it++;
    if (it == productos.end()) return NULL;
    return it->second;
}

Promocion* ControladorVendedor::findPromoByNombre(string nombre) {
    set<Promocion*>::iterator i = promociones.begin();
    while( i != promociones.end() && (*i)->getNombre() != nombre) i++;
    return (*i);
}

set<DTProductoExt> ControladorVendedor::listarProductosVendedor() {
    set<DTProductoExt> setProduVen;
    map<string, Vendedor*> :: iterator it = vendedores.find(vendedorsel);
    setProduVen = it->second->listarProductos();
    return setProduVen;
}

void ControladorVendedor::agregarProductos(int codigo, int cantMin) {
    map<int, Producto*>::iterator it = productos.find(codigo);
    Producto* p = it->second;
    string nomb = p->getNombre();
    DTProducto  dtp = DTProducto(codigo, nomb, p->getPrecio());
    DTProductoCantidad dtpc = DTProductoCantidad(dtp, cantMin);    
    this->l1.insert(dtpc);
}

void ControladorVendedor::altaPromocion() {//habalr con el grupo sobre si notificar debe hacer algo mas o si solo pone el DTNotificacion en la coleccion de notificaciones
    map<string, Vendedor*>::iterator it = vendedores.find(vendedorsel);
    Vendedor* vend = it->second;
    for(set<DTProductoCantidad> :: iterator it2 = l1.begin(); it2 != l1.end(); ++it2) {
        DTProductoCantidad dtpc = *it2;
        int pc = dtpc.getProducto().getCodigo();
        l2.insert(make_pair(pc,productos.find(pc)->second));
        
    }
    Promocion* promo = new Promocion(nombrePromoIng, descripcionPromoIng, FechaPromoIng, descuentoPromoIng, l1, l2, vend);
    vend->agregarPromoVendedor(promo);
    promociones.insert(promo);
    vend->notificarSus(nombrePromoIng, l1);
    vendedorsel = "";
    this->descripcionPromoIng = "";
    l1.clear();
    l2.clear();
}

set<DTPromocion> ControladorVendedor::listarPromocionesVigentes(DTFecha fechaActual){
    set<DTPromocion> promos;
    for(Promocion* promo: promociones){
        if(promo->getFecha() >= fechaActual) promos.insert(promo->getDTPromocion());
    }
    return promos;
}


DTPromocion ControladorVendedor::seleccionarPromocion(string nombre){
    Promocion* promo = findPromoByNombre(nombre);
    DTPromocion devo = promo->getDTPromocion();
    return devo;
}

void ControladorVendedor::seleccionarProducto(int codigo){
    this->productoSel = codigo;
}

set<DTComentario> ControladorVendedor::listarComentariosProducto(){
    map<int, Producto*>::iterator it = this->productos.find(this->productoSel);
    Producto* p = it->second;
    
    return p->listarComentarios();
}

void ControladorVendedor::agregarComentarioAProducto(Comentario* c){
    map<int, Producto*>::iterator it = this->productos.find(this->productoSel);
    Producto* p = it->second;
    p->agregarComentario(c);
    c->setProducto(p);
    this->productoSel = 0;
}

set<DTProducto> ControladorVendedor::listarProductosEnviosPend(){
    map<string,Vendedor*>::iterator it = this->vendedores.find(this->vendedorsel);
    Vendedor* vendedor = it->second;

    return vendedor->listarProductosEnviosPendientes();
}

set<DTCompraNoEnviada> ControladorVendedor::listarComprasProductoPend(){
    map<int, Producto*>::iterator it = this->productos.find(this->productoSel);
    Producto* p = it->second;
    return p->listarComprasProductoPend();
}
void ControladorVendedor::enviarCompra(int codigoCompra){
    Fabrica* fabri = Fabrica::getInstancia();
    IControladorCliente* cCliente = fabri->getControladorCliente();
    cCliente->enviarCompra(codigoCompra,this->productoSel);
    this->productoSel = 0;
}

Vendedor* ControladorVendedor::findVendedor(string nickname){
    for(map<string, Vendedor*>::iterator it=this->vendedores.begin(); it!=this->vendedores.end();it++){
        if(nickname==it->first){
            return it->second;
        }
    }
    return NULL;
}