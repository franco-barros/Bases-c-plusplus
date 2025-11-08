#pragma once
#include <vector>
#include <string>
#include "core/Empleado.h"
#include "core/Zona.h"
#include "core/Intermediario.h"

class Persistencia { 
public:
    // Empleados
    static void guardarEmpleados(const std::vector<Empleado>& lista, const std::string& ruta);
    static void cargarEmpleados(std::vector<Empleado>& lista, const std::string& ruta);

    // Zonas
    static void guardarZonas(const std::vector<Zona>& lista, const std::string& ruta);
    static void cargarZonas(std::vector<Zona>& lista, const std::string& ruta);

    // Intermediarios ✅ (faltaba)
    static void guardarIntermediarios(const std::vector<Intermediario>& lista, const std::string& ruta);
    static void cargarIntermediarios(std::vector<Intermediario>& lista, const std::string& ruta);
};
