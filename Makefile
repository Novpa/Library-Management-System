# Makefile for binary search program

# Compiler
CC = gcc

# Compiler flags
# CFLAGS = -Wall -Wextra -Werror -std=c11

# Target executable
TARGET = learning_tools

# Source files
SRC = main.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)
	./$(TARGET)

# Rule to link the object files and create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: all clean