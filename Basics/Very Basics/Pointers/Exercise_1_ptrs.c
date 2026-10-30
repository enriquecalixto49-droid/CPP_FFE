// Swap two integers using pointers

#include <stdio.h>

void Swap(int *dir_i, int *dir_j){
	// Function that swaps the values of two integers using pointers
	// dir_i: pointer to the first integer
	// dir_j: pointer to the second integer

	// Create a temporary variable to hold the value of the first integer
	int temp;

	// Swap the values of the two integers using the temporary variable
	temp = *dir_i;

	// Assign the value of the second integer to the first integer
	*dir_i = *dir_j;

	// Assign the value of the temporary variable (original value of the first integer) to the second integer
	*dir_j = temp;
}

int main(){
	// Declare two integer variables and initialize them with values
	int i = 123;
	int j = 456;
	
	// Print the values of the two integers before swapping
	printf("Before swapping:\n");
	printf("This is i: %d\n",i);
	printf("This is j: %d\n",j);
	
	printf("After swapping:\n");
	Swap(&i,&j);
	printf("This is i swaped: %d\n",i);
	printf("This is j swaped: %d\n",j);
	return 0;
}