#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int n; 
	scanf("%d",&n);
	int arr[n];
	for(int arr_i = 0; arr_i < n; arr_i++){
		scanf("%d",&arr[arr_i]);
	}

	int sum_positive = 0, sum_negative = 0, sum_zero = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
			sum_positive++;
		if (arr[i] < 0)
			sum_negative++;
		if (arr[i] == 0)
			sum_zero++;
	}

	float positive = sum_positive / (float) n;

	printf("%f\n", positive);

	float negative = sum_negative / (float) n;

	printf("%f\n", negative);

	float zero = sum_zero / (float) n;

	printf("%f\n", zero);

	return 0;
}
