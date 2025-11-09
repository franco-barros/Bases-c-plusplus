#pragma once
#include "core/Persona.h"
#include <string>

class Proveedor : virtual public Persona {
protected:
    int codigo;
  
public:
    Proveedor() = default;
    Proveedor(const std::string& nombre, long dni, int codigo);

    virtual ~Proveedor() = default;

    void leerDatos() override;
    void imprimir() const override;

    void mostrarInfo() const override;

    int getCodigo() const { return codigo; }
    void setCodigo(int c) { codigo = c; }
};
