#ifndef GENERATOR_H
#define GENERATOR_H

#include <ctime>
#include <string>

using namespace std;

#include "../../main_classes/datos_personales.h"

namespace DataGenerator {
    std::string generarCodigoAlfaNumerico(int longitud);
    /** Genera una cadena numerica de longitud fija (rellena con digitos). */
    std::string generarNumero(unsigned int longitud);
}

#endif // GENERATOR_H