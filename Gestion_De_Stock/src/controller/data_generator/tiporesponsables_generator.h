#include <ctime>
#include <string>

using namespace std;

#include "../../manager/manager_tiporesponsables.h"

namespace DataGenerator {
    struct DatosTipoResponsable {
        string codigo;
        std::string descripcion;
        float porcentaje;
        char tipoFacturacion;
    };
    void GenerateTipoResponsable(unsigned int count = 0);
}