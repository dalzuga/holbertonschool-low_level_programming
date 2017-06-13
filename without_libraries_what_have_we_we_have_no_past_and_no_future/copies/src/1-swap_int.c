void swap_int(int *a, int *b)
{
  int c; 			/* temporary value holder */
  c = *a;			/* c is now value pointed to by a */
  *a = *b;			/* value of of a changed to value of b */
  *b = c;			/* value of b changed to c (old a) */
}

