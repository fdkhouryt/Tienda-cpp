#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <set>
#include "DTProductoCantidad.h"
#include <iostream>

using namespace std;

class DTNotificacion {
private:
    string nomVend;
    string nomPromo;
    set<DTProductoCantidad> produPromo;

public:
    DTNotificacion();
    DTNotificacion(string nomVend, string nomPromo, set<DTProductoCantidad> produPromo);
    virtual ~DTNotificacion();
    //getters
    string getnomVend() const;
    string getnomPromo() const;
    //operadores
    string toString();
    bool operator==(const DTNotificacion& notificacion) const;
    bool operator<(const DTNotificacion& notificacion) const;
};

#endif // DTNOTIFICACION_H
