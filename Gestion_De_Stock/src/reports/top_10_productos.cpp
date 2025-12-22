#include "top_10_productos.h"

#include "../controller/modals/warning.h"

Top10ProductosReport::Top10ProductosReport() : Report("Top 10 productos mas vendidos") {}

void Top10ProductosReport::Run() {
	rlutil::cls();
	rlutil::setBackgroundColor(rlutil::BLUE);
	rlutil::setColor(rlutil::WHITE);
	PrintDecoratedTitle(this->GetTitle(), '=');
	rlutil::resetColor();

	unsigned int anio = AskYearOrCurrent();
	GenericArray<ProductoData> lista;
	CalcularTop(anio, lista);

	for(unsigned int i = 0; i < lista.Size(); i++) {
		for(unsigned int j = i + 1; j < lista.Size(); j++) {
			if(lista[j]->unidades > lista[i]->unidades) {
				lista.Swap(lista[i], lista[j]);
			}
		}
	}

	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);
	rlutil::cls();
	PrintDecoratedTitle(this->GetTitle() + " (" + std::to_string(anio) + ")", '=');

	const unsigned int limite = lista.Size() < 10 ? lista.Size() : 10;
	if(limite == 0) {
		rlutil::resetColor();
		Warning w("Sin datos", "No hay facturas para el anio indicado.");
		w.Show(); w.WaitForKey();
		return;
	}

	const unsigned int columnas = 4;
	Tabling::Table tabla(limite, columnas, '=', 5);
	Tabling::Row* header = new Tabling::Row(columnas);
	header->AddCell("Puesto", 8);
	header->AddCell("Producto", 40);
	header->AddCell("Unidades Vendidas", 18);
	header->AddCell("Recaudacion", 14);
	tabla.AddRow(header);

	for(unsigned int i = 0; i < limite; i++) {
		Tabling::Row* row = new Tabling::Row(columnas);
		row->AddCell(to_string(i + 1), 8);
		row->AddCell(lista[i]->descripcion, 40);
		row->AddCell(to_string(lista[i]->unidades), 18);
		row->AddCell(to_string(lista[i]->totalMonto), 14);
		tabla.AddRow(row);
	}

	tabla.Print();
}

void Top10ProductosReport::CalcularTop(unsigned int anio, GenericArray<ProductoData>& lista) {
	const unsigned int cantidad = facturas.Count();
	for(unsigned int i = 0; i < cantidad; i++) {
		Factura* f = facturas.At(i);
		if(f == nullptr) { continue; }
		
		const string cae = f->getCAE();
		if(cae.empty()) {
			delete f;
			continue;
		}
		
		const int anioFac = f->getFechaEmision().getAnio();
		if((unsigned int)anioFac != anio) {
			delete f;
			continue;
		}

		unsigned int itemsCount = f->CantidadItems();
		for(unsigned int j = 0; j < itemsCount; j++) {
			Item* it = f->ObtenerItem(j);
			if(it == nullptr) { continue; }

			string codigo = it->getCodigo();
			unsigned int unidades = it->getCantidad();
			double monto = unidades * it->getPrecioUnitario();

			int idx = -1;
			for(unsigned int k = 0; k < lista.Size(); k++) {
				if(Validation::IsEqual(lista[k]->codigo, codigo)) { idx = (int)k; break; }
			}

			if(idx == -1) {
				ProductoData p;
				p.codigo = codigo;
				p.unidades = unidades;
				p.totalMonto = monto;
				p.found = true;
				Producto* prod = productos[codigo];
				p.descripcion = prod ? prod->getDescripcion() : "";
				if(prod) delete prod;
				lista.Append(p);
			} else {
				lista[(unsigned int)idx]->unidades += unidades;
				lista[(unsigned int)idx]->totalMonto += monto;
			}
		}

		delete f;
	}
}
