#pragma once
#include "core/Persona.h"
#include <string> 

class Empleado : public Persona {
protected: 
    std::string puesto;
    double salario;
    int zonaAsignada; 

public: 
    Empleado() = default;
    Empleado(const std::string& nombre, long dni, const std::string& puesto, double salario);

    void leerDatos() override;
    void imprimir() const override;

    void mostrarInfo() const override;

    void asignarZona(int zona);
    int getZonaAsignada() const;

    double getSalario() const { return salario; }

    std::string getPuesto() const { return puesto; }

    void setPuesto(const std::string& p) { puesto = p; }
    void setSalario(double s) { salario = s; }
};
