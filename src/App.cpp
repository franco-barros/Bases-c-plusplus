#include "../include/App.h"
#include "../include/utils/Persistencia.h"
#include "../include/utils/Utils.h"
#include <iostream>
using namespace std;

namespace App {
    vector<Empleado> empleados;
    vector<Intermediario> intermediarios;
    vector<Zona> zonas;
    vector<Cliente> clientes;
    vector<Proveedor> proveedores;
}


void App::inicializarDatos() {
    colorearTexto("📂 Cargando datos previos...\n", Color::AMARILLO);
    Persistencia::cargarEmpleados(empleados, RUTA_EMPLEADOS);
    Persistencia::cargarIntermediarios(intermediarios, RUTA_INTERMEDIARIOS);
    Persistencia::cargarZonas(zonas, RUTA_ZONAS);
    Persistencia::cargarClientes(clientes, RUTA_CLIENTES);
    Persistencia::cargarProveedores(proveedores, RUTA_PROVEEDORES);
    colorearTexto("✅ Datos cargados correctamente.\n", Color::VERDE);
}


void App::guardarDatos() {
    colorearTexto("\n💾 Guardando datos...\n", Color::AMARILLO);
    Persistencia::guardarEmpleados(empleados, RUTA_EMPLEADOS);
    Persistencia::guardarIntermediarios(intermediarios, RUTA_INTERMEDIARIOS);
    Persistencia::guardarZonas(zonas, RUTA_ZONAS);
    Persistencia::guardarClientes(clientes, RUTA_CLIENTES);
    Persistencia::guardarProveedores(proveedores, RUTA_PROVEEDORES);
    colorearTexto("✅ Datos guardados.\n", Color::VERDE);
}


void App::ejecutarAplicacion() {
    inicializarDatos();
    menuPrincipal();
    guardarDatos();
}
