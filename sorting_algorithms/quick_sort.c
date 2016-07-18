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
        l = r = -1;

        /* let's use the middle one, favoring the left if even */
        r = pivot = array[(size + 1) / 2 - 1];
        printf("PIVOT: %d\n", pivot);
        for (i = 0; i < (size + 1) / 2; i++) {
                /* find element >= to pivot from left */
                if (array[i] >= pivot)
                  {
                          l = i;
                          printf("Left\t: %d\n", array[l]);
                          break;
                  }
        }
        
        for (i = 0; i < size / 2 + 1; i++) {
                /* find element <= to pivot from right */
                if (array[size - i - 1] <= pivot)
                  {
                          r = size - i - 1;
                          printf("Right\t: %d\n", array[r]);
                          break;
                  }
        }

        if (l != -1 && r != -1)
          {
                  swap_and_continue(array, l, r, size);
          }
}

/* swap two array elements and continue the partition */
void swap_and_continue(int *array, int l, int r, __attribute__ ((unused)) int size) {
        int tmp;

        if (l != r) {
                printf("SWAP\n");
                tmp = array[l];
                array[l] = array[r];
                array[r] = tmp;
                /* partition(array, size); */
        }
}
