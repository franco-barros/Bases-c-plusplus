#pragma once
#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad);
    virtual ~Persona(); // Destructor virtual

    virtual void mostrar() const; // Método virtual (permite polimorfismo)
};
