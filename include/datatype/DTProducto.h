#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class DTProducto {
private:
    int codigo;
    string nombre;
    float precio;
public:
    DTProducto();
    DTProducto(int codigo, string nombre, float precio);
    ~DTProducto();
    // Getters
    int getCodigo();
    string getNombre();
    float getPrecio();
    //Operadores
    string toString();
    bool operator==(const DTProducto&) const;
    bool operator<(const DTProducto&) const;
};

#endif // DTPRODUCTO_H
