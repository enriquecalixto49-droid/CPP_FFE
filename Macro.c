// This program demonstrates the use of macros defined in a header file to print with print1 and print2.

#include "Defs.h"
#include <stdio.h>
int main(){
	// Declare variables a and b: 
	char a[100];
	char b[100];
	
	// Retrieve variables a and b from the user: 
	printf("Give me the character a: \n");
	fgets(a, 100, stdin);
	printf("Give me the character b: \n");
	fgets(b, 100, stdin);
	
	// Call the functions defined as Macros in the header file: 
	printf("Output from PRINT1: \n");
	PRINT1(a);
	printf("Output from PRINT2: \n");
	PRINT2(a,b);
	
	return 0;
}