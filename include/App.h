#pragma once
#include <vector>
#include "core/Empleado.h"
#include "core/Intermediario.h"
#include "core/Zona.h"
#include "ui/Menus.h"

// =========================================================
// 📦 App principal: inicialización, guardado y ejecución
// =========================================================
namespace App {
    // Vectores globales (solo aquí)
    extern std::vector<Empleado> empleados;
    extern std::vector<Intermediario> intermediarios;
    extern std::vector<Zona> zonas;

    // Rutas de archivos
    const std::string RUTA_EMPLEADOS = "data/empleados.dat";
    const std::string RUTA_INTERMEDIARIOS = "data/intermediarios.dat";
    const std::string RUTA_ZONAS = "data/zonas.dat";

    // Inicializa los datos desde archivos
    void inicializarDatos();

    // Guarda los datos en los archivos
    void guardarDatos();

    // Ejecuta la aplicación (menu principal)
    void ejecutarAplicacion();
}
