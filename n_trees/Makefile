CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
SOURCES=0-main.c ntree_insert.c
OBJECTS=free_str_array.o  ntree_free.o  ntree_print.o  string_split.o
OBJECTS+=$(SOURCES:.c=.o)
EXECUTABLE=0-main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.PHONY: clean
clean:
	$(RM) 0-main $(SOURCES:.c=.o)
