#ifndef RECAUDACION_ANUAL_REPORT_H
#define RECAUDACION_ANUAL_REPORT_H

#include "../manager/ventas/manager_factura.h"

#include "report.h"

class RecaudacionAnualReport : public Report {
private:
    FacturaManager facturas;

public:
	RecaudacionAnualReport();
	void Run() override;
};

#endif // RECAUDACION_ANUAL_REPORT_H
