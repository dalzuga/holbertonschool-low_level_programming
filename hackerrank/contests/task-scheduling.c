#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ABS(x) ((x)<0 ? -(x) : (x))
#define LINE 0

int main() {
	int n;
	scanf("%d", &n);
	int d[n];
	int m[n];
	int i;
	int sum_prev, sum_curr;
	int maxmin_prev, maxmin_curr;
	char flag;

	for (i = 0; i < n; i++)	/* input */
	{
		scanf("%d %d", &d[i], &m[i]);
	}

	flag = sum_prev = sum_curr = maxmin_prev = maxmin_curr = 0;

	for (i = 0; i < n; i++)
	{
		sum_curr += m[i];
		if (maxmin_curr < d[i]) /* get the biggest deadline */
			maxmin_curr = d[i];
		if (sum_curr < maxmin_curr)
		{
			printf("TRIP\n");
			flag = 1;
		}

		/* printf("--------------line %d----------\n", i); */
		/* printf("sum_curr:\t%d\n", sum_curr); */
		/* printf("m[%d]:\t%d\n", i, m[i]); */
		printf("\t");
		if (flag == 0)	/* never tripped */
		{
			printf("%d\n", ABS(sum_curr - maxmin_curr));
			maxmin_prev = maxmin_curr;
			sum_prev = sum_curr;
		}
		else if (flag == 1) /* tripped once */
		{
			printf("%d\n", ABS(sum_prev - maxmin_prev));
			printf("UNTRIP\n");
			flag = 2;
		}
		else if (flag == 2) /* tripped more than once */
		{
			printf("%d\n", ABS(sum_curr - maxmin_curr));
			maxmin_prev = maxmin_curr;
			sum_prev = sum_curr;
		}
	}

	return 0;
}
