#pragma once
#include <vector>
#include <string>
#include "core/Empleado.h"
#include "core/Zona.h"
#include "core/Intermediario.h"
#include "core/Cliente.h"
#include "core/Proveedor.h"

class Persistencia {
public:
    // Empleados
    static void guardarEmpleados(const std::vector<Empleado>& lista, const std::string& ruta);
    static void cargarEmpleados(std::vector<Empleado>& lista, const std::string& ruta);

    // Zonas
    static void guardarZonas(const std::vector<Zona>& lista, const std::string& ruta);
    static void cargarZonas(std::vector<Zona>& lista, const std::string& ruta);

    // Intermediarios
    static void guardarIntermediarios(const std::vector<Intermediario>& lista, const std::string& ruta);
    static void cargarIntermediarios(std::vector<Intermediario>& lista, const std::string& ruta);

    // Clientes
    static void guardarClientes(const std::vector<Cliente>& lista, const std::string& ruta);
    static void cargarClientes(std::vector<Cliente>& lista, const std::string& ruta);

    // Proveedores
    static void guardarProveedores(const std::vector<Proveedor>& lista, const std::string& ruta);
    static void cargarProveedores(std::vector<Proveedor>& lista, const std::string& ruta);
};
