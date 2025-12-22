#ifndef BACKUP_MENU_H
#define BACKUP_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"

#include "../../manager/manager_cliente.h"
#include "../../manager/manager_proveedor.h"
#include "../../manager/manager_producto.h"
#include "../../manager/manager_tipo_responsables.h"
#include "../../manager/manager_ventas.h"

#include <iostream>

using namespace std;

class BackupMenu : public Menu {
public:
    /** Inicializa el menu de backups. */
    BackupMenu();
    /** Ejecuta la opcion seleccionada del menu de backups. */
    bool OnSelect(int index) override;
};

#endif // BACKUP_MENU_H
