#include <stdio.h>
void partition(int *, int);
void swap_and_continue(int *, int, int, int);

/* sort an array using quick-sort algorithm */
void quick_sort(int *array, int size)
{
        if (size > 1) {
                partition(array, size);
        }
}

/* partition the elements */
void partition(int *array, int size)
{
        int i, pivot, l, r;
        l = -1;

         /* let's use the middle one, favoring the left if even */
        r = pivot = array[(size + 1) / 2 - 1];

        for (i = 0; i < (size + 1) / 2; i++) {
                /* find element >= to pivot from left */
                if (array[i] >= pivot && l == -1)
                        l = i;
        }
        
        for (i = 0; i < (size + 1) / 2; i++) {
                /* find element < to pivot from right */
                if (array[size - i] < pivot)
                        r = size - i - 1;
        }

        if (l != -1)
                swap_and_continue(array, l, r, size);
}

/* swap two array elements and continue the partition */
void swap_and_continue(int *array, int l, int r, __attribute__ ((unused)) int size) {
        int tmp;
        tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
}
