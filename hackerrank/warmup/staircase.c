#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int n; 
	scanf("%d",&n);

	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

		       int main(){
			     int n;
			     scanf("%d",&n);

			     int i, j;

			     for (i = 1; i <= n; i++)
			     {
				     for (j = 1; j <= n - i; j++) /* print spaces */
					     printf(" ");

				     for (j = 1; j <= i; j++) /* print hash character */
					     printf("#");
				     printf("\n");
			     }

			     return 0;
		     } - i; j++) /* print spaces */
			printf(" ");

		for (j = 1; j <= i; j++) /* print hash character */
			printf("#");
		printf("\n");
	}

	return 0;
}
