#include "../include/Empleado.h"
#include <iostream>
using namespace std;

// Constructor con parámetros
Empleado::Empleado(const string& nombre, long dni, const string& puesto, double salario)
    : Persona(nombre, dni), puesto(puesto), salario(salario) {}

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
}

// Nuevo método para el menú principal (vector<Persona*>)
void Empleado::mostrarInfo() const {
    cout << "Empleado → " << nombre
         << " | DNI: " << dni
         << " | Puesto: " << puesto
         << " | Salario: $" << salario << endl;
}
