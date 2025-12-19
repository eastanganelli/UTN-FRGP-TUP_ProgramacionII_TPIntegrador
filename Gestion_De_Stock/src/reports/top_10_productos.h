#ifndef TOP_10_PRODUCTOS_REPORT_H
#define TOP_10_PRODUCTOS_REPORT_H

#include "../manager/ventas/manager_factura.h"
#include "../manager/manager_producto.h"
#include "../menu/menu_utils.h"
#include "../controller/validation.h"
#include "../controller/generic_array.h"

#include "report.h"

#include <iostream>

using namespace std;

class Top10ProductosReport : public Report {
private:
    ProductoManager productos;
    FacturaManager facturas;

	struct ProductoData {
		string codigo;
		string descripcion;
		double totalMonto;
		unsigned int unidades;
		bool found;
	};

	void CalcularTop(unsigned int anio, GenericArray<ProductoData>& lista);

public:
	Top10ProductosReport();
	void Run() override;
};

#endif // TOP_10_PRODUCTOS_REPORT_H
