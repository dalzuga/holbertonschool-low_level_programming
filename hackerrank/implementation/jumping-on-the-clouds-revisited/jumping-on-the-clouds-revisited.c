#include <stdio.h>
#include <stdlib.h>

#define DEBUG_MODE 0

void jumping_on_the_clouds(int, int, int *);

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int *c = malloc(sizeof(char) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}

	if (DEBUG_MODE == 1)
		for (i = 0; i < n; i++)
		{
			printf("%d", c[i]);
			if (i != n - 1)
				printf(" ");
			else
				printf("\n");
		}

	jumping_on_the_clouds(n, k, c);

	return 0;
}

void jumping_on_the_clouds(int n, int k, int *c)
{
	int energy = 100;

	for (int i = 1; i < n / k; i++)
	{
		if (c[i * k] == 0)
		{
			energy--;
			printf("down by 1\n");
		}
		else
		{
			energy -= 2;
			printf("down by 2\n");
		}
		printf("i*k = %d\n", i * k);
	}

	printf("%d", energy);
}
