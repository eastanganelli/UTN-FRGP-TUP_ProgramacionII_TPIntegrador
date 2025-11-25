#ifndef TIPORESPONSABLE_H
#define TIPORESPONSABLE_H

#include <string>
#include <cstring>

using namespace std;

class TipoResponsable {
private:
    static const unsigned int CODIGO_SIZE = 5;
    static const unsigned int DESCRIPCION_SIZE = 31;
    static const unsigned int PORCENTAJE_SIZE = 6;

    unsigned int codigo;
    char descripcion[DESCRIPCION_SIZE];
    float porcentaje;

public:
    // Constructor
    TipoResponsable(const unsigned int codigo = 0, const string descripcion = "", const float porcentaje = 0.0f);
    ~TipoResponsable();

    // Getters
    unsigned int getCodigo() const;
    string getDescripcion() const;
    float getPorcentaje() const;

    // Métodos
    bool operator==(const TipoResponsable& otra) const;
    bool IsEmpty() const;
    void Print();
};

#endif // TIPORESPONSABLE_H