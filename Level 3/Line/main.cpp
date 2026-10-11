// Main program to test some line functionality.
#include "The_class_concept.hpp"
#include <iostream>
using namespace std;

int main() {
	// Create two points and a line connecting them
	Point p1(10.24,13.98), p2(12.34, 19.32);
	Line myline(p1, p2);
	/*
	Create a read-only reference to the starting point of the line called random_point.

		const Point& ... = myline.getter() doesn't create new point objects, so the constructor will not be called. 
		Instead, we create read_only copies of the points which we cannot modify (const). 
		If we try random_point.X(23043.912), the compiler would return an error.
	*/
	const Point& random_point = myline.P1();
	
	// Print the coordinates of the starting point of the line using the read-only reference random_point
	cout << random_point.X() << endl;
	cout << random_point.Y() << endl;
	
	// Print the coordinates of the ending point of the line using the read-only reference another_point
	const Point& another_point = myline.P2();
	cout << another_point.X() << endl;
	cout << another_point.Y() << endl;
	
	// Print the string representation of the line and its length
	cout << myline.ToString() << endl;
	
	// Print the length of the line
	cout << "The length of my line is: " << myline.Length() << endl; 
	return 0; 
}