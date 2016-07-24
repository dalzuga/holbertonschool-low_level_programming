#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void print_preorder(BTree *tree);
int array_to_btree(char **array);

int main()
{
	/* BTree *tree; */
	char array[] = {'b', 'a', 'c'};
	char *array_ptr;
	int i;

	array_ptr = malloc(sizeof(array) + 1);

	for (i = 0; i < (int) sizeof(array); i++)
		array_ptr[i] = array[i];

	array_ptr[i] = '\0';
	printf("%s\n", array_ptr);

	printf("-------array_to_btree-----------\n");

	if (array_to_btree(&array_ptr))
		return 1;

	/* print_preorder(tree); */

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
