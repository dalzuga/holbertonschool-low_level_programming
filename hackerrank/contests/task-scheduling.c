#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ABS(x) ((x)<0 ? -(x) : (x))

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	scanf("%d", &n);
	int d[n];
	int m[n];
	int i;
	int j;
	int sum[n];
	int maxmin[n];

	for (i = 0; i < n; i++)	/* input */
	{
		scanf("%d %d", &d[i], &m[i]);
	}

	/* for (i = 0; i < n; i++)	/\* print input *\/ */
	/* { */
	/* 	printf("%d %d\n", d[i], m[i]); */
	/* } */

	printf("--------------------\n");

	for (j = 1; j <= n; j++)
	{
		sum[j] = 0;
		maxmin[j] = 0;

		for (i = 0; i < j; i++)
		{
			sum[j] += m[i];
			if (maxmin[j] < d[i])
				maxmin[j] = d[i];
			if ((sum[j] - maxmin[j]) < 0)
			{
				sum[j] = sum[j - 1];
				maxmin[j] = maxmin[j - 1];
			}
		}

		printf("%d\n", ABS(sum[j] - maxmin[j]));
	}

	return 0;
}
