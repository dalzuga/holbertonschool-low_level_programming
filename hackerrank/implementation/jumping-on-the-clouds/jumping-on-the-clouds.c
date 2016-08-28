#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define DEBUG_MODE 0

int is_odd(int);

int main(){
	int n; 
	scanf("%d",&n);
	int *c = malloc(sizeof(int) * n);
	for(int c_i = 0; c_i < n; c_i++){
		scanf("%d",&c[c_i]);
	}

	/* if (DEBUG_MODE) */
	/* 	printf("lower bound: %d\n", n / 2); */

	int count = 0;

	for (int i = 0; i < n - 1;) /* (n / 2) is the lower bound */
	{
		/* if (i == (n - 1))	/\* reached the end *\/ */
		/* { */
		/* 	if (DEBUG_MODE) */
		/* 		printf("end\n"); */
		/* 	break; */
		/* } */

		if ((i + 2 <= n - 1) && c[i + 2] == 0) /* jump two at a time */
		{
			i += 2;
			count++;
			if (DEBUG_MODE)
				printf("jump by two\n");
		}
		else		/* jump one at a time */
		{
			i++;
			count++;
			if (DEBUG_MODE)
				printf("jump by one\n");
		}
	}

	printf("%d", count);

	return 0;
}

/* returns 0 if even, 1 if odd */
int is_odd(int n)
{
	return n % 2;
}
