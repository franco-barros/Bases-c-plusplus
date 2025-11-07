#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona(const string& nombre, int edad)
    : nombre(nombre), edad(edad) {}

Persona::~Persona() {}

void Persona::mostrar() const {
    cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
}
