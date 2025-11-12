#include "TipoResponsable.h"

TipoResponsable::TipoResponsable(unsigned int _id, string _descripcion, float _porcentaje) : id(_id) {
    strcpy(this->descripcion, _descripcion.c_str());
    this->porcentaje = _porcentaje;
}

TipoResponsable::~TipoResponsable() {
    //dtor
}

unsigned int TipoResponsable::getId() {
    return this->id;
}

string TipoResponsable::getDescripcion() {
    return string(this->descripcion);
}

float TipoResponsable::getPorcentaje() {
    return this->porcentaje;
}
