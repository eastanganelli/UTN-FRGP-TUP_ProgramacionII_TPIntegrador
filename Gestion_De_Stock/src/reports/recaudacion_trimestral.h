#ifndef RECAUDACION_TRIMESTRAL_REPORT_H
#define RECAUDACION_TRIMESTRAL_REPORT_H

#include "../manager/ventas/manager_factura.h"
#include "../menu/menu_utils.h"
#include "../controller/validation.h"

#include "report.h"

#include <iostream>

using namespace std;

class RecaudacionTrimestralReport : public Report {
private:
    FacturaManager facturas;
    double CalcularRecaudacion(unsigned int anio, unsigned int trimestre);

public:
	RecaudacionTrimestralReport();
	void Run() override;
};

#endif // RECAUDACION_TRIMESTRAL_REPORT_H
