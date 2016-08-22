#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	scanf("%d", &n);
	int d[n];
	int m[n];
	int i;

	for (i = 0; i < n; i++)	/* input */
	{
		scanf("%d %d", &d[i], &m[i]);
	}

	for (i = 0; i < n; i++)	/* print input */
	{
		printf("%d %d\n", d[i], m[i]);
	}

	for (i = 0; i < n; i++)
	{
		
	}

	return 0;
}
