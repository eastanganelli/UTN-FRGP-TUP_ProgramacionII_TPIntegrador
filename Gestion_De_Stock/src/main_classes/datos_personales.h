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

protected:
    bool alta;
    char correo[CORREO_SIZE];
    char direccion[DIRECCION_SIZE];
    char telefono[TELEFONO_SIZE];
    char celular[CELULAR_SIZE];
    unsigned int codigoRazonSocial;

    DatosPersonales(bool _alta = false, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "");
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

    static unsigned int GetCorreoSize();
    static unsigned int GetDireccionSize();
    static unsigned int GetTelefonoSize();
    static unsigned int GetCelularSize();
    static unsigned int GetEstadoSize();

    // Setters
    void setAlta(bool a);
    void setCorreo(const string& correo);
    void setDireccion(const string& direccion);
    void setTelefono(const string& t);
    void setCelular(const string& c);
};

#endif // DATOSPERSONALES_H
