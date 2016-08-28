#include <stdio.h>
#include <math.h>

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
 * or, alternatively,
 * use the log2 function to solve the equivalent equation
 * (left as an exercise for the reader)
 */
int find_k(long int t)
{
	int k;

	k = (int) log2(1 + ((double) (t - 1) / 3));

	return k;
}
