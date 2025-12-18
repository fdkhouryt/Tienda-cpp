#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include <iostream>
#include <string>
#include "DTFecha.h"
#include "DTUsuario.h"

using namespace std;

class DTVendedor : public DTUsuario {
    private:
        string RUT;

    public:
        DTVendedor();
        DTVendedor(string nickname, DTFecha fecha, string RUT);
        ~DTVendedor();
        //getters
        string getNickname();
        DTFecha getFecha();
        string getRUT();
        string toString();
        //operators
        bool operator==(const DTVendedor&) const;
        bool operator<(const DTVendedor&) const;   
};

#endif // DTVENDEDOR_H
