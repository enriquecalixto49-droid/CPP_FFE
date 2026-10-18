// Header file containing macro definitions for printing and finding maximum values.

// Mechanism to avoid multiple inclusion of the header file. 
#ifndef DEFS_H
#define DEFS_H

// Include the stdio.h header to use printf
#include <stdio.h>

// Definition of Print1
#define PRINT1(a) printf("%s\n", (a))

// Definition of Print2
#define PRINT2(a, b) printf("%s%s\n",(a),(b))

// Definition of MAX2. We use a logical construction to perform the max function. 
#define MAX2(x,y) ((x)>(y)?(x):(y))

// Definition of MAX3. We use macro composition (one macro calling another) inside the logical construction to perform the max over 3 variables
#define MAX3(x,y,z) ((z)>MAX2(x,y)?(z):MAX2(x,y))

// End of the if not defined statement
#endif