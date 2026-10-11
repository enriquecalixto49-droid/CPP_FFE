// Header file for the Point and Line classes.

#ifndef The_class_concept_HPP
#define The_class_concept_HPP

#include <iostream>
#include <string>

using namespace std;

class Point{
    private:
        double m_x; // X coordinate
        double m_y; // y coordinate
    public:
        Point(); // Default Constructor
		Point(double x, double y); // Constructor accepting two double parameters
        Point(const Point& p); // Copy constructor
        ~Point(); // Destructor
		double X() const; // Getter for X coordinate
		double Y() const; // Getter for Y coordinate
		void X(double new_m_x); // Setter for X coordinate
		void Y(double new_m_y); // Setter for Y coordinate
		string ToString() const; // Returns a string description of the point
		double Distance() const; // Calculates the distance to the origin (0, 0)
		double Distance(const Point& p) const; // Calculates the distance between two points. We don't want to modify p, just get its values. Thus, we pass a read-only reference (const).
};

class Line{
    private:
		Point p_start; // Starting point of the line
		Point p_end; // Ending point of the line
    public:
        Line(); // Default Constructor
        // Constructor accepting two points. We don't want to modify p1 nor p2, just get their values. Thus, we pass a read-only reference (const). 
        Line(const Point& p1, const Point& p2); 
        Line(const Line& l); //Copy constructor
        ~Line(); // Destructor
        /*
        - Point& → return the actual stored object, no copy.
        - First const → caller cannot modify that object through the returned reference.
        - Final const → the getter itself cannot modify the Line.
        - Example: 
            - const Point& p = line.P1(); is allowed and cannot modify a point (no new Point object is created, just a read-only reference with another name (p))
            - Point p = myline.P1(); is allowed, and creates another Point object called p which is a copy of p_start. We can safely modify p without modifying the line.  
            - line.P1().X(100); is not allowed. 
            - Point& p = myline.P1(); -> doesn't compile (since it is not const, C++ will not allow to create the reference p). 
        */
		const Point& P1() const; // Getter for the starting point of the line. 
		const Point& P2() const; // Getter for the ending point of the line.
        void P1(const Point& p1); // Setter. We don't want to modify p1, just set the value of P1 to be p1. Thus, we pass a read-only reference
		void P2(const Point& p2); // Setter. We don't want to modify p2, just set the value of P2 to be p2. Thus, we pass a read-only reference
		string ToString() const; // Returns a string description of the line. Delegates to Point::ToString() to get the coordinates of each point.
        double Length() const; // Calculates the length of the line.
};

#endif