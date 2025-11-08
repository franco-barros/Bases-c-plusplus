#pragma once
#include <string>
#include <iostream>

class Persona {
protected:
    std::string nombre;
    long dni;

public:
    // Constructores
    Persona() = default;
    Persona(const std::string& nombre, long dni);

    // Destructor virtual (importante para polimorfismo)
    virtual ~Persona() = default;

    // Métodos base
    virtual void leerDatos();
    virtual void imprimir() const;

    // Método adicional para el nuevo main (nombre distinto)
    virtual void mostrarInfo() const;

    // Getters y setters
    std::string getNombre() const { return nombre; }
    long getDni() const { return dni; }

    void setNombre(const std::string& n) { nombre = n; }
    void setDni(long d) { dni = d; }
};
 