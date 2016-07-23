#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
void print_tree_all_nodes(BTree **tree);
void print_tree_node(BTree **tree);
void print_preorder(BTree *tree);
int test_insert();

int main()
{
        BTree *tree;

        tree = NULL;

	printf("-------DANIEL'S TREE STARTS NOW-----------\n");

	printf("insert:\tb\n");
        if (btree_insert(&tree, "b")) /* error check */
                return 1;

	printf("insert:\ta\n");
	if (btree_insert(&tree, "a")) /* error check */
		return 1;

	printf("insert:\tc\n");
	if (btree_insert(&tree, "c")) /* error check */
		return 1;

	printf("insert:\tb\n");
        if (btree_insert(&tree, "b")) /* error check */
                return 1;

	print_preorder(tree);

	tree = NULL;

	printf("-------JOHN SERRANO'S TREE STARTS NOW-----------\n");

	btree_insert(&tree, "q - 1");
	btree_insert(&tree, "w - 6");
	btree_insert(&tree, "e - 2");
	btree_insert(&tree, "r - 7");
	btree_insert(&tree, "t - 8");
	btree_insert(&tree, "y - 10");
	btree_insert(&tree, "u - 9");
	btree_insert(&tree, "i - 3");
	btree_insert(&tree, "o - 4");
	btree_insert(&tree, "p - 5");

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
