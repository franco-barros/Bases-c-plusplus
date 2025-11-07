#include <iostream>
#include <vector>
#include "Persona.h"
#include "Empleado.h"
using namespace std;

int main() {
    // Crear una persona y un empleado
    Persona p1("Ana", 30);
    Empleado e1("Franco", 25, "Desarrollador", 350000);

    // Vector de punteros a Persona (permite polimorfismo)
    vector<Persona*> personas;
    personas.push_back(&p1);
    personas.push_back(&e1);

    cout << "--- Lista de personas ---" << endl;
    for (const auto& persona : personas) {
        persona->mostrar(); // Ejecuta el método correspondiente (dinámicamente)
    }

    return 0;
}
