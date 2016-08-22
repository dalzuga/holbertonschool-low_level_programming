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
	
	int arr2[n];
	memset(arr2, 0, n * sizeof(int));

	printf("%d", arr[0] % k);
	arr2[arr[0] % k]++;
        for (i = 1; i < n; i++)
	{
		printf(" %d", arr[i] % k);
		arr2[arr[i] % k]++;
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		if (arr2[i] != 0)
			printf("arr2[%d] = %d\n", i, arr2[i]);
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
