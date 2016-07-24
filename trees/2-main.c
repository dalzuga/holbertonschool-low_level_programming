#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void print_preorder(BTree *tree);
BTree *array_to_btree(char **array);

int main()
{
	BTree *tree;
	char array[] = {'b', '\0', 'b', '\0', 'c', '\0', 'a', '\0'};
	char **array_ptr;
	int i;

	printf("sizeof(array):\t%lu\n", sizeof(array));
	
	array_ptr = malloc(sizeof(char *) * (sizeof(array) / 2 + 1));
	if (array_ptr == NULL)	/* malloc error */
		return 1;

	for (i = 0; i < (int) (sizeof(array) / 2); i++)
	{
		array_ptr[i] = array + 2 * i;
		/* printf("%s\n", array_ptr[i]); */
	}

	printf("-------array_to_btree-----------\n");

	tree = array_to_btree(array_ptr);
	if (tree == NULL)
		return 1;
	print_preorder(tree);

	return 0;
}

void print_preorder(BTree *tree)
{
	if (tree == NULL)
		return;

	printf("%s\n", tree->str);
	print_preorder(tree->left);
	print_preorder(tree->right);
}
