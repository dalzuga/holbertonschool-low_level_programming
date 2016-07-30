CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
SOURCES=ntree_insert
OBJECTS=free_str_array.o  ntree_free.o  ntree_print.o  string_split.o

all: 0-main

0-main: $(SOURCES).c $(OBJECTS)

run:
	valgrind ./0-main

clean:
	$(RM) 0-main
