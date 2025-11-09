#ifndef TIPORESPONSABLE_H
#define TIPORESPONSABLE_H

#include <cstring>
#include <string>

using namespace std;

class TipoResponsable {
private:
    const unsigned int id;
    char descripcion[50];
    float porcentaje;

public:
    TipoResponsable(unsigned int _id, string _descripcion, float porcentaje);
    ~TipoResponsable();

    unsigned int getId();
    string getDescripcion();
    float getPorcentaje();
};

#endif // TIPORESPONSABLE_H
