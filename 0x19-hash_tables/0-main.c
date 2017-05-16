#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    unsigned long int n;
    n = 1 << 10;

    ht = hash_table_create(n);
    hash_table_delete(ht);
    printf("%p\n", (void *)ht);
    printf("tested with size: %lu\n", n);
    return (EXIT_SUCCESS);
}
