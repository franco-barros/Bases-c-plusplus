#include "../include/core/Empleado.h"
#include <iostream>
using namespace std;

// Constructor con parámetros
Empleado::Empleado(const string& nombre, long dni, const string& puesto, double salario)
    : Persona(nombre, dni), puesto(puesto), salario(salario), zonaAsignada(-1) {} // 🔹 Inicializa sin zona asignada

// Métodos clásicos
void Empleado::leerDatos() {
    Persona::leerDatos();
    cout << "Ingrese puesto: ";
    cin.ignore();
    getline(cin, puesto);
    cout << "Ingrese salario: ";
    cin >> salario;
}

// Imprimir formato clásico
void Empleado::imprimir() const {
    Persona::imprimir();
    cout << "\nPuesto: " << puesto;
    cout << "\nSalario: $" << salario;
    if (zonaAsignada != -1)
        cout << "\nZona asignada: " << zonaAsignada;
    else
        cout << "\nZona asignada: (sin asignar)";
}

// Nuevo método para el menú principal (vector<Persona*>)
void Empleado::mostrarInfo() const {
    cout << "Empleado → " << nombre
         << " | DNI: " << dni
         << " | Puesto: " << puesto
         << " | Salario: $" << salario;

    if (zonaAsignada != -1)
        cout << " | Zona: " << zonaAsignada;
    else
        cout << " | Zona: (sin asignar)";
    cout << endl;
}

// 🔹 Métodos de zona
void Empleado::asignarZona(int zona) {
    zonaAsignada = zona;
}

int Empleado::getZonaAsignada() const {
    return zonaAsignada;
}
