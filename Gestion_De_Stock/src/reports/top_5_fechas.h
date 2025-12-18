#ifndef TOP_5_FECHAS_REPORT_H
#define TOP_5_FECHAS_REPORT_H

#include "../manager/ventas/manager_factura.h"

#include "report.h"

class Top5FechasReport : public Report {
private:
    FacturaManager facturas;

public:
	Top5FechasReport();
	void Run() override;
};

#endif // TOP_5_FECHAS_REPORT_H
