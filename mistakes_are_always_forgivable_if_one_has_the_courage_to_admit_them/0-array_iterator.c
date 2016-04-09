void array_iterator(int *arr, int n, void (*func_ptr)(int))
{
  int i;

  for (i = 0; i < n; i++)
  {
    (func_ptr)(arr[i]);
  }
}
