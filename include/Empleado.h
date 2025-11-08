#pragma once
#include "Persona.h"
#include <string>

class Empleado : public Persona {
private:
    std::string puesto;
    double salario;

public:
    // Constructores
    Empleado() = default;
    Empleado(const std::string& nombre, long dni, const std::string& puesto, double salario);

    // Métodos (sobrescriben los de Persona)
    void leerDatos() override;
    void imprimir() const override;
    void mostrarInfo() const override;

    // Getters
    std::string getPuesto() const { return puesto; }
    double getSalario() const { return salario; }

    // Setters (opcionales)
    void setPuesto(const std::string& p) { puesto = p; }
    void setSalario(double s) { salario = s; }
};
