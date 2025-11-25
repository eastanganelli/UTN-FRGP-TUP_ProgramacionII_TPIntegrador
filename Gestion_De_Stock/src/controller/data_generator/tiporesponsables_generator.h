#include <ctime>
#include <string>

using namespace std;

#include "../../manager/tiporesponsables_manager.h"

namespace DataGenerator {
    struct DatosCondicionIVA {
        unsigned int codigo;
        std::string descripcion;
        float porcentaje;
    };
    std::string GenerateTipoResponsable(unsigned int count = 0);
}