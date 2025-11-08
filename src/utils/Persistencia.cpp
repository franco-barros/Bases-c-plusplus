#include "../include/utils/Persistencia.h"
#include <fstream>
#include <iostream> 
using namespace std;

// =========================================================
// 🧍‍♂️ EMPLEADOS
// =========================================================
void Persistencia::guardarEmpleados(const vector<Empleado>& lista, const string& ruta) {
    ofstream archivo(ruta, ios::binary | ios::trunc);
    if (!archivo) {
        cerr << "Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& e : lista) archivo.write(reinterpret_cast<const char*>(&e), sizeof(Empleado));
    archivo.close();
}

void Persistencia::cargarEmpleados(vector<Empleado>& lista, const string& ruta) {
    ifstream archivo(ruta, ios::binary);
    if (!archivo) return;
    Empleado temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Empleado))) lista.push_back(temp);
    archivo.close();
}

// =========================================================
// 📍 ZONAS
// =========================================================
void Persistencia::guardarZonas(const vector<Zona>& lista, const string& ruta) {
    ofstream archivo(ruta, ios::binary | ios::trunc);
    if (!archivo) {
        cerr << "Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& z : lista) archivo.write(reinterpret_cast<const char*>(&z), sizeof(Zona));
    archivo.close();
}

void Persistencia::cargarZonas(vector<Zona>& lista, const string& ruta) {
    ifstream archivo(ruta, ios::binary);
    if (!archivo) return;
    Zona temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Zona))) lista.push_back(temp);
    archivo.close();
}

// =========================================================
// 🤝 INTERMEDIARIOS (nuevo)
// =========================================================
void Persistencia::guardarIntermediarios(const vector<Intermediario>& lista, const string& ruta) {
    ofstream archivo(ruta, ios::binary | ios::trunc);
    if (!archivo) {
        cerr << "Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& i : lista) archivo.write(reinterpret_cast<const char*>(&i), sizeof(Intermediario));
    archivo.close();
}

void Persistencia::cargarIntermediarios(vector<Intermediario>& lista, const string& ruta) {
    ifstream archivo(ruta, ios::binary);
    if (!archivo) return;
    Intermediario temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Intermediario))) lista.push_back(temp);
    archivo.close();
}
