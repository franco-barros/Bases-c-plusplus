#include "../include/core/Zona.h"
#include <iostream>
#include <limits> // para validar entradas
using namespace std;

// Constructor por defecto
Zona::Zona() : nroZona(0), nroSucursal(0) {}

// Cargar datos con validación
void Zona::cargar() {
    cout << "\nIngrese número de zona: ";
    while (!(cin >> nroZona)) {
        cout << "❌ Entrada inválida. Ingrese un número válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese número de sucursal: ";
    while (!(cin >> nroSucursal)) {
        cout << "❌ Entrada inválida. Ingrese un número válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
}

// Visualizar datos
void Zona::visualizar() const {
    cout << "Zona N°: " << nroZona
         << " | Sucursal N°: " << nroSucursal;
}
