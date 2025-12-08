#ifndef TIPORESPONSABLE_H
#define TIPORESPONSABLE_H

#include <string>
#include <cstring>

#include "../controller/validation.h"

using namespace std;

class TipoResponsable {
private:
    static const unsigned int CODIGO_SIZE = 5;
    static const unsigned int DESCRIPCION_SIZE = 31;
    static const unsigned int PORCENTAJE_SIZE = 6;
    static const unsigned int TIPOFACTURACION_SIZE = 5;

    static const unsigned int COL_Codigo = 6;
    static const unsigned int COL_Descripcion = 32;
    static const unsigned int COL_Porcentaje = 8;
    static const unsigned int COL_TipoFacturacion = 6;

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
    char getTipoFacturacion() const;

    static unsigned int ColCodigoSize();
    static unsigned int ColDescripcionSize();
    static unsigned int ColPorcentajeSize();
    static unsigned int ColTipoFacturacion();

    // Métodos
    bool operator==(const TipoResponsable& otra) const;
    bool IsEmpty() const;
    void Print();
    static TipoResponsable NuevoTipoResponsable();
    static void ModificarTipoResponsable(TipoResponsable& tipo);
    static unsigned int EliminarTipoResponsable(TipoResponsable& tipo);
};

#endif // TIPORESPONSABLE_H