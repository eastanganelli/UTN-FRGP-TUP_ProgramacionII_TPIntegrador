#ifndef BACKUP_MENU_H
#define BACKUP_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"

class BackupMenu : public Menu {
public:
    BackupMenu();
    bool OnSelect(int index) override;
};

#endif // BACKUP_MENU_H
