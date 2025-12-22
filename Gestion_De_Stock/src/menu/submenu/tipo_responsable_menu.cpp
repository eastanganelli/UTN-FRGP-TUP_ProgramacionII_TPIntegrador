#include "tipo_responsable_menu.h"
#include <iostream>
#include "../../controller/modals/warning.h"
#include "../../controller/modals/error.h"

using namespace std;

TipoResponsableMenu::TipoResponsableMenu() : Menu("Menu Tipo Responsables", true) {
    AddOption("Agregar Tipo Responsable");
    AddOption("Modificar Tipo Responsable");
    AddOption("Eliminar Tipo Responsable");
    AddOption("Listar por Descripcion");
    AddOption("Listar por Porcentaje");
    AddOption("Buscar por Porcentaje Mayor a");
    AddOption("Volver");
}

bool TipoResponsableMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            bool ok = false;
            TipoResponsable nuevo = CrearTipoResponsable(ok);
            if (!ok) { return false; }
            if (tipos.Agregar(nuevo)) {
                cout << "Tipo responsable agregado exitosamente." << endl;
                PauseConsole();
            } else {
                Error e("Error", "Error al agregar el tipo responsable.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 1: {
            string codigo = InputBox("Codigo del tipo a modificar: ");
            TipoResponsable* t = tipos[codigo];
            if (t == nullptr) {
                Warning w("Tipo responsable no encontrado", "No se encontro tipo con codigo " + codigo + ".");
                w.Show(); w.WaitForKey();
                return false;
            }

            ModificarTipoResponsable(*t);

            if (tipos.Modificar(codigo, t)) {
                Informational i("Tipo responsable modificado", "Tipo responsable " + codigo + " modificado exitosamente.");
                i.Show(); i.WaitForKey();
                PauseConsole();
            }
            else {
                Error e("Error", "Error al modificar el tipo responsable.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 2: {
            string codigo = InputBox("Codigo del tipo a eliminar: ");
            TipoResponsable* t = tipos[codigo];
            if (t == nullptr) {
                Warning w("Tipo responsable no encontrado", "No se encontro tipo con codigo " + codigo + ".");
                w.Show(); w.WaitForKey();
                return false;
            }
            bool confirma = EliminarTipoResponsable(*t);
            delete t;
            if (confirma) {
                if (tipos.Eliminar(codigo)) {
                    Informational i("Tipo responsable eliminado", "Tipo responsable " + codigo + " eliminado exitosamente.");
                    i.Show(); i.WaitForKey();
                } else {
                    Error e("Error", "Error al eliminar el tipo responsable.");
                    e.Show(); e.WaitForKey();
                }
            } else {
                Informational i("Operacion cancelada", "Operacion cancelada por el usuario.");
                i.Show(); i.WaitForKey();
            }
            PauseConsole();
            return false;
        }
        case 3: {
            tipos.ListarPorDescripcion();
            PauseConsole();
            return false;
        }
        case 4: {
            tipos.ListarPorPorcentaje();
            PauseConsole();
            return false;
        }
        case 5: {
            float minimo = InputNumber("Porcentaje minimo: ");
            auto lista = tipos.PorcentajeMayorA(minimo);
            TipoResponsableManager::Imprimir(lista);
            PauseConsole();
            return false;
        }
        case 6: {
            return true;
        }
        default:
            return false;
    }
}

void TipoResponsableMenu::ModificarTipoResponsable(TipoResponsable& tipo) {
    unsigned int opcion = 0;
    string entrada;
    do {
        rlutil::cls();
        cout << "-- Modificar Tipo Responsable --\n";
        cout << "1) Codigo: " << tipo.getCodigo() << "\n";
        cout << "2) Descripcion: " << tipo.getDescripcion() << "\n";
        cout << "3) Porcentaje: " << tipo.getPorcentaje() << "\n";
        cout << "4) Tipo Facturacion: " << tipo.getTipoFacturacion() << "\n";
        cout << "5) Terminar\n";

        opcion = InputNumber("Seleccione campo a modificar: ");

        switch(opcion) {
            case 1: {
                while (true) {
                    entrada = InputBox("Nuevo Codigo: ");
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || entrada.length() >= TipoResponsable::GetCodigoSize() || !Validation::IsAlphanumeric(entrada)) {
                        Warning w("Codigo invalido", "Ingrese un codigo valido (alfanumerico y longitud aceptable).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    tipo = TipoResponsable(entrada, tipo.getDescripcion(), tipo.getPorcentaje(), tipo.getTipoFacturacion());
                    Informational i("Codigo modificado", "Codigo actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 2: {
                while (true) {
                    entrada = InputBox("Nueva Descripcion: ");
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || entrada.length() >= TipoResponsable::GetDescripcionSize()) {
                        Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    tipo = TipoResponsable(tipo.getCodigo(), entrada, tipo.getPorcentaje(), tipo.getTipoFacturacion());
                    Informational i("Descripcion modificada", "Descripcion actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 3: {
                while (true) {
                    entrada = InputBox("Nuevo Porcentaje (0.0 - 100.0): ");
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
                    float p = -1.0f;
                    try { p = std::stof(entrada); } catch(...) { p = -1.0f; }
                    if (p < 0.0f || p > 100.0f) {
                        Warning w("Porcentaje invalido", "Ingrese un numero valido entre 0 y 100.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    tipo = TipoResponsable(tipo.getCodigo(), tipo.getDescripcion(), p, tipo.getTipoFacturacion());
                    Informational i("Porcentaje modificado", "Porcentaje actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 4: {
                while (true) {
                    entrada = InputBox("Nuevo Tipo Facturacion (A, B, C o E): ");
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
                    if (Validation::IsEmpty(entrada)) { Warning w("Tipo invalido", "Ingrese A, B, C o E."); w.Show(); w.WaitForKey(); continue; }
                    char t = toupper(entrada[0]);
                    if (t != 'A' && t != 'B' && t != 'C' && t != 'E') { Warning w("Tipo invalido", "Ingrese A, B, C o E."); w.Show(); w.WaitForKey(); continue; }
                    tipo = TipoResponsable(tipo.getCodigo(), tipo.getDescripcion(), tipo.getPorcentaje(), t);
                    Informational i("Tipo facturacion modificado", "Tipo de facturacion actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida (1-5).");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 5);
    rlutil::cls();
}

bool TipoResponsableMenu::EliminarTipoResponsable(TipoResponsable& tipo) {
    Warning w("Eliminar Tipo Responsable", "Esta seguro que desea eliminar este tipo responsable?");
    return w.ShowYesNo();
}

TipoResponsable TipoResponsableMenu::CrearTipoResponsable(bool& ok) {
    ok = false;
    string codigo, descripcion, entrada;
    float porcentaje = -1.0f;
    char tipo = '\0';

    while (true) {
        codigo = InputBox("Codigo: ");
        if (Validation::IsEmpty(codigo) || codigo.length() >= TipoResponsable::GetCodigoSize() || !Validation::IsAlphanumeric(codigo)) {
            Warning w("Codigo invalido", "Ingrese un codigo valido (alfanumerico y longitud aceptable).");
            w.Show(); w.WaitForKey();
            continue;
        }
        break;
    }

    while (true) {
        descripcion = InputBox("Descripcion: ");
        if (Validation::IsEmpty(descripcion) || descripcion.length() >= TipoResponsable::GetDescripcionSize()) {
            Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        break;
    }

    while (true) {
        entrada = InputBox("Porcentaje (0.0 - 100.0): ");
        try {
            porcentaje = std::stof(entrada);
        } catch(...) { porcentaje = -1.0f; }
        if (porcentaje < 0.0f || porcentaje > 100.0f) {
            Warning w("Porcentaje invalido", "Ingrese un numero valido entre 0 y 100.");
            w.Show(); w.WaitForKey();
            continue;
        }
        break;
    }

    while (true) {
        entrada = InputBox("Tipo de facturacion (A, B, C o E): ");
        if (Validation::IsEmpty(entrada)) {
            Warning w("Tipo invalido", "Ingrese A, B, C o E.");
            w.Show(); w.WaitForKey();
            continue;
        }
        tipo = toupper(entrada[0]);
        if (tipo != 'A' && tipo != 'B' && tipo != 'C' && tipo != 'E') {
            Warning w("Tipo invalido", "Ingrese A, B, C o E.");
            w.Show(); w.WaitForKey();
            continue;
        }
        break;
    }

    ok = true;
    return TipoResponsable(codigo, descripcion, porcentaje, tipo);
}
