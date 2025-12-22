#include "cliente_menu.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include "../../controller/modals/warning.h"
#include "../../controller/modals/error.h"
#include "../../controller/table/table.h"

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
    AddOption("Ver detalle de Cliente");
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

    if (tiposResponsables.Cantidad() == 0) {
        Warning w("Sin tipos de responsable", "Cargue tipos de responsable antes de asignar la razon social.");
        w.Show(); w.WaitForKey();
    } else {
        string codigo = SeleccionarRazonSocial(true);
        if (!codigo.empty()) {
            nuevoCliente.setCodigoRazonSocial(codigo);
        }
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
        cout << "8) Razon Social: " << cliente.getCodigoRazonSocial() << "\n";
        cout << "9) Terminar\n";

        opcion = InputNumber("Seleccione campo a modificar: ");

        switch(opcion) {
            case 1: { // Nombre
                while (true) {
                    entrada = InputBox("Nuevo Nombre: ");
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
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
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
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
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
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
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
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
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
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
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
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
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
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
            case 8: {
                string codigo = SeleccionarRazonSocial(false);
                if (!codigo.empty()) {
                    cliente.setCodigoRazonSocial(codigo);
                    Informational i("Razon social modificada", "Razon social actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                }
                break;
            }
            case 9: { // Terminar
                break;
            }
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida (1-9).");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 9);
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

string ClienteMenu::SeleccionarRazonSocial(bool obligatoria) {
    const unsigned int total = tiposResponsables.Cantidad();
    if (total == 0) {
        Warning w("Sin tipos de responsable", "No hay tipos de responsable cargados.");
        w.Show(); w.WaitForKey();
        return "";
    }

    GenericArray<TipoResponsable> lista;
    for (unsigned int i = 0; i < total; ++i) {
        TipoResponsable* t = tiposResponsables.At(i);
        if (t != nullptr) {
            lista.Append(*t);
            delete t;
        }
    }

    if (lista.Size() == 0) {
        Warning w("Sin tipos de responsable", "No hay tipos de responsable cargados.");
        w.Show(); w.WaitForKey();
        return "";
    }

    const unsigned int columnas = 5;
    Tabling::Table tabla(lista.Size(), columnas, '=', 3);
    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("Idx", 4);
    header->AddCell("Codigo", TipoResponsable::ColCodigoSize());
    header->AddCell("Descripcion", TipoResponsable::ColDescripcionSize());
    header->AddCell("% IVA", TipoResponsable::ColPorcentajeSize());
    header->AddCell("Tipo", TipoResponsable::ColTipoFacturacion());
    tabla.AddRow(header);

    for (unsigned int i = 0; i < lista.Size(); ++i) {
        TipoResponsable* t = lista[i];
        Tabling::Row* fila = new Tabling::Row(columnas);
        fila->AddCell(std::to_string(i), 4);
        fila->AddCell(t->getCodigo(), TipoResponsable::ColCodigoSize());
        fila->AddCell(t->getDescripcion(), TipoResponsable::ColDescripcionSize());
        fila->AddCell(Validation::ToFixedDecimal(t->getPorcentaje(), 1), TipoResponsable::ColPorcentajeSize());
        fila->AddCell(string(1, toupper(t->getTipoFacturacion())), TipoResponsable::ColTipoFacturacion());
        tabla.AddRow(fila);
    }

    while (true) {
        rlutil::cls();
        cout << "-- Seleccionar Razon Social --" << endl;
        tabla.Print();

        int idx = SelectorIndex(tabla, "Indice (vacio para cancelar): ", lista.Size());
        if (idx == -1) {
            if (obligatoria) {
                Warning w("Seleccion requerida", "Debe elegir una razon social.");
                w.Show(); w.WaitForKey();
                continue;
            }
            return "";
        }
        if (idx < 0) { continue; }
        return lista[static_cast<unsigned int>(idx)]->getCodigo();
    }
}

bool ClienteMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            Cliente nuevoCliente = CrearCliente();
            if(clientes.Agregar(nuevoCliente)) {
                Informational i("Cliente agregado", "Cliente " + nuevoCliente.getDNI() + " agregado exitosamente.");
                i.Show(); i.WaitForKey();
                PauseConsole();
            } else {
                Error e("Error", "Error al agregar el cliente.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 1: {
            string dni = InputBox("DNI del cliente a modificar: ");
            Cliente* cliente = clientes[dni];
            if (cliente == nullptr) {
                Warning w("Cliente no encontrado", "No se encontro cliente con DNI " + dni + ".");
                w.Show(); w.WaitForKey();
                return false;
            }
            ModificarClienteInteractivo(*cliente);

            if (clientes.Modificar(dni, cliente)) {
                Informational i("Cliente modificado", "Cliente " + dni + " modificado exitosamente.");
                i.Show(); i.WaitForKey();
                PauseConsole();
            } else {
                Error e("Error", "Error al modificar el cliente.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 2: {
            string dni = InputBox("DNI del cliente a eliminar: ");
            Cliente* cliente = clientes[dni];
            if (cliente == nullptr) {
                Warning w("Cliente no encontrado", "No se encontro cliente con DNI " + dni + ".");
                w.Show(); w.WaitForKey();
                return false;
            }
            bool confirma = EliminarClienteInteractivo(*cliente);
            delete cliente;
            if (confirma) {
                if (clientes.Eliminar(dni)) {
                    Informational i("Cliente eliminado", "Cliente " + dni + " eliminado exitosamente.");
                    i.Show(); i.WaitForKey();
                    PauseConsole();
                } else {
                    Error e("Error", "Error al eliminar el cliente.");
                    e.Show(); e.WaitForKey();
                }
            } else {
                cout << "Operacion cancelada." << endl;
                PauseConsole();
            }
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
            VerDetalleCliente();
            return false;
        }
        case 11: {
            return true; // Volver
        }
        default:
            return false;
    }
}

void ClienteMenu::VerDetalleCliente() {
    rlutil::cls();
    const unsigned int total = clientes.Count();
    if (total == 0) {
        Warning w("Sin clientes", "No hay clientes cargados.");
        w.Show(); w.WaitForKey();
        return;
    }

    GenericArray<Cliente> lista;
    for (unsigned int i = 0; i < total; ++i) {
        Cliente* c = clientes.At(i);
        if (c != nullptr) {
            lista.Append(*c);
            delete c;
        }
    }

    if (lista.Size() == 0) {
        Warning w("Sin clientes", "No hay clientes cargados.");
        w.Show(); w.WaitForKey();
        return;
    }

    const unsigned int cols = 5;
    const unsigned int widthNombre = Cliente::ColApellidoSize() + Cliente::ColNombreSize();
    Tabling::Table tabla(lista.Size(), cols);
    Tabling::Row* header = new Tabling::Row(cols);
    header->AddCell("Idx", 4);
    header->AddCell("DNI", Cliente::ColDniSize());
    header->AddCell("Nombre", widthNombre);
    header->AddCell("Correo", DatosPersonales::ColCorreoSize());
    header->AddCell("Estado", 8);
    tabla.AddRow(header);

    for (unsigned int i = 0; i < lista.Size(); ++i) {
        Cliente* c = lista[i];
        Tabling::Row* row = new Tabling::Row(cols);
        row->AddCell(std::to_string(i), 4);
        row->AddCell(c->getDNI(), Cliente::ColDniSize());
        row->AddCell(c->getApellido() + string(", ") + c->getNombre(), widthNombre);
        row->AddCell(c->getCorreo(), DatosPersonales::ColCorreoSize());
        row->AddCell(c->getAlta() ? "Alta" : "Baja", 8);
        tabla.AddRow(row);
    }

    int seleccionado = -1;
    while (true) {
        rlutil::cls();
        tabla.Print();
        seleccionado = SelectorIndex(tabla, "Indice a ver (vacio para cancelar): ", lista.Size());
        if (seleccionado == -1) return;
        if (seleccionado < 0) continue;
        break;
    }

    Cliente* elegido = lista[static_cast<unsigned int>(seleccionado)];
    if (elegido == nullptr) return;

    TipoResponsable* tipoResp = this->tiposResponsables[elegido->getCodigoRazonSocial()];
    string razonSocialDesc = "Sin datos";
    if (tipoResp != nullptr) {
        razonSocialDesc = tipoResp->getDescripcion();
        delete tipoResp;
    }

    rlutil::cls();
    cout << "-- Detalle de Cliente --" << endl
        << "DNI: " << elegido->getDNI() << endl
        << "CUIL/CUIT: " << elegido->getCuilCuit() << endl
        << "Razon Social: " << razonSocialDesc << endl
        << "Nombre: " << elegido->getNombre() << endl
        << "Apellido: " << elegido->getApellido() << endl
        << "Direccion: " << elegido->getDireccion() << endl
        << "Correo: " << elegido->getCorreo() << endl
        << "Telefono: " << elegido->getTelefono() << endl
        << "Celular: " << elegido->getCelular() << endl
        << "Estado: " << (elegido->getAlta() ? "Alta" : "Baja") << endl;
    PauseConsole();
}
