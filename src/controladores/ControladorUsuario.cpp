#include "../../include/controladores/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {}
ControladorUsuario* ControladorUsuario::getInstancia(){
    if(instancia == NULL) {
        instancia = new ControladorUsuario();
    }
    return instancia;
}

ControladorUsuario::~ControladorUsuario(){}

set<string>ControladorUsuario::listarUsuarios(){
    set<string> res;
    for(map<string,Usuario*>::iterator it = this->usuarios.begin(); it!=this->usuarios.end();++it){
        res.insert(it->second->getNickname());
    }
    return res;
}

void ControladorUsuario::seleccionarUsuario(string nickname){
    this->Usuariosel = nickname;
}

void ControladorUsuario::ingresarUsuario(string nickname, string password, DTFecha fecha){
    this->nicknameIng = nickname;
    this->passwordIng = password;
    this->fechaIng = fecha;
}

void ControladorUsuario::ingresarUbicacion(DTDireccion direccion) {
    Cliente* clienteIng = new Cliente(nicknameIng, passwordIng, fechaIng, direccion);
    this->clienteIng = clienteIng;
}
 
void ControladorUsuario::ingresarDatosVendedor(string RUT) {
    Vendedor* vendedorIng = new Vendedor(nicknameIng, passwordIng, fechaIng, RUT);
    this->vendedorIng = vendedorIng;
}


void ControladorUsuario::darDeAlta(){
    Fabrica* fabri = Fabrica::getInstancia();
    if(clienteIng != NULL) {
        IControladorCliente* Ccliente = fabri->getControladorCliente();
        Ccliente->altaCliente(clienteIng);
        usuarios.insert(make_pair(clienteIng->getNickname(), clienteIng));
        clienteIng = NULL;
    }else {
        IControladorVendedor* cVendedor = fabri->getControladorVendedor();
        cVendedor->altaVendedor(vendedorIng);
        usuarios.insert(make_pair(vendedorIng->getNickname(), vendedorIng));
        vendedorIng = NULL;
    }
}

set<DTUsuario*> ControladorUsuario::listarDatosUsuarios(){
    set<DTUsuario*> res;
    for (map<string,Usuario*>::iterator it = this->usuarios.begin(); it!=this->usuarios.end();++it){
        res.insert(it->second->getdtusuario());
    }
    return res;
}

DTUsuario* ControladorUsuario::infoUsuario(){
    DTUsuario* res = usuarios[Usuariosel]->obternerinfo();
    Usuariosel = "";
    return res;
}

void ControladorUsuario::seleccionarProducto(int codigo){
    this->productoSel = codigo;
    Fabrica* fabri = Fabrica::getInstancia();
    IControladorVendedor* cVendedor = fabri->getControladorVendedor();
    cVendedor->seleccionarProducto(codigo);
}

void ControladorUsuario::seleccionarComentario(int codigo){
    this->comentarioSel = codigo;
}

void ControladorUsuario::responderComentario(string texto){
    map<string,Usuario*>::iterator it = this->usuarios.find(this->Usuariosel);
    Usuario* usuario = it->second;
    Comentario * comentario = new Comentario(texto,FechaActual::getInstancia()->get(),usuario);
    Fabrica* fabri = Fabrica::getInstancia();
    IControladorVendedor* cVendedor = fabri->getControladorVendedor();
    cVendedor->agregarComentarioAProducto(comentario);
    usuario->agregarComentario(comentario);

    Comentario * padre = NULL;
    for (Comentario* c: this->comentarios){
        if (c->getId() == this->comentarioSel){
            padre = c;
            break;
        }
    }
    if (padre != NULL)
      padre->agregarRespuesta(comentario);

    this->comentarios.insert(comentario);
}

void ControladorUsuario::agregarComentario(string texto){
    map<string,Usuario*>::iterator it = this->usuarios.find(this->Usuariosel);
    Usuario* usuario = it->second;

    Comentario * comentario = new Comentario(texto,FechaActual::getInstancia()->get(),usuario);
    Fabrica* fabri = Fabrica::getInstancia();
    IControladorVendedor* cVendedor = fabri->getControladorVendedor();
    cVendedor->agregarComentarioAProducto(comentario);

    usuario->agregarComentario(comentario);

    this->comentarios.insert(comentario);
}

set<DTComentario> ControladorUsuario::listarComentariosUsuario(){
    map<string,Usuario*>::iterator it = this->usuarios.find(this->Usuariosel);
    Usuario* usuario = it->second;

    return usuario->listarComentarios();
}

void ControladorUsuario::eliminarComentario(int id){
    Comentario * comentario = NULL;
    for (Comentario* c: this->comentarios){
        if (c->getId() == id){
            comentario = c;
            break;
        }
    }
    if(comentario == NULL)
        return;
    
    comentario->~Comentario();
}

Comentario* ControladorUsuario::findComentarioByTexto(string text) {
    set<Comentario*>::iterator it = comentarios.begin();
    while((it != comentarios.end()) && ((*it)->getTexto() != text)) it++;
    if (it == comentarios.end()) return NULL;
    return (*it);
}

bool ControladorUsuario::isNicknameUsado(string nickname){
    map<string,Usuario*>::iterator it = usuarios.begin();
    while (it!=usuarios.end() && it->first != nickname) it++;
    return it != usuarios.end();
}

void ControladorUsuario::sacarcomentario(Comentario* c){
    comentarios.erase(c);
}