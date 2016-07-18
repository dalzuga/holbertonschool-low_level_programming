void insertion_sort(int *, int);
void print_array(int *, int);

int main(void)
{
        int array[] = {402, 94111, 98, 12, 1024};
        int array2[] = {2, 3, 1, 4, 5};

        print_array(array, 5);
        insertion_sort(array, 5);
        print_array(array, 5);

        print_array(array2, 5);
        insertion_sort(array2, 5);
        print_array(array2, 5);
        return (0);
}
