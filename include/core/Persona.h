#pragma once
#include <string>
#include <iostream> 

class Persona {
protected:
    std::string nombre;
    long dni;

public:
    Persona() = default;
    Persona(const std::string& nombre, long dni);

    virtual ~Persona() = default;

    virtual void leerDatos();
    virtual void imprimir() const;

    virtual void mostrarInfo() const;

    std::string getNombre() const { return nombre; }
    long getDni() const { return dni; }

    void setNombre(const std::string& n) { nombre = n; }
    void setDni(long d) { dni = d; }
};
 