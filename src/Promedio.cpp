#include "../include/Promedio.h"

// Tres valores float
float Promedio::calcular(float a, float b, float c) {
    return (a + b + c) / 3.0f;
}

// Tres valores int
float Promedio::calcular(int x, int y, int z) {
    return static_cast<float>(x + y + z) / 3.0f;
}

// Dos valores float
float Promedio::calcular(float a, float b) {
    return (a + b) / 2.0f;
}

// Dos valores int
float Promedio::calcular(int x, int y) {
    return static_cast<float>(x + y) / 2.0f;
}
 