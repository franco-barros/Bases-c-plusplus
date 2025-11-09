#include <iostream>
#include "../include/ui/menus/MenuReportes.h"
#include "../include/utils/Utils.h"
#include "../include/App.h"
using namespace std;

void menuReportes() {
    int opcion;
    do {
        limpiarPantalla();
        colorearTexto("===== 📊 MENÚ DE REPORTES =====\n", Color::BLANCO);
        cout << "1. Listar todos los clientes\n";
        cout << "2. Listar todos los proveedores\n";
        cout << "3. Listar intermediarios con zona asignada\n";
        cout << "4. Listar zonas y cantidad de asignaciones\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (App::clientes.empty())
                    colorearTexto("⚠ No hay clientes registrados.\n", Color::ROJO);
                else {
                    colorearTexto("\n📋 LISTA DE CLIENTES:\n", Color::VERDE);
                    for (const auto& c : App::clientes) c.imprimir();
                }
                break;
            case 2:
                if (App::proveedores.empty())
                    colorearTexto("⚠ No hay proveedores registrados.\n", Color::ROJO);
                else {
                    colorearTexto("\n🏭 LISTA DE PROVEEDORES:\n", Color::AMARILLO);
                    for (const auto& p : App::proveedores) p.imprimir();
                }
                break;
            case 3:
                if (App::intermediarios.empty())
                    colorearTexto("⚠ No hay intermediarios registrados.\n", Color::ROJO);
                else {
                    colorearTexto("\n🤝 INTERMEDIARIOS CON ZONA:\n", Color::MAGENTA);
                    for (const auto& i : App::intermediarios)
                        if (i.getZonaAsignada() != 0)
                            i.imprimir();
                }
                break;
            case 4:
                if (App::zonas.empty())
                    colorearTexto("⚠ No hay zonas registradas.\n", Color::ROJO);
                else {
                    colorearTexto("\n🌍 ZONAS Y ASIGNACIONES:\n", Color::AZUL);
                    for (const auto& z : App::zonas) {
                        int count = 0;
                        for (const auto& e : App::empleados)
                            if (e.getZonaAsignada() == z.getNroZona()) count++;
                        for (const auto& i : App::intermediarios)
                            if (i.getZonaAsignada() == z.getNroZona()) count++;
                        cout << "Zona " << z.getNroZona()
                             << " → Asignaciones: " << count << endl;
                    }
                }
                break;
            case 0: break;
            default: colorearTexto("⚠ Opción inválida.\n", Color::ROJO);
        }

        if (opcion != 0) pausar();
    } while (opcion != 0);
}
