#include "client_generator.h"

void DataGenerator::GenerateClients(unsigned int count, bool printLog) {
    srand(static_cast<unsigned int>(time(NULL)));
    ClienteManager clientes("clientes.dat");

    string nombres[]   = {"Juan", "Maria", "Carlos", "Ana", "Luis", "Sofia", "Miguel", "Laura", "Diego", "Elena",
                            "Jorge", "Carmen", "Pedro", "Lucia", "Andres", "Marta", "Fernando", "Isabel", "Ricardo", "Patricia", "Alberto", "Gabriela"},
            apellidos[] = {"Perez", "Gomez", "Rodriguez", "Lopez", "Garcia", "Martinez", "Sanchez", "Ramirez", "Torres", "Flores",
                            "Diaz", "Vargas", "Castro", "Rojas", "Silva", "Molina", "Suarez", "Ortega", "Gutierrez", "Jimenez", "Morales", "Alvarez"},
            calles[]    = {"Calle Falsa", "Avenida Siempreviva", "Boulevard Central", "Pasaje del Sol", "Camino Real",
                            "Paseo de las Flores", "Calle del Lago", "Avenida de la Libertad", "Callejón del Beso", "Paseo del Parque",
                            "Calle de la Amistad", "Avenida del Mar", "Boulevard de los Sueños", "Pasaje de la Luna", "Camino del Viento"};

    if(clientes.Count() == 0) {
        std::cout << "--- Datos de Clientes Generados ---" << std::endl;
        for (int i = 0; i < 10; ++i) {
            DataGenerator::DatosCliente dc;
            dc.nombre = nombres[rand() % nombres->length()];
            dc.apellido = apellidos[rand() % apellidos->length()];
            dc.DNI = std::to_string(40000000 + 10000000 + i);
            dc.cuilCuit = "20" + dc.DNI + "1";
            dc.direccion = calles[rand() % calles->length()] + std::to_string(rand() % 9999 + 1);
            dc.correo = dc.apellido + "." + dc.nombre + "@example.com";
            dc.telefono = "4" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000);
            dc.celular = "11-" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000);
            dc.alta = (i % 2 == 0);

            Cliente dataCliente(dc.nombre, dc.apellido, dc.DNI, dc.cuilCuit, dc.direccion, dc.correo, dc.telefono, dc.celular, dc.alta);
            if(printLog) {
                cout << "Cliente agregado? >> " << (clientes.New(dataCliente) ? "Si" : "No") << endl;
                dataCliente.Print();
            } else {
                clientes.New(dataCliente);
            }
        }
        if(printLog)
            std::cout << "\n-------------------------------------\n" << std::endl;
    } else {
        std::cout << "Los clientes ya existen. No se generaron nuevos datos." << std::endl;
    }
}
