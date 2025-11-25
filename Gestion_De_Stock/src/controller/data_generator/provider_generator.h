#include <ctime>
#include <string>
#include <iostream>

using namespace std;

#include "../../manager/proveedor_manager.h"

namespace DataGenerator {
    struct DatosProveedor {
        std::string cuit;
        std::string nombreRazon;
        unsigned int rubro;
        std::string direccion;
        std::string correo;
        std::string telefono;
        std::string celular;
        unsigned int codigoRazonSocial;
        bool alta;
    };
    void GenerateProviders(unsigned int count = 0);
}