#include <stdio.h>
#include <stdlib.h>

int main()
{
        int **dp;

        dp = malloc(sizeof(void *));
        *dp = malloc(sizeof(void *));
        /* **dp = malloc(sizeof(int)); */
        **dp = 10;

        printf("double pointer address\nhex:\t%p\n", &dp);
        printf("-----------------------\n");
        printf("intermediate pointer address\nhex:\t%p\n", dp);
        printf("-----------------------\n");
        printf("address of the int\nhex:\t%p\n", *dp);
        printf("-----------------------\n");
        printf("value of int\nint:\t%d\n", **dp);
}

