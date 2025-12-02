#ifndef PRODUCT_GENERATOR_H
#define PRODUCT_GENERATOR_H

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

#include "generator.h"
#include "../../manager/manager_proveedor.h"
#include "../../manager/manager_producto.h"

namespace DataGenerator {
    struct DatosProducto {
        std::string codigo;
        std::string codigoProveedor;
        std::string descripcion;
        float precio;
        unsigned int stock;
    };
    void GenerateProduct(unsigned int count = 30, bool printLog = false);
}

#endif // PRODUCT_GENERATOR_H