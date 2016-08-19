#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int maximal_sprime(int *arr, int size);
int count_positive_elements(int *arr, int size);

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int *arr;
	int n, k, i, j;

	scanf("%d", n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &(arr[i]));
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			
		}
	}

	return (0);
}

int maximal_sprime(int *arr, int size)
{
	int i, j, k;
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
