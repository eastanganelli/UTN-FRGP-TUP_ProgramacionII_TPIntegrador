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
    /** Crea un proveedor con datos de contacto y rubro. */
    Proveedor(string _cuit = "", string _nombreRazon = "", unsigned int _rubro = 0, string _direccion = "", string _correo = "", string _telefono = "", string _celular = "", string _razonSocial = "", bool _alta = false);
    /** Destructor de proveedor. */
    ~Proveedor();

    /** Indica si el proveedor esta de alta. */
    bool getAlta();
    /** Obtiene CUIT. */
    string getCuit();
    /** Obtiene el rubro. */
    unsigned int getRubro();
    /** Obtiene el nombre del rubro. */
    string getRubroNombre();
    /** Obtiene nombre o razon social. */
    string getNombreRazon();

    static unsigned int GetCuitSize();
    static unsigned int GetNombreRazonSize();

    static unsigned int ColCuitSize();
    static unsigned int ColNombreRazonSize();

    /** Actualiza alta/baja. */
    void setAlta(bool alta);
    /** Actualiza rubro. */
    void setRubro(unsigned int rubro);
    /** Actualiza nombre o razon social. */
    void setNombreRazon(string nombre);
    /** Actualiza CUIT. */
    void setCuit(string cuit);

    /** Compara igualdad de proveedores. */
    bool operator==(const Proveedor& otro);
    /** Indica si el proveedor esta vacio. */
    bool IsEmpty();
    /** Imprime datos del proveedor. */
    void Print();
};

#endif // PROVEEDOR_H
