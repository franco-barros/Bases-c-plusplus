#include <iostream>
#include "../include/ui/menus/MenuIntermediarios.h"
#include "../include/core/Intermediario.h"
#include "../include/utils/Utils.h"
#include "../include/utils/Persistencia.h"
#include "../include/App.h"
using namespace std;

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
