#include <iostream>
#include "../include/ui/Menus.h"
#include "../include/ui/menus/MenuClientes.h"
#include "../include/ui/menus/MenuProveedores.h"
#include "../include/ui/menus/MenuIntermediarios.h"
#include "../include/ui/menus/MenuZonas.h"
#include "../include/ui/menus/MenuPromedios.h"
#include "../include/ui/menus/MenuReportes.h"
#include "../include/utils/Utils.h"
#include "../include/App.h"

using namespace std;

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
        cout << Color::BLANCO << "6. Reportes\n" << Color::RESET;
        cout << Color::ROJO << "0. Salir\n" << Color::RESET;
        cout << Color::BLANCO << "\nSeleccione una opción: " << Color::RESET;
        cin >> opcion;

        switch (opcion) {
            case 1: menuClientes(); break;
            case 2: menuProveedores(); break;
            case 3: menuIntermediarios(); break;
            case 4: menuZonas(); break;
            case 5: menuPromedios(); break;
            case 6: menuReportes(); break;
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
