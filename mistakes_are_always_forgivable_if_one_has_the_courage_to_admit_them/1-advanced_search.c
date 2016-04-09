int advanced_search(int *arr, int n, int (*func_ptr)(int))
{
  int i;

  for (i = 0; i < n; i++)
  {
    if (func_ptr(arr[i]))
      return 1;
  }

  return -1;
}
