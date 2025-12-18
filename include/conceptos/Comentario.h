#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "../datatype/DTFecha.h"
#include "../datatype/DTComentario.h"
#include "Usuario.h"

#include <string>
#include <set>

using namespace std;

class Producto;

//LAS COSAS QUE ESTAN COMENTADAS, EL SIGNIFICADO ES QUE NO ESTAN IMPLEMENTADAS
class Comentario {
private:
    int id;
    string texto;
    DTFecha fecha;
    static int numero;
    set<Comentario*> respuestas;
    Usuario* escritor;
    Producto* producto;
    Comentario* padre;

public:
    //Comentario();
    Comentario(string& texto, DTFecha fecha, Usuario* escritor);
    virtual ~Comentario();

    //getters
    int getId();
    string getTexto();
    DTFecha getFecha();
    DTComentario getDTComentario();

    //setters
    //void setId(int id);
    //void setTexto(string& texto);
    //void setFecha(DTFecha fecha);
    void setProducto(Producto* producto);
    void setPadre(Comentario* comentario);

    void agregarRespuesta(Comentario* comentario);
    void eliminarRespuesta(Comentario* comentario);

    //operadores
    string toString();
    //bool operator==(const Comentario& comentario) const;
    //bool operator<(const Comentario& comentario) const;
};

#include "Producto.h"


#endif // COMENTARIO_H
