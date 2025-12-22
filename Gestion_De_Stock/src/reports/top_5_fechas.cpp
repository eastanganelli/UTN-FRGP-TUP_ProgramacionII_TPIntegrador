#include "top_5_fechas.h"

Top5FechasReport::Top5FechasReport() : Report("Top 5 fechas de mayores ventas") {}

void Top5FechasReport::Run() {
	rlutil::cls();
	rlutil::setBackgroundColor(rlutil::BLUE);
	rlutil::setColor(rlutil::WHITE);
	PrintDecoratedTitle(this->GetTitle(), '=');
	rlutil::resetColor();

	unsigned int anio = AskYearOrCurrent();
	GenericArray<FechaData> lista;
	CalcularTop(anio, lista);

	for(unsigned int i = 0; i < lista.Size(); i++) {
		for(unsigned int j = i + 1; j < lista.Size(); j++) {
			FechaData* a = lista[i];
			FechaData* b = lista[j];
			if(a == nullptr || b == nullptr) { continue; }
			if(b->total > a->total) {
				lista.Swap(a, b);
			}
		}
	}

	while(lista.Size() > 5) {
		lista.RemoveAt(5);
	}

	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);
	rlutil::cls();
	PrintDecoratedTitle(this->GetTitle(), '=');

	const unsigned int limite = lista.Size() < 5 ? lista.Size() : 5;
	if(limite == 0) {
		rlutil::resetColor();
		Warning w("Sin datos", "No hay facturas con CAE para el anio indicado.");
		w.Show(); w.WaitForKey();
		return;
	}

	const unsigned int columnas = 3;
	Tabling::Table tabla(limite, columnas, '=', 5);
	Tabling::Row* header = new Tabling::Row(columnas);
	header->AddCell("Puesto", 8);
	header->AddCell("Fecha", 18);
	header->AddCell("Recaudacion", 14);
	tabla.AddRow(header);

	for(unsigned int i = 0; i < limite; i++) {
		FechaData* data = lista[i];
		if(data == nullptr) { continue; }
		Fecha fecha(data->dia, data->mes, data->anio);
		Tabling::Row* row = new Tabling::Row(columnas);
		row->AddCell(to_string(i + 1), 8);
		row->AddCell(fecha.toString(), 18);
		row->AddCell(to_string(data->total), 14);
		tabla.AddRow(row);
	}

	tabla.Print();
}

void Top5FechasReport::CalcularTop(unsigned int anio, GenericArray<FechaData>& lista) {
	const unsigned int cantidad = facturas.Count();
	for(unsigned int i = 0; i < cantidad; i++) {
		Factura* f = facturas.At(i);
		if(f == nullptr) { continue; }

		const string cae = f->getCAE();
		if(cae.empty()) {
			delete f;
			continue;
		}

		Fecha& fechaEmision = f->getFechaEmision();
		if((unsigned int)fechaEmision.getAnio() != anio) {
			delete f;
			continue;
		}

		int idx = -1;
		for(unsigned int j = 0; j < lista.Size(); j++) {
			FechaData* current = lista[j];
			if(current == nullptr) { continue; }
			if(current->dia == fechaEmision.getDia() && current->mes == fechaEmision.getMes() && current->anio == fechaEmision.getAnio()) {
				idx = (int)j;
				break;
			}
		}

		if(idx == -1) {
			FechaData nuevo;
			nuevo.dia = fechaEmision.getDia();
			nuevo.mes = fechaEmision.getMes();
			nuevo.anio = fechaEmision.getAnio();
			nuevo.total = f->TotalSinIVA();
			nuevo.comprobantes = 1;
			nuevo.found = true;
			lista.Append(nuevo);
		} else {
			FechaData* existente = lista[(unsigned int)idx];
			if(existente != nullptr) {
				existente->total += f->TotalSinIVA();
				existente->comprobantes += 1;
			}
		}

		delete f;
	}
}
