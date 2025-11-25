#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <ctime>
#include <iostream>

#include "src/controller/modals/informational.h"
#include "src/controller/modals/warning.h"
#include "src/controller/modals/error.h"
#include "src/controller/generic_array.h"
#include "src/file_manager/file_system.h"
#include "src/manager/cliente_manager.h"

using namespace std;

namespace Testing {
    void Modals();
    void Array();
    void File();
    void ClientePrueba();
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
