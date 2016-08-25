#include <stdio.h>
#include <string.h>

#define DEBUG_MODE 0

void save_the_prisoner(int, int, int);

int main()
{
	int t;
	scanf("%d", &t);
	int n[t], s[t], m[t];

	memset(m, 0, t);
	
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &(n[i]), &(m[i]), &(s[i]));
	}

	for (int i = 0; i < t; i++)
	{
		save_the_prisoner(n[i], m[i], s[i]);
	}

	return 0;
}

/* 
 * n - # of prisoners
 * m - # of candies
 * s - starting prisoner
 */
void save_the_prisoner(int n, int m, int s)
{
	int res;

	res = (m - 1 + s - 1) % n + 1;

	if (DEBUG_MODE)
	{
		printf("-----params-----\n");
		printf("n =\t%d\n", n);
		printf("m =\t%d\n", m);
		printf("s =\t%d\n", s);
		printf("-----result-----\n");
	}

	printf("%d\n", res);
}
