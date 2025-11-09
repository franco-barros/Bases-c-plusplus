#include "../include/core/Persona.h"
#include <iostream>
using namespace std;

Persona::Persona(const string& nombre, long dni)
    : nombre(nombre), dni(dni) {}

void Persona::leerDatos() {
    cout << "\nIngrese nombre: ";
    cin >> ws; // limpia espacios y saltos de línea previos
    getline(cin, nombre);

    cout << "Ingrese DNI: ";
    cin >> dni;
}

void Persona::imprimir() const {
    cout << "\nNombre: " << nombre;
    cout << "\nDNI: " << dni;
}

void Persona::mostrarInfo() const {
    cout << "Persona: " << nombre << " | DNI: " << dni << endl;
}
