# Author: Anvay Mayekar
# Cross-platform Makefile for MegaMatrixMania

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iheader

# Platform-specific linker flags
ifeq ($(OS),Windows_NT)
    LDFLAGS = -Wl,--subsystem,console -lmingw32
    EXE = .exe
    SHELL = cmd
else
    LDFLAGS =
    EXE =
    SHELL = /bin/sh
endif

# Source files
SRC = $(wildcard src/*.c) main.c
OBJ_DIR = build/obj
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(filter src/%.c,$(SRC))) $(OBJ_DIR)/main.o
BIN = build/MegaMatrixMania

# Default target
all: $(BIN)$(EXE)

# Create object directory
$(OBJ_DIR):
ifeq ($(OS),Windows_NT)
	@if not exist "build\obj" mkdir build\obj
else
	@mkdir -p $(OBJ_DIR)
endif

# Link object files to create executable
$(BIN)$(EXE): $(OBJ)
ifeq ($(OS),Windows_NT)
	@if not exist "build" mkdir build
else
	@mkdir -p build
endif
	$(CC) $(OBJ) -o $(BIN)$(EXE) $(LDFLAGS)
	@echo Linked successfully

# Compile source files from src/ directory
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo Compiled $<

# Compile main.c from root directory
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo Compiled $<

# Clean build artifacts
clean:
ifeq ($(OS),Windows_NT)
	@if exist build rmdir /S /Q build
else
	@rm -rf build
endif

# Run the program
run: $(BIN)$(EXE)
	$(BIN)$(EXE)

# Rebuild from scratch
rebuild: clean all

.PHONY: all clean run rebuild