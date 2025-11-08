# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Archivos fuente (todos los .cpp dentro de src)
SRC = $(wildcard src/*.cpp)

# Archivos objeto (se generan automáticamente)
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
TARGET = programa

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable a partir de los objetos
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Regla genérica para compilar cada .cpp a .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de archivos compilados
clean:
	rm -f $(OBJ) $(TARGET)
