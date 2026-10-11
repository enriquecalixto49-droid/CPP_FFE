// Implementation of the Point class member functions
// Differences from the previous version:
// Overload of X and Y getters/setters and Distance methods.

// Include the header file for the Point class
#include "The_class_concept.hpp"

// Include the necessary libraries
#include <sstream>

// Use the standard namespace to save std:: prefix
using namespace std; 

// Default constructor initializes the point to (0, 0)
Point::Point(): m_x(0), m_y(0){
	cout << "Default constructor called" << endl;
}

// Constructor with parameters initializes the point to (x, y)
Point::Point(double x, double y) : m_x(x), m_y(y) {
	cout << "Constructor with parameters called" << endl;
}

// Copy constructor initializes the point to the same coordinates as another point
Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
	cout << "Copy constructor called" << endl;
}

// Destructor outputs a message when a Point object is destroyed
Point::~Point(){
	cout << "Destructor called" << endl;
}

// Getter for the X coordinate
double Point::X() const{
    return m_x;
}

// Getter for the Y coordinate
double Point::Y() const{
    return m_y;
}

// Setter for the X coordinate
void Point::X(double new_m_x){
    m_x = new_m_x;
}

// Setter for the Y coordinate
void Point::Y(double new_m_y){
    m_y = new_m_y;
}

// Returns a string representation of the point in the format "Point(x, y)"
string Point::ToString(){
    stringstream ss;
    ss << "Point(" << m_x << ", "<< m_y<<")";
    return ss.str();
}

// Calculates the distance from the point to the origin (0, 0)
double Point::Distance() const {
	return sqrt(m_x * m_x + m_y * m_y);
}

// Calculates the distance from the point to another point p
double Point::Distance(const Point& p) const  {
    return sqrt(pow((m_x-p.m_x), 2) + pow((m_y-p.m_y), 2));
}

