#include "Cliente.h"
#include "../controller/modals.h"
#include <algorithm>

Cliente::Cliente(string _nombre, string _apellido, string _DNI, string _cuilCuit, string direccion, string correo, string _telefono, string _celular, bool _alta)
    : DatosPersonales(_alta, direccion, correo, _telefono, _celular) {
    this->DNI[0] = '\0';
    this->nombre[0] = '\0';
    this->apellido[0] = '\0';
    this->cuilCuit[0] = '\0';
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->cuilCuit, _cuilCuit.c_str());
}

Cliente::~Cliente() { }

string Cliente::getDNI() { return string(this->DNI); }

string Cliente::getNombre() { return string(this->nombre); }

string Cliente::getApellido() { return string(this->apellido); }

string Cliente::getCuilCuit() { return string(this->cuilCuit); }

unsigned int Cliente::GetDniSize() { return DNI_SIZE; }

unsigned int Cliente::GetNombreSize() { return NOMBRE_SIZE; }

unsigned int Cliente::GetApellidoSize() { return APELLIDO_SIZE; }

unsigned int Cliente::GetCuilCuitSize() { return CUIL_CUIT_SIZE; }

void Cliente::setDNI(const string& dni) { strcpy(this->DNI, dni.c_str()); }

void Cliente::setNombre(const string& n) { strcpy(this->nombre, n.c_str()); }

void Cliente::setApellido(const string& a) { strcpy(this->apellido, a.c_str()); }

void Cliente::setCuilCuit(const string& c) { strcpy(this->cuilCuit, c.c_str()); }

bool Cliente::operator==(Cliente& cliente) {
    return Validation::IsEqual(this->DNI, cliente.DNI)           && Validation::IsEqual(this->cuilCuit, cliente.cuilCuit)
        && Validation::IsEqual(this->apellido, cliente.apellido) && Validation::IsEqual(this->nombre, cliente.nombre)
        && this->IsEqual(cliente);
}

bool Cliente::IsEmpty() {
    return Validation::IsEmpty(this->DNI) && Validation::IsEmpty(this->nombre)
        && Validation::IsEmpty(this->apellido) && Validation::IsEmpty(this->cuilCuit)
        && this->DatosPersonales::IsEmpty();
}

void Cliente::Print() {
    printf("%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n",
            Cliente::GetDniSize(), this->getDNI().c_str(),
            Cliente::GetApellidoSize(), this->getApellido().c_str(),
            Cliente::GetNombreSize(), this->getNombre().c_str(),
            Cliente::GetCuilCuitSize(), this->getCuilCuit().c_str(),
            DatosPersonales::GetCorreoSize(), this->getCorreo().c_str(),
            DatosPersonales::GetTelefonoSize(), this->getTelefono().c_str(),
            DatosPersonales::GetCelularSize(), this->getCelular().c_str(),
            DatosPersonales::GetDireccionSize(), this->getDireccion().c_str(),
            DatosPersonales::GetEstadoSize(), this->Estado().c_str());
}

Cliente Cliente::NuevoCliente() {
    Cliente nuevoCliente;
    string v;

    // Nombre (solo letras y espacios)
    while (true) {
        v = InputBox("Nombre: ");
        string tmp = v;
        tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
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
        tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
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

void Cliente::ModificarCliente(Cliente& cliente) {
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
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
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
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
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

unsigned int Cliente::EliminarCliente(Cliente& cliente) {
    Warning w("Eliminar Cliente", "Ests seguro que desea eliminar este cliente?");
    if (w.ShowYesNo()) {
        cliente.setAlta(false);
        return 1;
    }
    return 0;
}