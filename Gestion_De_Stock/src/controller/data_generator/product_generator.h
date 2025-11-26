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
    void GenerateProduct(unsigned int count = 30);
}
