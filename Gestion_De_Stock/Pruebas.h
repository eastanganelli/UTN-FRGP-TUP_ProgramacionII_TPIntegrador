#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <ctime>
#include <iostream>

#include "src/controller/modals.h"
#include "src/controller/generic_array.h"
#include "src/file_manager/file_system.h"

#include "src/manager/cliente_manager.h"
#include "src/manager/tiporesponsables_manager.h"

using namespace std;

namespace Testing {
    void Modals();
    void Array();
    void File();
    void ClientePrueba();
    void TipoResponsablePrueba();
}

//void TestingCliente();
//
//void TestingProveedores();
//
//void TestingProductos();
//
//void TestingVentas();
//
//void TestingAll();
//
//void loadData();

#endif // PRUEBAS_H
