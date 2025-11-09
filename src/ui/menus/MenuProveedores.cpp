#include <iostream>
#include "../include/ui/menus/MenuProveedores.h"
#include "../include/core/Proveedor.h"
#include "../include/utils/Utils.h"
using namespace std;

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
