#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
#include <string>

using namespace std;

class DTFecha{
    private:
        int dia;
        int mes;
        int anio;

    public:
        DTFecha();
        DTFecha(int dia, int mes, int anio);
        DTFecha(const DTFecha&);
        ~DTFecha();
        bool operator==(const DTFecha &fecha)const;
        bool operator<=(const DTFecha &fecha)const;
        bool operator>=(const DTFecha &fecha)const;
        bool operator>(const DTFecha &fecha)const;
        bool operator<(const DTFecha &fecha)const;
        bool operator!=(const DTFecha &fecha)const;
        int getDia()const;
        int getMes()const;
        int getAnio()const;
        friend ostream &operator<<(ostream& x, DTFecha fecha);
        string toString()const;

};

#endif //DTFECHA_H