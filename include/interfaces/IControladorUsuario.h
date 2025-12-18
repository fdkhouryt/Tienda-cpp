#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H

#include <string>
#include <set>
#include <iostream>

#include "../datatype/DTComentario.h"
#include "../datatype/DTFecha.h"
#include "../datatype/DTDireccion.h"
#include "../datatype/DTUsuario.h"
#include "../conceptos/Cliente.h"
#include "../conceptos/Vendedor.h"
#include "../conceptos/Usuario.h"
#include "../conceptos/Comentario.h"

using namespace std;

class IControladorUsuario{
public:
    virtual ~IControladorUsuario(){};
    virtual void seleccionarUsuario(string nickname)=0;
    virtual void ingresarUsuario(string nickname, string password, DTFecha fecha)=0;
    virtual void ingresarUbicacion(DTDireccion direccion)=0;
    virtual void ingresarDatosVendedor(string RUT)=0;
    virtual set<string> listarUsuarios()=0;
    virtual set<DTUsuario*> listarDatosUsuarios()=0;
    virtual void darDeAlta()=0;
    virtual set<DTComentario> listarComentariosUsuario()=0; 
    virtual void eliminarComentario(int id)=0;
    virtual void seleccionarProducto(int id)=0;
    virtual void seleccionarComentario(int id)=0;
    virtual void agregarComentario(string texto)=0;
    virtual void responderComentario(string texto)=0;
    virtual DTUsuario* infoUsuario()=0;
    virtual Comentario* findComentarioByTexto(string)=0;
    virtual bool isNicknameUsado(string nickname)=0;
    virtual void sacarcomentario(Comentario*)=0;
};




#endif