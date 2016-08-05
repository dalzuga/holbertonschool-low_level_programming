#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n, k, q;
	
	scanf("%d %d %d", &n, &k, &q);

	int arr[n], qry[q];
	scanf("%d", &(arr[0]));
	for (int i = 1; i < n; i++)
	{
		scanf(" %d", &(arr[i]));
	}

	for (int i = 0; i < q; i++) /* get query array */
	{
		scanf("%d", &(qry[i]));
	}

	for (int i = 0; i < q; i++) /* print result */
	{
		printf("%d\n", arr[(qry[i] - (k % n) + n) % n]);
	}	

	return 0;
}
