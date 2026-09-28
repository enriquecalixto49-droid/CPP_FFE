/* Calculate the length of a string */ 
#include <stdio.h> 
#define MAXLINE 30 
// String lenght declaration 
int Length(char str[]); 
int main(){ 
	char string[MAXLINE+1]; // Line of maxium 30 chars + \0 
	int c;    
	// The input character 
	int i=0;    
	// Print intro text 
	// The counter 
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE); 
	// Get the characters 
	while ((c=getchar())!=EOF && i<MAXLINE){ 
		// Append entered character to string 
		string[i++]=(char)c; 
		} 
	string[i]='\0';  
	// String must be closed with \0 
	printf("String length is %d\n", Length(string)); 
	return 0; 
} 
/* Implement the Length() function here */ 
int Length(char str[]){
	// Initiliaze the index of the string 
	int len = 0;
	int line_breaks = 0;
	// Count the number of characters while the character is not \0. 
	// When we write char str[] = "Hello"; the compiler actually creates | H | e | l | l | o | \0 |
	while(str[len]!='\0'){
		// Count the number of line breaks in the string
		if(str[len]=='\n'){
			line_breaks++;
			len++;
			continue;
		}
		len++;
	}
	// Return the length of the string without line breaks
	return len - line_breaks;
}