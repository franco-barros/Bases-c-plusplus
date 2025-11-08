#include "../include/Zona.h"
#include <iostream>
using namespace std;

void Zona::cargar() {
    cout << "\nIngrese numero de zona: ";
    cin >> nroZona;
    cout << "Ingrese numero de sucursal: ";
    cin >> nroSucursal;
}

void Zona::visualizar() {
    cout << "\nZona: " << nroZona;
    cout << "\nSucursal: " << nroSucursal;
}
 