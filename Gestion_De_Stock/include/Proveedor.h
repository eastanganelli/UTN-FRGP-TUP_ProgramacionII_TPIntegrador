#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "DatosPersonales.h"

#include <iostream>
#include <cstring>

using namespace std;

class Proveedor : public DatosPersonales {
private:
    int id;
    char nombreRazon[35];
    char rubro[15];
    bool alta;

public:
    Proveedor();
    ~Proveedor();

    // Getters
    int getID();
    const string getNombre();
    const string getRubro();
    bool getAlta();

    // Setters
    void setNombre(const string& nombre);
    void setRubro(const string& rubro);

    // Metodos

};

#endif // PROVEEDOR_H
