/*
	• Create an array of Point pointers with 3 elements on the heap. 
	• Create for each element in the array a point on the heap. 
	• Iterate the array and print each point in the array. 
	• Iterate the array again and delete each point in the array. 
	• Delete the array itself. 
*/
#include "Point.hpp"

#include <iostream>
using namespace std;

int main() {
	/*
		If we were to create an array of points, there is just one level of allocation (A single block of memory is allocated containing 3 Point objects next to each other): 
			Point* points = new Point[3];

			points[0] = Point(1.0, 2.0);
			points[1] = Point(3.0, 4.0);
			points[2] = Point(5.0, 6.0);
	
	points 
	   | 
	   v 
	+---------+---------+---------+ 
	| Point 0 | Point 1 | Point 2 | 
	+---------+---------+---------+

	The dellocation is simpler since there is just one dellocation: delete[] points;
	Access to each point methods is simpler as well: points[0].X()
	*/ 



	// Create an array of Point pointers with 3 elements on the heap. 
	int len = 3; 
	/*
		There are actually two levels of allocation:
			1- An array of pointers: new Point*[size]
			2- One Point object for each pointer: new Point(...)
	
	We do have to dellocate each point from the memory, and then the array of pointers.
	To access each point method, we do have to use the pointer notation: p_array->X()
	*/
	Point** p_array = new Point*[len];
	cout << "Memory allocated for the array" << endl; 

	// Iterate the array and print each point in the array. 
	for (int i = 0; i < len; ++i)
		{
    		p_array[i] = new Point(i, i + 1);
			cout << *p_array[i] <<endl;
		} 

	// Iterate the array again and delete each point in the array. 
	for (int i = 0; i < len; ++i)
		{
    		delete p_array[i];
			cout << "Memory freed up from point " << i + 1 << endl;
		} 

	// Delete the array itself. 
	delete [] p_array;
	cout << "Memory freed from the array of pointers" << endl; 

	// Memory layout of an array of pointers : 
	/*
	p_array 
	  | 
	  v 
	+-----+-----+-----+ 
	| * | * | * |  -> array of pointers 
	+--|--+--|--+--|--+ 
	   |     |     | 
	   v     v     v 
	+------+ +------+ +------+ 
	|Point | |Point | |Point | -> actual points
	+------+ +------+ +------+
	*/
	return 0;
}
