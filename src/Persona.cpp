#include "../include/Persona.h"
#include <iostream>
using namespace std;

// Constructor con parámetros
Persona::Persona(const string& nombre, long dni)
    : nombre(nombre), dni(dni) {}

// Métodos clásicos (compatibles con tu código viejo)
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

// Nuevo método (para el main con vector<Persona*>)
void Persona::mostrarInfo() const {
    cout << "Persona: " << nombre << " | DNI: " << dni << endl;
}
