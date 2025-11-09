#include <iostream>
#include "../include/ui/menus/MenuClientes.h"
#include "../include/core/Cliente.h"
#include "../include/utils/Utils.h"
using namespace std;

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
