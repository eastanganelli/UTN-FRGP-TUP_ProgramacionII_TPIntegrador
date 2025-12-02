#ifndef TIPORESPONSABLE_MENU_H
#define TIPORESPONSABLE_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_tipo_responsables.h"

class TipoResponsableMenu : public Menu {
private:
    TipoResponsableManager tipos;
public:
    TipoResponsableMenu();
    virtual bool OnSelect(int index) override;
};

#endif // TIPORESPONSABLE_MENU_H
