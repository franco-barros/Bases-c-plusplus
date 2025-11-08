#include <iostream>
#include "../include/ui/Menus.h"
#include "../include/core/Cliente.h"
#include "../include/core/Proveedor.h"
#include "../include/utils/Promedio.h"
#include "../include/App.h"
#include "../include/utils/Utils.h"
#include "../include/utils/Persistencia.h"

using namespace std;

// =========================================================
// 🧭 MENÚ PRINCIPAL
// =========================================================
void menuPrincipal() {
    int opcion;
    do {
        limpiarPantalla();
        colorearTexto("\n========= SISTEMA DE GESTIÓN =========\n", Color::CYAN);
        cout << Color::VERDE << "1. Clientes\n" << Color::RESET;
        cout << Color::AMARILLO << "2. Proveedores\n" << Color::RESET;
        cout << Color::MAGENTA << "3. Intermediarios\n" << Color::RESET;
        cout << Color::AZUL << "4. Zonas\n" << Color::RESET;
        cout << Color::CYAN << "5. Promedios\n" << Color::RESET;
        cout << Color::ROJO << "0. Salir\n" << Color::RESET;
        cout << Color::BLANCO << "\nSeleccione una opción: " << Color::RESET;
        cin >> opcion;

        switch (opcion) {
            case 1: menuClientes(); break;
            case 2: menuProveedores(); break;
            case 3: menuIntermediarios(); break;
            case 4: menuZonas(); break;
            case 5: menuPromedios(); break;
            case 0:
                App::guardarDatos();
                colorearTexto("👋 Saliendo del sistema...\n", Color::AMARILLO);
                break;
            default:
                colorearTexto("⚠ Opción inválida.\n", Color::ROJO);
                pausar();
        }
    } while (opcion != 0);
}

// =========================================================
// 🧩 MENÚ CLIENTES
// =========================================================
void menuClientes() {
    Cliente c;
    int opcion;
    do {
        limpiarPantalla();
        colorearTexto("--- MENÚ CLIENTES ---\n", Color::VERDE);
        cout << "1. Ingresar nuevo cliente\n";
        cout << "2. Mostrar cliente\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: c.leerDatos(); break;
            case 2: c.imprimir(); break;
            case 0: break;
            default: colorearTexto("⚠ Opción inválida.\n", Color::ROJO);
        }

        if (opcion != 0) pausar();
    } while (opcion != 0);
}

// =========================================================
// 🧩 MENÚ PROVEEDORES
// =========================================================
void menuProveedores() {
    Proveedor p;
    int opcion;
    do {
        limpiarPantalla();
        colorearTexto("--- MENÚ PROVEEDORES ---\n", Color::AMARILLO);
        cout << "1. Ingresar nuevo proveedor\n";
        cout << "2. Mostrar proveedor\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: p.leerDatos(); break;
            case 2: p.imprimir(); break;
            case 0: break;
            default: colorearTexto("⚠ Opción inválida.\n", Color::ROJO);
        }

        if (opcion != 0) pausar();
    } while (opcion != 0);
}

// =========================================================
// 🧩 MENÚ INTERMEDIARIOS
// =========================================================
void menuIntermediarios() {
    Intermediario i;
    int opcion;
    do {
        limpiarPantalla();
        colorearTexto("--- MENÚ INTERMEDIARIOS ---\n", Color::MAGENTA);
        cout << "1. Ingresar nuevo intermediario\n";
        cout << "2. Mostrar intermediarios\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                i.leerDatos();
                App::intermediarios.push_back(i);
                Persistencia::guardarIntermediarios(App::intermediarios, App::RUTA_INTERMEDIARIOS);
                break;
            case 2:
                if (App::intermediarios.empty())
                    colorearTexto("⚠ No hay intermediarios registrados.\n", Color::ROJO);
                else
                    for (const auto& inter : App::intermediarios) inter.imprimir();
                break;
            case 0: break;
            default: colorearTexto("⚠ Opción inválida.\n", Color::ROJO);
        }

        if (opcion != 0) pausar();
    } while (opcion != 0);
}

// =========================================================
// 🧩 MENÚ ZONAS
// =========================================================
void menuZonas() {
    int opcion;
    do {
        limpiarPantalla();
        colorearTexto("--- MENÚ ZONAS ---\n", Color::AZUL);
        cout << "1. Ingresar nueva zona\n";
        cout << "2. Mostrar zonas\n";
        cout << "3. Asignar zona a empleado\n";
        cout << "4. Asignar zona a intermediario\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Zona z;
                z.cargar();
                App::zonas.push_back(z);
                Persistencia::guardarZonas(App::zonas, App::RUTA_ZONAS);
                break;
            }
            case 2: {
                if (App::zonas.empty())
                    colorearTexto("⚠ No hay zonas registradas.\n", Color::ROJO);
                else
                    for (const auto& z : App::zonas) z.visualizar();
                break;
            }
            case 3: {
                if (App::empleados.empty() || App::zonas.empty()) {
                    colorearTexto("⚠ No hay empleados o zonas registradas.\n", Color::ROJO);
                    break;
                }
                int iEmpleado, iZona;
                cout << "Seleccione índice de empleado (0-" << App::empleados.size() - 1 << "): ";
                cin >> iEmpleado;
                cout << "Seleccione índice de zona (0-" << App::zonas.size() - 1 << "): ";
                cin >> iZona;
                if (iEmpleado >= 0 && iEmpleado < (int)App::empleados.size() &&
                    iZona >= 0 && iZona < (int)App::zonas.size()) {
                    App::empleados[iEmpleado].asignarZona(App::zonas[iZona].getNroZona());
                    Persistencia::guardarEmpleados(App::empleados, App::RUTA_EMPLEADOS);
                    colorearTexto("✅ Zona asignada al empleado.\n", Color::VERDE);
                } else {
                    colorearTexto("⚠ Índice inválido.\n", Color::ROJO);
                }
                break;
            }
            case 4: {
                if (App::intermediarios.empty() || App::zonas.empty()) {
                    colorearTexto("⚠ No hay intermediarios o zonas registradas.\n", Color::ROJO);
                    break;
                }
                int iInter, iZona;
                cout << "Seleccione índice de intermediario (0-" << App::intermediarios.size() - 1 << "): ";
                cin >> iInter;
                cout << "Seleccione índice de zona (0-" << App::zonas.size() - 1 << "): ";
                cin >> iZona;
                if (iInter >= 0 && iInter < (int)App::intermediarios.size() &&
                    iZona >= 0 && iZona < (int)App::zonas.size()) {
                    App::intermediarios[iInter].asignarZona(App::zonas[iZona].getNroZona());
                    Persistencia::guardarIntermediarios(App::intermediarios, App::RUTA_INTERMEDIARIOS);
                    colorearTexto("✅ Zona asignada al intermediario.\n", Color::VERDE);
                } else {
                    colorearTexto("⚠ Índice inválido.\n", Color::ROJO);
                }
                break;
            }
            case 0: break;
            default: colorearTexto("⚠ Opción inválida.\n", Color::ROJO);
        }

        if (opcion != 0) pausar();
    } while (opcion != 0);
}

// =========================================================
// 🧩 MENÚ PROMEDIOS
// =========================================================
void menuPromedios() {
    Promedio p;
    int opcion;
    do {
        limpiarPantalla();
        colorearTexto("--- MENÚ PROMEDIOS ---\n", Color::CYAN);
        cout << "1. Calcular promedio de 2 valores\n";
        cout << "2. Calcular promedio de 3 valores\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            float a, b;
            cout << "Ingrese dos valores: ";
            cin >> a >> b;
            cout << Color::VERDE << "Promedio: " << p.calcular(a, b) << Color::RESET;
        } else if (opcion == 2) {
            float a, b, c;
            cout << "Ingrese tres valores: ";
            cin >> a >> b >> c;
            cout << Color::VERDE << "Promedio: " << p.calcular(a, b, c) << Color::RESET;
        } else if (opcion != 0) {
            colorearTexto("⚠ Opción inválida.\n", Color::ROJO);
        }

        if (opcion != 0) pausar();
    } while (opcion != 0);
}
