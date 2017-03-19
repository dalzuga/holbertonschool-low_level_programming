all: a b c d e

a:
	gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-print_listint.c -o a
b:
	gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-listint_len.c -o b
c:
	gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-add_nodeint.c 0-print_listint.c -o c
d:
	gcc -Wall -pedantic -Werror -Wextra 3-main.c 3-add_nodeint_end.c 0-print_listint.c -o d
e: 4-main.c 4-free_listint.c
	gcc -Wall -pedantic -Werror -Wextra 4-main.c 3-add_nodeint_end.c 0-print_listint.c 4-free_listint.c -o e
