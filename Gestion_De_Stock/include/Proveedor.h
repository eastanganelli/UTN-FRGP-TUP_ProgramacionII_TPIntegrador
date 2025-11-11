#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "DatosPersonales.h"
#include "TipoResponsable.h"

#include <iostream>
#include <cstring>

using namespace std;

class Proveedor : public DatosPersonales {
private:
    int id;
    char rubro[15];
    char cuit[11];
    char nombreRazon[35];

public:
    Proveedor(unsigned int _id = 0, string _cuit = "", string _nombreRazon = "", string _rubro = "", string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", unsigned int _codigoRazonSocial = 0, bool _alta = false);
    ~Proveedor();

    // Getters
    int getID();
    bool getAlta();
    string getCuit();
    string getRubro();
    string getNombreRazon();

    // Setters
    void setCuit(string& cuit);
    void setRubro(string& rubro);
    void setNombreRazon(string& nombre);

    // Metodos

};

#endif // PROVEEDOR_H
