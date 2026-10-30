#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <string>
#include "Shape.hpp"

using namespace std;

/*
Point object
+------------------+
| Shape part       |
|  m_id            |
+------------------+
| Point part       |
|  m_x             |
|  m_y             |
+------------------+
*/


class Point: public Shape
{
    private:
        double m_x; // X coordinate
        double m_y; // y coordinate
    public:
        Point(); // Default Constructor
		Point(int id, double x, double y); // Constructor accepting two double parameters
        Point(const Point& p); // Copy constructor
        explicit Point(int id, double value); // Constructor as a conversion operator. 
        ~Point(); // Destructor
        
        // Operators:
        // Operators creating a new object (const and return type Point):
		Point operator -() const; // Negate the coordinates.
		Point operator *(double factor) const; // Scale the coordinates.
		Point operator +(const Point& p) const; // Add coordinates.

		// Comparison operators:
		bool operator ==(const Point& p) const; // Equally compare operator.
		
		// Operators modifying the current object (not const and return type Point&):
        Point& operator = (const Point& source); // Assignment operator.
		Point& operator *= (double factor); // Scale the coordinates & assign.

        // ostream operator << for Point class.
        friend ostream& operator << (ostream& os, const Point& p);

        //normal inline -> the body to be defined afterwards with the inline keyword. 
        double X() const;
        double Y() const;
        
        // default inline -> the body to be included directly. 
        void X(double new_m_x){
            m_x = new_m_x;
        }
        void Y(double new_m_y){
            m_y = new_m_y;
        }

        string ToString() const;
		double Distance() const;
		double Distance(const Point& p) const;

        // Draw function: 
        void Draw();
        void Print() const override;
};

// Normal inline body defition. 
inline double Point::X() const{
    return m_x;
}

inline double Point::Y() const{
    return m_y;
}

#endif