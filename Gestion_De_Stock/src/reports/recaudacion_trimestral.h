#ifndef RECAUDACION_TRIMESTRAL_REPORT_H
#define RECAUDACION_TRIMESTRAL_REPORT_H

#include "../manager/ventas/manager_factura.h"

#include "report.h"

class RecaudacionTrimestralReport : public Report {
private:
    FacturaManager facturas;

public:
	RecaudacionTrimestralReport();
	void Run() override;
};

#endif // RECAUDACION_TRIMESTRAL_REPORT_H
