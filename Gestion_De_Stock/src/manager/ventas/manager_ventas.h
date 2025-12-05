  #ifndef VENTAMANAGER_H
#define VENTAMANAGER_H

#include <string>
#include "manager_factura.h"
#include "manager_nota_de_credito.h"

using namespace std;

class VentaManager {
private:
    FacturaManager facturas;
    NotaDeCreditoManager notas;

public:
    VentaManager();
    ~VentaManager();

    bool ConvertirFacturaANota(unsigned int numeroFactura, const string& motivo);

    void ImprimirComprobantesPorCliente(const string& clienteDNI);
    void ImprimirTodos();
};

#endif // VENTAMANAGER_H
