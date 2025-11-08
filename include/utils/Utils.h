#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // para system()

using namespace std;

// ============================================================
// 🎨 Códigos de colores ANSI
// ============================================================
namespace Color {
    const string RESET   = "\033[0m";
    const string ROJO    = "\033[1;31m";
    const string VERDE   = "\033[1;32m";
    const string AMARILLO= "\033[1;33m";
    const string AZUL    = "\033[1;34m";
    const string MAGENTA = "\033[1;35m";
    const string CYAN    = "\033[1;36m";
    const string BLANCO  = "\033[1;37m";
    const string NEGRITA = "\033[1m";
}

// ============================================================
// 🧹 Limpia la pantalla (compatible con Windows / Linux)
// ============================================================
inline void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ============================================================
// ⏸️ Pausa hasta que el usuario presione ENTER
// ============================================================
inline void pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

// ============================================================
// 🎨 Imprime texto con color
// ============================================================
inline void colorearTexto(const string& texto, const string& color) {
    cout << color << texto << Color::RESET;
}
