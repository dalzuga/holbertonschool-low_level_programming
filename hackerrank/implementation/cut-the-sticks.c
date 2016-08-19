#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

int find_smallest(int *arr, int n);
int find_greatest(int *arr, int n);
void print_array(int *arr, int n);

int main(){
	int n, i, tmp, count;
	scanf("%d",&n);
	int arr[n];
	for(int arr_i = 0; arr_i < n; arr_i++){
		scanf("%d",&arr[arr_i]);
	}

	tmp = find_smallest(arr, n);

	while (tmp > 0)
	{
		/* print_array(arr, n); */
		tmp = find_smallest(arr, n);
		count = 0;	/* counts the cuts */

		for (i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				arr[i] -= tmp;
				count++;
			}
		}

		if (count > 0)
			printf("%d\n", count);
	}

	return (EXIT_SUCCESS);
}

/* returns 0 if no sticks are left */
int find_smallest(int *arr, int n)
{
	int i, ret;

	ret = find_greatest(arr, n);

	for (i = 0; i < n; i++)
	{
		if (arr[i] != 0 && arr[i] < ret)
		{
			ret = arr[i];
		}
	}

	return (ret);
}

int find_greatest(int *arr, int n)
{
	int i, ret;

	ret = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > ret)
		{
			ret = arr[i];
		}
	}

	return ret;
}

void print_array(int *arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}
