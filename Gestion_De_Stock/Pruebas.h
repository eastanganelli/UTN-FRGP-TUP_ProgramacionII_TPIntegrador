#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <ctime>
#include <iostream>

#include "src/controller/modals.h"
#include "src/controller/generic_array.h"
#include "src/file_manager/file_system.h"

#include "src/manager/manager_cliente.h"
#include "src/manager/manager_tipo_responsables.h"

using namespace std;

namespace Testing {
    void Modals();
    void Array();
    void File();
    void ClientePrueba();
    void TipoResponsablePrueba();
    void FacturaPrueba();
}

#endif // PRUEBAS_H
