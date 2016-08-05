#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	char* time = (char *)malloc(10240 * sizeof(char));
	scanf("%s",time);

	if (strncmp("12", time, 2) == 0 && (time[8] == 'A')) /* special case 12:XX:XXAM */
	{
		time[0] = '0';
		time[1] = '0';
		time[8] = '\0';
	}

	else if (strncmp("12", time, 2) == 0 && (time[8] == 'P'))
	{
		time[8] = '\0';
	}

	else if (time[8] == 'A') /* general case AM */
	{
		time[8] = '\0';
	}

	else if (time[8] == 'P') /* general case PM */
	{
		time[0] += 1;
		time[1] += 2;
		time[8] = '\0';
		printf("%s", time);
		return 0;		
	}

	printf("%s", time);

	return 0;
}
