#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr;
        int **dp;

	ptr = NULL;

        dp = &ptr;

        printf("dp\naddr:\t%p\n", (void *) &dp);
        printf("value:\t%p\n", (void *) dp);
        printf("-----------------------\n");
        printf("ptr\naddr:\t%p\n", (void *) &(*dp));
        printf("value:\t%p\n", (void *) *dp);
        printf("-----------------------\n");
        printf("n\naddr:\t%p\n", (void *) &(**dp));
        printf("value:\t%d\n", **dp);

        return 0;
}
