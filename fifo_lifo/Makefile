CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
SOURCES=push_queue.c pop_queue.c push_stack.c
OBJECTS=print_queue_Ubuntu.o print_stack_Ubuntu.o
OBJECTS+=$(SOURCES:.c=.o)
EXECUTABLE=0-main 1-main 2-main

all: $(SOURCES) $(EXECUTABLE)

# this is implicit
# 0-main.o: $(SOURCES) 0-main.c

0-main: $(OBJECTS) 0-main.o
	$(CC) $(OBJECTS) 0-main.o -o $@

# this is implicit
# 1-main.o: $(SOURCES) 1-main.c

1-main: $(OBJECTS) 1-main.o
	$(CC) $(OBJECTS) 1-main.o -o $@

2-main: $(OBJECTS) 2-main.o
	$(CC) $(OBJECTS) 2-main.o -o $@

# pop_queue.o: pop_queue.c
# 	$(CC) $< -o $@

# 1-main.o: 1-main.c
# 	$(CC) $< -o $@

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(SOURCES:.c=.o) 0-main.o 1-main.o
