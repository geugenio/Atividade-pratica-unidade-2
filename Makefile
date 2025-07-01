# Makefile 
CC       := gcc
CXX      := g++
CFLAGS   := -Iinclude_c -std=c11 -Wall
CXXFLAGS := -Iinclude_cpp -std=c++17 -Wall

# Make expande os arquivos .c e .cpp
SRCS   := $(wildcard src/*.cpp)
.PHONY: all clean test

all: test

ifeq ($(OS),Windows_NT)
    RM = del /Q
	EXE_EXT = .exe
else
    RM = rm -f
	EXE_EXT =
endif


test:
	$(CXX) $(CXXFLAGS) $(SRCS_CPP) test/main.cpp -o test_ex$(EXE_EXT)
	./test_ex$(EXE_EXT)

clean:
	$(RM) test_ex$(EXE_EXT