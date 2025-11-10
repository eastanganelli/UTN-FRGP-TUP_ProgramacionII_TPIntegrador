#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "DatosPersonales.h"
#include "TipoResponsable.h"

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
    unsigned int codigoRazonSocial;

public:
    Proveedor(unsigned int _id = 0, string _cuit = "", string _nombreRazon = "", string _telefono = "", string _celular = "", unsigned int _codigoRazonSocial = 0, bool _alta = false);
    ~Proveedor();

    // Getters
    int getID();
    bool getAlta();
    string getCuit();
    string getRubro();
    string getNombreRazon();
    unsigned int getCodigoRazonSocial();

    // Setters
    void setCuit(string& cuit);
    void setRubro(string& rubro);
    void setNombreRazon(string& nombre);
    void setCodigoRazonSocial(unsigned int rs);

    // Metodos

};

#endif // PROVEEDOR_H
