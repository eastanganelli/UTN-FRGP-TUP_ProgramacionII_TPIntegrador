#ifndef TIPORESPONSABLES_GENERATOR_H
#define TIPORESPONSABLES_GENERATOR_H

#include <ctime>
#include <string>

using namespace std;

#include "../../manager/manager_tipo_responsables.h"

namespace DataGenerator {
    struct DatosTipoResponsable {
        string codigo;
        std::string descripcion;
        float porcentaje;
        char tipoFacturacion;
    };
    void GenerateTipoResponsable(unsigned int count = 0, bool printLog = false);
}

#endif // TIPORESPONSABLES_GENERATOR_H