int string_to_integer(char *s)
{
  char sign;			/* keep track of negative signs */
  int n;			/* integer to return, unsigned */
  char flag;

  sign = 0;
  n = 0;
  flag = 0;

  while (*s != '\0' && (flag != 2))
    {
      if (*s == '-')
	{
	  sign = (sign + 1) % 2; 	/* 0 means positive, 1 means negative */
	  /* if (flag == 1) */
	  /*   flag = 2; */
	}

      if (*s >= '0' && *s <= '9')	/* if character is in [0-9] */
	{
	  flag = 1;
	  n = n * 10 - (int)(*s - '0'); /* make it part of the int */
	  if (n >= 0) 		/* reached limit */
	    return 0;		/* return 0 */
	}
      else if (flag) 		/* if flag is 1 */
	flag = 2;		/* set flag to 2 */
      s++;
    }

  if (n == -2147483648 && (sign == 0)) /* if output is 2147483648 */
    return 0;			       /* return 0 */

  if (sign) 			/* if negative */
    return n;			/* return negative */
  return -n;			/* otherwise, return positive */
}
