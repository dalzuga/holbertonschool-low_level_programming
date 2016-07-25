CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g

all: 0-main 1-main 2-main 3-main 4-main

0-main: 0-main.c btree_insert.c

1-main: 1-main.c btree_insert.c btree_find.c

2-main: 2-main.c btree_insert.c btree_find.c array_to_btree.c

3-main: 3-main.c btree_insert.c btree_find.c array_to_btree.c btree_free.c

4-main: 4-main.c btree_insert.c btree_find.c array_to_btree.c btree_free.c btree_depth.c

run:
	./4-main
clean:
	rm 0-main 1-main 2-main 3-main 4-main
