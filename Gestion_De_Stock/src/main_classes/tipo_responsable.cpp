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

string TipoResponsable::getCodigo() const { return string(this->codigo, CODIGO_SIZE); }

string TipoResponsable::getDescripcion() const { return string(this->descripcion); }

float TipoResponsable::getPorcentaje() const { return this->porcentaje; }

char TipoResponsable::getTipoFacturacion() const { return toupper(this->tipoFacturacion); }

unsigned int TipoResponsable::GetCodigoSize() { return CODIGO_SIZE; }

unsigned int TipoResponsable::GetDescripcionSize() { return DESCRIPCION_SIZE; }

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

float TipoResponsable::Resultado(float valor) {
    return valor * (1 + this->porcentaje / 100.0f);
}

