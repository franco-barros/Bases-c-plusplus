#include "../include/core/Proveedor.h"
#include <iostream>
using namespace std;

Proveedor::Proveedor(const string& nombre, long dni, int codigo)
    : Persona(nombre, dni), codigo(codigo) {}

void Proveedor::leerDatos() { 
    Persona::leerDatos();
    cout << "Ingrese código del proveedor: ";
    cin >> codigo;
}

void Proveedor::imprimir() const {
    Persona::imprimir();
    cout << "\nCódigo del proveedor: " << codigo;
}

// Mostrar datos (modo polimórfico)
void Proveedor::mostrarInfo() const {
    cout << "Proveedor: " << nombre
         << " | DNI: " << dni
         << " | Código: " << codigo << endl;
}
