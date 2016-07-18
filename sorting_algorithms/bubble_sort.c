void bubble_sort(int *array, int n)
{
        int i, tmp;

        for (i = 0; i < (n - 1); i++) {
                if (array[i + 1] < array[i]) {
                        tmp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = tmp;
                }
        }

        /* now do recursion with the last one left alone */
        if (n > 1)
                bubble_sort(array, n - 1);
}
