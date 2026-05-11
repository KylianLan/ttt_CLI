# Compiler and flags
CC = gcc
FLAGS = -g -c -Wall
LFLAGS = 

# Source files and object files
OBJS = arrow_input.o game.o input.o main.o menu.o settings.o
SOURCE = arrow_input.c game.c input.c main.c menu.c settings.c
HEADER = arrow_input.h game.h input.h menu.h settings.h
OUT = main

# Libraries
LDLIBS = 

# Default target
all: $(OUT)

# Linking rules
$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) $(LDLIBS)

# Compilation rules
%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -o $@ $<

# Clean rule
clean:
	rm -f $(OBJS) $(OUT)
