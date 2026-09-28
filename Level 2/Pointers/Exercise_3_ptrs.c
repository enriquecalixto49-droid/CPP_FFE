 
/* Predict what will be printed on the screen */ 
 
#include <stdio.h> 
 
#define PRD(a) printf("%d", (a) )  // Print decimal 
#define NL  printf("\n");  // Print new line 
 
// Create and initialse array 
int a[]={0, 1, 2, 3, 4}; 
 
int main() 
{ 
	int i; 
	int* p; 
	
	for (i=0; i<=4; i++) PRD(a[i]);    // 1 Prints 01234 and one new line is created.
		NL; 
	
	for (p=&a[0]; p<=&a[4]; p++) PRD(*p);   // 2 Prints 01234 and two new lines are created.
		NL; 
		NL; 
		
	for (p=&a[0], i=0; i<=4; i++) PRD(p[i]);  // 3 Prints 01234 and one new line is created.
		NL; 
	
	for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // 4 Prints 024 since both p and i increments (not just i), and 2 new lines are created
		NL; 
		NL; 
	
	for (p=a+4; p>=a; p--) PRD(*p);    // 5 Prints 43210 and one new line
		NL; 
	
	for (p=a+4, i=0; i<=4; i++) PRD(p[-i]);   // 6 Prints 43210 and one new line
		NL; 
	
	for (p=a+4; p>=a; p--) PRD(a[p-a]);   // 7 Prints 43210 and one new line
		NL; 
	
	return 0; 
} 
