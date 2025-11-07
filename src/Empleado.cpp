#include "Empleado.h"
#include <iostream>
using namespace std;

Empleado::Empleado(const string& nombre, int edad, const string& puesto, double salario)
    : Persona(nombre, edad), puesto(puesto), salario(salario) {}

void Empleado::mostrar() const {
    cout << "Empleado: " << nombre
         << " | Edad: " << edad
         << " | Puesto: " << puesto
         << " | Salario: $" << salario << endl;
}
