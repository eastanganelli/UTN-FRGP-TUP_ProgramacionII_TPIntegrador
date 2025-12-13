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
    Cliente(string _nombre = "", string _apellido = "", string _DNI = "", string _cuilCuit = "", string direccion = "", string correo = "", string _telefono = "", string _celular = "", bool _alta = true);
    ~Cliente();

    // Getters
    string getDNI();
    string getNombre();
    string getApellido();
    string getCuilCuit();

    static unsigned int GetDniSize();
    static unsigned int GetNombreSize();
    static unsigned int GetApellidoSize();
    static unsigned int GetCuilCuitSize();

    // Column-size accessors (align with other main_classes naming)
    static unsigned int ColDniSize();
    static unsigned int ColNombreSize();
    static unsigned int ColApellidoSize();
    static unsigned int ColCuilCuitSize();

    // Setters
    void setDNI(const string& dni);
    void setNombre(const string& n);
    void setApellido(const string& a);
    void setCuilCuit(const string& cuilCuit);

    // Métodos
    bool operator==(Cliente& cliente);
    bool IsEmpty();
    void Print();
};

#endif // CLIENTE_H
