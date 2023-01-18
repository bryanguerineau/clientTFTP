# Makefile for program with main.c, functions.c, and functions.h

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -g

# Output binary
BIN = main

# Object files
OBJS = main.o functions.o

# Default target
all: $(BIN)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to binary
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and binary
clean:
	rm -f $(OBJS) $(BIN)
