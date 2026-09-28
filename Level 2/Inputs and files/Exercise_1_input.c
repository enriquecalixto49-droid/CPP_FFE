/*
File to exercise the input of characters in C. The program will read a line of characters and print it back to the console. The program will finish when the user presses CTRL + A or (Enter and Ctrl+Z)-> EOF.
Windows console does not allow to read the input of characters without echoing them, so we disable the echoing of characters in the console. 
The program will allocate memory for the line of characters dynamically, so it can handle lines of any length. 
The program will also free the allocated memory at the end. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Function to disable echoing of input characters in Windows console
void disable_echo() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode &= ~ENABLE_ECHO_INPUT;   // turn off echo
    SetConsoleMode(hStdin, mode);
}

// Function to enable echoing of input characters in Windows console
void enable_echo() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode |= ENABLE_ECHO_INPUT;    // turn echo back on
    SetConsoleMode(hStdin, mode);
}

//Set the initial memory size of the characters' line.
#define INITIAL_SIZE 10	

void print_buffer(int i, char *buffer){
	/*
		Function to print the buffer
	*/
	for(int j=0; j<i;j++){
			putchar(buffer[j]);
		}
		putchar('\n');
}

int main(){
	// Declare the variables
	int c; 
	int i = 0;
	int size = INITIAL_SIZE; 
	
	// Since we don't know in advance the size of the characters of the line, we allocate some space in the heap memory.
	char *buffer = malloc(size * sizeof(char));
	
	printf("Please enter a line of characters. Press CTRL + A to finish the input.\n");
	disable_echo(); // Disable echoing of input characters
	// Initialize the while loop until EOF. 
	while((c = getchar())!= EOF){
		// We control if the char input is CTRL+A.
		if(c==1){
			// Control in case the user wrote a new line and pressed CTRL+A without pressing enter before: 
			if(i>0){
				print_buffer(i, buffer);
			}
			printf("\nCTRL + A is a correct ending.\n");
			break;
		
		// We control if the line ended. The usefulness here is to add each character to the buffer to be printed afterwards. 
		}else if(c != '\n' ){
			// If the number of characters enter surpassed the current size allocated in the memory, we allocate the double of memory to the buffer
			if (i>=size){
				size *=2;
				buffer = realloc(buffer, size * sizeof(char));
			}
			buffer[i++] = c;
		
		// In this case, a new line started, so we print the input. 		
		}else{
			print_buffer(i, buffer);
			// We reinitialise the buffer index
			i=0;
		}
		
	}
	enable_echo(); // Enable echoing of input characters
	
	// We free-up all the memory allocated to the buffer of characters. 
	free(buffer);
	return 0;
}