#include "Proveedor.h"
#include "../controller/modals.h"
#include "../menu/menu_utils.h"

Proveedor::Proveedor(string _cuit, string _nombreRazon, unsigned int _rubro, string _direccion, string _correo, string _telefono, string _celular, string _razonSocial, bool _alta)
    : DatosPersonales(_alta, _direccion, _correo, _telefono, _celular, _razonSocial) {
    this->alta = _alta;
    this->cuit[0] = '\0';
    this->nombreRazon[0] = '\0';
    strcpy(this->cuit, _cuit.c_str());
    strcpy(this->nombreRazon, _nombreRazon.c_str());
    this->rubro = _rubro;
}

Proveedor::~Proveedor() { }

bool Proveedor::getAlta() { return this->alta; }

string Proveedor::getCuit() { return string(this->cuit); }

string Proveedor::getNombreRazon() { return this->nombreRazon; }

unsigned int Proveedor::getRubro() {  return this->rubro; }

string Proveedor::getRubroNombre() {
    switch(this->rubro) {
    case 1:
        return "Textil";
    case 2:
        return "Calzado";
    case 3:
        return "Gastronomia";
    case 4:
        return "Automotor";
    case 5:
        return "Libreria";
    default:
        break;
    }
    return "Indumentaria";
}

unsigned int Proveedor::ColCuitSize() { return Proveedor::COL_CUIT; }

unsigned int Proveedor::ColNombreRazonSize() { return Proveedor::COL_NOMBRE_RAZON; }

void Proveedor::setAlta(bool alta) { this->alta = alta; }

void Proveedor::setRubro(unsigned int rubro) { this->rubro = rubro; }

void Proveedor::setNombreRazon(string nombre) { strcpy(this->nombreRazon, nombre.c_str()); }

bool Proveedor::operator==(const Proveedor& otro) {
    return Validation::IsEqual(this->cuit, otro.cuit) && Validation::IsEqual(this->nombreRazon, otro.nombreRazon)
        && this->rubro == otro.rubro && this->IsEqual(otro);
}

bool Proveedor::IsEmpty() {
    return Validation::IsEmpty(this->cuit) && Validation::IsEmpty(this->nombreRazon)
        && this->rubro == 0 && this->DatosPersonales::IsEmpty();
}

void Proveedor::Print() {
    cout << "CUIT: " + this->getCuit() +
           " | Nombre/Razon: " + this->getNombreRazon() +
           " | Rubro: " + this->getRubroNombre() +
           " | Direccion: " + this->getDireccion() +
           " | Correo: " + this->getCorreo() +
           " | Telefono: " + this->getTelefono() +
           " | Celular: " + this->getCelular() +
           " | Estado: " + (this->getAlta() ? string("Activo") : string("Inactivo"));
}

Proveedor Proveedor::NuevoProveedor() {
    Proveedor p;
    string v;

    // Nombre / Razon
    while (true) {
        v = InputBox("Nombre/Razon: ");
        if (Validation::IsEmpty(v) || !Validation::IsAlphabetic(v) || v.length() >= NOMBRE_RAZON_SIZE) {
            Warning w("Nombre/Razon invalido", "Ingrese solo letras y/o espacios y longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        p.setNombreRazon(v);
        break;
    }

    // CUIT
    while (true) {
        v = InputBox("CUIT: ");
        if (Validation::IsEmpty(v) || v.length() >= CUIT_SIZE || !Validation::IsAlphanumeric(v)) {
            Warning w("CUIT invalido", "Ingrese CUIT valido (alfanumerico y longitud aceptable).");
            w.Show(); w.WaitForKey();
            continue;
        }
        strcpy(p.cuit, v.c_str());
        break;
    }

    // Rubro
    while (true) {
        cout << "Rubros disponibles:\n1) Textil\n2) Calzado\n3) Gastronimia\n4) Automotor\n5) Libreria\n";
        unsigned int r = InputNumber("Seleccione rubro (1-5): ");
        if (r < 1 || r > 5) {
            Warning w("Rubro invalido", "Seleccione un rubro valido (1-5).");
            w.Show(); w.WaitForKey();
            continue;
        }
        p.setRubro(r);
        break;
    }

    // Direccion
    while (true) {
        v = InputBox("Direccion: ");
        if (Validation::IsEmpty(v) || v.length() >= DatosPersonales::GetDireccionSize()) {
            Warning w("Direccion invalida", "Ingrese una direccion valida y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        p.setDireccion(v);
        break;
    }

    // Correo
    while (true) {
        v = InputBox("Correo: ");
        if (Validation::IsEmpty(v) || v.length() >= DatosPersonales::GetCorreoSize() || v.find('@') == string::npos || v.find('.') == string::npos) {
            Warning w("Correo invalido", "Ingrese un correo valido (contiene @ y .) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        p.setCorreo(v);
        break;
    }

    // Telefono
    while (true) {
        v = InputBox("Telefono: ");
        if (Validation::IsEmpty(v) || !Validation::IsNumeric(v) || v.length() >= DatosPersonales::GetTelefonoSize()) {
            Warning w("Telefono invalido", "Ingrese un telefono valido (solo digitos) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        p.setTelefono(v);
        break;
    }

    // Celular
    while (true) {
        v = InputBox("Celular: ");
        if (Validation::IsEmpty(v) || !Validation::IsNumeric(v) || v.length() >= DatosPersonales::GetCelularSize()) {
            Warning w("Celular invalido", "Ingrese un celular valido (solo digitos) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        p.setCelular(v);
        break;
    }

    p.setAlta(true);
    return p;
}

void Proveedor::ModificarProveedor(Proveedor& proveedor) {
    unsigned int opcion = 0;
    string entrada;
    do {
        rlutil::cls();
        cout << "-- Modificar Proveedor --\n";
        cout << "1) Nombre/Razon: " << proveedor.getNombreRazon() << "\n";
        cout << "2) CUIT: " << proveedor.getCuit() << "\n";
        cout << "3) Rubro: " << proveedor.getRubroNombre() << "\n";
        cout << "4) Direccion: " << proveedor.getDireccion() << "\n";
        cout << "5) Correo: " << proveedor.getCorreo() << "\n";
        cout << "6) Telefono: " << proveedor.getTelefono() << "\n";
        cout << "7) Celular: " << proveedor.getCelular() << "\n";
        cout << "8) Terminar\n";

        opcion = InputNumber("Seleccione campo a modificar: ");

        switch(opcion) {
            case 1: {
                while (true) {
                    entrada = InputBox("Nuevo Nombre/Razon: ");
                    if (Validation::IsEmpty(entrada) || !Validation::IsAlphabetic(entrada) || entrada.length() >= NOMBRE_RAZON_SIZE) {
                        Warning w("Nombre invalido", "Ingrese solo letras para el nombre/razon.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setNombreRazon(entrada);
                    Informational i("Nombre modificado", "Nombre actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 2: {
                while (true) {
                    entrada = InputBox("Nuevo CUIT: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= CUIT_SIZE || !Validation::IsAlphanumeric(entrada)) {
                        Warning w("CUIT invalido", "Ingrese CUIT valido (solo letras y/o digitos, longitud correcta).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setAlta(proveedor.getAlta()); // keep alta
                    strcpy(proveedor.cuit, entrada.c_str());
                    Informational i("CUIT modificado", "CUIT actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 3: {
                while (true) {
                    cout << "Rubros disponibles:\n1) Textil\n2) Calzado\n3) Gastronimia\n4) Automotor\n5) Libreria\n";
                    unsigned int r = InputNumber("Seleccione rubro (1-5): ");
                    if (r < 1 || r > 5) {
                        Warning w("Rubro invalido", "Seleccione un rubro valido (1-5).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setRubro(r);
                    Informational i("Rubro modificado", "Rubro actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 4: {
                while (true) {
                    entrada = InputBox("Nueva Direccion: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= DatosPersonales::GetDireccionSize()) {
                        Warning w("Direccion invalida", "Ingrese una direccion valida y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setDireccion(entrada);
                    Informational i("Direccion modificada", "Direccion actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 5: {
                while (true) {
                    entrada = InputBox("Nuevo Correo: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= DatosPersonales::GetCorreoSize() || entrada.find('@') == string::npos || entrada.find('.') == string::npos) {
                        Warning w("Correo invalido", "Ingrese un correo valido (contiene @ y .) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setCorreo(entrada);
                    Informational i("Correo modificado", "Correo actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 6: {
                while (true) {
                    entrada = InputBox("Nuevo Telefono: ");
                    if (Validation::IsEmpty(entrada) || !Validation::IsNumeric(entrada) || entrada.length() >= DatosPersonales::GetTelefonoSize()) {
                        Warning w("Telefono invalido", "Ingrese un telefono valido (solo digitos) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setTelefono(entrada);
                    Informational i("Telefono modificado", "Telefono actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 7: {
                while (true) {
                    entrada = InputBox("Nuevo Celular: ");
                    if (Validation::IsEmpty(entrada) || !Validation::IsNumeric(entrada) || entrada.length() >= DatosPersonales::GetCelularSize()) {
                        Warning w("Celular invalido", "Ingrese un celular valido (solo digitos) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setCelular(entrada);
                    Informational i("Celular modificado", "Celular actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 8: {
                break;
            }
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida (1-8).");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 8);
    rlutil::cls();
}

unsigned int Proveedor::EliminarProveedor(Proveedor& proveedor) {
    Warning w("Eliminar Proveedor", "Esta seguro que desea eliminar este proveedor?");
    if (w.ShowYesNo()) {
        proveedor.setAlta(false);
        return 1;
    }
    return 0;
}
