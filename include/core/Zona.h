#pragma once
#include <iostream>
using namespace std;

class Zona {
private:
    int nroZona;
    int nroSucursal; 

public:
    Zona();

    void cargar();
    void visualizar() const;

    int getNroZona() const { return nroZona; }
    int getNroSucursal() const { return nroSucursal; }

    void setNroZona(int nro) { nroZona = nro; }
    void setNroSucursal(int suc) { nroSucursal = suc; }
};
