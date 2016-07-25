CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g

all: 0-main 1-main 2-main

0-main: 0-main.c btree_insert.c

1-main: 1-main.c btree_insert.c btree_find.c

2-main: 2-main.c btree_insert.c btree_find.c array_to_btree.c

run:
	./2-main
clean:
	rm 0-main 1-main 2-main
