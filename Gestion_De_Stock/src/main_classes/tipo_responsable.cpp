#include "tipo_responsable.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../../rlutil.h"
#include "../controller/modals.h"
#include "../menu/menu_utils.h"

TipoResponsable::TipoResponsable(const string codigo, const string descripcion, const float _porcentaje, const char _tipoFacturacion) {
    this->codigo[0] = '\0';
    this->descripcion[0] = '\0';
    this->tipoFacturacion = '\0';
    strcpy(this->codigo, codigo.c_str());
    strcpy(this->descripcion, descripcion.c_str());
    this->porcentaje = _porcentaje;
    this->tipoFacturacion = _tipoFacturacion;
}

TipoResponsable::~TipoResponsable() { }

string TipoResponsable::getCodigo() const { return string(this->codigo); }

string TipoResponsable::getDescripcion() const { return string(this->descripcion); }

float TipoResponsable::getPorcentaje() const { return this->porcentaje; }

char TipoResponsable::getTipoFacturacion() const { return toupper(this->tipoFacturacion); }

unsigned int TipoResponsable::ColCodigoSize() { return TipoResponsable::COL_Codigo; }

unsigned int TipoResponsable::ColDescripcionSize() { return TipoResponsable::COL_Descripcion; }

unsigned int TipoResponsable::ColPorcentajeSize() { return TipoResponsable::COL_Porcentaje; }

unsigned int TipoResponsable::ColTipoFacturacion() { return TipoResponsable::COL_TipoFacturacion; }

bool TipoResponsable::operator==(const TipoResponsable& otra) const {
    return Validation::IsEqual(this->codigo, otra.codigo) && Validation::IsEqual(this->descripcion, otra.descripcion)
           && this->porcentaje == otra.porcentaje && Validation::IsEqual(&this->tipoFacturacion, &otra.tipoFacturacion);
}

bool TipoResponsable::IsEmpty() const {
    return Validation::IsEmpty(this->codigo) && Validation::IsEmpty(this->descripcion)
        && this->porcentaje, -1.0f && Validation::IsEmpty(&this->tipoFacturacion);
}

void TipoResponsable::Print() {
    int row = rlutil::trows();
    int x = 1;

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::COL_Codigo) << this->codigo;
    x += TipoResponsable::COL_Codigo;

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::COL_Descripcion) << this->descripcion;
    x += TipoResponsable::COL_Descripcion;

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::COL_Porcentaje) << std::fixed << std::setprecision(1) << this->porcentaje;
    x += TipoResponsable::COL_Porcentaje;

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::COL_Porcentaje) << (char)toupper(this->tipoFacturacion);

    rlutil::locate(1, row + 1);
}

TipoResponsable TipoResponsable::NuevoTipoResponsable() {
    string codigo, descripcion, entrada;
    float porcentaje = -1.0f;
    char tipo = '\0';

    // Codigo
    while (true) {
        codigo = InputBox("Codigo: ");
        if (Validation::IsEmpty(codigo) || codigo.length() >= CODIGO_SIZE || !Validation::IsAlphanumeric(codigo)) {
            Warning w("Codigo invalido", "Ingrese un codigo valido (alfanumerico y longitud aceptable).");
            w.Show(); w.WaitForKey();
            continue;
        }
        break;
    }

    // Descripcion
    while (true) {
        descripcion = InputBox("Descripcion: ");
        if (Validation::IsEmpty(descripcion) || descripcion.length() >= DESCRIPCION_SIZE) {
            Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        break;
    }

    // Porcentaje
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

    // Tipo Facturacion
    while (true) {
        entrada = InputBox("Tipo de facturacion (A, B, C o E): ");
        if (Validation::IsEmpty(entrada)) { Warning w("Tipo invalido", "Ingrese A, B, C o E."); w.Show(); w.WaitForKey(); continue; }
        tipo = toupper(entrada[0]);
        if (tipo != 'A' && tipo != 'B' && tipo != 'C' && tipo != 'E') {
            Warning w("Tipo invalido", "Ingrese A, B, C o E.");
            w.Show(); w.WaitForKey();
            continue;
        }
        break;
    }

    return TipoResponsable(codigo, descripcion, porcentaje, tipo);
}

void TipoResponsable::ModificarTipoResponsable(TipoResponsable& tipo) {
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
                    if (Validation::IsEmpty(entrada) || entrada.length() >= CODIGO_SIZE || !Validation::IsAlphanumeric(entrada)) {
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
                    if (Validation::IsEmpty(entrada) || entrada.length() >= DESCRIPCION_SIZE) {
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

unsigned int TipoResponsable::EliminarTipoResponsable(TipoResponsable& tipo) {
    Warning w("Eliminar Tipo Responsable", "Esta seguro que desea eliminar este tipo responsable?");
    if (w.ShowYesNo()) {
        return 1;
    }
    return 0;
}
