#ifndef HASH_TABLES
#define HASH_TABLES

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

#ifndef DEBUG
#define DEBUG 1
#endif

/* hash_table_create - creates a hash table. */
hash_table_t *hash_table_create(unsigned long int size);

/* hash_djb2 - returns a hash based on djb2 algorithm */
unsigned long int hash_djb2(const unsigned char *str);

/* key_index - returns index depending on table size */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/* hash_table_set - set a key-value pair in a hash table */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/* hash_table_get - gets a value from the key in a hash table */
char *hash_table_get(const hash_table_t *ht, const char *key);

/*
 * hash_table_print - prints a hash table. If the hash table is not valid, it
 * will not print anything.
 */
void hash_table_print(const hash_table_t *ht);

/*
 * print_linked_list - prints a linked list starting at first_node_ptr until
 * there are no more values.
 */
void print_linked_list(hash_node_t *first_node_ptr);

/*  */
int _strlen(const char *s);

/*  */
char *_strdup(const char *s1);

/*  */
hash_node_t *make_node(const char *key, const char *value);

/*  */
void hash_table_delete(hash_table_t *ht);

/*  */
int invalid_ht(hash_table_t *ht);

/*  */
void delete_ht_ll(hash_node_t *head);

/*  */
void delete_node(hash_node_t *node_ptr);

#endif
