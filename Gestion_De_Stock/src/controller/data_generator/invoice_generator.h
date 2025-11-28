#include <ctime>
#include <string>
#include <iostream>

using namespace std;

#include "generator.h"
#include "client_generator.h"
#include "product_generator.h"
#include "provider_generator.h"

#include "../../manager/manager_factura.h"
#include "../../manager/manager_producto.h"
#include "../../manager/manager_proveedor.h"
#include "../../manager/manager_cliente.h"
#include "../../manager/manager_tipo_responsables.h"

#include "../../main_classes/ventas/Item.h"

namespace DataGenerator {
    struct DatosFactura {
        unsigned int id;
        std::string clienteDNI;
        unsigned int cantidadItems;
        char tipoFactura;
    };

    void GenerateInvoices(unsigned int count = 10);
}
