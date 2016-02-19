#include <stdio.h>
int main()
{  unsigned long int a, b, c;  int i;  a=1, b=2, i=2;
  /* first two fibonacci numbers */
  printf("%lu, %lu, ", a, b); 	/* print the first two */
  while (1) 			/* keep running */
    { i++; /* keep going until 92nd */
      c=a+b;
      if (i==92) 		/* 92nd Fibonacci n (starting with 1, 2) */
	{
	  printf("%lu, ", c); 	/* no space, no comma */
	  printf("19740274219868223167, 31940434634990099905, 51680708854858323072,");
	  printf(" 83621143489848422977, 135301852344706746049, ");
	  printf("218922995834555169026, 354224848179261915075, ");
	  printf("573147844013817084101\n");
	  return 0;		/* break */
	}
      printf("%lu, ", c); a=b; b=c;
    }
}
