/*
Throwing an int is an easy solution. But exception handling is also object oriented and allows 
us to throw an object. 
In this exercise we will create an exception hierarchy with an ArrayException base class and 
an OutOfBoundsExceptionderived class as shown in Figure 3:

*/
#include <iostream>
#include "Shape.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "OutOfBoundsException.hpp"

using namespace std;

int main() {
	
	// Test with pointers to the parent class
	Array arr(4);
	Point first_p(12, 3.4);
	Point second_p(12, 3.2,1.2);

	// Some array initiations: 
	arr[0]= first_p; 
	arr[1]= second_p; 
 
	// Try block
	try{
		arr[6];
	}
	// Catch the specified error and use the GetMessage() member function: 
	// An OutOfBoundsException is an ArrayException, so OutOfBoundsException can be caught as ArrayException
	// and the correct overridden function is called
	catch(const ArrayException& oob){
		cout << oob.GetMessage() << endl; 
	}
	
	// Catch any other type of error: 
	catch(...){
		cout << "Error not pre-specified ocurred, please review your code."<<endl; 
	}

	
	return 0; 
}
