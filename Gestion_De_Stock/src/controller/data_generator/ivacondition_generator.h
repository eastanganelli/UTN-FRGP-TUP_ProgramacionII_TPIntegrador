#include <ctime>
#include <string>

using namespace std;

#include "../../manager/condicioniva_manager.h"

namespace DataGenerator {
    struct DatosCondicionIVA {
        unsigned int codigo;
        std::string descripcion;
        float porcentaje;
    };
    std::string GenerateIVACondition(unsigned int count = 0);
}