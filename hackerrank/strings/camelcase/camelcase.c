#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100000

int main()
{
	char s[BUF_SIZE];
	memset(s, '\0', BUF_SIZE);
	scanf("%s", s);

	int i, n;
	char c;

	n = 1;			/* we start at 1 */
	for (i = 0; ; i++)
	{
		if ((c = s[i]) == '\0')
			break;
		
		if (c >= 'A' && c <= 'Z')
			n++;
	}

	printf("%d", n);
	
	return 0;
}
