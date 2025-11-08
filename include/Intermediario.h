#pragma once
#include "Cliente.h"
#include "Proveedor.h"
#include <string>

class Intermediario : public Cliente, public Proveedor {
protected:
    std::string empresa;
    std::string rubro;

public:
    // Constructores
    Intermediario() = default;
    Intermediario(const std::string& nombre, long dni, int codigoCliente, int codigoProveedor,
                  const std::string& empresa, const std::string& rubro);

    // Destructor
    virtual ~Intermediario() = default;

    // Métodos sobrescritos
    void leerDatos() override;
    void imprimir() const override;
    void mostrarInfo() const override;

    // Getters y setters
    std::string getEmpresa() const { return empresa; }
    std::string getRubro() const { return rubro; }
};
