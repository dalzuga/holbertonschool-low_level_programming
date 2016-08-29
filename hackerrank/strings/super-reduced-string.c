#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 100

void super_reduced_string(char *s);
void delete_pair(char *s, int i);

int main()
{
	char s[BUF_SIZE];

	scanf("%s", s);

	super_reduced_string(s);

	return 0;
}

void super_reduced_string(char *s)
{
	int i, j;
	int len = strlen(s);

	for (j = 0; j < len; j++)
	{
		for (i = 0; i < len; i++)
		{
			if (s[i] == s[i + 1])
			{
				delete_pair(s, i);
				break;
			}
		}
	}

	if (s[0] == '\0')
		printf("Empty String");
	else
		printf("%s", s);
}

/*
 * deletes pair of characters
 * at s[i] and s[i + 1]
 * from string s
 */
void delete_pair(char *s, int i)
{
	int len = strlen(s);

	for (; i < len; i++)
	{
		s[i] = s[i + 2];
	}
}
