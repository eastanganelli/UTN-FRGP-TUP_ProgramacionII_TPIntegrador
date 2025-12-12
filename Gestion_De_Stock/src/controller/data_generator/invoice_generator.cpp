#include "invoice_generator.h"

void DataGenerator::GenerateInvoices(unsigned int count, bool printLog) {
    srand(static_cast<unsigned int>(time(NULL)));

    FacturaManager facturas;
    ProductoManager productos;
    ProveedorManager proveedores;
    ClienteManager clientes;
    TipoResponsableManager tipos;

    if (facturas.Count() == 0) {
        std::cout << "--- Datos de Facturas Generados ---" << std::endl;

        unsigned int prodCount = productos.Count();
        unsigned int provCount = proveedores.Count();
        unsigned int cliCount = clientes.Count();

        if (prodCount == 0 || cliCount == 0) {
            if (printLog)
                std::cout << "No hay productos o clientes suficientes para generar facturas." << std::endl;
            return;
        }

        for (unsigned int i = 0; i < count; ++i) {
            Cliente* cliente = clientes.At(rand() % cliCount);
            string clienteDNI = cliente->getDNI();

            // Obtener codigoRazonSocial desde el cliente (vinculo a TipoResponsable)
            string codigoRazon = cliente->getCodigoRazonSocial();

            unsigned int id = 1000 + i;
//            unsigned int index;
//            string tipo = tipos.At(index)->getCodigo();

            Factura f(id, clienteDNI);

            unsigned int itemsCount = (rand() % 6) + 1;
            for (unsigned int it = 0; it < itemsCount; ++it) {
                Producto* p = productos.At(rand() % prodCount);
                string codigoProducto = p->getCodigo();
                float precioUnitario = p->getPrecio();
                unsigned int cantidad = (rand() % 5) + 1;

                Item item(codigoProducto.c_str(), cantidad, precioUnitario);
                f.AgregarItem(item);
            }

            // Si la factura tiene items, generar CAE antes de persistir
            if (f.CantidadItems() > 0) f.Facturar();

            bool added = facturas.New(f);
            if (printLog)
                cout << endl << "Factura agregada? >> " << (added ? "Si" : "No") << endl;

            // Intentar leer la factura recién guardada desde el archivo
            Factura* saved = nullptr;
            if (added) {
                unsigned int total = facturas.Count();
                if (total > 0) {
                    saved = facturas.At(total - 1);
                }
            }

            if (saved != nullptr) {
                // Calcular porcentaje de IVA consultando TipoResponsableManager
//                TipoResponsable* tr = nullptr;
//                if (!Validation::IsEmpty(codigoRazon)) {
//                    tr = tipos[codigoRazon];
//                }
//                float porcentaje = (tr != nullptr) ? tr->getPorcentaje() : 21.0f;

                float neto = saved->TotalSinIVA();
                float totalConIVA = neto * (1.0f + 1 / 100.0f);

                if (printLog) {
                    cout << "Factura leida del archivo - ID: " << saved->getNumero()
                        << " | Cliente: " << saved->getClienteDNI()
                        //  << " | Tipo: " << saved->getTipoFactura()
                        << " | Neto: " << neto
    //                     << " | IVA(%): " << porcentaje
                        << " | Total c/IVA: " << totalConIVA
                        << " | Items: " << saved->CantidadItems() << std::endl;

                    for (unsigned int k = 0; k < saved->CantidadItems(); ++k) {
                        const Item* it = saved->ObtenerItem(k);
                        if (it != nullptr) {
                            cout << "  - Item codigo: " << it->getCodigo() << std::endl;
                        }
                    }
                }

                delete saved; // FileSystem::At devuelve un nuevo puntero
            } else {
                // Fallback: imprimir la factura auxiliar en memoria
//                TipoResponsableManager tipos;
//                TipoResponsable* tr = nullptr;
//                if (codigoRazon > 0 && codigoRazon < tipos.Count()) tr = tipos[codigoRazon];
//                float porcentaje = (tr != nullptr) ? tr->getPorcentaje() : 21.0f;

                float neto = f.TotalSinIVA();
                float totalConIVA = neto * (1.0f + 1 / 100.0f);

                if (printLog) {
                    cout << "Factura (no encontrada en archivo) - ID: " << f.getNumero()
                        << " | Cliente: " << f.getClienteDNI()
                        //  << " | Tipo: " << f.getTipoFactura()
                        << " | Neto: " << neto
    //                     << " | IVA(%): " << porcentaje
                        << " | Total c/IVA: " << totalConIVA
                        << " | Items: " << f.CantidadItems() << std::endl;

                    for (unsigned int k = 0; k < f.CantidadItems(); ++k) {
                        const Item* it = f.ObtenerItem(k);
                        if (it != nullptr) {
                            cout << "  - Item codigo: " << it->getCodigo() << std::endl;
                        }
                    }
                }
            }
        }
        if (printLog)
            std::cout << "\n-------------------------------------\n" << std::endl;
    } else {
        std::cout << "Las facturas ya existen. No se generaron nuevos datos." << std::endl;
    }
}
