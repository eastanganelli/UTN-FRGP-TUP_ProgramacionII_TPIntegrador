#ifndef DATOSPERSONALES_H
#define DATOSPERSONALES_H

#include <cstring>
#include <string>

using namespace std;

class DatosPersonales {
protected:
    bool alta;
    char correo[121];
    char direccion[121];
    char telefono[16];
    char celular[16];
    unsigned int codigoRazonSocial;

    DatosPersonales(bool _alta = false, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "");
public:
    ~DatosPersonales();

    // Getters
    bool getAlta();
    string Estado();
    string getCorreo();
    string getDireccion();
    string getTelefono();
    string getCelular();

    // Setters
    void setAlta(bool a);
    void setCorreo(const string& correo);
    void setDireccion(const string& direccion);
    void setTelefono(const string& t);
    void setCelular(const string& c);
};

#endif // DATOSPERSONALES_H
