#ifndef ICONTROLADORCLIENTE_H
#define ICONTROLADORCLIENTE_H

#include <string>
#include <set>
#include <iostream>

#include "../datatype/DTCompra.h"
#include "../datatype/DTNotificacion.h"
#include "../conceptos/Cliente.h"
#include "../conceptos/Compra.h"
#include "../conceptos/Compra-Producto.h"

using namespace std;

class Cliente;

class IControladorCliente{
    public:
        virtual ~IControladorCliente(){};
        virtual set<string> listarNicknameClientes()=0;
        virtual void seleccionarCliente(string nickname)=0;
        virtual void comprarProducto(int codProducto, int cantidad)=0;
        virtual DTCompra listarCompra()=0;
        virtual void confirmarCompra()=0;
        virtual set<string> listarVendedoresNoCliente()=0;
        virtual set<string> listarSuscripciones()=0;
        virtual set<DTNotificacion> consultaNotificacionesCliente()=0;
        virtual void suscribirAVendedores()=0;
        virtual void altaCliente(Cliente* cliente)=0;
        virtual void eliminarSuscripciones()=0;
        virtual void agregarVendedor(string nickname)=0;
        virtual void enviarCompra(int codigoCompra,int codigoProducto)=0;
        virtual int findIDCompra(DTFecha fecha, string nombre)=0;
};

#endif