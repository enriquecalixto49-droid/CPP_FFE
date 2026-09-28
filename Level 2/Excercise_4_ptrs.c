// This program asks the user for a day of the week as an integer (1-7) and prints the corresponding day name using an array of strings.

#include <stdio.h> 

// If an array of pointers -> char *week_days[]
void DayName(char week_days[][10]){
	// Ask the user for the day of the week as an integer
	int day;
	printf("Enter your day of the week as an integer (1-7): ");
	scanf_s("%d",&day);
	
	// Check if the input is valid
	if(day>7 || day<1){
		printf("Incorrect number. Please enter a number from 1 to 7");
		return;
	} 
	// To take into account the fact that indexing starts by 0;
	--day;
	printf("Your day of the week is: %s", week_days[day]);
}

int main(){
	char week[][10] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	// Solution for an array of pointers to strings instead of an array of strings :
	// char *week[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	DayName(week);
}