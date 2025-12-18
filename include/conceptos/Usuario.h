#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <set>
#include "../../include/datatype/DTFecha.h"
#include "../../include/datatype/DTComentario.h"
#include "../../include/datatype/DTUsuario.h"


using namespace std;

class Comentario;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class Usuario {
    private:
        string nickname;
        string password;
        DTFecha fecha;
        set<Comentario*> comentarios;

    public:
        Usuario(string nickname, string password, DTFecha fecha);
       // ~Usuario();

        //geters
        virtual DTUsuario* getdtusuario() = 0;
        string getNickname();
        string getPassword();
        DTFecha getFecha();
        //set<Comentario> getComentarios();
        virtual DTUsuario* obternerinfo()=0;

        set<DTComentario> listarComentarios();
        void agregarComentario(Comentario* c);
        void eliminarComentario(Comentario* c);
};

#include "Comentario.h"

#endif // USUARIO_H