OBJ_CATALOG=build

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.c get_count_strokes.c get_data.c print_rezult.c get_sum.c check_data_strokes.c
VPATH=src

.PHONY: all clean

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
EXECUTABLE=geometry

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/main

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_CATALOG)/*.o  bin/*.exe
