#pragma once
#include "core/Persona.h"
#include <string>

class Empleado : public Persona {
protected:
    std::string puesto;
    double salario;
    int zonaAsignada; // 🔹 Nueva propiedad opcional

public:
    // Constructores
    Empleado() = default;
    Empleado(const std::string& nombre, long dni, const std::string& puesto, double salario);

    // Métodos clásicos
    void leerDatos() override;
    void imprimir() const override;

    // Método adicional para el sistema (para vector<Persona*>)
    void mostrarInfo() const override;

    // 🔹 Nuevos métodos de zona
    void asignarZona(int zona);
    int getZonaAsignada() const;
};
