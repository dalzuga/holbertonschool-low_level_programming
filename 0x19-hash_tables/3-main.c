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

    ht = hash_table_create(1024);
    hash_table_set(ht, "hetairas", "holberton");
    hash_table_set(ht, "mentioner", "hello");
    hash_table_set(ht, "mentioner", "");
    hash_table_set(ht, "", "hello");
    hash_table_set(ht, "hetairas", NULL);
    hash_table_print(ht);
    hash_table_delete(ht);
    return (EXIT_SUCCESS);
}
