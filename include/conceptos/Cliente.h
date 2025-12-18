#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <set>
#include "../../include/datatype/DTFecha.h"
#include "../../include/datatype/DTDireccion.h"
#include "../../include/datatype/DTNotificacion.h"
#include "../../include/datatype/DTClienteExt.h"
#include "../interfaces/ISubscriptor.h"

#include "Vendedor.h"
#include "Usuario.h"

using namespace std;

class Compra;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class Cliente : public Usuario, public ISuscriptor {
    private:
        DTDireccion direccion;
        set<Compra*> compras;
        set<DTNotificacion> notificaciones;
        set<Vendedor*> suscripciones;

    public:
        //Cliente();
        Cliente(string nickname, string password, DTFecha fecha, DTDireccion direccion);
        Cliente(Cliente& cli);
        //~Cliente();

        //getters
        //string getNickname();
        //DTFecha getFecha();
        set<Compra*> getCompras();
        set<string> getSuscripciones();

        void notificar(DTNotificacion noti);
        void suscribirse(set<string>);
        void deSuscribirse(set<string>);
        void agregarCompra(Compra*);

        //IMPORTANTE
        set<DTNotificacion> consultarNotificaciones(); 
        //IMPORTANTE 
        
        DTUsuario* getdtusuario();
        DTUsuario* obternerinfo();


};

#include "Compra.h"

#endif // DTVENDEDOR_H

