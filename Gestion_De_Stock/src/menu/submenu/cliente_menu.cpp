#include "cliente_menu.h"
#include <iostream>

using namespace std;

ClienteMenu::ClienteMenu() : Menu("Menu Clientes", true) {
    AddOption("Agregar Cliente");
    AddOption("Modificar Cliente");
    AddOption("Eliminar Cliente");
    AddOption("Listar Por DNI");
    AddOption("Listar Por CUIL/CUIT");
    AddOption("Listar Por Apellido");
    AddOption("Buscar por DNI");
    AddOption("Buscar por CUIL/CUIT");
    AddOption("Buscar por Nombre y Apellido");
    AddOption("Buscar por Correo");
    AddOption("Volver");
} 

Cliente ClienteMenu::CrearCliente() {
    Cliente nuevoCliente;
    string v;

    // Nombre (solo letras y espacios)
    while (true) {
        v = InputBox("Nombre: ");
        string tmp = v;
        Validation::RemoveSpaces(tmp);
        if (Validation::IsEmpty(v) || !Validation::IsAlphabetic(tmp)) {
            Warning w("Nombre invalido", "Ingrese solo letras para el nombre.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setNombre(v);
        break;
    }

    // Apellido (solo letras y espacios)
    while (true) {
        v = InputBox("Apellido: ");
        string tmp = v;
        Validation::RemoveSpaces(tmp);
        if (Validation::IsEmpty(v) || !Validation::IsAlphabetic(tmp)) {
            Warning w("Apellido invalido", "Ingrese solo letras para el apellido.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setApellido(v);
        break;
    }

    // DNI (solo digitos, longitud max)
    while (true) {
        v = InputBox("DNI: ");
        if (!Validation::IsNumeric(v) || v.length() >= Cliente::GetDniSize()) {
            Warning w("DNI invalido", "Ingrese solo digitos y longitud correcta para el DNI.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setDNI(v);
        break;
    }

    // CUIL/CUIT (alfanum, longitud max)
    while (true) {
        v = InputBox("CUIL/CUIT: ");
        if (Validation::IsEmpty(v) || v.length() >= Cliente::GetCuilCuitSize() || !Validation::IsAlphanumeric(v)) {
            Warning w("CUIL/CUIT invalido", "Ingrese CUIL/CUIT valido (solo letras y/o digitos, longitud correcta).");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setCuilCuit(v);
        break;
    }

    // Direccion (no vacio, longitud)
    while (true) {
        v = InputBox("Direccion: ");
        if (Validation::IsEmpty(v) || v.length() >= DatosPersonales::GetDireccionSize()) {
            Warning w("Direccion invalida", "Ingrese una direccion valida y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setDireccion(v);
        break;
    }

    // Correo (contiene @ y ., longitud)
    while (true) {
        v = InputBox("Correo: ");
        if (Validation::IsEmpty(v) || v.length() >= DatosPersonales::GetCorreoSize() || v.find('@') == string::npos || v.find('.') == string::npos) {
            Warning w("Correo invalido", "Ingrese un correo valido (contiene @ y .) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setCorreo(v);
        break;
    }

    // Telefono (solo digitos, longitud)
    while (true) {
        v = InputBox("Telefono: ");
        if (Validation::IsEmpty(v) || !Validation::IsNumeric(v) || v.length() >= DatosPersonales::GetTelefonoSize()) {
            Warning w("Telefono invalido", "Ingrese un telefono valido (solo digitos) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setTelefono(v);
        break;
    }

    // Celular (solo digitos, longitud)
    while (true) {
        v = InputBox("Celular: ");
        if (Validation::IsEmpty(v) || !Validation::IsNumeric(v) || v.length() >= DatosPersonales::GetCelularSize()) {
            Warning w("Celular invalido", "Ingrese un celular valido (solo digitos) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nuevoCliente.setCelular(v);
        break;
    }
    return nuevoCliente;
}

void ClienteMenu::ModificarClienteInteractivo(Cliente& cliente) {
    unsigned int opcion = 0;
    string entrada;
    do {
        rlutil::cls();
        cout << "-- Modificar Cliente --\n";
        cout << "1) Nombre: " << cliente.getNombre() << "\n";
        cout << "2) Apellido: " << cliente.getApellido() << "\n";
        cout << "3) CUIL/CUIT: " << cliente.getCuilCuit() << "\n";
        cout << "4) Direccion: " << cliente.getDireccion() << "\n";
        cout << "5) Correo: " << cliente.getCorreo() << "\n";
        cout << "6) Telefono: " << cliente.getTelefono() << "\n";
        cout << "7) Celular: " << cliente.getCelular() << "\n";
        cout << "8) Terminar\n";

        opcion = InputNumber("Seleccione campo a modificar: ");

        switch(opcion) {
            case 1: { // Nombre
                while (true) {
                    entrada = InputBox("Nuevo Nombre: ");
                    string tmp = entrada;
                    Validation::RemoveSpaces(tmp);
                    if (Validation::IsEmpty(entrada) || !Validation::IsAlphabetic(tmp)) {
                        Warning w("Nombre invalido", "Ingrese solo letras para el nombre.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    cliente.setNombre(entrada);
                    Informational i("Nombre modificado", "Nombre actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 2: { // Apellido
                while (true) {
                    entrada = InputBox("Nuevo Apellido: ");
                    string tmp = entrada;
                    Validation::RemoveSpaces(tmp);
                    if (Validation::IsEmpty(entrada) || !Validation::IsAlphabetic(tmp)) {
                        Warning w("Apellido invalido", "Ingrese solo letras para el apellido.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    cliente.setApellido(entrada);
                    Informational i("Apellido modificado", "Apellido actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 3: { // CUIL/CUIT
                while (true) {
                    entrada = InputBox("Nuevo CUIL/CUIT: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= Cliente::GetCuilCuitSize() || !Validation::IsAlphanumeric(entrada)) {
                        Warning w("CUIL/CUIT invalido", "Ingrese CUIL/CUIT valido (solo letras y/o digitos, longitud correcta).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    cliente.setCuilCuit(entrada);
                    Informational i("CUIL/CUIT modificado", "CUIL/CUIT actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 4: { // Direccion
                while (true) {
                    entrada = InputBox("Nueva Direccion: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= DatosPersonales::GetDireccionSize()) {
                        Warning w("Direccion invalida", "Ingrese una direccion valida y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    cliente.setDireccion(entrada);
                    Informational i("Direccion modificada", "Direccion actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 5: { // Correo
                while (true) {
                    entrada = InputBox("Nuevo Correo: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= DatosPersonales::GetCorreoSize() || entrada.find('@') == string::npos || entrada.find('.') == string::npos) {
                        Warning w("Correo invalido", "Ingrese un correo valido (contiene @ y .) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    cliente.setCorreo(entrada);
                    Informational i("Correo modificado", "Correo actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 6: { // Telefono
                while (true) {
                    entrada = InputBox("Nuevo Telefono: ");
                    if (Validation::IsEmpty(entrada) || !Validation::IsNumeric(entrada) || entrada.length() >= DatosPersonales::GetTelefonoSize()) {
                        Warning w("Telefono invalido", "Ingrese un telefono valido (solo digitos) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    cliente.setTelefono(entrada);
                    Informational i("Telefono modificado", "Telefono actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 7: { // Celular
                while (true) {
                    entrada = InputBox("Nuevo Celular: ");
                    if (Validation::IsEmpty(entrada) || !Validation::IsNumeric(entrada) || entrada.length() >= DatosPersonales::GetCelularSize()) {
                        Warning w("Celular invalido", "Ingrese un celular valido (solo digitos) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    cliente.setCelular(entrada);
                    Informational i("Celular modificado", "Celular actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 8: { // Terminar
                break;
            }
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida (1-9).");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 8);
    rlutil::cls();
}

bool ClienteMenu::EliminarClienteInteractivo(Cliente& cliente) {
    Warning w("Eliminar Cliente", "Ests seguro que desea eliminar este cliente?");
    if (w.ShowYesNo()) {
        cliente.setAlta(false);
        return true;
    }
    return false;
}

bool ClienteMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            Cliente nuevoCliente = CrearCliente();
            if(clientes.Agregar(nuevoCliente)) cout << "Cliente agregado exitosamente." << endl;
            else cout << "Error al agregar el cliente." << endl;
            return false;
        }
        case 1: {
            string dni = InputBox("DNI del cliente a modificar: ");
            Cliente* cliente = clientes[dni];
            if (cliente == nullptr) {
                cout << "Cliente no encontrado." << endl;
                PauseConsole();
                return false;
            }
            ModificarClienteInteractivo(*cliente);

            if (clientes.Modificar(dni, cliente)) cout << "Cliente modificado exitosamente." << endl;
            else cout << "Error al modificar el cliente." << endl;
            PauseConsole();
            return false;
        }
        case 2: {
            string dni = InputBox("DNI del cliente a eliminar: ");
            Cliente* cliente = clientes[dni];
            if (cliente == nullptr) {
                cout << "Cliente no encontrado." << endl;
                PauseConsole();
                return false;
            }
            bool confirma = EliminarClienteInteractivo(*cliente);
            delete cliente;
            if (confirma) {
                if (clientes.Eliminar(dni)) cout << "Cliente eliminado exitosamente." << endl;
                else cout << "Error al eliminar el cliente." << endl;
            } else cout << "Operacion cancelada." << endl;
            PauseConsole();
            return false;
        }
        case 3: {
            clientes.ListarPorDNI();
            PauseConsole();
            return false;
        }
        case 4: {
            clientes.ListarPorCuil_Cuit();
            PauseConsole();
            return false;
        }
        case 5: {
            clientes.ListarPorApellido();
            PauseConsole();
            return false;
        }
        case 6: {
            string dni = InputBox("DNI: ");
            auto res = clientes.BuscarPorDNI(dni);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            string cuilCuit = InputBox("CUIL/CUIT: ");
            auto res = clientes.BuscarPorCUIL_CUIT(cuilCuit);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 8: {
            string nombre = InputBox("Nombre: "),
                   apellido = InputBox("Apellido: ");
            auto res = clientes.BuscarPorNombreApellido(nombre, apellido);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 9: {
            string correo = InputBox("Correo: ");
            auto res = clientes.BuscarPorCorreo(correo);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 10: {
            return true; // Volver
        }
        default:
            return false;
    }
}
