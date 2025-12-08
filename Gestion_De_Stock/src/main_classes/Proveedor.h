#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <iostream>

#include "../controller/validation.h"
#include "datos_personales.h"

using namespace std;

class Proveedor : public DatosPersonales {
private:
    static const unsigned int CUIT_SIZE = 12;
    static const unsigned int NOMBRE_RAZON_SIZE = 35;
    static const unsigned int COL_CUIT = 14;
    static const unsigned int COL_NOMBRE_RAZON = 36;

    char cuit[CUIT_SIZE];
    char nombreRazon[NOMBRE_RAZON_SIZE];
    unsigned int rubro;

public:
    Proveedor(string _cuit = "", string _nombreRazon = "", unsigned int _rubro = 0, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", string _razonSocial = "", bool _alta = false);
    ~Proveedor();

    // Getters
    bool getAlta();
    string getCuit();
    unsigned int getRubro();
    string getRubroNombre();
    string getNombreRazon();

    static unsigned int ColCuitSize();
    static unsigned int ColNombreRazonSize();

    // Setters
    void setAlta(bool alta);
    void setRubro(unsigned int rubro);
    void setNombreRazon(string nombre);

    // Metodos
    bool operator==(const Proveedor& otro);
    bool IsEmpty();
    void Print();
    static Proveedor NuevoProveedor();
    static void ModificarProveedor(Proveedor& proveedor);
    static unsigned int EliminarProveedor(Proveedor& proveedor);
};

#endif // PROVEEDOR_H
