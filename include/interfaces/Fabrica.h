#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>
#include <string>
#include "../controladores/ControladorUsuario.h"
#include "../controladores/ControladorCliente.h"
#include "../controladores/ControladorVendedor.h"
#include "IControladorCliente.h"
#include "IControladorUsuario.h"
#include "IControladorVendedor.h"

class Fabrica{
    private:
        static Fabrica * singleton;
        Fabrica();
    public:
        static Fabrica * getInstancia();
        IControladorUsuario * getControladorUsuario();
        IControladorCliente * getControladorCliente();
        IControladorVendedor * getControladorVendedor();
        FechaActual* getFechaActual();
};

#endif
