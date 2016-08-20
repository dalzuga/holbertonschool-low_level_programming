#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int maximal_sprime(int *arr, int size);
int count_positive_elements(int *arr, int size);

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n, k, i, j, count_pairs, count_freq;
	scanf("%d %d", &n, &k);
	int arr[n];

	count_pairs = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &(arr[i]));
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (i == j)
			{}
			else if ((arr[i] + arr[j]) % k == 0)
			{
				printf("(%d, %d)\n", arr[i], arr[j]);
				count_pairs++;
			}
		}
	}

	printf("count_pairs: %d\n", count_pairs);

	count_freq = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{}
			else if ((arr[i] + arr[j]) % k == 0)
			{
				count_freq++;
			}
		}
		printf("%d appears %d times.\n", arr[i], count_freq);
		count_freq = 0;
	}

	return (0);
}

int maximal_sprime(int *arr, int size)
{
	int a;

	a = count_positive_elements(arr, size);
	return a;
}

int count_positive_elements(int *arr, int size)
{
	int i, count;

	for (i = 0; i < size; i++)
	{
		if (arr[i] > 0)
			count++;
	}

	return count;
}
