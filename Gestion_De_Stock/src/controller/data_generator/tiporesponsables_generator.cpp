#include "tiporesponsables_generator.h"

void DataGenerator::GenerateTipoResponsable(unsigned int count) {
    TipoResponsableManager tipos_responsables;

    if(tipos_responsables.Count() == 0) {
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

        for(const auto& datos : datos_ejemplo) {
            TipoResponsable nuevo_tipo(datos.codigo, datos.descripcion, datos.porcentaje, datos.tipoFacturacion);
            tipos_responsables.New(nuevo_tipo);

            nuevo_tipo.Print();
        }
    }
}
