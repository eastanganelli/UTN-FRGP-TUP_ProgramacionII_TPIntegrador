#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "DatosPersonales.h"

#include <cstring>

using namespace std;

class Proveedor : public DatosPersonales {
private:
    char cuit[12];
    char nombreRazon[35];
    unsigned int rubro;

public:
    Proveedor(string _cuit = "", string _nombreRazon = "", unsigned int _rubro = 0, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", bool _alta = false);
    ~Proveedor();

    // Getters
    bool getAlta();
    string getCuit();
    unsigned int getRubro();
    string getRubroNombre();
    string getNombreRazon();

    // Setters
    void setAlta(bool alta);
    void setRubro(unsigned int rubro);
    void setNombreRazon(string nombre);

    // Metodos
    string toString();
};

#endif // PROVEEDOR_H
