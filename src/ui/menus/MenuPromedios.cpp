#include <iostream>
#include "../include/ui/menus/MenuPromedios.h"
#include "../include/utils/Promedio.h"
#include "../include/utils/Utils.h"
using namespace std;

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
