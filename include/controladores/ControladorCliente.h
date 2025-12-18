#ifndef CONTROLADORCLIENTE_H
#define CONTROLADORCLIENTE_H

#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

#include "../datatype/DTCompra.h"
#include "../datatype/DTNotificacion.h"
#include "../conceptos/Cliente.h"
#include "../conceptos/Compra.h"
#include "../interfaces/IControladorCliente.h"
#include "../interfaces/IControladorVendedor.h"
#include "../interfaces/Fabrica.h"
#include "FechaActual.h"

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class ControladorCliente: public IControladorCliente{
    private:
        static ControladorCliente * instancia;
        string nombreClienteCompra;
        ControladorCliente();
        set<Cliente*> clientes;
        map<int,Compra*> compras;
        set<string> vendedores;
        set<DTProductoCantidad> listaCompra; //usado para recordar la nueva compra creada
        set<DTPromocion> promocionesEnCompra; //usado para recordar la nueva compra creada
        void setPromocionesEnCompra(set<DTPromocion>);
        float calcularMonto(set<DTPromocion>, set<DTProductoCantidad>);
        Cliente* buscarCliente(set<Cliente*>, string);
        float montoCompra;
        void setMontoCompra(float);

    public:
        ~ControladorCliente();
        static ControladorCliente * getInstancia();
        set<string> listarNicknameClientes();
        void seleccionarCliente(string nickname);
        void comprarProducto(int codProducto, int cantidad);
        DTCompra listarCompra();
        void confirmarCompra();
        set<string> listarVendedoresNoCliente();
        set<string> listarSuscripciones();
        set<DTNotificacion> consultaNotificacionesCliente();
        void suscribirAVendedores();
        void altaCliente(Cliente* cliente);
        void eliminarSuscripciones();
        void agregarVendedor(string nickname);
        void enviarCompra(int codigoCompra,int codigoProducto);
        int findIDCompra(DTFecha fecha, string nombre);
};
#endif