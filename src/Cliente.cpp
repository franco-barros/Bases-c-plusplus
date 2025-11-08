#include "../include/Cliente.h"
#include <iostream>
using namespace std;

// Constructor con parámetros
Cliente::Cliente(const string& nombre, long dni, int codigo)
    : Persona(nombre, dni), codigo(codigo) {}

// Método para ingresar datos por teclado
void Cliente::leerDatos() {
    Persona::leerDatos();
    cout << "Ingrese código de cliente: ";
    cin >> codigo;
}

// Método para imprimir datos (modo clásico)
void Cliente::imprimir() const {
    Persona::imprimir();
    cout << "\nCódigo de cliente: " << codigo;
}

// Método para mostrar datos (modo polimórfico moderno)
void Cliente::mostrarInfo() const {
    cout << "Cliente → " << nombre
         << " | DNI: " << dni
         << " | Código: " << codigo << endl;
}
