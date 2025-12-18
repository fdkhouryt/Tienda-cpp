#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <string>
#include <iostream>

using namespace std;

class DTComentario {
private:
    int id;
    string texto;
public:
    DTComentario(int id, const string& texto);
    //getters
    int getId() const;
     string getTexto() const;
    //operador
    string toString();
    bool operator==(const DTComentario& comentario) const;
    bool operator<(const DTComentario& comentario) const;
};

#endif // DTCOMENTARIO_H