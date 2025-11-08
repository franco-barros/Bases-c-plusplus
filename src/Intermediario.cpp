#include "../include/Intermediario.h"
#include <iostream>
using namespace std;

// Constructor con parámetros
Intermediario::Intermediario(const string& nombre, long dni, int codigoCliente, int codigoProveedor,
                             const string& empresa, const string& rubro)
    : Persona(nombre, dni), Cliente(nombre, dni, codigoCliente),
      Proveedor(nombre, dni, codigoProveedor),
      empresa(empresa), rubro(rubro) {}

// Leer datos desde teclado
void Intermediario::leerDatos() {
    Persona::leerDatos();
    cout << "Ingrese código de cliente: ";
    cin >> Cliente::codigo;
    cout << "Ingrese código de proveedor: ";
    cin >> Proveedor::codigo;
    cout << "Ingrese nombre de empresa: ";
    cin >> empresa;
    cout << "Ingrese rubro: ";
    cin >> rubro;
}

// Imprimir datos completos
void Intermediario::imprimir() const {
    cout << "\n=== Intermediario ===";
    Persona::imprimir();
    cout << "\nCódigo cliente: " << Cliente::codigo;
    cout << "\nCódigo proveedor: " << Proveedor::codigo;
    cout << "\nEmpresa: " << empresa;
    cout << "\nRubro: " << rubro << endl;
}

// Mostrar resumen polimórfico
void Intermediario::mostrarInfo() const {
    cout << "Intermediario: " << nombre
         << " | DNI: " << dni
         << " | Cod.Cliente: " << Cliente::codigo
         << " | Cod.Proveedor: " << Proveedor::codigo
         << " | Empresa: " << empresa
         << " | Rubro: " << rubro << endl;
}
