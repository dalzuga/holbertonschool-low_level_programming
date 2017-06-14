void print_array(int *a, int n);

void reverse_array(int *a, int n)
{
  int i, basket; 		/* counter and int holder */
  
  for (i = 0; i < n/2; i++) /* split array in 2 */
    {
      basket = a[i]; 		/* hold left integer */
      a[i] = a[n - i - 1]; 	/* copy right to left */
      a[n - i - 1] = basket;	/* put integer back, into right */
    }
}
