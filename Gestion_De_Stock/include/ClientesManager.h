#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "Base.h"

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ClienteManager : public Base {
private:
    string rutaArchivo;

public:
    ClienteManager(string ruta);

    void agregar(Cliente* cli);
    bool eliminar(int id);
    Cliente* buscar(int id);
    int obtenerIndice(int id);

    int getCantidad();
    Cliente* getPorIndice(int index);

    void listarTodos();

    bool cargarDeArchivo();
    bool escribirArchivo();

    void alta() override;
    void baja() override;
    void modificacion() override;
    void consulta() const override;
};

#endif // CLIENTEMANAGER_H
