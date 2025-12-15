#include "venta_menu.h"
#include <iostream>
#include "../../../controller/table/table.h"
#include "../../../manager/ventas/manager_nota_de_credito.h"
#include "../../../main_classes/ventas/comprobante.h"
#include "../../../main_classes/ventas/factura.h"
#include "../../../controller/modals/warning.h"

using namespace std;

VentaMenu::VentaMenu() : Menu("Menu Ventas", true) {
    AddOption("Agregar Factura");
    AddOption("Modificar Factura");
    AddOption("Anular factura");
    AddOption("Listar Comprobantes por Cliente");
    AddOption("Listar Comprobantes por Monto");
    AddOption("Buscar Comprobante por Cliente");
    AddOption("Buscar Comprobante por Extra (CAE/Motivo)");
    AddOption("Buscar Comprobante por Rango de Fecha");
    AddOption("Ver detalle de Comprobante");
    AddOption("Volver");
}

bool VentaMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: AgregarFactura(); return false;
        case 1: ModificarFactura(); return false;
        case 2: AnularFactura(); return false;
        case 3: ListarComprobantesPorCliente(); return false;
        case 4: ListarFacturasPorMonto(); return false;
        case 5: BuscarComprobantePorCliente(); return false;
        case 6: BuscarComprobantePorExtra(); return false;
        case 7: BuscarComprobantePorRangoFecha(); return false;
        case 8: VerDetalleComprobante(); return false;
        case 9: return true;
        default: return false;
    }
}

void VentaMenu::AgregarFactura() {
    unsigned int maxNum = 0;
    unsigned int fc = facturas.Count();
    for (unsigned int i = 0; i < fc; ++i) {
        Factura* f = facturas.At(i);
        if (f != nullptr) { if (f->getNumero() > maxNum) maxNum = f->getNumero(); delete f; }
    }
    unsigned int nc = notas.Count();
    for (unsigned int i = 0; i < nc; ++i) {
        NotaDeCredito* n = notas.At(i);
        if (n != nullptr) { if (n->getNumero() > maxNum) maxNum = n->getNumero(); delete n; }
    }

    unsigned int nuevoId = maxNum + 1;
    bool ok = false;
    Factura f = CrearFactura(nuevoId, ok);
    if (!ok) {
        cout << "Operacion cancelada." << endl;
        PauseConsole();
        return;
    }
    if (facturas.Agregar(f)) cout << "Factura agregada exitosamente." << endl;
    else cout << "Error al agregar la factura." << endl;
    PauseConsole();
}

void VentaMenu::ModificarFactura() {
    unsigned int numero = InputNumber("Numero de la factura a modificar: ");
    Factura* f = facturas[numero];
    if (f == nullptr) {
        cout << "Factura no encontrada." << endl;
        PauseConsole();
        return;
    }
    if (!Validation::IsEmpty(f->getCAE())) {
        rlutil::cls();
        Warning w("Factura facturada", "No se puede modificar una factura con CAE asignado.");
        w.Show(); w.WaitForKey();
        PauseConsole();
        return;
    }

    ModificarFacturaInteractiva(*f);

    if (facturas.Modificar(numero, f)) cout << "Factura modificada exitosamente." << endl;
    else cout << "Error al modificar la factura." << endl;
    PauseConsole();
}

void VentaMenu::ListarFacturasPorMonto() {
    GenericArray<Factura> fcs = facturas.BuscarPorRangoFecha(Fecha(1,1,1900), Fecha(31,12,9999));
    GenericArray<NotaDeCredito> nts = notas.BuscarPorRangoFecha(Fecha(1,1,1900), Fecha(31,12,9999));
    GenericArray<unsigned int> numeros;
    GenericArray<unsigned int> tipos;
    OrdenarComprobantesPorMonto(fcs, nts, numeros, tipos);
    ImprimirIntercalado(numeros, tipos);
    PauseConsole();
}

void VentaMenu::BuscarComprobantePorCliente() {
    string dni = InputBox("DNI del cliente: ");
    ImprimirComprobantesCliente(dni);
    PauseConsole();
}

void VentaMenu::BuscarComprobantePorExtra() {
    string extra = InputBox("CAE (factura) o Motivo (nota): ");
    GenericArray<Factura> fcs;
    const unsigned int fcCount = facturas.Count();
    for (unsigned int i = 0; i < fcCount; ++i) {
        Factura* f = facturas.At(i);
        if (f != nullptr) {
            if (f->getCAE().find(extra) != string::npos) {
                fcs.Append(*f);
            }
            delete f;
        }
    }

    GenericArray<NotaDeCredito> nts;
    const unsigned int ntCount = notas.Count();
    for (unsigned int i = 0; i < ntCount; ++i) {
        NotaDeCredito* n = notas.At(i);
        if (n != nullptr) {
            if (n->getMotivoAnulacion().find(extra) != string::npos) {
                nts.Append(*n);
            }
            delete n;
        }
    }

    GenericArray<unsigned int> numeros;
    GenericArray<unsigned int> tipos;
    ConstruirIntercaladoPorNumero(fcs, nts, numeros, tipos);
    ImprimirIntercalado(numeros, tipos);
    PauseConsole();
}

void VentaMenu::BuscarComprobantePorRangoFecha() {
    Fecha fechaInicio = InputDate("Ingrese Fecha Inicio");
    rlutil::cls();
    Fecha fechaFin = InputDate("Ingrese Fecha Fin");
    GenericArray<Factura> fcs = facturas.BuscarPorRangoFecha(fechaInicio, fechaFin);
    GenericArray<NotaDeCredito> nts = notas.BuscarPorRangoFecha(fechaInicio, fechaFin);
    GenericArray<unsigned int> numeros;
    GenericArray<unsigned int> tipos;
    ConstruirIntercaladoPorNumero(fcs, nts, numeros, tipos);
    ImprimirIntercalado(numeros, tipos);
    PauseConsole();
}

void VentaMenu::ListarComprobantesPorCliente() {
    GenericArray<Factura> fcs;
    for (unsigned int i = 0; i < facturas.Count(); ++i) {
        Factura* f = facturas.At(i);
        if (f != nullptr) { fcs.Append(*f); delete f; }
    }

    GenericArray<NotaDeCredito> nts;
    for (unsigned int i = 0; i < notas.Count(); ++i) {
        NotaDeCredito* n = notas.At(i);
        if (n != nullptr) { nts.Append(*n); delete n; }
    }

    GenericArray<unsigned int> numeros;
    GenericArray<unsigned int> tipos;
    OrdenarComprobantesPorCliente(fcs, nts, numeros, tipos);
    ImprimirIntercalado(numeros, tipos);
    PauseConsole();
}

void VentaMenu::VerDetalleComprobante() {
    rlutil::cls();

    GenericArray<Factura> fcs;
    for (unsigned int i = 0; i < facturas.Count(); ++i) {
        Factura* f = facturas.At(i);
        if (f != nullptr) { fcs.Append(*f); delete f; }
    }

    GenericArray<NotaDeCredito> nts;
    for (unsigned int i = 0; i < notas.Count(); ++i) {
        NotaDeCredito* n = notas.At(i);
        if (n != nullptr) { nts.Append(*n); delete n; }
    }

    if (fcs.Size() == 0 && nts.Size() == 0) {
        Warning w("Sin comprobantes", "No hay facturas ni notas para mostrar.");
        w.Show(); w.WaitForKey();
        PauseConsole();
        return;
    }

    OrdenarPorNumero(fcs);
    OrdenarPorNumero(nts);

    GenericArray<unsigned int> mapEsFactura; // 1 = factura/presupuesto, 0 = nota
    GenericArray<unsigned int> mapIdx;       // indice dentro de su arreglo

    const unsigned int columnas = 6;
    const unsigned int widthNumero = Comprobante::ColNumeroSize();
    const unsigned int widthFecha = Comprobante::ColFechaEmisionSize();
    const unsigned int widthTotal = Comprobante::ColMontoTotalSize();
    const unsigned int widthCliente = Comprobante::ColClienteDNISize();
    const unsigned int widthTipo = Comprobante::ColTipoSize();

    Tabling::Table tabla(fcs.Size() + nts.Size(), columnas);
    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("Idx", 4);
    header->AddCell("Numero", widthNumero);
    header->AddCell("Tipo", widthTipo);
    header->AddCell("Cliente", widthCliente);
    header->AddCell("Fecha", widthFecha);
    header->AddCell("Total", widthTotal);
    tabla.AddRow(header);

    unsigned int i = 0, j = 0, idxTabla = 0;
    while (i < fcs.Size() || j < nts.Size()) {
        bool tomarFactura = false;
        if (i < fcs.Size() && j < nts.Size()) {
            tomarFactura = fcs[i]->getNumero() <= nts[j]->getNumero();
        } else if (i < fcs.Size()) {
            tomarFactura = true;
        }

        Tabling::Row* row = new Tabling::Row(columnas);
        if (tomarFactura) {
            Factura* f = fcs[i];
            const string tipo = Validation::IsEmpty(f->getCAE()) ? "Presupuesto" : "Factura";
            row->AddCell(to_string(idxTabla), 4);
            row->AddCell(to_string(f->getNumero()), widthNumero);
            row->AddCell(tipo, widthTipo);
            row->AddCell(f->getClienteDNI(), widthCliente);
            row->AddCell(f->getFechaEmision().toString(), widthFecha);
            row->AddCell(to_string(f->TotalSinIVA()), widthTotal);
            unsigned int flag = 1; // factura/presupuesto
            unsigned int pos = i;
            mapEsFactura.Append(flag);
            mapIdx.Append(pos);
            ++i;
        } else {
            NotaDeCredito* n = nts[j];
            row->AddCell(to_string(idxTabla), 4);
            row->AddCell(to_string(n->getNumero()), widthNumero);
            row->AddCell("Nota", widthTipo);
            row->AddCell(n->getClienteDNI(), widthCliente);
            row->AddCell(n->getFechaEmision().toString(), widthFecha);
            row->AddCell(to_string(n->TotalSinIVA()), widthTotal);
            unsigned int flag = 0; // nota
            unsigned int pos = j;
            mapEsFactura.Append(flag);
            mapIdx.Append(pos);
            ++j;
        }
        tabla.AddRow(row);
        ++idxTabla;
    }

    int seleccionado = -1;
    while (true) {
        rlutil::cls();
        tabla.Print();
        string entrada = InputBox("Indice a ver (vacio para cancelar): ");
        if (entrada.empty()) return;
        char* endptr = nullptr;
        const char* raw = entrada.c_str();
        unsigned long idxLong = std::strtoul(raw, &endptr, 10);
        if (endptr == raw || *endptr != '\0') continue;
        if (idxLong >= mapEsFactura.Size()) continue;
        seleccionado = static_cast<int>(idxLong);
        break;
    }

    const unsigned int flag = *mapEsFactura[static_cast<unsigned int>(seleccionado)];
    const unsigned int pos = *mapIdx[static_cast<unsigned int>(seleccionado)];

    unsigned int cantidad_filas = 0;
    GenericArray<Item> items_comprobante;

    rlutil::cls();
    if (flag == 1) {
        Factura* f = fcs[pos];
        const string tipo = Validation::IsEmpty(f->getCAE()) ? "Presupuesto" : "Factura";
        cout << "Tipo: " << tipo << endl
            << "Numero: " << f->getNumero() << endl
            << "Cliente: " << f->getClienteDNI() << endl
            << "Fecha emision: " << f->getFechaEmision().toString() << endl
            << "Total sin IVA: " << f->TotalSinIVA() << endl
            << "CAE: " << f->getCAE() << endl
            << "Vto CAE: " << f->getVencimientoCAE().toString() << endl
            << endl << "Items " << endl;

        cantidad_filas = f->CantidadItems();
        items_comprobante = f->ObtenerTodosLosItems();

    } else {
        NotaDeCredito* n = nts[pos];
        cout << "Tipo: Nota de Credito" << endl
            << "Numero: " << n->getNumero() << endl
            << "Cliente: " << n->getClienteDNI() << endl
            << "Fecha emision: " << n->getFechaEmision().toString() << endl
            << "Total sin IVA: " << n->TotalSinIVA() << endl
            << "Motivo: " << n->getMotivoAnulacion() << endl
            << endl << "Items " << endl;

        cantidad_filas = n->CantidadItems();
        items_comprobante = n->ObtenerTodosLosItems();
    }
    
    const unsigned int itemCols = 4;
    const unsigned int widthCod = Item::CodigoSize();
    const unsigned int widthCant = Item::CantidadSize();
    const unsigned int widthPrecio = Item::PrecioUnitarioSize();
    const unsigned int widthSub = Item::TotalItemSize();

    Tabling::Table itemsTable(cantidad_filas, itemCols, '-', 9);
    Tabling::Row* ih = new Tabling::Row(itemCols);
    ih->AddCell("Codigo", widthCod);
    ih->AddCell("Cant", widthCant);
    ih->AddCell("Precio", widthPrecio);
    ih->AddCell("Subtotal", widthSub);
    itemsTable.AddRow(ih);
    for (unsigned int k = 0; k < cantidad_filas; ++k) {
        const Item* it = items_comprobante[k];
        if (it == nullptr) continue;
        Tabling::Row* ir = new Tabling::Row(itemCols);
        ir->AddCell(it->getCodigo(), widthCod);
        ir->AddCell(to_string(it->getCantidad()), widthCant);
        ir->AddCell(to_string(it->getPrecioUnitario()), widthPrecio);
        ir->AddCell(to_string(it->getCantidad() * it->getPrecioUnitario()), widthSub);
        itemsTable.AddRow(ir);
    }
    itemsTable.Print();

    PauseConsole();
}

void VentaMenu::ImprimirComprobantesCliente(const string& dni) {
    GenericArray<Factura> fcs = facturas.BuscarPorCliente(dni);
    GenericArray<NotaDeCredito> nts = notas.BuscarPorCliente(dni);
    GenericArray<unsigned int> numeros;
    GenericArray<unsigned int> tipos;
    ConstruirIntercaladoPorNumero(fcs, nts, numeros, tipos);
    ImprimirIntercalado(numeros, tipos);
}

void VentaMenu::ConstruirOrdenIntercalado(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, bool ordenarPorCliente, GenericArray<unsigned int>& mapTipo, GenericArray<unsigned int>& mapIdx) {
    mapTipo.Clear();
    mapIdx.Clear();

    unsigned int i = 0, j = 0;
    while (i < fcs.Size() || j < nts.Size()) {
        bool tomarFactura = false;
        if (i < fcs.Size() && j < nts.Size()) {
            if (ordenarPorCliente) {
                const string& cf = fcs[i]->getClienteDNI();
                const string& cn = nts[j]->getClienteDNI();
                if (cf == cn) {
                    tomarFactura = fcs[i]->getNumero() <= nts[j]->getNumero();
                } else {
                    tomarFactura = cf < cn;
                }
            } else {
                tomarFactura = fcs[i]->getNumero() <= nts[j]->getNumero();
            }
        } else if (i < fcs.Size()) {
            tomarFactura = true;
        }

        if (tomarFactura) {
            unsigned int flag = 1; // factura/presupuesto
            unsigned int pos = i;
            mapTipo.Append(flag);
            mapIdx.Append(pos);
            ++i;
        } else {
            unsigned int flag = 0; // nota
            unsigned int pos = j;
            mapTipo.Append(flag);
            mapIdx.Append(pos);
            ++j;
        }
    }
}

void VentaMenu::ConstruirIntercaladoPorNumero(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos) {
    numeros.Clear();
    tipos.Clear();

    GenericArray<unsigned int> idxs;
    OrdenarPorNumero(fcs);
    OrdenarPorNumero(nts);
    ConstruirOrdenIntercalado(fcs, nts, false, tipos, idxs);

    for (unsigned int ord = 0; ord < tipos.Size(); ++ord) {
        const unsigned int idx = *idxs[ord];
        if (*tipos[ord] == 1) {
            unsigned int nro = fcs[idx]->getNumero();
            numeros.Append(nro);
        } else {
            unsigned int nro = nts[idx]->getNumero();
            numeros.Append(nro);
        }
    }
}

void VentaMenu::OrdenarComprobantesPorCliente(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos) {
    numeros.Clear();
    tipos.Clear();

    OrdenarPorCliente(fcs);
    OrdenarPorCliente(nts);

    unsigned int i = 0, j = 0;
    while (i < fcs.Size() || j < nts.Size()) {
        bool tomarFactura = false;
        if (i < fcs.Size() && j < nts.Size()) {
            const string& cf = fcs[i]->getClienteDNI();
            const string& cn = nts[j]->getClienteDNI();
            if (cf == cn) {
                tomarFactura = fcs[i]->getNumero() <= nts[j]->getNumero();
            } else {
                tomarFactura = cf < cn;
            }
        } else if (i < fcs.Size()) {
            tomarFactura = true;
        }

        if (tomarFactura) {
            unsigned int nro = fcs[i]->getNumero();
            unsigned int tipo = 1; // factura/presupuesto
            numeros.Append(nro);
            tipos.Append(tipo);
            ++i;
        } else {
            unsigned int nro = nts[j]->getNumero();
            unsigned int tipo = 0; // nota de credito
            numeros.Append(nro);
            tipos.Append(tipo);
            ++j;
        }
    }
}

void VentaMenu::OrdenarComprobantesPorMonto(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos) {
    numeros.Clear();
    tipos.Clear();

    GenericArray<float> montos;

    for (unsigned int i = 0; i < fcs.Size(); ++i) {
        float m = fcs[i]->TotalSinIVA();
        montos.Append(m);
        unsigned int nro = fcs[i]->getNumero();
        numeros.Append(nro);
        unsigned int tipo = 1;
        tipos.Append(tipo);
    }

    for (unsigned int j = 0; j < nts.Size(); ++j) {
        float m = nts[j]->TotalSinIVA();
        montos.Append(m);
        unsigned int nro = nts[j]->getNumero();
        numeros.Append(nro);
        unsigned int tipo = 0;
        tipos.Append(tipo);
    }

    for (unsigned int i = 0; i + 1 < montos.Size(); ++i) {
        for (unsigned int j = i + 1; j < montos.Size(); ++j) {
            if (*montos[j] < *montos[i]) {
                float tempMonto = *montos[i];
                *montos[i] = *montos[j];
                *montos[j] = tempMonto;

                unsigned int tempNum = *numeros[i];
                *numeros[i] = *numeros[j];
                *numeros[j] = tempNum;

                unsigned int tempTipo = *tipos[i];
                *tipos[i] = *tipos[j];
                *tipos[j] = tempTipo;
            }
        }
    }
}

void VentaMenu::ImprimirIntercalado(GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos) {
    rlutil::cls();
    if (numeros.Size() == 0 || tipos.Size() == 0 || numeros.Size() != tipos.Size()) {
        Warning w("Sin comprobantes", "No se encontraron facturas ni notas para los criterios indicados.");
        w.Show();
        return;
    }

    const unsigned int totalRows = numeros.Size();
    const unsigned int columnas = 6;
    const unsigned int widthNumero = Comprobante::ColNumeroSize();
    const unsigned int widthFecha = Comprobante::ColFechaEmisionSize();
    const unsigned int widthTotal = Comprobante::ColMontoTotalSize();
    const unsigned int widthExtra = Factura::ColCAESize();
    const unsigned int widthTipo = Comprobante::ColTipoSize();
    const unsigned int widthCliente = Comprobante::ColClienteDNISize();

    Tabling::Table tabla(totalRows, columnas);

    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("Numero", widthNumero);
    header->AddCell("Tipo", widthTipo);
    header->AddCell("Cliente", widthCliente);
    header->AddCell("Fecha", widthFecha);
    header->AddCell("Total", widthTotal);
    header->AddCell("Extra", widthExtra);
    tabla.AddRow(header);

    for (unsigned int ord = 0; ord < numeros.Size(); ++ord) {
        Tabling::Row* row = new Tabling::Row(columnas);
        const unsigned int flag = *tipos[ord];
        const unsigned int nro = *numeros[ord];
        if (flag == 1) {
            Factura* f = facturas[nro];
            if (f == nullptr) { delete row; continue; }
            const string tipo = Validation::IsEmpty(f->getCAE()) ? "Presupuesto" : "Factura";
            row->AddCell(to_string(f->getNumero()), widthNumero);
            row->AddCell(tipo, widthTipo);
            row->AddCell(f->getClienteDNI(), widthCliente);
            row->AddCell(f->getFechaEmision().toString(), widthFecha);
            row->AddCell(to_string(f->TotalSinIVA()), widthTotal);
            row->AddCell(string("CAE: ") + f->getCAE(), widthExtra);
            delete f;
        } else {
            NotaDeCredito* n = notas[nro];
            if (n == nullptr) { delete row; continue; }
            row->AddCell(to_string(n->getNumero()), widthNumero);
            row->AddCell("Nota", widthTipo);
            row->AddCell(n->getClienteDNI(), widthCliente);
            row->AddCell(n->getFechaEmision().toString(), widthFecha);
            row->AddCell(to_string(n->TotalSinIVA()), widthTotal);
            row->AddCell(string("Motivo: ") + n->getMotivoAnulacion(), widthExtra);
            delete n;
        }
        tabla.AddRow(row);
    }

    tabla.Print();
}

void VentaMenu::OrdenarPorNumero(GenericArray<Factura>& fcs) {
    for (unsigned int i = 0; i + 1 < fcs.Size(); ++i) {
        for (unsigned int j = i + 1; j < fcs.Size(); ++j) {
            if (fcs[j]->getNumero() < fcs[i]->getNumero()) {
                fcs.Swap(fcs[i], fcs[j]);
            }
        }
    }
}

void VentaMenu::OrdenarPorNumero(GenericArray<NotaDeCredito>& nts) {
    for (unsigned int i = 0; i + 1 < nts.Size(); ++i) {
        for (unsigned int j = i + 1; j < nts.Size(); ++j) {
            if (nts[j]->getNumero() < nts[i]->getNumero()) {
                nts.Swap(nts[i], nts[j]);
            }
        }
    }
}

void VentaMenu::OrdenarPorCliente(GenericArray<Factura>& fcs) {
    for (unsigned int i = 0; i + 1 < fcs.Size(); ++i) {
        for (unsigned int j = i + 1; j < fcs.Size(); ++j) {
            if (fcs[j]->getClienteDNI() < fcs[i]->getClienteDNI() ||
               (fcs[j]->getClienteDNI() == fcs[i]->getClienteDNI() && fcs[j]->getNumero() < fcs[i]->getNumero())) {
                fcs.Swap(fcs[i], fcs[j]);
            }
        }
    }
}

void VentaMenu::OrdenarPorCliente(GenericArray<NotaDeCredito>& nts) {
    for (unsigned int i = 0; i + 1 < nts.Size(); ++i) {
        for (unsigned int j = i + 1; j < nts.Size(); ++j) {
            if (nts[j]->getClienteDNI() < nts[i]->getClienteDNI() ||
               (nts[j]->getClienteDNI() == nts[i]->getClienteDNI() && nts[j]->getNumero() < nts[i]->getNumero())) {
                nts.Swap(nts[i], nts[j]);
            }
        }
    }
}

void VentaMenu::AnularFactura() {
    rlutil::cls();
    GenericArray<Factura> candidatas;
    for (unsigned int i = 0; i < facturas.Count(); ++i) {
        Factura* f = facturas.At(i);
        if (f != nullptr) {
            if (!Validation::IsEmpty(f->getCAE())) {
                candidatas.Append(*f);
            }
            delete f;
        }
    }

    if (candidatas.Size() == 0) {
        Warning w("Sin comprobantes facturados", "No hay facturas con CAE para anular.");
        w.Show(); w.WaitForKey();
        PauseConsole();
        return;
    }

    const unsigned int cols = 7;
    Tabling::Table tabla(candidatas.Size(), cols);
    Tabling::Row* header = new Tabling::Row(cols);
    header->AddCell("Idx", 4);
    header->AddCell("Numero", Comprobante::ColNumeroSize());
    header->AddCell("Cliente", Comprobante::ColClienteDNISize());
    header->AddCell("Fecha", Comprobante::ColFechaEmisionSize());
    header->AddCell("CAE", Factura::ColCAESize());
    header->AddCell("Vto CAE", Factura::ColVencimientoCAESize());
    header->AddCell("Items", 6);
    tabla.AddRow(header);

    for (unsigned int i = 0; i < candidatas.Size(); ++i) {
        Factura* f = candidatas[i];
        Tabling::Row* row = new Tabling::Row(cols);
        row->AddCell(std::to_string(i), 4);
        row->AddCell(std::to_string(f->getNumero()), Comprobante::ColNumeroSize());
        row->AddCell(f->getClienteDNI(), Comprobante::ColClienteDNISize());
        row->AddCell(f->getFechaEmision().toString(), Comprobante::ColFechaEmisionSize());
        row->AddCell(f->getCAE(), Factura::ColCAESize());
        row->AddCell(f->getVencimientoCAE().toString(), Factura::ColVencimientoCAESize());
        row->AddCell(std::to_string(f->CantidadItems()), 6);
        tabla.AddRow(row);
    }

    int idx = -1;
    while (true) {
        rlutil::cls();
        tabla.Print();
        string entrada = InputBox("Indice a anular (vacio para cancelar): ");
        if (entrada.empty()) return;

        char* endptr = nullptr;
        const char* raw = entrada.c_str();
        unsigned long idxLong = std::strtoul(raw, &endptr, 10);
        if (endptr == raw || *endptr != '\0') continue;
        if (idxLong >= candidatas.Size()) continue;
        idx = static_cast<int>(idxLong);
        break;
    }

    Factura* seleccion = candidatas[idx];
    unsigned int nro = seleccion->getNumero();
    string motivo = InputBox("Motivo de anulación: ");
    Warning confirmacion("Confirmar", "Anular factura?");
    if (confirmacion.ShowYesNo()) {
        bool ok = ConvertirFacturaEnNota(nro, motivo);
        if (ok) cout << "Factura convertida en Nota de Credito." << endl;
        else cout << "Error: no se pudo convertir la factura." << endl;
    }
    PauseConsole();
}

string VentaMenu::SeleccionarCliente() {
    rlutil::cls();
    const unsigned int total = clientes.Count();
    GenericArray<string> dnis;
    GenericArray<string> nombres;

    for (unsigned int i = 0; i < total; ++i) {
        Cliente* c = clientes.At(i);
        if (c != nullptr) {
            if (c->getAlta()) {
                string dni = c->getDNI();
                string nombre = c->getApellido() + string(", ") + c->getNombre();
                dnis.Append(dni);
                nombres.Append(nombre);
            }
            delete c;
        }
    }

    if (dnis.Size() == 0) {
        rlutil::cls();
        Warning w("Sin clientes activos", "No hay clientes dados de alta para seleccionar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    while (true) {
        cout << "\nSeleccione cliente (solo activos):\n";
        for (unsigned int i = 0; i < dnis.Size(); ++i) {
            cout << i << ") " << *dnis[i] << " - " << *nombres[i] << "\n";
        }

        string entrada = InputBox("Indice (vacio para cancelar): ");
        if (entrada.empty()) return "";
        char* endptr = nullptr;
        const char* raw = entrada.c_str();
        unsigned long idxLong = std::strtoul(raw, &endptr, 10);
        if (endptr == raw || *endptr != '\0') {
            rlutil::cls();
            Warning w("Indice invalido", "Ingrese un numero de la lista.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }
        unsigned int idx = static_cast<unsigned int>(idxLong);
        if (idx >= dnis.Size()) {
            rlutil::cls();
            Warning w("Fuera de rango", "Seleccione un indice existente.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        return *dnis[idx];
    }
}

string VentaMenu::SeleccionarProductoCodigo() {
    rlutil::cls();
    const unsigned int total = productos.Count();
    if (total == 0) {
        rlutil::cls();
        Warning w("Sin productos", "No hay productos cargados. Agregue alguno antes de facturar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    while (true) {
        cout << "\nSeleccione producto (vaciar para terminar):\n";
        for (unsigned int i = 0; i < total; ++i) {
            Producto* p = productos.At(i);
            if (p != nullptr) {
                cout << i << ") " << p->getCodigo() << " - " << p->getDescripcion() << " | Precio: " << p->getPrecio() << " | Stock: " << p->getStock() << "\n";
                delete p;
            }
        }

        string entrada = InputBox("Indice: ");
        if (entrada.empty()) return "";
        char* endptr = nullptr;
        const char* raw = entrada.c_str();
        unsigned long idxLong = std::strtoul(raw, &endptr, 10);
        if (endptr == raw || *endptr != '\0') {
            rlutil::cls();
            Warning w("Indice invalido", "Ingrese un numero de la lista.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }
        unsigned int idx = static_cast<unsigned int>(idxLong);
        if (idx >= total) {
            rlutil::cls();
            Warning w("Fuera de rango", "Seleccione un indice existente.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        Producto* elegido = productos.At(idx);
        string codigo = "";
        if (elegido != nullptr) {
            codigo = elegido->getCodigo();
            delete elegido;
        }
        return codigo;
    }
}

bool VentaMenu::AgregarItemInteractivo(Factura& factura) {
    while (true) {
        string codigo = SeleccionarProductoCodigo();
        if (codigo.empty()) return false;

        Producto* p = productos[codigo];
        if (p == nullptr) {
            rlutil::cls();
            Warning w("Producto no encontrado", "Seleccione un producto valido.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        unsigned int stock = p->getStock();
        if (stock == 0) {
            rlutil::cls();
            Warning w("Sin stock", "El producto no tiene stock disponible.");
            w.Show(); w.WaitForKey();
            delete p;
            rlutil::cls();
            continue;
        }

        unsigned int cantidad = InputNumber("Cantidad: ");
        if (cantidad == 0 || cantidad > stock) {
            rlutil::cls();
            Warning w("Cantidad invalida", "Ingrese una cantidad mayor a 0 y menor o igual al stock.");
            w.Show(); w.WaitForKey();
            delete p;
            rlutil::cls();
            continue;
        }

        Item it(codigo.c_str(), cantidad, p->getPrecio());
        Producto actualizado = *p;
        delete p;

        if (!factura.AgregarItem(it)) {
            rlutil::cls();
            Warning w("Item duplicado", "Ya existe un item con ese producto en la factura.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        actualizado.setStock(stock - cantidad);
        productos.Modificar(actualizado.getCodigo(), &actualizado);
        return true;
    }
}

Factura VentaMenu::CrearFactura(unsigned int numero, bool& ok) {
    ok = false;
    Factura f(numero, "");

    string dni = SeleccionarCliente();
    if (dni.empty()) return f;
    f.setClienteDNI(dni);

    f.getFechaEmision() = Fecha::Hoy();

    while (AgregarItemInteractivo(f)) { }

    if (f.CantidadItems() > 0) {
        if (!f.Facturar()) {
            rlutil::cls();
            Warning w("Facturacion", "No se pudo generar CAE para la factura.");
            w.Show(); w.WaitForKey();
        }
    } else {
        rlutil::cls();
        Informational i("Factura guardada", "Factura creada sin items. No puede ser facturada hasta agregar items.");
        i.Show(); i.WaitForKey();
    }

    ok = true;
    return f;
}

void VentaMenu::ModificarFacturaInteractiva(Factura& factura) {
    unsigned int opcion = 0;
    do {
        rlutil::cls();
        cout << "-- Modificar Factura (ID: " << factura.getNumero() << ") --\n";
        cout << "1) Agregar Item\n";
        cout << "2) Modificar Item\n";
        cout << "3) Eliminar Item\n";
        cout << "4) Cambiar cliente\n";
        cout << "5) Terminar\n";
        opcion = InputNumber("Seleccione accion: ");
        switch(opcion) {
            case 1: {
                AgregarItemInteractivo(factura);
                break;
            }
            case 2: {
                if (factura.CantidadItems() == 0) {
                    rlutil::cls();
                    Warning w("Sin items", "La factura no tiene items para modificar.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                unsigned int idx = InputNumber("Indice de item (0-based): ");
                const Item* pit = factura.ObtenerItem(idx);
                if (pit == nullptr) {
                    rlutil::cls();
                    Warning w("Item no encontrado", "Indice invalido.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                Item mutableItem = *pit;
                Item::ModificarItem(mutableItem, productos);
                factura.EliminarItem(mutableItem.getCodigo());
                factura.AgregarItem(mutableItem);
                break;
            }
            case 3: {
                if (factura.CantidadItems() == 0) {
                    rlutil::cls();
                    Warning w("Sin items", "La factura no tiene items para eliminar.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                unsigned int idx = InputNumber("Indice de item (0-based): ");
                const Item* pit = factura.ObtenerItem(idx);
                if (pit == nullptr) {
                    rlutil::cls();
                    Warning w("Item no encontrado", "Indice invalido.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                Item temp = *pit;
                if (Item::EliminarItem(temp, productos)) {
                    factura.EliminarItem(temp.getCodigo());
                }
                break;
            }
            case 4: {
                string nuevo = SeleccionarCliente();
                if (!Validation::IsEmpty(nuevo)) {
                    factura.setClienteDNI(nuevo);
                    rlutil::cls();
                    Informational i("Cliente actualizado", "Se actualizo el cliente de la factura.");
                    i.Show(); i.WaitForKey();
                }
                break;
            }
            case 5: break;
            default: {
                rlutil::cls();
                Warning w("Opcion invalida", "Seleccione una opcion valida.");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 5);
    rlutil::cls();
}

bool VentaMenu::ConvertirFacturaEnNota(unsigned int numero, const string& motivo) {
    Factura* factura = facturas[numero];
    if (factura == nullptr) return false;

    NotaDeCredito nota(factura->getNumero(), factura->getClienteDNI(), motivo);
    nota.getFechaEmision() = Fecha::Hoy();

    for (unsigned int i = 0; i < factura->CantidadItems(); ++i) {
        const Item* it = factura->ObtenerItem(i);
        if (it != nullptr) {
            nota.AgregarItem(*it);
        }
    }

    if (!notas.Agregar(nota)) {
        delete factura;
        return false;
    }

    if (!facturas.Eliminar(numero)) {
        notas.Eliminar(nota.getNumero());
        delete factura;
        return false;
    }

    for (unsigned int i = 0; i < factura->CantidadItems(); ++i) {
        const Item* it = factura->ObtenerItem(i);
        if (it == nullptr) continue;
        Producto* p = productos[it->getCodigo()];
        if (p != nullptr) {
            Producto actualizado = *p;
            actualizado.setStock(p->getStock() + it->getCantidad());
            productos.Modificar(actualizado.getCodigo(), &actualizado);
            delete p;
        }
    }

    delete factura;
    return true;
}
