#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_MODE 1
#define BUF_SIZE 101

int main()
{
	int n;
	scanf("%d", &n);
	char **s = malloc(sizeof(char *) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		s[i] = malloc(sizeof(char) * BUF_SIZE);
		memset(s[i], '\0', BUF_SIZE);
		scanf("%s", s[i]);
	}

	if (DEBUG_MODE)
		for (i = 0; i < n; i++)
		{
			printf("%s\n", s[i]);
			printf("strlen:%2lu\n", strlen(s[i]));
		}

	return 0;
}
