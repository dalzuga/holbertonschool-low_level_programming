void quick_sort(int *, int);
void print_array(int *, int);

int main(void)
{
        int array[] = {402, 94111, 98, 12, 1024};
        int array2[] = {7, 2, 8, 3, 5, 1, 9, 4, 6};
        int array3[] = {7, 2, 8, 3, 5, 1, 9, 4, 6, 10};

        print_array(array, 5);
        quick_sort(array, 5);
        print_array(array, 5);

        print_array(array2, 9);
        quick_sort(array2, 9);
        print_array(array2, 9);

        print_array(array3, 10);
        quick_sort(array3, 10);
        print_array(array3, 10);

        return (0);
}
