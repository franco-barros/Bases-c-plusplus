#include "../include/core/Empleado.h"
#include <iostream>
using namespace std;

Empleado::Empleado(const string& nombre, long dni, const string& puesto, double salario)
    : Persona(nombre, dni), puesto(puesto), salario(salario), zonaAsignada(-1) {} // 🔹 Inicializa sin zona asignada

void Empleado::leerDatos() {
    Persona::leerDatos();
    cout << "Ingrese puesto: ";
    cin.ignore();
    getline(cin, puesto);
    cout << "Ingrese salario: ";
    cin >> salario;
} 

void Empleado::imprimir() const {
    Persona::imprimir();
    cout << "\nPuesto: " << puesto;
    cout << "\nSalario: $" << salario;
    if (zonaAsignada != -1)
        cout << "\nZona asignada: " << zonaAsignada;
    else
        cout << "\nZona asignada: (sin asignar)";
}

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

void Empleado::asignarZona(int zona) {
    zonaAsignada = zona;
}

int Empleado::getZonaAsignada() const {
    return zonaAsignada;
}
