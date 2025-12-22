#ifndef INVOICE_GENERATOR_H
#define INVOICE_GENERATOR_H

#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

#include "../validation.h"
#include "../modals/warning.h"

#include "generator.h"
#include "client_generator.h"
#include "product_generator.h"
#include "provider_generator.h"

#include "../../manager/ventas/manager_factura.h"
#include "../../manager/ventas/manager_nota_de_credito.h"
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

    void LogFacturaBasica(Factura& f, bool printItems);
    void CollectClientes(ClienteManager& clientes, GenericArray<string>& dnis);
    void ShuffleDnis(GenericArray<string>& dnis);
    Fecha RandomFechaWithinDays(int spanDays);
    void GenerateInvoices(unsigned int count = 30, bool printLog = false);
}

#endif // INVOICE_GENERATOR_H
