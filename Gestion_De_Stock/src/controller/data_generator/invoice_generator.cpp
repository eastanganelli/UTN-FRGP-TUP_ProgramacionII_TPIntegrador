#include "invoice_generator.h"

const float IVA_RATE = 0.21f;

void DataGenerator::LogFacturaBasica(Factura& f, bool printItems) {
    const float neto = f.TotalSinIVA();
    const float totalConIVA = neto * (1.0f + IVA_RATE);

    cout << "Factura - ID: " << f.getNumero()
         << " | Cliente: " << f.getClienteDNI()
         << " | Neto: " << neto
         << " | Total c/IVA: " << totalConIVA
         << " | Items: " << f.CantidadItems() << std::endl;

    if (!printItems) return;

    for (unsigned int k = 0; k < f.CantidadItems(); ++k) {
        const Item* it = f.ObtenerItem(k);
        if (it != nullptr) {
            cout << "  - Item codigo: " << it->getCodigo() << std::endl;
        }
    }
}

void DataGenerator::CollectClientes(ClienteManager& clientes, GenericArray<string>& dnis) {
    const unsigned int cliCount = clientes.Count();
    for (unsigned int c = 0; c < cliCount; ++c) {
        Cliente* cli = clientes.At(c);
        if (cli != nullptr) {
            string dni = cli->getDNI();
            dnis.Append(dni);
            delete cli;
        }
    }
}

void DataGenerator::ShuffleDnis(GenericArray<string>& dnis) {
    if (dnis.Size() < 2) return;
    // Fisher-Yates sin STL
    for (int i = static_cast<int>(dnis.Size()) - 1; i > 0; --i) {
        unsigned int j = static_cast<unsigned int>(rand() % (i + 1));
        dnis.Swap(dnis[static_cast<unsigned int>(i)], dnis[j]);
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

void DataGenerator::GenerateInvoices(unsigned int count, bool printLog) {
    srand(time(NULL));

    FacturaManager facturas;
    NotaDeCreditoManager notas;
    ProductoManager productos;
    ProveedorManager proveedores;
    ClienteManager clientes;
    TipoResponsableManager tipos;

    if (facturas.Count() == 0) {
        std::cout << "--- Datos de Facturas Generados ---" << std::endl;

        unsigned int prodCount = productos.Count();
        unsigned int cliCount = clientes.Count();

        if (prodCount == 0 || cliCount == 0) {
            if (printLog) {
                Warning w("Sin datos", "No hay productos o clientes suficientes para generar facturas.");
                w.Show(); w.WaitForKey();
            }
            return;
        }

        GenericArray<string> clientDnis;
        CollectClientes(clientes, clientDnis);
        ShuffleDnis(clientDnis);

        GenericArray<unsigned int> facturasConCAE;

        for (unsigned int i = 0; i < count; ++i) {
            const string clienteDNI = *clientDnis[i % clientDnis.Size()];

            unsigned int id = 1000 + i;

            Factura f(id, clienteDNI);
            Fecha aux = RandomFechaWithinDays(180);
            f.setFechaEmision(aux);

            unsigned int itemsCount = (rand() % 10) + 1;
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

            if (f.CantidadItems() > 0 && (rand() % 100) < 70) {
                if (f.Facturar() && !Validation::IsEmpty(f.getCAE())) {
                    unsigned int nro = f.getNumero();
                    facturasConCAE.Append(nro);
                }
            }

            bool added = facturas.New(f);
            if (printLog)
                cout << endl << "Factura agregada? >> " << (added ? "Si" : "No") << endl;

            Factura* saved = nullptr;
            if (added) {
                unsigned int total = facturas.Count();
                if (total > 0) {
                    saved = facturas.At(total - 1);
                }
            }

            if (saved != nullptr) {
                if (printLog) {
                    cout << "Factura leida del archivo -> ";
                    LogFacturaBasica(*saved, true);
                }
                delete saved; // FileSystem::At devuelve un nuevo puntero
            } else if (printLog) {
                cout << "Factura (no encontrada en archivo, auxiliar) -> ";
                LogFacturaBasica(f, true);
            }
        }

        // Convertir algunas facturas facturadas en notas de credito
        for (unsigned int idx = 0; idx < facturasConCAE.Size(); ++idx) {
            if ((rand() % 100) >= 20) continue; // 20% se anulan
            unsigned int nro = *facturasConCAE[idx];
            Factura* fac = facturas[nro];
            if (fac == nullptr) continue;
            if (Validation::IsEmpty(fac->getCAE())) { delete fac; continue; }

            NotaDeCredito nota(fac->getNumero(), fac->getClienteDNI(), "Anulada por generador");
            Fecha aux = Fecha::Hoy();
            nota.setFechaEmision(aux);

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
