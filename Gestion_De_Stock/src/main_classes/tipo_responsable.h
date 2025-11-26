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
    static const unsigned int TIPOFACTURACION_SIZE = 5;

    char codigo[CODIGO_SIZE];
    char descripcion[DESCRIPCION_SIZE];
    float porcentaje;
    char tipoFacturacion;

public:
    // Constructor
    TipoResponsable(const string _codigo = "", const string _descripcion = "", const float _porcentaje = -1.0f, const char _tipoFacturacion = '\0');
    ~TipoResponsable();

    // Getters
    string getCodigo() const;
    string getDescripcion() const;
    float getPorcentaje() const;

    static unsigned int GetCodigoLength();
    static unsigned int GetDescripcionLength();
    static unsigned int GetPorcentajeLength();
    static unsigned int GetTipoFacturacionLength();

    // Métodos
    bool operator==(const TipoResponsable& otra) const;
    bool IsEmpty() const;
    void Print();
};

#endif // TIPORESPONSABLE_H