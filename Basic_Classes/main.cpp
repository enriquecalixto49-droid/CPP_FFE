/*
	Test namespaces -> for compiling and running, just leave the number related code without comment and comment the rest. 
	1. In the main program, the full namespace for Point class
	2. In the main program, using declaration for using a single class (Line).
	3. In the main program, using declaration for a complete namespace (Containers).
	4. In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.
*/

#include <iostream>
#include "Array.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace std;

// 2. In the main program, using declaration for using a single class (Line).
// 2. using Enrique::CAD::Line;

// 3. In the main program, using declaration for a complete namespace (Containers).
// 3. using namespace Enrique::Container;

// 4. In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.
// 4. namespace CAD = Enrique::CAD;

int main() {
	// 1. In the main program, the full namespace for Point class
	// 1. Enrique::CAD::Point p(1.0, 4.5);
	// 1. cout << p << endl;

	// 2. In the main program, using declaration for using a single class (Line).
	// 2. Line l;
	// 2. cout << l << endl;
	
	// 3. In the main program, using declaration for a complete namespace (Containers).
	// 3. Array arr;
	// 3. cout << arr << endl; 

	// 4. In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.
	// 4. CAD::Circle c;
	// 4. cout << c << endl; 
	return 0;
}
