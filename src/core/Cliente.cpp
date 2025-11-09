#include "../include/core/Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(const string& nombre, long dni, int codigo)
    : Persona(nombre, dni), codigo(codigo) {}

void Cliente::leerDatos() {
    Persona::leerDatos();
    cout << "Ingrese código de cliente: "; 
    cin >> codigo;
}

void Cliente::imprimir() const {
    Persona::imprimir();
    cout << "\nCódigo de cliente: " << codigo;
}

void Cliente::mostrarInfo() const {
    cout << "Cliente → " << nombre
         << " | DNI: " << dni
         << " | Código: " << codigo << endl;
}
