# =========================================================
# ⚙️ CONFIGURACIÓN DEL COMPILADOR
# =========================================================
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# =========================================================
# 📁 ESTRUCTURA DE ARCHIVOS
# =========================================================
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Archivos fuente (.cpp), incluyendo main.cpp
SRC = main.cpp $(shell find $(SRC_DIR) -name "*.cpp")

# Archivos objeto correspondientes en obj/
OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Nombre del ejecutable
TARGET = $(BIN_DIR)/gestion

# =========================================================
# 🧱 REGLA PRINCIPAL
# =========================================================
all: $(BIN_DIR) $(OBJ_DIR) $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)
	@echo ""
	@echo "✅ Compilación completada con éxito: $(TARGET)"
	@echo ""

# =========================================================
# 🔧 COMPILACIÓN DE CADA ARCHIVO CPP
# =========================================================
# Crear carpeta de objetos si no existe
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================================================
# 📂 CREACIÓN DE CARPETAS BIN Y OBJ
# =========================================================
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# =========================================================
# 🧹 LIMPIEZA DE ARCHIVOS COMPILADOS
# =========================================================
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "🧹 Archivos compilados eliminados."

# =========================================================
# 🏃 ATAJOS ÚTILES
# =========================================================
run: all
	./$(TARGET)

rebuild: clean all
