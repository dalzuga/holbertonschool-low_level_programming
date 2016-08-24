#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int n; 
	scanf("%d",&n);
	int *c = malloc(sizeof(int) * n);
	for(int c_i = 0; c_i < n; c_i++){
		scanf("%d",&c[c_i]);
	}

	int even;
	int i;
	int count;		/* change in parity */
	for (i = 0, count = 0, even = 0; i < n; i++)
	{
		if ((c[i] == 1) && ((i % 2) == even))
		{
			count++;
			even = (even + 1) % 2;
			/* printf("count:\t%d\t%d\n", count, i); */
			/* printf("even:\t%d\n", even); */
		}
	}

	if (count > 0 && ((n % 2) == 0))
	    count--;

	/* printf("n:\t%d\n", n); */
	printf("%d", n / 2 + count);	/* n/2 is the lower bound */
	return 0;
}

