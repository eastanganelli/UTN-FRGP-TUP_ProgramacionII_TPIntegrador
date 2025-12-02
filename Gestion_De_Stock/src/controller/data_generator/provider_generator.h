#ifndef PROVIDER_GENERATOR_H
#define PROVIDER_GENERATOR_H

#include <ctime>
#include <string>
#include <iostream>

using namespace std;
#include "generator.h"
#include "../../manager/manager_proveedor.h"

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
    void GenerateProviders(unsigned int count = 5, bool printLog = false);
}

#endif // PROVIDER_GENERATOR_H