#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int a0; 
	int a1; 
	int a2; 
	scanf("%d %d %d",&a0,&a1,&a2);
	int b0; 
	int b1; 
	int b2; 
	scanf("%d %d %d",&b0,&b1,&b2);

	int A = 0; 			/* alice score */
	int B = 0;			/* bob score */

	if (a0 > b0)
		A++;
	else if (a0 < b0)
		B++;

	if (a1 > b1)
		A++;
	else if (a1 < b1)
		B++;

	if (a2 > b2)
		A++;
	else if (a2 < b2)
		B++;

	printf("%d %d", A, B);

	return 0;
}
