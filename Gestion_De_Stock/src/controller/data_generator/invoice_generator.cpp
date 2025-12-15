#include "invoice_generator.h"

#include <vector>
#include <algorithm>
#include "../validation.h"

void DataGenerator::GenerateInvoices(unsigned int count, bool printLog) {
    srand(static_cast<unsigned int>(time(NULL)));

    FacturaManager facturas;
    NotaDeCreditoManager notas;
    ProductoManager productos;
    ProveedorManager proveedores;
    ClienteManager clientes;
    TipoResponsableManager tipos;

    if (facturas.Count() == 0) {
        std::cout << "--- Datos de Facturas Generados ---" << std::endl;

        unsigned int prodCount = productos.Count();
        // unsigned int provCount = proveedores.Count();
        unsigned int cliCount = clientes.Count();

        if (prodCount == 0 || cliCount == 0) {
            if (printLog)
                std::cout << "No hay productos o clientes suficientes para generar facturas." << std::endl;
            return;
        }

        // Distribuir clientes de forma rotativa para no repetir siempre el mismo
        std::vector<string> clientDnis;
        clientDnis.reserve(cliCount);
        for (unsigned int c = 0; c < cliCount; ++c) {
            Cliente* cli = clientes.At(c);
            if (cli != nullptr) {
                clientDnis.push_back(cli->getDNI());
                delete cli;
            }
        }
        if (clientDnis.size() > 1) {
            std::random_shuffle(clientDnis.begin(), clientDnis.end());
        }

        std::vector<unsigned int> facturasConCAE;

        for (unsigned int i = 0; i < count; ++i) {
            const string& clienteDNI = clientDnis[i % clientDnis.size()];

            unsigned int id = 1000 + i;

            Factura f(id, clienteDNI);
            f.getFechaEmision() = DataGenerator::RandomFechaWithinDays(180);

            unsigned int itemsCount = (rand() % 6) + 1;
            for (unsigned int it = 0; it < itemsCount; ++it) {
                Producto* p = productos.At(rand() % prodCount);
                if (p == nullptr) continue;
                string codigoProducto = p->getCodigo();
                float precioUnitario = p->getPrecio();
                unsigned int cantidad = (rand() % 5) + 1;
                delete p;

                Item item(codigoProducto.c_str(), cantidad, precioUnitario);
                f.AgregarItem(item);
            }

            // Solo algunas facturas obtienen CAE para mezclar facturadas y pendientes
            if (f.CantidadItems() > 0 && (rand() % 100) < 70) {
                if (f.Facturar() && !Validation::IsEmpty(f.getCAE())) {
                    facturasConCAE.push_back(f.getNumero());
                }
            }

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

        // Convertir algunas facturas facturadas en notas de credito
        for (unsigned int idx = 0; idx < facturasConCAE.size(); ++idx) {
            if ((rand() % 100) >= 20) continue; // 20% se anulan
            unsigned int nro = facturasConCAE[idx];
            Factura* fac = facturas[nro];
            if (fac == nullptr) continue;
            if (Validation::IsEmpty(fac->getCAE())) { delete fac; continue; }

            NotaDeCredito nota(fac->getNumero(), fac->getClienteDNI(), "Anulada por generador");
            nota.getFechaEmision() = Fecha::Hoy();

            for (unsigned int it = 0; it < fac->CantidadItems(); ++it) {
                const Item* item = fac->ObtenerItem(it);
                if (item != nullptr) nota.AgregarItem(*item);
            }

            bool notaOk = notas.Agregar(nota);
            bool factDel = false;
            if (notaOk) {
                factDel = facturas.Eliminar(nro);
                if (!factDel) {
                    notas.Eliminar(nota.getNumero());
                }
            }

            if (printLog) {
                cout << "Factura " << nro << (notaOk && factDel ? " anulada y convertida a NC" : " no pudo anularse") << endl;
            }
            delete fac;
        }
        if (printLog)
            std::cout << "\n-------------------------------------\n" << std::endl;
    } else {
        std::cout << "Las facturas ya existen. No se generaron nuevos datos." << std::endl;
    }
}

Fecha DataGenerator::RandomFechaWithinDays(int spanDays) {
    time_t now = time(nullptr);
    int span = spanDays > 0 ? spanDays : 1;
    int offset = rand() % span;
    time_t target = now - static_cast<time_t>(offset * 24 * 3600);
    tm* ltm = localtime(&target);
    return Fecha(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
}
