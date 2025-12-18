#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <iostream>
#include <string>
#include <map>
#include "../../include/datatype/DTFecha.h"
#include "../../include/datatype/DTProductoExt.h"
#include "../../include/datatype/DTNotificacion.h"
#include "../../include/datatype/DTVendedorExt.h"
#include "../interfaces/ISubscriptor.h"
#include "Usuario.h"
#include "Promocion.h"

using namespace std;

class Cliente;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class Vendedor: public Usuario {
    private:
        string RUT;
        set<Promocion*> promociones;
        map<int, Producto*> productosVend;
        set<ISuscriptor*> suscriptores;

    public:
        //Vendedor();
        Vendedor(string nickname, string password, DTFecha fecha, string RUT);
        //~Vendedor();

        //getters
        //string getNickname(); si se heredo y no se va a sobreescribir no es necesario reescribir la firma
        //DTFecha* getFecha();
        string getRUT();

        void agregarPromoVendedor(Promocion*);
        void notificarSus(string nombrePromo, set<DTProductoCantidad> productos);
        set<DTProductoExt> listarProductos();
        set<DTProducto> listarProductosEnviosPendientes();
        void agregarSuscriptor(Cliente*);
        void quitarSuscriptor(Cliente*);
        void agregarProducto(Producto*);
        DTUsuario* getdtusuario();
        DTUsuario* obternerinfo();
};

#include "Cliente.h"
#endif // VENDEDOR_H