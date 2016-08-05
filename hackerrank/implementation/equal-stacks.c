#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int n1; 
	int n2; 
	int n3; 
	scanf("%d %d %d",&n1,&n2,&n3);
	int *h1 = malloc(sizeof(int) * n1);
	for(int h1_i = 0; h1_i < n1; h1_i++){
		scanf("%d",&h1[h1_i]);
	}
	int *h2 = malloc(sizeof(int) * n2);
	for(int h2_i = 0; h2_i < n2; h2_i++){
		scanf("%d",&h2[h2_i]);
	}
	int *h3 = malloc(sizeof(int) * n3);
	for(int h3_i = 0; h3_i < n3; h3_i++){
		scanf("%d",&h3[h3_i]);
	}
	return 0;
}
