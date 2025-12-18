#include "../../include/datatype/DTComentario.h"


using namespace std;

DTComentario::DTComentario(int id, const string& texto) : id(id), texto(texto) {}

//getters
int DTComentario::getId() const {
    return id;
}

string DTComentario::getTexto() const {
    return texto;
}

//operador
bool DTComentario::operator==(const DTComentario& comentario) const {
    return (this->id == comentario.id) && (this->texto == comentario.texto);
}

bool DTComentario::operator<(const DTComentario& comentario) const {
    if (this->id < comentario.id) return true;
    if (this->texto < comentario.texto) return true;
    return false;
}

string DTComentario::toString(){
    return "ID: " + to_string(id) + ", Texto: " + texto;
}