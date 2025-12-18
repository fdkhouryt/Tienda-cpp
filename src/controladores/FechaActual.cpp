#include "../../include/controladores/FechaActual.h"

FechaActual * FechaActual::instancia = NULL;
FechaActual::FechaActual(){}

FechaActual* FechaActual::getInstancia(){
    if (FechaActual::instancia == NULL){
        FechaActual::instancia = new FechaActual();
    }
    return FechaActual::instancia;
}

DTFecha FechaActual::get(){
    return FechaActual::fecha;
}

void FechaActual::set(DTFecha fecha){
    FechaActual::fecha = fecha;
}
