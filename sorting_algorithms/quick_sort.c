void print_array(int *, int);
int print_char(char);
void print_number(int);

/* sort an array using quick-sort algorithm */
void quick_sort(int *array, int size)
{
        int i, pivot;

        if (size > 1) {
                pivot = array[size / 2];
                
                print_number(pivot);
                print_char('\n');

                for (i = 0; i < (size + 1) / 2; i++) {
                        print_number(i);
                        print_char('\t');
                }
                print_char('\n');
        }
}
