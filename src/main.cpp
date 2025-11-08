#include <iostream>
#include <vector>
#include <cstdlib> // para system()
#include "../include/Persona.h"
#include "../include/Empleado.h"
#include "../include/Cliente.h"
#include "../include/Proveedor.h"
#include "../include/Intermediario.h"
#include "../include/Zona.h"
#include "../include/Promedio.h"

using namespace std;

// 🎨 Códigos de color ANSI
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define BOLD        "\033[1m"

// 🔄 Función para limpiar pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    // --- Datos de ejemplo ---
    vector<Empleado> empleados = {
        Empleado("Ana", 30589876, "Desarrolladora", 350000),
        Empleado("Franco", 28999888, "Diseñador", 280000)
    };

    vector<Cliente> clientes = {
        Cliente("Lucía", 40123456, 101),
        Cliente("Juan", 28999888, 102)
    };

    vector<Proveedor> proveedores = {
        Proveedor("Carlos", 45111222, 201),
        Proveedor("Sofía", 33444555, 202)
    };

    vector<Intermediario> intermediarios = {
        Intermediario("Laura", 29, 101, 501, "TechSolutions", "Software"),
        Intermediario("Pedro", 35, 102, 502, "LogiCorp", "Transporte")
    };

    vector<Zona> zonas;
    Promedio promedio;

    int opcion = 0;
    do {
        limpiarPantalla();
        cout << BOLD << CYAN << "\n=== SISTEMA GENERAL DE GESTIÓN ===\n" << RESET;
        cout << YELLOW << "1. " << RESET << "Ver listas (Empleados, Clientes, Proveedores, Intermediarios)\n";
        cout << YELLOW << "2. " << RESET << "Ingresar como persona (Cliente, Proveedor o Intermediario)\n";
        cout << YELLOW << "3. " << RESET << "Gestión avanzada (Zonas / Promedios)\n";
        cout << YELLOW << "4. " << RESET << "Salir\n";
        cout << BOLD << BLUE << "\nSeleccione una opción: " << RESET;
        cin >> opcion;

        limpiarPantalla();

        switch (opcion) {
            // --- Opción 1: Mostrar todas las listas ---
            case 1: {
                cout << BOLD << GREEN << "\n--- Empleados ---\n" << RESET;
                for (const auto& e : empleados) e.mostrarInfo();

                cout << BOLD << GREEN << "\n--- Clientes ---\n" << RESET;
                for (const auto& c : clientes) c.mostrarInfo();

                cout << BOLD << GREEN << "\n--- Proveedores ---\n" << RESET;
                for (const auto& p : proveedores) p.mostrarInfo();

                cout << BOLD << GREEN << "\n--- Intermediarios ---\n" << RESET;
                for (const auto& i : intermediarios) i.mostrarInfo();

                cout << YELLOW << "\nPresione ENTER para continuar..." << RESET;
                cin.ignore(); cin.get();
                break;
            }

            // --- Opción 2: Ingreso según tipo de persona ---
            case 2: {
                int tipo;
                cout << BOLD << MAGENTA << "\nIngresar como:\n" << RESET;
                cout << "1. Cliente\n";
                cout << "2. Proveedor\n";
                cout << "3. Intermediario\n";
                cout << BOLD << BLUE << "Opción: " << RESET;
                cin >> tipo;

                string nombre;
                cout << BOLD << "Ingrese su nombre: " << RESET;
                cin >> nombre;
                bool encontrado = false;

                if (tipo == 1) {
                    for (const auto& c : clientes) {
                        if (c.getNombre() == nombre) {
                            cout << GREEN << "\nBienvenido, " << nombre << " 👋 (Cliente)\n" << RESET;
                            c.mostrarInfo();
                            encontrado = true;
                            break;
                        }
                    }
                } 
                else if (tipo == 2) {
                    for (const auto& p : proveedores) {
                        if (p.getNombre() == nombre) {
                            cout << GREEN << "\nBienvenido, " << nombre << " 👋 (Proveedor)\n" << RESET;
                            p.mostrarInfo();
                            encontrado = true;
                            break;
                        }
                    }
                } 
                else if (tipo == 3) {
                    for (const auto& i : intermediarios) {
                        if (i.getNombre() == nombre) {
                            cout << GREEN << "\nBienvenido, " << nombre << " 👋 (Intermediario)\n" << RESET;
                            i.mostrarInfo();
                            encontrado = true;
                            break;
                        }
                    }
                } 
                else {
                    cout << RED << "Opción inválida.\n" << RESET;
                    break;
                }

                if (!encontrado) cout << RED << "No se encontró la persona ingresada.\n" << RESET;

                cout << YELLOW << "\nPresione ENTER para continuar..." << RESET;
                cin.ignore(); cin.get();
                break;
            }

            // --- Opción 3: Gestión avanzada ---
            case 3: {
                int subopcion;
                cout << BOLD << CYAN << "\n--- Gestión avanzada ---\n" << RESET;
                cout << YELLOW << "1. " << RESET << "Registrar nueva zona\n";
                cout << YELLOW << "2. " << RESET << "Ver zonas registradas\n";
                cout << YELLOW << "3. " << RESET << "Calcular promedios\n";
                cout << BOLD << BLUE << "Opción: " << RESET;
                cin >> subopcion;

                limpiarPantalla();

                switch (subopcion) {
                    case 1: {
                        Zona z;
                        z.cargar();
                        zonas.push_back(z);
                        cout << GREEN << "\n✅ Zona registrada correctamente.\n" << RESET;
                        break;
                    }
                    case 2: {
                        if (zonas.empty()) {
                            cout << RED << "\n⚠ No hay zonas registradas.\n" << RESET;
                        } else {
                            cout << BOLD << "\n--- Listado de zonas ---\n" << RESET;
                            for (auto& z : zonas) {
                                z.visualizar();
                                cout << endl;
                            }
                        }
                        break;
                    }
                    case 3: {
                        cout << BOLD << MAGENTA << "\n--- Cálculo de Promedios ---\n" << RESET;
                        int tipoProm;
                        cout << "1. Promedio de 2 valores\n";
                        cout << "2. Promedio de 3 valores\n";
                        cout << BOLD << BLUE << "Opción: " << RESET;
                        cin >> tipoProm;

                        if (tipoProm == 1) {
                            float a, b;
                            cout << "Ingrese el primer valor: ";
                            cin >> a;
                            cout << "Ingrese el segundo valor: ";
                            cin >> b;
                            cout << GREEN << "\nPromedio = " << promedio.calcular(a, b) << RESET << endl;
                        } else if (tipoProm == 2) {
                            float a, b, c;
                            cout << "Ingrese el primer valor: ";
                            cin >> a;
                            cout << "Ingrese el segundo valor: ";
                            cin >> b;
                            cout << "Ingrese el tercer valor: ";
                            cin >> c;
                            cout << GREEN << "\nPromedio = " << promedio.calcular(a, b, c) << RESET << endl;
                        } else {
                            cout << RED << "Opción inválida.\n" << RESET;
                        }
                        break;
                    }
                    default:
                        cout << RED << "Opción inválida.\n" << RESET;
                        break;
                }

                cout << YELLOW << "\nPresione ENTER para continuar..." << RESET;
                cin.ignore(); cin.get();
                break;
            }

            case 4:
                cout << YELLOW << "\n👋 Saliendo del sistema...\n" << RESET;
                break;

            default:
                cout << RED << "Opción inválida.\n" << RESET;
                cout << YELLOW << "\nPresione ENTER para continuar..." << RESET;
                cin.ignore(); cin.get();
                break;
        }

    } while (opcion != 4);

    return 0;
}
