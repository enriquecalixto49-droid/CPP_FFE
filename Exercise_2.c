// Print the maximum of 2 and 3 numbers using macros defined in a header file

#include <stdio.h>
#include "Defs.h"

int main(){
	// Declare the variables
	int x,y,z;
	int max_res2, max_res3; 
	
	// Demand the variables to the user
	printf("Give me x: ");
	scanf_s("%d", &x);
	printf("Give me y: ");
	scanf_s("%d", &y);
	printf("Give me z: ");
	scanf_s("%d", &z);
	
	// Call the max functions declared in the header file as macros
	max_res2 = MAX2(x,y);
	max_res3 = MAX3(x,y,z);
	
	// Print the results
	printf("The results are: \n");
	printf("Max 2: %d\n", max_res2);
	printf("Max 3: %d\n", max_res3);
	return 0;
}