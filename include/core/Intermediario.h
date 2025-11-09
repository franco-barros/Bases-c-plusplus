#pragma once
#include "core/Cliente.h"
#include "core/Proveedor.h"
#include <string>

class Intermediario : public Cliente, public Proveedor {
protected:
    std::string empresa;
    std::string rubro;
    int zonaAsignada; 

public:
    Intermediario() : zonaAsignada(-1) {}

    Intermediario(const std::string& nombre, long dni, int codigoCliente, int codigoProveedor,
                  const std::string& empresa, const std::string& rubro)
        : Persona(nombre, dni),
          Cliente(nombre, dni, codigoCliente),
          Proveedor(nombre, dni, codigoProveedor),
          empresa(empresa),
          rubro(rubro),
          zonaAsignada(-1) {}

    virtual ~Intermediario() = default;

    void leerDatos() override;
    void imprimir() const override;
    void mostrarInfo() const override;

    void asignarZona(int zona) { zonaAsignada = zona; }
    int getZonaAsignada() const { return zonaAsignada; }

    std::string getEmpresa() const { return empresa; }
    std::string getRubro() const { return rubro; }

    int getCodigoCliente() const { return Cliente::getCodigo(); }
    int getCodigoProveedor() const { return Proveedor::getCodigo(); }

    void setCodigoCliente(int c) { Cliente::setCodigo(c); }
    void setCodigoProveedor(int c) { Proveedor::setCodigo(c); }
};
