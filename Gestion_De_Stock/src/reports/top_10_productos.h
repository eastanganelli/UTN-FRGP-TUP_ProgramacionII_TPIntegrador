#ifndef TOP_10_PRODUCTOS_REPORT_H
#define TOP_10_PRODUCTOS_REPORT_H

#include "../manager/ventas/manager_factura.h"
#include "../manager/manager_producto.h"

#include "report.h"

class Top10ProductosReport : public Report {
private:
    ProductoManager productos;
    FacturaManager facturas;

public:
	Top10ProductosReport();
	void Run() override;
};

#endif // TOP_10_PRODUCTOS_REPORT_H
