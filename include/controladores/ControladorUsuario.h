#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <string>
#include <set>
#include <iostream>
#include <map>

#include "../datatype/DTComentario.h"
#include "../datatype/DTFecha.h"
#include "../datatype/DTDireccion.h"
#include "../datatype/DTUsuario.h"
#include "../conceptos/Cliente.h"
#include "../conceptos/Vendedor.h"
#include "../conceptos/Usuario.h"
#include "../conceptos/Comentario.h"
#include "../interfaces/IControladorUsuario.h"
#include "../interfaces/IControladorCliente.h"
#include "../interfaces/Fabrica.h"
#include "FechaActual.h"

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS

class ControladorUsuario: public IControladorUsuario{
private:
    static ControladorUsuario * instancia;
    ControladorUsuario();
    //variables para recordar NO BORRAR
    string nicknameIng; 
    string passwordIng;
    DTFecha fechaIng;
    Cliente* clienteIng;
    Vendedor* vendedorIng;
    set<Comentario*> comentarios;
    map<string, Usuario*> usuarios;
    string Usuariosel; //nickname usuario de seleccionarUsuario();
    int productoSel;
    int comentarioSel;

public:
    static ControladorUsuario * getInstancia();

    //ControladorUsuario();
    ~ControladorUsuario();
    void seleccionarUsuario(string nickname);
    void ingresarUsuario(string nickname, string password, DTFecha fecha);
    void ingresarUbicacion(DTDireccion direccion);
    void ingresarDatosVendedor(string RUT);
    set<string> listarUsuarios();
    set<DTUsuario*> listarDatosUsuarios();
    void darDeAlta();
    set<DTComentario> listarComentariosUsuario(); 
    void eliminarComentario(int id);
    void seleccionarProducto(int codigo);
    void seleccionarComentario(int id);
    void agregarComentario(string texto);
    void responderComentario(string texto);
    DTUsuario* infoUsuario();
    Comentario* findComentarioByTexto(string);
    bool isNicknameUsado(string nickname);
    void sacarcomentario(Comentario*);
};

#endif