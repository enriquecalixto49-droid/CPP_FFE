/*
Why must the inline getters be in the header file?

When a source file such as main.cpp is compiled and the compiler sees:

    p1.X();

it can only inline the function if it also sees the function's body.

For example, to replace the call with the equivalent code:

    return m_x;

the compiler needs access to the implementation at compile time.

Therefore, the definition:

    inline double Point::X() const
    {
        return m_x;
    }

must be placed in Point.hpp so that every .cpp file including the header
can see the function body.

If the implementation remained in Point.cpp, other translation units would
only see the declaration:

    double X() const;

and would not have access to the function body during compilation.
As a result, the compiler would generally be unable to inline the function.
*/

#ifndef Point_HPP
#define Point_HPP

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
        explicit Point(double value); // Constructor as a conversion operator. 
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
};

// Normal inline body defition. 
inline double Point::X() const{
    return m_x;
}

inline double Point::Y() const{
    return m_y;
}

#endif