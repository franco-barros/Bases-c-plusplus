#pragma once

class Promedio {
public:
    // Sobrecarga para tres valores float
    float calcular(float a, float b, float c);

    // Sobrecarga para tres valores int
    float calcular(int x, int y, int z);

    // Sobrecarga para dos valores float
    float calcular(float a, float b);

    // Sobrecarga para dos valores int
    float calcular(int x, int y);
};
 