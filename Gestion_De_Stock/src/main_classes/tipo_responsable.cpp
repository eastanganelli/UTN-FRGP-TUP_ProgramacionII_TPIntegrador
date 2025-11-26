#include "tipo_responsable.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../../rlutil.h"

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

unsigned int TipoResponsable::GetCodigoLength() { return TipoResponsable::CODIGO_SIZE; }

unsigned int TipoResponsable::GetDescripcionLength() { return TipoResponsable::DESCRIPCION_SIZE; }

unsigned int TipoResponsable::GetPorcentajeLength() { return TipoResponsable::PORCENTAJE_SIZE; }

unsigned int TipoResponsable::GetTipoFacturacionLength() { return TipoResponsable::TIPOFACTURACION_SIZE; }

bool TipoResponsable::operator==(const TipoResponsable& otra) const {
    return Validation::IsEqual(this->codigo, otra.codigo) && Validation::IsEqual(this->descripcion, otra.descripcion)
           && this->porcentaje == otra.porcentaje && Validation::IsEqual(&this->tipoFacturacion, &otra.tipoFacturacion);
}

bool TipoResponsable::IsEmpty() const {
    return Validation::IsEmpty(this->codigo) && Validation::IsEmpty(this->descripcion)
        && this->porcentaje == -1.0f && Validation::IsEmpty(&this->tipoFacturacion);
}

void TipoResponsable::Print() {
    int row = rlutil::trows();
    int x = 1;

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::GetCodigoLength()) << this->codigo;
    x += TipoResponsable::GetCodigoLength();

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::GetDescripcionLength()) << this->descripcion;
    x += TipoResponsable::GetDescripcionLength();

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::GetPorcentajeLength()) << std::fixed << std::setprecision(1) << this->porcentaje;
    x += TipoResponsable::GetPorcentajeLength();

    rlutil::locate(x, row);
    std::cout << std::left << std::setw(TipoResponsable::GetTipoFacturacionLength()) << (char)toupper(this->tipoFacturacion);

    rlutil::locate(1, row + 1);
}
