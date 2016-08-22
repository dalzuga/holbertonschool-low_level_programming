#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ABS(x) ((x)<0 ? -(x) : (x))

int main() {
	int n;
	scanf("%d", &n);
	int d[n];
	int m[n];
	int i;
	int sum_prev, sum_curr;
	int maxmin_prev, maxmin_curr;

	for (i = 0; i < n; i++)	/* input */
	{
		scanf("%d %d", &d[i], &m[i]);
	}

	sum_prev = sum_curr = maxmin_prev = maxmin_curr = 0;

	for (i = 0; i < n; i++)
	{
		sum_curr += m[i];
		if (maxmin_curr < d[i]) /* get the biggest deadline */
			maxmin_curr = d[i];
		if (sum_curr < maxmin_curr)
		{
			/* printf("trippin the flag\n"); */
			sum_curr = sum_prev;
			maxmin_curr = maxmin_prev;
		}

		/* if (34 < i && i < 50) */
		/* { */
			/* printf("--------------line %d----------\n", i); */
			/* printf("sum_curr:\t%d\n", sum_curr); */
			/* printf("m[%d]:\t%d\n", i, m[i]); */
			printf("%d\n", ABS(sum_curr - maxmin_curr));
		/* } */

		maxmin_prev = maxmin_curr;
		sum_prev = sum_curr;
	}

	return 0;
}
