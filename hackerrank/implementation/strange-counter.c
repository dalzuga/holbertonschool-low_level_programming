#include <stdio.h>

#define INIT 3 			/* initial value at t = 1 */

int find_k(long int);

int main()
{
	long int t;
	scanf("%ld", &t);

	/* find k */
	int k = find_k(t);
	
	/* result = 3 * 2^(k+1) - 2 - t*/
	printf("%ld", 3 * (1 << (k + 1)) - 2 - t);

	return 0;
}

/*
 * starting at k = 0, increment k until the following equation is true:
 * t <= 3(2^(k+1) - 1)
 */
int find_k(long int t)
{
	int k;

	k = 0;
	while (t > (3 * ((1 << (k + 1)) - 1)))
	{
		k++;
	}

	return k;
}
