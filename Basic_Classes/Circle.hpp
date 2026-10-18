// Implementation of the class concept for Point and Circle 

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace Enrique::CAD {
    class Circle {
    private:
        Point centre; // Centre point of the circle
        double m_radius; // Radius of the circle
    public:
        // Constructors and destructors: 
        Circle(); //Default constructor
        // Copying a double is cheap and avoids reference-related issues, so we call the double by value.
        Circle(const Point& ctr, double r); // Constructor accepting a Point and a double
        Circle(const Circle& c); // Copy constructor
        ~Circle();  // Destructor

        // Assignment operator
        Circle& operator=(const Circle& source);

        // Getters
        // Return the centre point as a constant reference to avoid copying.
        const Point& CentrePoint() const;
        // Return the radius by value since doubles are cheap to copy. However, indicating const at the end of the function we assure that the radius of the object will not be modified
        double Radius() const;

        //Setters
        void CentrePoint(const Point& new_ctr);
        void Radius(double new_r);

        //Calculations
        double Diameter() const;
        double Area() const;
        double Circumference()const;

        //To string
        string ToString() const;
    };

    // ostream operator << for Circle class. It uses the ToString() method to get the string representation of the circle and outputs it to the provided ostream.
    ostream& operator << (ostream& os, const Circle& c);
}


#endif