# Compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
BUILD_DIR = build
BIN = main

# Arquivos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TEST = $(TEST_DIR)/main.cpp

# Regra padrão
all: $(BIN)

# Compila o executável
$(BIN): $(OBJS) $(TEST)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compila os arquivos objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa os arquivos gerados
clean:
	rm -rf $(BUILD_DIR) $(BIN)

# Executa o programa
run: $(BIN)
	./$(BIN)

.PHONY: all clean run