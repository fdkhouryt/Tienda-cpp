#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class DTDireccion {
private:
    string calle;
    string ciudad;
    int numero;

public:
    DTDireccion(); //Es necesario pero no hace falta implementarlo
    DTDireccion(string calle, string ciudad, int numero); 
    //virtual ~DTDireccion();

    // Getters
    //string getCalle() const;
    //int getNumero() const;
    //string getCuidad(); //falta implementar
    // Operadores
    string toString();
    //bool operator==(const DTDireccion& direccion) const;
    //bool operator<(const DTDireccion& direccion) const;
};

#endif // DTDIRECCION_H

