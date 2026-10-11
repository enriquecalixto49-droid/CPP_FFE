#include "The_class_concept.hpp"
#include <iostream>
using namespace std;

int main() {
	Point center(8,9);
	center.ToString();
	cout << "X getter inlined: " << center.X() << endl;
	// Inlined setter:
	center.Y(78.2);
	return 0; 
}