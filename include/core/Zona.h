#pragma once
#include <iostream>
using namespace std;

class Zona {
private:
    int nroZona;
    int nroSucursal;

public:
    // Constructor por defecto (solo declarado)
    Zona();

    // Métodos principales
    void cargar();
    void visualizar() const;

    // Getters
    int getNroZona() const { return nroZona; }
    int getNroSucursal() const { return nroSucursal; }
};
