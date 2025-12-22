#ifndef CLIENTE_H
#define CLIENTE_H

#include "datos_personales.h"
#include "../controller/validation.h"
#include "../menu/menu_utils.h"

#include <iostream>
#include <cstring>
#include <string>


using namespace std;

class Cliente : public DatosPersonales {
private:
    static const unsigned int DNI_SIZE = 9;
    static const unsigned int NOMBRE_SIZE = 20;
    static const unsigned int APELLIDO_SIZE = 20;
    static const unsigned int CUIL_CUIT_SIZE = 12;

    // Column widths (for table printing) — restored for consistency with other classes
    static const unsigned int COL_DNI = 12;
    static const unsigned int COL_NOMBRE = 25;
    static const unsigned int COL_APELLIDO = 25;
    static const unsigned int COL_CUIL_CUIT = 15;

    char DNI[DNI_SIZE];
    char nombre[NOMBRE_SIZE];
    char apellido[APELLIDO_SIZE];
    char cuilCuit[CUIL_CUIT_SIZE];

public:
    /** Crea un cliente con datos personales y fiscales. */
    Cliente(string _nombre = "", string _apellido = "", string _DNI = "", string _cuilCuit = "", string direccion = "", string correo = "", string _telefono = "", string _celular = "", bool _alta = true, string _codigoRazonSocial = "");
    /** Destructor de cliente. */
    ~Cliente();

    /** Obtiene el DNI. */
    string getDNI();
    /** Obtiene el nombre. */
    string getNombre();
    /** Obtiene el apellido. */
    string getApellido();
    /** Obtiene CUIL/CUIT. */
    string getCuilCuit();

    static unsigned int GetDniSize();
    static unsigned int GetNombreSize();
    static unsigned int GetApellidoSize();
    static unsigned int GetCuilCuitSize();

    /** Ancho de columna para DNI. */
    static unsigned int ColDniSize();
    /** Ancho de columna para Nombre. */
    static unsigned int ColNombreSize();
    /** Ancho de columna para Apellido. */
    static unsigned int ColApellidoSize();
    /** Ancho de columna para CUIL/CUIT. */
    static unsigned int ColCuilCuitSize();

    /** Actualiza el DNI. */
    void setDNI(const string& dni);
    /** Actualiza el nombre. */
    void setNombre(const string& n);
    /** Actualiza el apellido. */
    void setApellido(const string& a);
    /** Actualiza CUIL/CUIT. */
    void setCuilCuit(const string& cuilCuit);

    /** Compara igualdad de clientes. */
    bool operator==(Cliente& cliente);
    /** Indica si el cliente esta vacio. */
    bool IsEmpty();
    /** Imprime datos del cliente. */
    void Print();
};

#endif // CLIENTE_H
