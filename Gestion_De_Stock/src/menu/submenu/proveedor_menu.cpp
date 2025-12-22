#include "proveedor_menu.h"
#include <iostream>
#include <cstdlib>
#include "../../controller/modals/error.h"

using namespace std;

ProveedorMenu::ProveedorMenu() : Menu("Menu Proveedores", true) {
    AddOption("Agregar Proveedor");
    AddOption("Modificar Proveedor");
    AddOption("Eliminar Proveedor");
    AddOption("Listar por Rubro");
    AddOption("Listar por CUIT");
    AddOption("Listar por Nombre o Razon Social");
    AddOption("Buscar por Rubro");
    AddOption("Buscar por CUIT");
    AddOption("Buscar por Nombre o Razon Social");
    AddOption("Buscar por Estado");
    AddOption("Volver");
}

Proveedor ProveedorMenu::CrearProveedor(bool& ok) {
    ok = false;
    string v;
    string nombreRazon, cuit, direccion, correo, telefono, celular;
    unsigned int rubro = 0;

    while (true) {
        v = InputBox("Nombre/Razon: ");
        if (Validation::IsEmpty(v) || !Validation::IsAlphabetic(v) || v.length() >= 35) {
            Warning w("Nombre/Razon invalido", "Ingrese solo letras y/o espacios y longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        nombreRazon = v;
        break;
    }

    while (true) {
        v = InputBox("CUIT: ");
        if (Validation::IsEmpty(v) || v.length() >= 12 || !Validation::IsAlphanumeric(v)) {
            Warning w("CUIT invalido", "Ingrese CUIT valido (alfanumerico y longitud aceptable).");
            w.Show(); w.WaitForKey();
            continue;
        }
        cuit = v;
        break;
    }

    while (true) {
        cout << "Rubros disponibles:\n1) Textil\n2) Calzado\n3) Gastronimia\n4) Automotor\n5) Libreria\n";
        unsigned int r = InputNumber("Seleccione rubro (1-5): ");
        if (r < 1 || r > 5) {
            Warning w("Rubro invalido", "Seleccione un rubro valido (1-5).");
            w.Show(); w.WaitForKey();
            continue;
        }
        rubro = r;
        break;
    }

    while (true) {
        v = InputBox("Direccion: ");
        if (Validation::IsEmpty(v) || v.length() >= 100) {
            Warning w("Direccion invalida", "Ingrese una direccion valida y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        direccion = v;
        break;
    }

    while (true) {
        v = InputBox("Correo: ");
        if (Validation::IsEmpty(v) || v.length() >= 100 || v.find('@') == string::npos || v.find('.') == string::npos) {
            Warning w("Correo invalido", "Ingrese un correo valido (contiene @ y .) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        correo = v;
        break;
    }

    while (true) {
        v = InputBox("Telefono: ");
        if (Validation::IsEmpty(v) || !Validation::IsNumeric(v) || v.length() >= 25) {
            Warning w("Telefono invalido", "Ingrese un telefono valido (solo digitos) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        telefono = v;
        break;
    }

    while (true) {
        v = InputBox("Celular: ");
        if (Validation::IsEmpty(v) || !Validation::IsNumeric(v) || v.length() >= 25) {
            Warning w("Celular invalido", "Ingrese un celular valido (solo digitos) y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        celular = v;
        break;
    }

    Proveedor p(cuit, nombreRazon, rubro, direccion, correo, telefono, celular, "", true);
    ok = true;
    return p;
}

void ProveedorMenu::ModificarProveedorInteractivo(Proveedor& proveedor) {
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
                    if (entrada.empty()) {
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || !Validation::IsAlphabetic(entrada) || entrada.length() >= 35) {
                        Warning w("Nombre invalido", "Ingrese solo letras para el nombre/razon.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setNombreRazon(entrada);
                    Informational i("Nombre modificado", "Nombre " + proveedor.getNombreRazon() + " actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 2: {
                while (true) {
                    entrada = InputBox("Nuevo CUIT: ");
                    if (entrada.empty()) {
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || entrada.length() >= 12 || !Validation::IsAlphanumeric(entrada)) {
                        Warning w("CUIT invalido", "Ingrese CUIT valido (solo letras y/o digitos, longitud correcta).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setCuit(entrada);
                    Informational i("CUIT modificado", "CUIT " + proveedor.getCuit() + " actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 3: {
                while (true) {
                    cout << "Rubros disponibles:\n1) Textil\n2) Calzado\n3) Gastronimia\n4) Automotor\n5) Libreria\n";
                    entrada = InputBox("Seleccione rubro (vacio para mantener): ");
                    if (entrada.empty()) {
                        break;
                    }
                    if (!Validation::IsNumeric(entrada)) {
                        Warning w("Rubro invalido", "Seleccione un rubro valido (1-5).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    unsigned int r = static_cast<unsigned int>(std::strtoul(entrada.c_str(), nullptr, 10));
                    if (r < 1 || r > 5) {
                        Warning w("Rubro invalido", "Seleccione un rubro valido (1-5).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setRubro(r);
                    Informational i("Rubro modificado", "Rubro " + proveedor.getRubroNombre() + " actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 4: {
                while (true) {
                    entrada = InputBox("Nueva Direccion: ");
                    if (entrada.empty()) {
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || entrada.length() >= 100) {
                        Warning w("Direccion invalida", "Ingrese una direccion valida y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setDireccion(entrada);
                    Informational i("Direccion modificada", "Direccion " + proveedor.getDireccion() + " actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 5: {
                while (true) {
                    entrada = InputBox("Nuevo Correo: ");
                    if (entrada.empty()) {
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || entrada.length() >= 100 || entrada.find('@') == string::npos || entrada.find('.') == string::npos) {
                        Warning w("Correo invalido", "Ingrese un correo valido (contiene @ y .) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setCorreo(entrada);
                    Informational i("Correo modificado", "Correo " + proveedor.getCorreo() + " actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 6: {
                while (true) {
                    entrada = InputBox("Nuevo Telefono: ");
                    if (entrada.empty()) {
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || !Validation::IsNumeric(entrada) || entrada.length() >= 25) {
                        Warning w("Telefono invalido", "Ingrese un telefono valido (solo digitos) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setTelefono(entrada);
                    Informational i("Telefono modificado", "Telefono " + proveedor.getTelefono() + " actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 7: {
                while (true) {
                    entrada = InputBox("Nuevo Celular: ");
                    if (entrada.empty()) {
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || !Validation::IsNumeric(entrada) || entrada.length() >= 25) {
                        Warning w("Celular invalido", "Ingrese un celular valido (solo digitos) y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    proveedor.setCelular(entrada);
                    Informational i("Celular modificado", "Celular " + proveedor.getCelular() + " actualizado correctamente.");
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

bool ProveedorMenu::EliminarProveedorInteractivo(Proveedor& proveedor) {
    Warning w("Eliminar Proveedor", "Esta seguro que desea eliminar este proveedor?");
    if (w.ShowYesNo()) {
        proveedor.setAlta(false);
        return true;
    }
    return false;
}


bool ProveedorMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            bool ok = false;
            Proveedor nuevo = CrearProveedor(ok);
            if (!ok) { return false; }
            if (proveedores.Agregar(nuevo)) {
                Informational i("Proveedor agregado", "Proveedor " + nuevo.getNombreRazon() + " agregado exitosamente.");
                i.Show(); i.WaitForKey();
            }
            else {
                Error e("Error", "Error al agregar el proveedor.");
                e.Show(); e.WaitForKey();
            }
            PauseConsole();
            return false;
        }
        case 1: {
            string cuit = InputBox("CUIT del proveedor a modificar: ");
            Proveedor* pv = proveedores[cuit];
            if (pv == nullptr) {
                Warning w("Proveedor no encontrado", "No se encontro proveedor con CUIT " + cuit + ".");
                w.Show(); w.WaitForKey();
                return false;
            }

            ModificarProveedorInteractivo(*pv);

            if (proveedores.Modificar(cuit, pv)) {
                Informational i("Proveedor modificado", "Proveedor " + pv->getNombreRazon() + " modificado exitosamente.");
                i.Show(); i.WaitForKey();
                PauseConsole();
            }
            else {
                Error e("Error", "Error al modificar el proveedor.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 2: {
            string cuit = InputBox("CUIT del proveedor a eliminar: ");
            Proveedor* pv = proveedores[cuit];
            if (pv == nullptr) {
                Warning w("Proveedor no encontrado", "No se encontro proveedor con CUIT " + cuit + ".");
                w.Show(); w.WaitForKey();
                return false;
            }
            bool confirma = EliminarProveedorInteractivo(*pv);
            if (confirma) {
                if (proveedores.Eliminar(cuit)) {
                    Informational i("Proveedor eliminado", "Proveedor " + pv->getNombreRazon() + " eliminado exitosamente.");
                    i.Show(); i.WaitForKey();
                }
                else
                {
                    Error e("Error", "Error al eliminar el proveedor.");
                    e.Show(); e.WaitForKey();
                }
            } else {
                Informational i("Operacion cancelada", "Operacion de eliminacion cancelada.");
                i.Show(); i.WaitForKey();
            }
            
            delete pv;
            PauseConsole();
            return false;
        }
        case 3: {
            proveedores.ListarPorRubro();
            PauseConsole();
            return false;
        }
        case 4: {
            proveedores.ListarPorCUIT();
            PauseConsole();
            return false;
        }
        case 5: {
            proveedores.ListarPorNombre();
            PauseConsole();
            return false;
        }
        case 6: {
            unsigned int rubro = proveedores.SeleccionarRubro();
            auto res = proveedores.ConsultarPorRubro(rubro);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            string cuit = InputBox("CUIT: ");
            auto res = proveedores.ConsultarPorCUIT(cuit);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 8: {
            string nombre = InputBox("Nombre o Razon Social: ");
            auto res = proveedores.ConsultarPorNombre(nombre);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 9: {
            bool estado = Confirm("¿Desea buscar proveedores activos?");
            auto res = proveedores.ConsultarPorEstado(estado);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 10: {
            return true;
        }
        default:
            return false;
    }
}
