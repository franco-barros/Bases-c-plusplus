#include "../include/utils/Persistencia.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


void Persistencia::guardarEmpleados(const vector<Empleado>& lista, const string& ruta) {
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "❌ Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& e : lista) {
        archivo << e.getNombre() << ";"
                << e.getDni() << ";"
                << e.getPuesto() << ";"
                << e.getSalario() << ";"
                << e.getZonaAsignada() << "\n";
    }
}

void Persistencia::cargarEmpleados(vector<Empleado>& lista, const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo) return;
    lista.clear();

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, dni, puesto, salario, zona;

        getline(ss, nombre, ';');
        getline(ss, dni, ';');
        getline(ss, puesto, ';');
        getline(ss, salario, ';');
        getline(ss, zona, ';');

        Empleado e(nombre, stol(dni), puesto, stod(salario));
        e.asignarZona(stoi(zona));
        lista.push_back(e);
    }
}


void Persistencia::guardarZonas(const vector<Zona>& lista, const string& ruta) {
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "❌ Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& z : lista) {
        archivo << z.getNroZona() << ";" << z.getNroSucursal() << "\n";
    }
}

void Persistencia::cargarZonas(vector<Zona>& lista, const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo) return;
    lista.clear();

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nroZona, nroSucursal;
        getline(ss, nroZona, ';');
        getline(ss, nroSucursal, ';');

        Zona z;
        z.setNroZona(stoi(nroZona));
        z.setNroSucursal(stoi(nroSucursal));
        lista.push_back(z);
    }
}


void Persistencia::guardarIntermediarios(const vector<Intermediario>& lista, const string& ruta) {
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "❌ Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& i : lista) {
        archivo << i.getNombre() << ";"
                << i.getDni() << ";"
                << i.getCodigoCliente() << ";"  
                << i.getCodigoProveedor() << ";"  
                << i.getEmpresa() << ";"
                << i.getRubro() << ";"
                << i.getZonaAsignada() << "\n";
    }
}

void Persistencia::cargarIntermediarios(vector<Intermediario>& lista, const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo) return;
    lista.clear();

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, dni, codCli, codProv, empresa, rubro, zona;

        getline(ss, nombre, ';');
        getline(ss, dni, ';');
        getline(ss, codCli, ';');
        getline(ss, codProv, ';');
        getline(ss, empresa, ';');
        getline(ss, rubro, ';');
        getline(ss, zona, ';');

        Intermediario i(nombre, stol(dni), stoi(codCli), stoi(codProv), empresa, rubro);
        i.asignarZona(stoi(zona));
        lista.push_back(i);
    }
}


void Persistencia::guardarClientes(const vector<Cliente>& lista, const string& ruta) {
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "❌ Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& c : lista) {
        archivo << c.getNombre() << ";"
                << c.getDni() << ";"
                << c.getCodigo() << "\n";
    }
}

void Persistencia::cargarClientes(vector<Cliente>& lista, const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo) return;
    lista.clear();

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, dni, codigo;
        getline(ss, nombre, ';');
        getline(ss, dni, ';');
        getline(ss, codigo, ';');

        Cliente c(nombre, stol(dni), stoi(codigo));
        lista.push_back(c);
    }
}


void Persistencia::guardarProveedores(const vector<Proveedor>& lista, const string& ruta) {
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "❌ Error al abrir " << ruta << " para escritura.\n";
        return;
    }
    for (const auto& p : lista) {
        archivo << p.getNombre() << ";"
                << p.getDni() << ";"
                << p.getCodigo() << "\n";
    }
}

void Persistencia::cargarProveedores(vector<Proveedor>& lista, const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo) return;
    lista.clear();

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, dni, codigo;
        getline(ss, nombre, ';');
        getline(ss, dni, ';');
        getline(ss, codigo, ';');

        Proveedor p(nombre, stol(dni), stoi(codigo));
        lista.push_back(p);
    }
}
