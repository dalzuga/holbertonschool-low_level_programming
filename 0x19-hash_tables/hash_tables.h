#ifndef HASH_TABLES
#define HASH_TABLES

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

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

#ifndef DEBUG
#define DEBUG 0
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

/* _strlen - gets the length of a string. */
int _strlen(const char *s);

/* _strdup - duplicates a string. */
char *_strdup(const char *s1);

/* make_node - makes a hash table node. */
hash_node_t *make_node(const char *key, const char *value);

/* hash_table_delete - frees all memory allocated to a hash table. */
void hash_table_delete(hash_table_t *ht);

/* invalid_ht - checks if the hash table is valid. */
int invalid_ht(const hash_table_t *ht);

/*  delete_ht_ll - frees all memory allocated to a linked list. */
void delete_ht_ll(hash_node_t *head);

/* delete_node - frees a node inside a linked list. */
void delete_node(hash_node_t *node_ptr);

/* _strcmp - compare two strings */
int _strcmp(const char *s1, const char *s2);

/* ht_set_helper - traverses hash table linked list */
int ht_set_helper(hash_node_t **head, const char *key, const char *value);

/* ht_node_update - updates the value in a node */
int ht_node_update(hash_node_t *tmp_node, const char *value);

/* invalid_sht - checks if the sorted hash table is valid */
int invalid_sht(const shash_table_t *sht);

/* make_sht_node - makes a sorted hash table node */
shash_node_t *make_sht_node(const char *key, const char *value);

/* shash_table_create - creates a sorted hash table */
shash_table_t *shash_table_create(unsigned long int size);

/* shash_table_set - set a key-value pair in a sorted hash table */
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

/* sht_set_1a - set a key-value pair in a sorted hash table */
int sht_set_1a(shash_table_t *sht, const char *key, const char *value);

/* sht_set_1b - set a key-value pair in a sorted hash table */
int sht_set_1b(shash_table_t *sht, const char *key, const char *value);

/*
 * sht_insert_dll - insert a node at the end of the double linked list of a
 * sorted hash table.
 */
int sht_insert_dll(shash_table_t *sht, shash_node_t *node);

/* sht_set_2 - set a key-value pair in a sorted hash table */
int sht_set_2(shash_table_t *sht, const char *key, const char *value);

/* update_sht_node - updates the value in a node */
int update_sht_node(shash_node_t *tmp_node, const char *value);

/*
 * sht_push_dllnode - move a node to the end of the double linked list of a
 * sorted hash table.
 */
int sht_push_dllnode(shash_table_t *sht, shash_node_t *node);

/* /\* shash_table_get - gets a value from the key in a sorted hash table *\/ */
/* char *shash_table_get(const shash_table_t *ht, const char *key); */

/*
 * shash_table_print - prints a sorted hash table. If the hash table is not
 * valid, it will not print anything.
 */
void shash_table_print(const shash_table_t *ht);

/*
 * shash_table_print_rev - prints a sorted hash table in reverse order. If the
 * hash table is not valid, it will not print anything.
 */
void shash_table_print_rev(const shash_table_t *ht);

/* /\* */
/*  * hash_table_print - prints a sorted hash table in reverse order. If the hash */
/*  * table is not valid, it will not print anything. */
/*  *\/ */
/* void shash_table_print_rev(const shash_table_t *ht); */

/* /\* shash_table_delete - frees all memory allocated to a sorted hash table. *\/ */
/* void shash_table_delete(shash_table_t *ht); */

#endif
