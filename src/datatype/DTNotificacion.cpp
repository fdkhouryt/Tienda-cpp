#include "../../include/datatype/DTNotificacion.h"


using namespace std;

DTNotificacion::DTNotificacion() {}

DTNotificacion::DTNotificacion(string nomVend, string nomPromo, set<DTProductoCantidad> produPromo) : nomVend(nomVend), nomPromo(nomPromo), produPromo(produPromo) {}

DTNotificacion::~DTNotificacion() {}

//getters
string DTNotificacion::getnomVend() const {
    return nomVend;
}

string DTNotificacion::getnomPromo() const {
    return nomPromo;
}

//operadores
bool DTNotificacion::operator==(const DTNotificacion& notificacion) const {
    return (this->nomVend == notificacion.nomVend) && (this->nomPromo == notificacion.nomPromo);
}

bool DTNotificacion::operator<(const DTNotificacion& notificacion) const {
    if (this->nomVend < notificacion.nomVend) return true;
    if (this->nomVend == notificacion.nomVend && this->nomPromo < notificacion.nomPromo) return true;
    return false;
}

string DTNotificacion::toString() {
    string res = "--Notificacion--\nVendedor: " + nomVend + "\nPromo: " + nomPromo+"\nProductos:";
    for (DTProductoCantidad pc : produPromo)
        res+="\n"+pc.toString();
    return res;
}
