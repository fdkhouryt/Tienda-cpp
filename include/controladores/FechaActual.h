#ifndef FECHAACTUAL_H
#define FECHAACTUAL_H

#include <string>
#include <set>
#include <iostream>

#include "../datatype/DTFecha.h"

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class FechaActual{
    private:
        static FechaActual* instancia;
        FechaActual();
        DTFecha fecha;

    public:
        static FechaActual* getInstancia();

        void set(DTFecha fecha);
        DTFecha get();
};

#endif