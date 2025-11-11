#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "DatosPersonales.h"

#include <cstring>

using namespace std;

class Proveedor : public DatosPersonales {
private:
    char cuit[11];
    char nombreRazon[35];
    char rubro[15];

public:
    Proveedor(string _cuit = "", string _nombreRazon = "", string _rubro = "", string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", unsigned int _codigoRazonSocial = 0, bool _alta = false);
    ~Proveedor();

    // Getters
    bool getAlta();
    string getCuit();
    string getRubro();
    string getNombreRazon();

    // Setters
    void setRubro(string rubro);
    void setNombreRazon(string nombre);

    // Metodos

};

#endif // PROVEEDOR_H
