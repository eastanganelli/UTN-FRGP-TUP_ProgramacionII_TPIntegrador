#ifndef DATOSPERSONALES_H
#define DATOSPERSONALES_H

#include "../controller/validation.h"

#include <cstring>
#include <string>

using namespace std;

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

    DatosPersonales(bool _alta = false, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", string _codigoRazonSocial = "");
    bool IsEqual(const DatosPersonales& otro);
    bool IsEmpty();

public:
    ~DatosPersonales();

    // Getters
    bool getAlta();
    string Estado();
    string getCorreo();
    string getDireccion();
    string getTelefono();
    string getCelular();
    string getCodigoRazonSocial();

    static unsigned int GetCorreoSize();
    static unsigned int GetDireccionSize();
    static unsigned int GetTelefonoSize();
    static unsigned int GetCelularSize();
    static unsigned int GetEstadoSize();
    static unsigned int GetCodigoRazonSocialSize();

    // Column-size accessors
    static unsigned int ColCorreoSize();
    static unsigned int ColDireccionSize();
    static unsigned int ColTelefonoSize();
    static unsigned int ColCelularSize();
    static unsigned int ColEstadoSize();
    static unsigned int ColCodigoRazonSocialSize();

    // Setters
    void setAlta(bool a);
    void setCorreo(const string& correo);
    void setDireccion(const string& direccion);
    void setTelefono(const string& t);
    void setCelular(const string& c);
    void setCodigoRazonSocial(const string& codigo);
};

#endif // DATOSPERSONALES_H
