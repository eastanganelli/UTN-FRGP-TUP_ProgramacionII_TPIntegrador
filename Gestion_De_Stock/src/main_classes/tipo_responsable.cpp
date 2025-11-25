#include "tipo_responsable.h"

TipoResponsable::TipoResponsable(const unsigned int codigo, const string descripcion, const float porcentaje) {
    this->codigo = codigo;
    strcpy(this->descripcion, descripcion.c_str());
    this->descripcion[sizeof(this->descripcion) - 1] = '\0';
    this->porcentaje = porcentaje;
}

TipoResponsable::~TipoResponsable() { }

unsigned int TipoResponsable::getCodigo() const {
    return this->codigo;
}

string TipoResponsable::getDescripcion() const {
    return string(this->descripcion);
}

float TipoResponsable::getPorcentaje() const {
    return this->porcentaje;
}

bool TipoResponsable::operator==(const TipoResponsable& otra) const {
    return this->codigo == otra.codigo &&
           strcmp(this->descripcion, otra.descripcion) == 0 &&
           this->porcentaje == otra.porcentaje;
}

bool TipoResponsable::IsEmpty() const {
    return this->codigo == 0 &&
           strlen(this->descripcion) == 0 &&
           this->porcentaje == 0.0f;
}

void TipoResponsable::Print() {
    printf("%-5u%-30s%5.2f%%\n", this->codigo, this->descripcion, this->porcentaje);
}