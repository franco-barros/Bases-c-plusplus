#include <iostream>
#include "../include/App.h"
#include "../include/utils/Persistencia.h"
#include "../include/utils/Utils.h"

using namespace std;

// =========================================================
// 🔹 Definición de vectores globales
// =========================================================
namespace App {
    vector<Empleado> empleados;
    vector<Intermediario> intermediarios;
    vector<Zona> zonas;
}

// =========================================================
// 🧭 Inicialización de datos
// =========================================================
void App::inicializarDatos() {
    colorearTexto("📂 Cargando datos previos...\n", Color::AMARILLO);
    Persistencia::cargarEmpleados(empleados, RUTA_EMPLEADOS);
    Persistencia::cargarZonas(zonas, RUTA_ZONAS);
    Persistencia::cargarIntermediarios(intermediarios, RUTA_INTERMEDIARIOS);
    colorearTexto("✅ Datos cargados correctamente.\n", Color::VERDE);
}

// =========================================================
// 💾 Guardado de datos
// =========================================================
void App::guardarDatos() {
    colorearTexto("\n💾 Guardando datos...\n", Color::AMARILLO);
    Persistencia::guardarEmpleados(empleados, RUTA_EMPLEADOS);
    Persistencia::guardarIntermediarios(intermediarios, RUTA_INTERMEDIARIOS);
    Persistencia::guardarZonas(zonas, RUTA_ZONAS);
    colorearTexto("✅ Datos guardados.\n", Color::VERDE);
}

// =========================================================
// 🧭 Ejecutar aplicación
// =========================================================
void App::ejecutarAplicacion() {
    inicializarDatos();
    menuPrincipal();  // menuPrincipal ahora usa los vectores de App:: (globales)
    guardarDatos();
}
