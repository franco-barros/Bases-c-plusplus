# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Archivos fuente y ejecutable
SRC = src/main.cpp src/Persona.cpp src/Empleado.cpp
TARGET = programa

# Regla por defecto
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Limpieza
clean:
	rm -f $(TARGET)
