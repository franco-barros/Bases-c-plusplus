#pragma once
#include "core/Cliente.h"
#include "core/Proveedor.h"
#include <string>

class Intermediario : public Cliente, public Proveedor {
protected:
    std::string empresa;
    std::string rubro;
    int zonaAsignada; // nueva propiedad

public:
    // Constructores
    Intermediario() : zonaAsignada(-1) {}
    Intermediario(const std::string& nombre, long dni, int codigoCliente, int codigoProveedor,
                  const std::string& empresa, const std::string& rubro)
        : Persona(nombre, dni),
          Cliente(nombre, dni, codigoCliente),
          Proveedor(nombre, dni, codigoProveedor),
          empresa(empresa),
          rubro(rubro),
          zonaAsignada(-1) {}

    // Destructor virtual
    virtual ~Intermediario() = default;

    // Métodos sobrescritos
    void leerDatos() override;
    void imprimir() const override;
    void mostrarInfo() const override;

    // Métodos para manejo de zona
    void asignarZona(int zona) { zonaAsignada = zona; }
    int getZonaAsignada() const { return zonaAsignada; }

    // Getters y setters adicionales
    std::string getEmpresa() const { return empresa; }
    std::string getRubro() const { return rubro; }
};
