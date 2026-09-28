/*
Extends the previous exercise to allow the user to input a line of characters and store it in a file. 
The program will ask the user for the output file path (to open or create a file) and then read characters from the standard input until the user presses CTRL + A (ASCII code 1). 
The program will store the characters in a dynamically allocated buffer and write them to the specified output file. 
The program will also handle memory allocation and deallocation properly.
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


void print_buffer(int i, char *buffer, FILE *of){
	/*
		Function to print the buffer
	*/
	for(int j=0; j<i;j++){
			fputc(buffer[j], of);
		}
		// fprintf(of, buffer); -> fprintf would be better for a whole string, but the exercise 1 demanded character by character.
		fputc('\n', of);
}

int main(){
	// Declare the variables
	int c; 
	int i = 0;
	int size = INITIAL_SIZE; 
	
	// Since we don't know in advance the size of the characters of the line, we allocate some space in the heap memory.
	char *buffer = malloc(size * sizeof(char));
	
	// We allocate up to 250 characters for the output path (should be enough). 
	char *output_file = malloc(250 *sizeof(char)); 
	
	// We ask the user for the output path (open or create file).
	printf("Enter the output path (open or create file): \n");
	fgets(output_file,250, stdin);

	// We remove the newline character from the output file path if it exists.
	output_file[strcspn(output_file, "\n")] = '\0';
	
	// We open the output file in write mode. If it doesn't exist, it will be created.
	FILE *of = fopen(output_file,"w");

	// We control if the file was opened/created successfully.
	if(!of){
		printf("Error opening/creating the output file.\n");
		free(buffer);
		free(output_file);
		return 1;
	}
	printf("Output file created/opened successfully.\n");

	// We inform the user about the input method.
	printf("Please enter a line of characters. Press CTRL + A to finish the input.\n");
	disable_echo(); // Disable echoing of input characters
	// Initialize the while loop until EOF. 
	while((c = getchar())!= EOF){
		// We control if the char input is CTRL+A.
		if(c==1){
			// Control in case the user wrote a new line and pressed CTRL+A without pressing enter before: 
			if(i>0){
				print_buffer(i, buffer, of);
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
			print_buffer(i, buffer, of);
			// We reinitialise the buffer index.
			i=0;
		}
	}
	
	enable_echo(); // Enable echoing of input characters
	// We free-up all the memory allocated to the buffer of characters. 
	free(buffer);
	fclose(of);
	free(output_file);
	return 0;

}