// Create two Point objects and calculate the distance between them.

// The copy constructor is not called since we passed the argument by reference in the distance function.
// If we had passed the argument by value, the copy constructor would have been called to create a copy of the Point object. 
// However, since we are passing a reference, no copy is made, and the original object is used directly.

#include "The_class_concept.hpp"
#include <iostream>
using namespace std;

int main() {
	// Declare the coordinates of the two points
	double x, y;

	// Get the coordinates of the first point from the user
	cout << "Enter the coordinates of the first point (x): "<< endl;
	cin >> x;
	cout << "Enter the coordinates of the first point (y): " << endl;
	cin >> y;

	// Create the first Point object
	Point p1(x, y);

	// Get the coordinates of the second point from the user
	cout << "Enter the coordinates of the second point (x): " << endl;
	cin >> x;
	cout << "Enter the coordinates of the second point (y): " << endl;
	cin >> y;

	// Create the second Point object
	Point p2(x, y);

	// Calculate and display the distance between the two points
	cout << "The distance between the two points is: " << p1.Distance(p2) << endl;
	return 0;
}