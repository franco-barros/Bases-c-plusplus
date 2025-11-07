#pragma once
#include "Persona.h"

class Empleado : public Persona {
private:
    std::string puesto;
    double salario;

public:
    Empleado(const std::string& nombre, int edad, const std::string& puesto, double salario);

    void mostrar() const override; // Sobrescribe el método mostrar() de Persona
};
