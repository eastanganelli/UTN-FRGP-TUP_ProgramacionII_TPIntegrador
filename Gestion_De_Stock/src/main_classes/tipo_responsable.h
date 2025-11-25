#ifndef TIPORESPONSABLE_H
#define TIPORESPONSABLE_H

#include <string>
#include <cstring>

using namespace std;

class TipoResponsable {
private:
    static const unsigned int CODIGO_SIZE = 5;
    static const unsigned int DESCRIPCION_SIZE = 31;
    static const unsigned int PORCENTAJE_SIZE = 5;
    static const unsigned int TIPOFACTURACION_SIZE = 5;

    unsigned int codigo;
    char descripcion[DESCRIPCION_SIZE];
    float porcentaje;
    char tipoFacturacion;

public:
    // Constructor
    TipoResponsable(const unsigned int _codigo = 0, const string _descripcion = "", const float _porcentaje = -1, const char _tipoFacturacion = '\0');
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