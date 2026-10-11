// Implementation of the class concept for Point and Circle 

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
		double Distance() const; // Calculate the distance to the origin (0, 0)
		double Distance(const Point& p) const; // Calculate the distance between two points
};

class Circle{
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
#endif