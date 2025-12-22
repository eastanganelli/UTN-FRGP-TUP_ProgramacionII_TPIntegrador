#ifndef TIPORESPONSABLE_MENU_H
#define TIPORESPONSABLE_MENU_H

#include <iostream>

using namespace std;

#include "../../controller/modals/error.h"
#include "../../controller/modals/warning.h"

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_tipo_responsables.h"

class TipoResponsableMenu : public Menu {
private:
    TipoResponsableManager tipos;
    /** Construye un tipo de responsable mediante ingreso interactivo. */
    TipoResponsable CrearTipoResponsable(bool& ok);
    /** Permite modificar campos del tipo indicado. */
    void ModificarTipoResponsable(TipoResponsable& tipo);
    /** Marca como baja un tipo de responsable tras confirmacion. */
    bool EliminarTipoResponsable(TipoResponsable& tipo);
public:
    /** Inicializa el menu de tipos de responsable. */
    TipoResponsableMenu();
    /** Ejecuta la opcion elegida del menu. */
    virtual bool OnSelect(int index) override;
};

#endif // TIPORESPONSABLE_MENU_H
