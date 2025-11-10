#ifndef NOTADECREDITOMANAGER_H
#define NOTADECREDITOMANAGER_H

#include "NotaDeCredito.h"

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class NotaDeCreditoManager {
private:
    vector<NotaDeCredito> notasDeCredito;
    string rutaArchivo;

public:
    NotaDeCreditoManager(string& ruta);

    void agregar(NotaDeCredito* nota);
    bool eliminar(int idVenta);
    NotaDeCredito* buscar(int idVenta);
    int obtenerIndice(int idVenta);

    int getCantidad();
    NotaDeCredito getPorIndice(int index);

    void listarTodos();

    bool cargarDeArchivo();
    bool escribirArchivo();
};

#endif // NOTADECREDITOMANAGER_H
