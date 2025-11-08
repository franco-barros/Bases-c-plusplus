#pragma once
#include "core/Persona.h"
#include <string>

class Proveedor : virtual public Persona {
protected:
    int codigo;

public:
    // Constructores
    Proveedor() = default;
    Proveedor(const std::string& nombre, long dni, int codigo);

    // Destructor virtual
    virtual ~Proveedor() = default;

    // Métodos clásicos
    void leerDatos() override;
    void imprimir() const override;

    // Método para el sistema polimórfico
    void mostrarInfo() const override;

    // Getters y setters
    int getCodigo() const { return codigo; }
    void setCodigo(int c) { codigo = c; }
};
