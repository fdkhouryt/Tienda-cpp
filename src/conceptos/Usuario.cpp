#include "../../include/conceptos/Usuario.h"

Usuario::Usuario(string nickname, string password, DTFecha fecha){
    this->nickname = nickname;
    this->password = password;
    this->fecha = fecha;
    set<Comentario> comentarios;
}

void Usuario::agregarComentario(Comentario* c){
    this->comentarios.insert(c);
}
void Usuario::eliminarComentario(Comentario* c){
    this->comentarios.erase(c);
}

set<DTComentario> Usuario::listarComentarios(){
    set<DTComentario> comentarios;
    for (Comentario * c: this->comentarios){
        comentarios.insert(c->getDTComentario());
    }
    return comentarios;
}

    string  Usuario :: getNickname(){
        return this->nickname;
    }
    
    string Usuario :: getPassword(){
        return this->password;
    }
    
    DTFecha Usuario :: getFecha(){
        return this->fecha;
    }