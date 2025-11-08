#pragma once
#include "core/Persona.h"
#include <string>
#include <iostream>

class Cliente : virtual public Persona {
protected:
    int codigo;

public:
    // Constructores
    Cliente() = default;
    Cliente(const std::string& nombre, long dni, int codigo);

    // Destructor virtual
    virtual ~Cliente() = default;

    // Métodos que sobrescriben los de Persona
    void leerDatos() override;
    void imprimir() const override;
    void mostrarInfo() const override;

    // Getters y setters
    int getCodigo() const { return codigo; }
    void setCodigo(int c) { codigo = c; }
};
