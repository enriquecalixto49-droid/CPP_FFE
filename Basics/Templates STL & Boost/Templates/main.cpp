/*
Test of the Array template

*/
#include <iostream>
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Array.cpp"
#include "OutOfBoundsException.hpp"

using namespace std;

int main() {
	// 
	int p_size, l_size;
	cout << "Enter the size of points array: "; 
	cin >> p_size; 
	cout << "Enter the size of lines array: ";
	cin >> l_size; 
	
	Array<Point> points(p_size); 
	Array<Line> lines(l_size);

	cout << points << endl;
	cout << lines << endl; 

	/*
	Tip: by placing the following code at the end of the array header file, but before the header 
    file’s #endif, the client can keep including the header file for template classes instead of the 
    source file. 
        #ifndef Array_cpp      
        #include "Array.cpp" 
        #endif
	
	Can you explain how this works?: 
	
	Template definitions must be visible to the compiler whenever a template is instantiated. Now when a client writes #include "Array.hpp"
	the preprocessor expands it so the compiler sees both declaration and implementation. If the source file is not included in the header, 
	the definitions are not visible to the compiler for templates (don't work as for classes).
	*/
	return 0; 
}
