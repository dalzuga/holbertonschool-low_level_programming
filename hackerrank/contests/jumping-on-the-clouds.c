#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int parity_int(int n);
int opposite_parity(int n);

int main(){
	int n; 
	scanf("%d",&n);
	int *c = malloc(sizeof(int) * n);
	for(int c_i = 0; c_i < n; c_i++){
		scanf("%d",&c[c_i]);
	}

	int par = 0;	/* parity, initialized to 0 */
	int i;
	int count = 0;		/* hops */

	for (i = 4; i < n && c[i] != 0; i++)
	{
		if (parity_int(i) == par)
		{
			count++;
			par = opposite_parity(par);
		}
	}

	if ((count > 0) && (parity_int(n) == 0)) /* if n is even forgive 1 count */
		count--;

	printf("%d", n / 2 + count);	/* (n / 2) is the lower bound */
	return 0;
}

/* returns 0 if even, 1 if odd */
int parity_int(int n)
{
	return n % 2;
}

int opposite_parity(int n)
{
	return (n + 1) % 2;
}
