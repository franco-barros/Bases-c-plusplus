#pragma once
#include <vector>
#include "../core/Empleado.h"
#include "../core/Intermediario.h"
#include "../core/Zona.h"

namespace Reportes {
    void mostrarResumenGeneral(
        const std::vector<Empleado>& empleados,
        const std::vector<Intermediario>& intermediarios,
        const std::vector<Zona>& zonas
    );

    void mostrarSueldos(
        const std::vector<Empleado>& empleados
    );

    void mostrarZonasActivas(
        const std::vector<Empleado>& empleados,
        const std::vector<Intermediario>& intermediarios,
        const std::vector<Zona>& zonas
    );
}
