#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

#include "ClientesManager.h"
#include "VentasManager.h"
#include "ProveedoresManager.h"
#include "ProductosManager.h"
#include "../rlutil.h"

class Menu {
private:
    const int MARGIN_X = 8;
    const int HEADER_WIDTH = 64;

    // Funcion generica para mostrar un submenu de cualquier seccion
    void menuSub(string titulo);

    // Muestra el submenu genérico y devuelve la opción elegida
    int mostrarSubmenu(string titulo);

    int centeredOffset(string text, int width);
    void drawHeader(string title = "", int startY = 2);
    void drawSectionTitle(string text, int y);
    void printOption(int y, int index, string label);
    int readIntAtPrompt(int y, string prompt = "Ingrese una opcion: ");
    int renderClientesLC();
    int renderVentasLC();
    int renderProveedoresLC();
    int renderProductosLC();
    int renderExtrasLC();
    int renderConfiguracionesLC();
    int renderModelosCopiaSeguridad(string ruta);
    int renderModelosRestaurarCopiaSeguridad(string ruta);
    int renderModelosExportarCSV(string ruta);
    void renderRecaudacionTrimestral(VentaManager& ventasManager);
    void renderRecaudacionAnual(VentaManager& ventasManager);
    
public:
    // Muestra el menu principal
    void mostrar();
};

#endif // MENU_H
