#ifndef NOTA_DE_CREDITO_MENU_H
#define NOTA_DE_CREDITO_MENU_H

#include "../../menu.h"
#include "../../menu_utils.h"
#include "../../../manager/ventas/manager_nota_de_credito.h"

class NotaDeCreditoMenu : public Menu {
private:
    NotaDeCreditoManager notas;
public:
    NotaDeCreditoMenu();
    virtual bool OnSelect(int index) override;
};

#endif // NOTA_DE_CREDITO_MENU_H
