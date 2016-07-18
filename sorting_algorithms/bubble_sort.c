void bubble_sort(__attribute__ ((unused)) int *array, __attribute__ ((unused)) int n)
{
        int i, tmp;

        for (i = 0; i < n; i++) {
                if (array[i + 1] < array[i]) {
                        tmp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = tmp;
                }
        }
}
