#include "backup_menu.h"

static void ShowBackupModal(const string& label, const string& path, bool ok, bool restoring) {
    const string action = restoring ? " restaurado desde " : " generado en ";
    const string message = label + action + path + ".";
    if (ok) {
        Informational modal("Operacion exitosa", message);
        modal.Show();
    } else {
        Error modal("Operacion fallida", message);
        modal.Show();
    }
}

BackupMenu::BackupMenu() : Menu("Copias de Seguridad/Exportacion de Datos", true) {
    AddOption("Crear backup");
    AddOption("Restaurar backup");
    AddOption("Exportacion de datos CSV");
    AddOption("Volver");
}

bool BackupMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            ClienteManager clienteManager;
            ProveedorManager proveedorManager;
            ProductoManager productoManager;
            TipoResponsableManager tipoManager;
            FacturaManager facturaManager;
            NotaDeCreditoManager notaManager;

            unsigned int opt = 0;
            do {
                rlutil::cls();
                cout << "-- Crear backup" << endl
                    << "1) Clientes" << endl
                    << "2) Proveedores" << endl
                    << "3) Productos" << endl
                    << "4) Tipos Responsables" << endl
                    << "5) Ventas" << endl
                    << "6) Todo" << endl
                    << "7) Cancelar" << endl;

                opt = InputNumber("Seleccione una opcion: ");
                if (opt < 1 || opt > 7) {
                    Warning w("Opcion invalida", "Ingrese un numero entre 1 y 7.");
                    w.Show(); w.WaitForKey();
                    continue;
                }

                if (opt == 7) break;

                switch(opt) {
                    case 1: {
                        bool ok = clienteManager.Backup("clientes.bak");
                        ShowBackupModal("[Backup] Clientes", "clientes.bak", ok, false);
                        break;
                    }
                    case 2: {
                        bool ok = proveedorManager.Backup("proveedores.bak");
                        ShowBackupModal("[Backup] Proveedores", "proveedores.bak", ok, false);
                        break;
                    }
                    case 3: {
                        bool ok = productoManager.Backup("productos.bak");
                        ShowBackupModal("[Backup] Productos", "productos.bak", ok, false);
                        break;
                    }
                    case 4: {
                        bool ok = tipoManager.Backup("tipo_responsable.bak");
                        ShowBackupModal("[Backup] Tipos Responsables", "tipo_responsable.bak", ok, false);
                        break;
                    }
                    case 5: {
                        bool facturasOk = facturaManager.Backup("facturas.bak");
                        bool notasOk = notaManager.Backup("notas_de_credito.bak");
                        ShowBackupModal("[Backup] Facturas", "facturas.bak", facturasOk, false);
                        ShowBackupModal("[Backup] Notas de Credito", "notas_de_credito.bak", notasOk, false);
                        break;
                    }
                    case 6: {
                        bool clientesOk = clienteManager.Backup("clientes.bak");
                        bool proveedoresOk = proveedorManager.Backup("proveedores.bak");
                        bool productosOk = productoManager.Backup("productos.bak");
                        bool tiposOk = tipoManager.Backup("tipo_responsable.bak");
                        bool facturasOk = facturaManager.Backup("facturas.bak");
                        bool notasOk = notaManager.Backup("notas_de_credito.bak");
                        const bool allOk = clientesOk && proveedoresOk && productosOk && tiposOk && facturasOk && notasOk;
                        if (allOk) {
                            Informational modal("Backup completo", "Se generaron todos los archivos de respaldo correctamente.");
                            modal.Show();
                        } else {
                            Error modal("Backup incompleto", "Hubo fallas al generar uno o mas respaldos.");
                            modal.Show();
                        }
                        break;
                    }
                }
                PauseConsole();
            } while (opt != 7);
            return false;
        }
        case 1: {
            ClienteManager clienteManager;
            ProveedorManager proveedorManager;
            ProductoManager productoManager;
            TipoResponsableManager tipoManager;
            FacturaManager facturaManager;
            NotaDeCreditoManager notaManager;

            unsigned int opt = 0;
            do {
                rlutil::cls();
                cout << "-- Restaurar backup --" << endl
                    << "1) Clientes" << endl
                    << "2) Proveedores" << endl
                    << "3) Productos" << endl
                    << "4) Tipos Responsables" << endl
                    << "5) Ventas" << endl
                    << "6) Todo" << endl
                    << "7) Cancelar" << endl;

                opt = InputNumber("Seleccione una opcion: ");
                if (opt < 1 || opt > 7) {
                    Warning w("Opcion invalida", "Ingrese un numero entre 1 y 7.");
                    w.Show(); w.WaitForKey();
                    continue;
                }

                if (opt == 7) break;

                switch(opt) {
                    case 1: {
                        bool ok = clienteManager.Restore("clientes.bak");
                        ShowBackupModal("[Restore] Clientes", "clientes.bak", ok, true);
                        break;
                    }
                    case 2: {
                        bool ok = proveedorManager.Restore("proveedores.bak");
                        ShowBackupModal("[Restore] Proveedores", "proveedores.bak", ok, true);
                        break;
                    }
                    case 3: {
                        bool ok = productoManager.Restore("productos.bak");
                        ShowBackupModal("[Restore] Productos", "productos.bak", ok, true);
                        break;
                    }
                    case 4: {
                        bool ok = tipoManager.Restore("tipo_responsable.bak");
                        ShowBackupModal("[Restore] Tipos Responsables", "tipo_responsable.bak", ok, true);
                        break;
                    }
                    case 5: {
                        bool facturasOk = facturaManager.Restore("facturas.bak");
                        bool notasOk = notaManager.Restore("notas_de_credito.bak");
                        ShowBackupModal("[Restore] Facturas", "facturas.bak", facturasOk, true);
                        ShowBackupModal("[Restore] Notas de Credito", "notas_de_credito.bak", notasOk, true);
                        break;
                    }
                    case 6: {
                        bool clientesOk = clienteManager.Restore("clientes.bak");
                        bool proveedoresOk = proveedorManager.Restore("proveedores.bak");
                        bool productosOk = productoManager.Restore("productos.bak");
                        bool tiposOk = tipoManager.Restore("tipo_responsable.bak");
                        bool facturasOk = facturaManager.Restore("facturas.bak");
                        bool notasOk = notaManager.Restore("notas_de_credito.bak");
                        const bool allOk = clientesOk && proveedoresOk && productosOk && tiposOk && facturasOk && notasOk;
                        if (allOk) {
                            Informational modal("Restauracion completa", "Se restauraron todos los archivos desde los respaldos.");
                            modal.Show();
                        } else {
                            Error modal("Restauracion incompleta", "Hubo fallas al restaurar uno o mas respaldos.");
                            modal.Show();
                        }
                        break;
                    }
                }
                PauseConsole();
            } while (opt != 7);
            return false;
        }
        case 2: {
            ClienteManager clienteManager;
            ProveedorManager proveedorManager;
            ProductoManager productoManager;
            FacturaManager facturaManager;
            NotaDeCreditoManager notaManager;

            unsigned int opt = 0;
            do {
                rlutil::cls();
                cout << "-- Exportacion de datos (CSV) --" << endl
                    << "1) Clientes" << endl
                    << "2) Proveedores" << endl
                    << "3) Productos" << endl
                    << "4) Ventas" << endl
                    << "5) Todo" << endl
                    << "6) Cancelar" << endl;

                opt = InputNumber("Seleccione una opcion: ");
                if (opt < 1 || opt > 6) {
                    Warning w("Opcion invalida", "Ingrese un numero entre 1 y 6.");
                    w.Show(); w.WaitForKey();
                    continue;
                }

                if (opt == 6) break;

                switch(opt) {
                    case 1: {
                        bool ok = clienteManager.ExportCSV("clientes.csv");
                        if (!ok) { Error e("Exportar Clientes", "No se pudo exportar clientes."); e.Show(); }
                        break;
                    }
                    case 2: {
                        bool ok = proveedorManager.ExportCSV("proveedores.csv");
                        if (!ok) { Error e("Exportar Proveedores", "No se pudo exportar proveedores."); e.Show(); }
                        break;
                    }
                    case 3: {
                        bool ok = productoManager.ExportCSV("productos.csv");
                        if (!ok) { Error e("Exportar Productos", "No se pudo exportar productos."); e.Show(); }
                        break;
                    }
                    case 4: {
                        bool okFact = facturaManager.ExportCSV("ventas.csv", "ventas_items.csv", false, true);
                        bool okNota = notaManager.ExportCSV("ventas.csv", "ventas_items.csv", true, false);
                        if (!okFact || !okNota) {
                            Error e("Exportar Ventas", "No se pudo exportar todas las ventas e items.");
                            e.Show();
                        } else {
                            Informational i("Exportar Ventas", "Se exportaron facturas y notas a CSV.");
                            i.Show();
                        }
                        break;
                    }
                    case 5: {
                        bool cOk = clienteManager.ExportCSV("clientes.csv");
                        bool pOk = proveedorManager.ExportCSV("proveedores.csv");
                        bool prOk = productoManager.ExportCSV("productos.csv");
                        bool fOk = facturaManager.ExportCSV("ventas.csv", "ventas_items.csv", false, true);
                        bool nOk = notaManager.ExportCSV("ventas.csv", "ventas_items.csv", true, false);
                        const bool allOk = cOk && pOk && prOk && fOk && nOk;
                        if (allOk) {
                            Informational modal("Exportacion completa", "Se exportaron todos los datos a CSV.");
                            modal.Show();
                        } else {
                            Error modal("Exportacion incompleta", "Hubo fallas al exportar uno o mas conjuntos de datos.");
                            modal.Show();
                        }
                        break;
                    }
                }
                PauseConsole();
            } while (opt != 6);
            return false;
        }
        case 3: {
            return true; // Volver
        }
        default:
            return false;
    }
}
