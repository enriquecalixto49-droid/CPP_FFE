// main file to test the Circle class
#include "The_class_concept.hpp"
#include <iostream>
using namespace std;

int main() {
	// Create a Point object for the center of the circle
	Point center(8,9);
	
	// Create a Circle object with the center point and a radius
	double radius;
	cout << "Enter the radius: ";
	cin >> radius;
	Circle ccl(center, radius);

	// Display the circle's information
	ccl.ToString();

	// Display the calculated properties of the circle
	cout << "The Diameter is: " << ccl.Diameter() << endl; 
	cout << "The circumference is: " << ccl.Circumference() << endl;
	cout << "The Area is: " << ccl.Area() << endl; 
	return 0; 
}