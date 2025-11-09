#ifndef DATOSPERSONALES_H
#define DATOSPERSONALES_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class DatosPersonales {
protected:
    bool alta;
    char correo[120];
    char direccion[120];
    char telefono[2][15];

    DatosPersonales(bool _alta = false, string _direccion = "", string _correo = "", string _telefono_I = "", string _telefono_II = "");

public:
    ~DatosPersonales();

    // Getters
    bool getAlta();
    string getCorreo();
    string getDireccion();
    string getTelefono(int posicion);

    // Setters
    void setAlta(bool a);
    void setCorreo(const string& correo);
    void setDireccion(const string& direccion);
    void setTelefono(const string& t, int posicion);
};

#endif // DATOSPERSONALES_H
