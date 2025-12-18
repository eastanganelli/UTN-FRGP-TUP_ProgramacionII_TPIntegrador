#ifndef TOP_CLIENTE_REPORT_H
#define TOP_CLIENTE_REPORT_H

#include "../manager/ventas/manager_factura.h"
#include "../manager/manager_cliente.h"

#include "report.h"

class TopClienteReport : public Report {
private:
    ClienteManager clientes;
    FacturaManager facturas;

    
public:
	TopClienteReport();
	void Run() override;
};

#endif // TOP_CLIENTE_REPORT_H
