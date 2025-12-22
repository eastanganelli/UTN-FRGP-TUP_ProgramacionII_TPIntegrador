#ifndef DATOSPERSONALES_H
#define DATOSPERSONALES_H

#include <cstring>
#include <string>

using namespace std;

#include "../controller/validation.h"

class DatosPersonales {
private:
    static const unsigned int CORREO_SIZE = 40;
    static const unsigned int DIRECCION_SIZE = 40;
    static const unsigned int TELEFONO_SIZE = 16;
    static const unsigned int CELULAR_SIZE = 16;
    static const unsigned int ESTADO_SIZE = 8;
    static const unsigned int CODIGORAZONSOCIAL_SIZE = 5;

    // Column widths for aligned table output
    static const unsigned int COL_CORREO = CORREO_SIZE;
    static const unsigned int COL_DIRECCION = DIRECCION_SIZE;
    static const unsigned int COL_TELEFONO = TELEFONO_SIZE;
    static const unsigned int COL_CELULAR = CELULAR_SIZE;
    static const unsigned int COL_ESTADO = ESTADO_SIZE;
    static const unsigned int COL_CODIGO_RAZON_SOCIAL = CODIGORAZONSOCIAL_SIZE;

protected:
    bool alta;
    char correo[CORREO_SIZE];
    char direccion[DIRECCION_SIZE];
    char telefono[TELEFONO_SIZE];
    char celular[CELULAR_SIZE];
    char codigoRazonSocial[CODIGORAZONSOCIAL_SIZE];

    /** Constructor protegido que inicializa datos personales. */
    DatosPersonales(bool _alta = false, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", string _codigoRazonSocial = "");
    /** Compara igualdad de datos personales. */
    bool IsEqual(const DatosPersonales& otro);
    /** Indica si los datos personales estan vacios. */
    bool IsEmpty();

public:
    /** Destructor base de datos personales. */
    ~DatosPersonales();

    /** Indica si el registro esta de alta. */
    bool getAlta();
    /** Devuelve el estado textual. */
    string Estado();
    /** Obtiene el correo. */
    string getCorreo();
    /** Obtiene la direccion. */
    string getDireccion();
    /** Obtiene el telefono. */
    string getTelefono();
    /** Obtiene el celular. */
    string getCelular();
    /** Obtiene el codigo de razon social. */
    string getCodigoRazonSocial();

    static unsigned int GetCorreoSize();
    static unsigned int GetDireccionSize();
    static unsigned int GetTelefonoSize();
    static unsigned int GetCelularSize();
    static unsigned int GetEstadoSize();
    static unsigned int GetCodigoRazonSocialSize();

    /** Ancho de columna para correo. */
    static unsigned int ColCorreoSize();
    /** Ancho de columna para direccion. */
    static unsigned int ColDireccionSize();
    /** Ancho de columna para telefono. */
    static unsigned int ColTelefonoSize();
    /** Ancho de columna para celular. */
    static unsigned int ColCelularSize();
    /** Ancho de columna para estado. */
    static unsigned int ColEstadoSize();
    /** Ancho de columna para codigo de razon social. */
    static unsigned int ColCodigoRazonSocialSize();

    /** Actualiza estado de alta/baja. */
    void setAlta(bool a);
    /** Actualiza correo. */
    void setCorreo(const string& correo);
    /** Actualiza direccion. */
    void setDireccion(const string& direccion);
    /** Actualiza telefono. */
    void setTelefono(const string& t);
    /** Actualiza celular. */
    void setCelular(const string& c);
    /** Actualiza codigo de razon social. */
    void setCodigoRazonSocial(const string& codigo);
};

#endif // DATOSPERSONALES_H
