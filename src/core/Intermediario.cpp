#include "../include/core/Intermediario.h"
#include <iostream>
#include <limits> 
using namespace std;



// Leer datos desde teclado
void Intermediario::leerDatos() {
    Persona::leerDatos();

    cout << "Ingrese código de cliente: ";
    while (!(cin >> Cliente::codigo)) {
        cout << "❌ Entrada inválida. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese código de proveedor: ";
    while (!(cin >> Proveedor::codigo)) {
        cout << "❌ Entrada inválida. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

    cout << "Ingrese nombre de empresa: ";
    getline(cin, empresa);

    cout << "Ingrese rubro: ";
    getline(cin, rubro);
}

void Intermediario::imprimir() const {
    cout << "\n=== INTERMEDIARIO ===";
    Persona::imprimir();
    cout << "\nCódigo cliente: " << Cliente::codigo;
    cout << "\nCódigo proveedor: " << Proveedor::codigo;
    cout << "\nEmpresa: " << empresa;
    cout << "\nRubro: " << rubro << endl;
}

void Intermediario::mostrarInfo() const {
    cout << "Intermediario → " << nombre
         << " | DNI: " << dni
         << " | Cod.Cliente: " << Cliente::codigo
         << " | Cod.Proveedor: " << Proveedor::codigo
         << " | Empresa: " << empresa
         << " | Rubro: " << rubro << endl;
}
