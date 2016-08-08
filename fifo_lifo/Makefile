CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
SOURCES=push_queue.c pop_queue.c push_stack.c
OBJECTS=print_queue_Ubuntu.o print_stack_Ubuntu.o pop_stack.o
OBJECTS+=$(SOURCES:.c=.o)
EXECUTABLE=0-main 1-main 2-main 3-main

all: $(SOURCES) $(EXECUTABLE)

0-main: $(OBJECTS) 0-main.o
	$(CC) $(OBJECTS) 0-main.o -o $@

1-main: $(OBJECTS) 1-main.o
	$(CC) $(OBJECTS) 1-main.o -o $@

2-main: $(OBJECTS) 2-main.o
	$(CC) $(OBJECTS) 2-main.o -o $@

3-main: $(OBJECTS) 3-main.o
	$(CC) $(OBJECTS) 3-main.o -o $@

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(SOURCES:.c=.o) 0-main.o 1-main.o 2-main.o
