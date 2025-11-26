#include "tipo_responsable.h"
#include <cctype>

TipoResponsable::TipoResponsable(const string codigo, const string descripcion, const float _porcentaje, const char _tipoFacturacion) {
    strcpy(this->codigo, codigo.c_str());
    strcpy(this->descripcion, descripcion.c_str());
    this->descripcion[sizeof(this->descripcion) - 1] = '\0';
    this->porcentaje = _porcentaje;
    this->tipoFacturacion = _tipoFacturacion;
}

TipoResponsable::~TipoResponsable() { }

string TipoResponsable::getCodigo() const {
    return string(this->codigo);
}

string TipoResponsable::getDescripcion() const {
    return string(this->descripcion);
}

float TipoResponsable::getPorcentaje() const {
    return this->porcentaje;
}

unsigned int TipoResponsable::GetCodigoLength() {
    return TipoResponsable::CODIGO_SIZE;
}

unsigned int TipoResponsable::GetDescripcionLength() {
    return TipoResponsable::DESCRIPCION_SIZE;
}

unsigned int TipoResponsable::GetPorcentajeLength() {
    return TipoResponsable::PORCENTAJE_SIZE;
}

unsigned int TipoResponsable::GetTipoFacturacionLength() {
    return TipoResponsable::TIPOFACTURACION_SIZE;
}

bool TipoResponsable::operator==(const TipoResponsable& otra) const {
    return this->codigo == otra.codigo &&
           strcmp(this->descripcion, otra.descripcion) == 0 &&
           this->porcentaje == otra.porcentaje;
}

bool TipoResponsable::IsEmpty() const {
    return this->codigo == 0 &&
           strlen(this->descripcion) == 0 &&
           this->porcentaje == -1.0f;
}

void TipoResponsable::Print() {
    printf("%-*s%-*s%-*.1f%-*c\n",
           TipoResponsable::GetCodigoLength(), this->codigo,
           TipoResponsable::GetDescripcionLength(), this->descripcion,
           TipoResponsable::GetPorcentajeLength(), this->porcentaje,
           TipoResponsable::GetTipoFacturacionLength(), (int)toupper(this->tipoFacturacion));
}