#include <stdio.h>
void quick_sort(int *, int);
void print_array(int *, int);

int main(void)
{
        int array[] = {402, 94111, 98, 12, 1024};
        int array2[] = {1, 2, 3, 4, 5, 6};
        int array3[] = {6, 4, 2, 5, 3, 1};

        print_array(array, 5);
        quick_sort(array, 5);
        print_array(array, 5);
        printf("-----------\n");

        print_array(array2, 6);
        quick_sort(array2, 6);
        print_array(array2, 6);
        printf("-----------\n");

        print_array(array3, 6);
        quick_sort(array3, 6);
        print_array(array3, 6);
        printf("-----------\n");

        return (0);
}
