// Header file for the Point and Line classes.

#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <string>
#include "Point.hpp"
#include "Shape.hpp"

using namespace std;


class Line: public Shape{
    private:
		Point p_start; // Starting point of the line
		Point p_end; // Ending point of the line
    public:
        Line(); // Default Constructor
        // Constructor accepting two points. We don't want to modify p1 nor p2, just get their values. Thus, we pass a read-only reference (const). 
        Line(int id, const Point& p1, const Point& p2); 
        Line(const Line& l); //Copy constructor
        ~Line(); // Destructor

		Line& operator=(const Line& source); // Assignment operator.
		
        const Point& P1() const; // Getter for the starting point of the line. 
		const Point& P2() const; // Getter for the ending point of the line.
        void P1(const Point& p1); // Setter. We don't want to modify p1, just set the value of P1 to be p1. Thus, we pass a read-only reference
		void P2(const Point& p2); // Setter. We don't want to modify p2, just set the value of P2 to be p2. Thus, we pass a read-only reference
		string ToString() const; // Returns a string description of the line. Delegates to Point::ToString() to get the coordinates of each point.
        double Length() const; // Calculates the length of the line.

        // Draw function: 
        void Draw();
};

// ostream operator << for Line class. It uses the ToString() method to get the string representation of the line and outputs it to the provided ostream.
ostream& operator << (ostream& os, const Line& l);


#endif