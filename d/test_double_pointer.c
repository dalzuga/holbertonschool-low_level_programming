#include <stdio.h>
#include <stdlib.h>

int main()
{
        int **dp;

        dp = malloc(sizeof(void *));
        *dp = malloc(sizeof(void *));
        /* the below malloc is done automatically */
        /* **dp = malloc(sizeof(int)); */
        **dp = 10;

        printf("double pointer address\nhex:\t%p\n", (void *) &dp);
        printf("double pointer value\nhex:\t%p\n", (void *) dp);
        printf("-----------------------\n");
        printf("intermediate pointer address\nhex:\t%p\n", (void *) &*dp);
        printf("intermediate pointer value\nhex:\t%p\n", (void *) *dp);
        printf("-----------------------\n");
        printf("address of the int\nhex:\t%p\n", (void *) &**dp);
        printf("value of the int\nint:\t%d\n", **dp);

        return 0;
}
