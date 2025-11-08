#include "../include/Proveedor.h"
#include <iostream>
using namespace std;

// Constructor con parámetros
Proveedor::Proveedor(const string& nombre, long dni, int codigo)
    : Persona(nombre, dni), codigo(codigo) {}

// Leer datos desde consola
void Proveedor::leerDatos() {
    Persona::leerDatos();
    cout << "Ingrese código del proveedor: ";
    cin >> codigo;
}

// Imprimir datos clásicos
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
