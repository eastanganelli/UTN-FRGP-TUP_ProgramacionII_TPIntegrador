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
    /** Crea un tipo de responsable con codigo, descripcion y alicuota. */
    TipoResponsable(const string _codigo = "", const string _descripcion = "", const float _porcentaje = -1.0f, const char _tipoFacturacion = '\0');
    /** Destructor de tipo de responsable. */
    ~TipoResponsable();

    /** Obtiene el codigo del tipo. */
    string getCodigo() const;
    /** Obtiene la descripcion. */
    string getDescripcion() const;
    /** Obtiene el porcentaje aplicado. */
    float getPorcentaje() const;
    /** Obtiene el tipo de facturacion. */
    char getTipoFacturacion() const;

    static unsigned int GetCodigoSize();
    static unsigned int GetDescripcionSize();

    static unsigned int ColCodigoSize();
    static unsigned int ColDescripcionSize();
    static unsigned int ColPorcentajeSize();
    static unsigned int ColTipoFacturacion();

    /** Compara igualdad por contenido. */
    bool operator==(const TipoResponsable& otra) const;
    /** Indica si esta vacio. */
    bool IsEmpty() const;
    /** Imprime el tipo de responsable. */
    void Print();
    /** Calcula el resultado aplicando el porcentaje a un valor. */
    float Resultado(float valor);

};

#endif // TIPORESPONSABLE_H