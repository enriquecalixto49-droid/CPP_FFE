// Header file for the Point class, which represents a point in 2D space with x and y coordinates. 
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
		double X() const; // Getter for the X coordinate
		double Y() const; // Getter for the Y coordinate
		void X(double new_m_x); // Setter for the X coordinate
		void Y(double new_m_y); // Setter for the Y coordinate
		string ToString(); // Returns a string representation of the point in the format "Point(x, y)"
		double Distance() const; // Calculates the distance from the point to the origin (0, 0)
		double Distance(const Point& p) const; // Calculates the distance from the point to another point p
};

#endif