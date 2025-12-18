#include "../../include/conceptos/Comentario.h"

int Comentario::numero = 0;

Comentario::Comentario(string& texto, DTFecha fecha, Usuario* escritor){
    this->texto=texto;
    this->fecha=fecha;
    this->escritor = escritor;
    this->padre = NULL;

    Comentario::numero++;
    this->id=Comentario::numero;
}

int Comentario::getId(){
    return this->id;
}
string Comentario::getTexto(){
    return this->texto;
}
DTFecha Comentario::getFecha(){
    return this->fecha;
}

DTComentario Comentario::getDTComentario(){
    return DTComentario(this->id,this->texto);
}

void Comentario::agregarRespuesta(Comentario* c){
    this->respuestas.insert(c);
    c->setPadre(this);
}
void Comentario::eliminarRespuesta(Comentario* c){
    this->respuestas.erase(c);
}

void Comentario::setProducto(Producto* producto){
    this->producto = producto;
}
void Comentario::setPadre(Comentario* comentario){
    this->padre = comentario;
}

Comentario::~Comentario(){
    this->escritor->eliminarComentario(this);
    this->producto->eliminarComentario(this);
    
    Fabrica::getInstancia()->getControladorUsuario()->sacarcomentario(this);
    if (this->padre != NULL) 
        this->padre->eliminarRespuesta(this);
    
    for (Comentario* respuesta:this->respuestas){
        respuesta->setPadre(NULL);
        respuesta->~Comentario();
    }
    this->respuestas.clear();
}
