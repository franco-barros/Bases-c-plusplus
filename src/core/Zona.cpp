#include "../include/core/Zona.h"
#include <iostream>
#include <limits> 
using namespace std;

Zona::Zona() : nroZona(0), nroSucursal(0) {}

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

void Zona::visualizar() const {
    cout << "Zona N°: " << nroZona
         << " | Sucursal N°: " << nroSucursal;
}
