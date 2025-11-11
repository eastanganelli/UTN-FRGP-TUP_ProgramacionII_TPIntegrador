#ifndef DATOSPERSONALES_H
#define DATOSPERSONALES_H

#include <cstring>
#include <string>

using namespace std;

class DatosPersonales {
protected:
    bool alta;
    char correo[120];
    char direccion[120];
    char telefono[15];
    char celular[15];
    unsigned int codigoRazonSocial;

    DatosPersonales(bool _alta = false, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", unsigned int _codigoRazonSocial = 0);
public:
    ~DatosPersonales();

    // Getters
    bool getAlta();
    string getCorreo();
    string getDireccion();
    string getTelefono();
    string getCelular();
    unsigned int getCodigoRazonSocial();

    // Setters
    void setAlta(bool a);
    void setCorreo(const string& correo);
    void setDireccion(const string& direccion);
    void setTelefono(const string& t);
    void setCelular(const string& c);
    void setCodigoRazonSocial(unsigned int codigo);
};

#endif // DATOSPERSONALES_H
