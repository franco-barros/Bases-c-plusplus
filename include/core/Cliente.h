#pragma once
#include "core/Persona.h"
#include <string>
#include <iostream>

class Cliente : virtual public Persona {
protected:
    int codigo;

public: 
    Cliente() = default;
    Cliente(const std::string& nombre, long dni, int codigo);

    virtual ~Cliente() = default;

    void leerDatos() override;
    void imprimir() const override;
    void mostrarInfo() const override;

    int getCodigo() const { return codigo; }
    void setCodigo(int c) { codigo = c; }
};
