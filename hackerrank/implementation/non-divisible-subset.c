#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int maximal_sprime(int *arr, int size);
int count_positive_elements(int *arr, int size);

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n, k, i;
	scanf("%d %d", &n, &k);
	int arr[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &(arr[i]));
	}
	
        for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", arr[i] % k);
	}
	printf("\n");

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
