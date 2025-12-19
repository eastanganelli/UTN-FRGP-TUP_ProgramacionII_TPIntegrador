#ifndef RECAUDACION_ANUAL_REPORT_H
#define RECAUDACION_ANUAL_REPORT_H

#include "../manager/ventas/manager_factura.h"
#include "../menu/menu_utils.h"
#include "../controller/validation.h"

#include "report.h"

#include <iostream>

using namespace std;

class RecaudacionAnualReport : public Report {
private:
    FacturaManager facturas;
    double CalcularRecaudacion(unsigned int anio);

public:
	RecaudacionAnualReport();
	void Run() override;
};

#endif // RECAUDACION_ANUAL_REPORT_H
