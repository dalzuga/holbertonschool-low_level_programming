all: a b c d e f g

a:
	gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-hash_table_create.c -o a
b:
	gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-djb2.c -o b
c:
	gcc -Wall -pedantic -Werror -Wextra 2-main.c 1-djb2.c 2-key_index.c -o c
d:
	gcc -Wall -pedantic -Werror -Wextra 3-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c -o d
e:
	gcc -Wall -pedantic -Werror -Wextra 4-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c -o e
f:
	gcc -Wall -pedantic -Werror -Wextra 5-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c -o f
g:
	gcc -Wall -pedantic -Werror -Wextra 6-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c -o g

clean:
	rm a b c d e f g
