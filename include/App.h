#pragma once
#include <vector>
#include "core/Empleado.h"
#include "core/Intermediario.h"
#include "core/Zona.h"
#include "core/Cliente.h"
#include "core/Proveedor.h"
#include "ui/Menus.h"

// Variables globales de App principal
namespace App {
    extern std::vector<Empleado> empleados;
    extern std::vector<Intermediario> intermediarios;
    extern std::vector<Zona> zonas;
    extern std::vector<Cliente> clientes;
    extern std::vector<Proveedor> proveedores;

    const std::string RUTA_EMPLEADOS = "data/empleados.dat";
    const std::string RUTA_INTERMEDIARIOS = "data/intermediarios.dat";
    const std::string RUTA_ZONAS = "data/zonas.dat";
    const std::string RUTA_CLIENTES = "data/clientes.dat";
    const std::string RUTA_PROVEEDORES = "data/proveedores.dat";

    void inicializarDatos();
    void guardarDatos();
    void ejecutarAplicacion();
}
