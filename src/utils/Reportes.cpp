#include "../../include/utils/Reportes.h"
#include <iostream>
#include <iomanip>
#include "../../include/utils/Utils.h" 
using namespace std;

namespace Reportes {

void mostrarResumenGeneral(
    const vector<Empleado>& empleados,
    const vector<Intermediario>& intermediarios,
    const vector<Zona>& zonas
) {
    colorearTexto("\n===== 📊 RESUMEN GENERAL =====\n", Color::CYAN);
    cout << "Total de empleados: " << empleados.size() << endl;
    cout << "Total de intermediarios: " << intermediarios.size() << endl;
    cout << "Total de zonas: " << zonas.size() << endl;
    cout << "------------------------------\n";
}

void mostrarSueldos(const vector<Empleado>& empleados) {
    if (empleados.empty()) {
        colorearTexto("\n⚠ No hay empleados registrados.\n", Color::ROJO);
        return;
    }

    double total = 0;
    for (const auto& e : empleados)
        total += e.getSalario(); 

    double promedio = total / empleados.size();

    colorearTexto("\n===== 💰 SUELDOS =====\n", Color::VERDE);
    cout << fixed << setprecision(2);
    cout << "Sueldo promedio: $" << promedio << endl;
    cout << "----------------------\n";
}

void mostrarZonasActivas(
    const vector<Empleado>& empleados,
    const vector<Intermediario>& intermediarios,
    const vector<Zona>& zonas
) {
    if (zonas.empty()) {
        colorearTexto("\n⚠ No hay zonas registradas.\n", Color::ROJO);
        return;
    }

    colorearTexto("\n===== 🗺️ ZONAS ACTIVAS =====\n", Color::AZUL);
    for (const auto& z : zonas) {
        int empleadosZona = 0;
        int intermediariosZona = 0;

        for (const auto& e : empleados)
            if (e.getZonaAsignada() == z.getNroZona())
                empleadosZona++;

        for (const auto& i : intermediarios)
            if (i.getZonaAsignada() == z.getNroZona())
                intermediariosZona++;

        cout << "Zona " << z.getNroZona()
             << " → Empleados: " << empleadosZona
             << " | Intermediarios: " << intermediariosZona << endl;
    }
    cout << "------------------------------\n";
}

} 
