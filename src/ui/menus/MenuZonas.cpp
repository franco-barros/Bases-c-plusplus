#include <iostream>
#include "../include/ui/menus/MenuZonas.h"
#include "../include/core/Zona.h"
#include "../include/core/Empleado.h"
#include "../include/core/Intermediario.h"
#include "../include/utils/Utils.h"
#include "../include/utils/Persistencia.h"
#include "../include/App.h"
using namespace std;

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
