all: a b c d e f g
0: 0-main.c 0-hash_table_create.c 6-hash_table_delete.c
	gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-hash_table_create.c 6-hash_table_delete.c -o a
1: 1-main.c 1-djb2.c
	gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-djb2.c -o b
2: 2-main.c 1-djb2.c 2-key_index.c
	gcc -Wall -pedantic -Werror -Wextra 2-main.c 1-djb2.c 2-key_index.c -o c
3: 3-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 5-hash_table_print.c 6-hash_table_delete.c
	gcc -Wall -pedantic -Werror -Wextra 3-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 5-hash_table_print.c 6-hash_table_delete.c -o d
4: 4-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 6-hash_table_delete.c
	gcc -Wall -pedantic -Werror -Wextra 4-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 6-hash_table_delete.c -o e
5: 5-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c
	gcc -Wall -pedantic -Werror -Wextra 5-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c -o f
6: 6-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c
	gcc -Wall -pedantic -Werror -Wextra 6-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c -o g

clean:
	rm a b c d e f g
