#include "tiporesponsables_generator.h"

void DataGenerator::GenerateTipoResponsable(unsigned int count) {
    srand(static_cast<unsigned int>(time(NULL)));
    TipoResponsable condicion_ivaManager("tipo_responsable.dat");
    
    DatosTipoResponsable datos_ejemplo[] = {
        {"1A4", "IVA Responsable Inscripto", 10.5f, 'A'},
        {"1A5", "IVA Responsable Inscripto", 21.0f, 'A'},
        {"1A6", "IVA Responsable Inscripto", 27.0f, 'A'},
        {"4B5", "IVA Sujeto Exento", 21.0f, 'B'},
        {"5B4", "Consumidor Final", 10.5f, 'B'},
        {"5B5", "Consumidor Final", 21.0f, 'B'},
        {"6B4", "Responsable Monotributo", 10.5f, 'B'},
        {"6B5", "Responsable Monotributo", 21.0f, 'B'},
        {"9E3", "Cliente del Exterior", 0.0f, 'E'}
    };
}