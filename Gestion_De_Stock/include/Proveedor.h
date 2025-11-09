#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "DatosPersonales.h"

#include <iostream>
#include <cstring>

using namespace std;

class Proveedor : public DatosPersonales {
private:
    bool alta;
    int id;
    char rubro[15];
    char cuit[11];
    char nombreRazon[35];
    TipoResponsable* razonSocial;

public:
    Proveedor();
    ~Proveedor();

    // Getters
    int getID();
    bool getAlta();
    const string getCuit();
    const string getRubro();
    const string getNombreRazon();

    // Setters
    void setRubro(const string& rubro);
    void setRubro(const )
    void setNombreRazon(const string& nombre);

    // Metodos

};

#endif // PROVEEDOR_H
