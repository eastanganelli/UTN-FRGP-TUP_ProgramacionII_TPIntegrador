#ifndef REPORTS_MENU_H
#define REPORTS_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"

#include "../../reports/recaudacion_anual.h"
#include "../../reports/recaudacion_trimestral.h"
#include "../../reports/top_10_productos.h"
#include "../../reports/top_5_fechas.h"
#include "../../reports/top_cliente.h"

class ReportsMenu : public Menu {
public:
    ReportsMenu();
    bool OnSelect(int index) override;
};

#endif // REPORTS_MENU_H
