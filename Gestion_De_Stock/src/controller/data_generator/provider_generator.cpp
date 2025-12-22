#include "provider_generator.h"

void DataGenerator::GenerateProviders(unsigned int count, bool printLog) {
    srand(static_cast<unsigned int>(time(NULL)));
    ProveedorManager proveedores;

    string calles[] = {"Calle Falsa", "Avenida Siempreviva", "Boulevard Central", "Pasaje del Sol", "Camino Real",
                    "Paseo de las Flores", "Calle del Lago", "Avenida de la Libertad", "Callejón del Beso", "Paseo del Parque",
                    "Calle de la Amistad", "Avenida del Mar", "Boulevard de los Sueños", "Pasaje de la Luna", "Camino del Viento"};

    if(proveedores.Count() == 0) {
        std::cout << "--- Datos de Proveedores Generados ---" << std::endl;
        for (int i = 0; i < (int)count; ++i) {
            DatosProveedor dp;
            dp.cuit = "30" + std::to_string(rand() % 40000000 + 10000000 + i) + "9";
            dp.nombreRazon = "Proveedor SA " + generarCodigoAlfaNumerico(6);
            dp.rubro = (i % 6) + 1;
            dp.direccion = calles[rand() % calles->length()] + std::to_string(rand() % 9999 + 1);
            dp.correo = "info@" + dp.nombreRazon.substr(0, dp.nombreRazon.find(" ")) + ".com";
            dp.telefono = generarNumero(DatosPersonales::GetTelefonoSize() - 1);
            dp.celular = generarNumero(DatosPersonales::GetCelularSize() - 1);
            dp.alta = (i % 2 != 0);

            Proveedor dataProveedor(dp.cuit, dp.nombreRazon, dp.rubro, dp.direccion, dp.correo, dp.telefono, dp.celular, "", dp.alta);
            if (printLog) {
                cout << endl << "Proveedor agregado? >> " << (proveedores.New(dataProveedor) ? "Si" : "No") << endl;
                dataProveedor.Print();
                cout << endl;
            } else {
                proveedores.New(dataProveedor);
            }
        }
        if (printLog)
            std::cout << "\n-------------------------------------\n" << std::endl;
    } else {
        std::cout << "Los datos de proveedores ya existen. No se generaron nuevos datos." << std::endl;
    }
}
