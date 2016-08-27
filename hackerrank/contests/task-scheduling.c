#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ABS(x) ((x)<0 ? -(x) : (x))
#define DEBUG_MODE 1

void task_scheduling(int n, int *d, int *m);

int main() {
	int n;
	scanf("%d", &n);
	int d[n];
	int m[n];

	for (int i = 0; i < n; i++)	/* input */
	{
		scanf("%d %d", &d[i], &m[i]);
	}

	task_scheduling(n, d, m);

	return 0;
}

void task_scheduling(int n, int *d, int *m)
{
	int i;
	int sum_prev = 0, sum_curr = 0;
	int maxmin_prev = 0, maxmin_curr = 0;
	int prev_res = 0, curr_res = 0;

	/*
	 * prev_res = sum_prev - maxmin_prev
	 * curr_res = sum_curr - maxmin_curr
         */

	for (i = 0; i < n; i++)
	{
		sum_curr += m[i];
		if (maxmin_curr < d[i]) /* get the biggest deadline */
			maxmin_curr = d[i];
		curr_res = sum_curr - maxmin_curr;
		if (m[i] - d[i] > prev_res) /* special case */
		{
			prev_res = m[i] - d[i];
		}
		if (m[i] > sum_curr)
		{
			
		}
		if (curr_res < prev_res) /* if curr result is less than a prev result */
		{
			if (DEBUG_MODE)
			{
				printf("%2d %2d: ", d[i], m[i]);
			}
			printf("%d\n", ABS(prev_res)); /* print prev result */
		}
		else
		{
			if (DEBUG_MODE)
			{
				printf("%2d %2d: ", d[i], m[i]);
			}
			printf("%d\n", ABS(sum_curr - maxmin_curr)); /* print the real sum */
			maxmin_prev = maxmin_curr; /* update prev */
			sum_prev = sum_curr;	   /* update prev */
			prev_res = (sum_prev - maxmin_prev); /* update prev */
		}
	}
}
