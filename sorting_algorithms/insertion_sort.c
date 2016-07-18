void insert(int *array, int val, int n);

/* sort the array using insertion sorting method */
void insertion_sort(int *array, int size)
{
        int i;

        /* find the first unsorted value */
        for (i = 0; i < (size - 1); i++) {
                if (array[i + 1] < array[i]) {
                        /* first unsorted value found at place i+1 */
                        insert(array, array[i + 1],  i + 1);
                        break;
                }
        }
}

/*
 * take an array of size n, sorted from 0 to n-1;
 * the last value at index n is free space;
 * insert the value passed in such a way that
 * it yields a sorted array of size n with no free space.
 */
void insert(int *array, int val, int n) {
        int i, j;

        /* find the place for insertion */
        for (i = 0; i < n; i++) {
                if (val < array[i]) {
                        /* place found at i */
                        /* make space for insertion (by shifting right) */
                        for (j = n; j > i; j--) {
                                array[j] = array[j - 1];
                        }
                        /* insert */
                        array[i] = val;
                }
        }
}
