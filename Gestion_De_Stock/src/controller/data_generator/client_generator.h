#ifndef CLIENT_GENERATOR_H
#define CLIENT_GENERATOR_H

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

#include "../../manager/manager_cliente.h"

namespace DataGenerator {
     struct DatosCliente {
        std::string nombre;
        std::string apellido;
        std::string DNI;
        std::string cuilCuit;
        std::string direccion;
        std::string correo;
        std::string telefono;
        std::string celular;
        std::string codigoRazonSocial;
        bool alta;
    };
    void GenerateClients(unsigned int count = 15, bool printLog = false);
}

#endif // CLIENT_GENERATOR_H