CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
SOURCES = $(SRCDIR)/box.c $(SRCDIR)/puzzle.c $(SRCDIR)/row.c $(SRCDIR)/square.c $(SRCDIR)/sudoku.c
OBJECTS = box.o puzzle.o row.o square.o sudoku.o
TARGET = sudoku

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
