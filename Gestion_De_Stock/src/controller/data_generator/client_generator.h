#include <ctime>
#include <string>
#include <iostream>

using namespace std;

#include "../../manager/cliente_manager.h"

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
        unsigned int codigoRazonSocial;
        bool alta;
    };
    void GenerateClients(unsigned int count = 0);
}