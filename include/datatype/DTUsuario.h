#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <iostream>
#include <string>
#include "DTFecha.h"

using namespace std;

class DTUsuario{
    private:
        string nickname;
        DTFecha fecha;

    public:
        DTUsuario();
        DTUsuario(string nickname, DTFecha fecha);
        virtual ~DTUsuario();
        //getters
        string getNickname();
        DTFecha getFecha();
        virtual string toString()=0;
        //operators
        bool operator==(const DTUsuario&) const;
        bool operator<(const DTUsuario&) const;
};

#endif //DTUSUARIO_H