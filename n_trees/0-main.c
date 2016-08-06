#include <stdlib.h>
#include "tree.h"
#include <stdio.h>

int ntree_insert(NTree **, char **, char *);

void ntree_print(NTree *);
void ntree_free(NTree *);
char **string_split(const char *, char);
void free_str_array(char **);

int main(void)
{
	NTree *tree;
	char __attribute__((unused)) **array;

	printf("------1 (root node)------\n");
	tree = NULL;
	ntree_insert(&tree, NULL, "/");

	printf("------2------\n");
	ntree_insert(&tree, (array = string_split("/", ' ')), "tmp");
	free_str_array(array);

	printf("------3------\n");
	ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file");
	free_str_array(array);

	printf("------4------\n");
	ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file2");
	free_str_array(array);

	printf("------5------\n");
	ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file3");
	free_str_array(array);

	printf("------6------\n");
	ntree_insert(&tree, (array = string_split("/", ',')), "mnt");
	free_str_array(array);

	printf("------7------\n");
	ntree_insert(&tree, (array = string_split("/ mnt", ' ')), "HDD1");
	free_str_array(array);

	ntree_insert(&tree, (array = string_split("/ mnt HDD1", ' ')), "Desktop");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ mnt HDD1 Desktop", ' ')), "image.jpg");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ mnt", ' ')), "HDD2");
	free_str_array(array);

	ntree_insert(&tree, (array = string_split("/", ',')), "home");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home", ' ')), "ubuntu");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Documents");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Download");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Public");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Templates");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Pictures");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Videos");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Music");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Desktop");
	free_str_array(array);

	ntree_insert(&tree, (array = string_split("/", ',')), "dev");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "urandom");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sda");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sda1");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sda2");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb1");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb2");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ dev", ' ')), "sdb3");
	free_str_array(array);

	printf("------print------\n");
	ntree_print(tree);
	printf("------free------\n");
	ntree_free(tree);
	return (0);
}
