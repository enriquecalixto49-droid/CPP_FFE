#define _USE_MATH_DEFINES 
#include "Circle.hpp"
#include <sstream>
#include <cmath>
using namespace std; 

namespace Enrique::CAD {
    // By leaving the centre empty, we call the default constructor of the Point, which already is set to be the origin (0,0)
    Circle::Circle() : centre(), m_radius(1.0) {
        cout << "Default constructor called" << endl;
    }

    // centre(ctr) calls Point's copy constructor. Thus, no need to input both coordinates, just the point itself.
    Circle::Circle(const Point& ctr, double r) : centre(ctr), m_radius(r) {
        cout << "Constructor with parameters called" << endl;
    }

    // Copy constructor: centre(c.centre) calls Point's copy constructor. Thus, no need to input both coordinates, just the point itself.
    Circle::Circle(const Circle& c) : centre(c.centre), m_radius(c.m_radius) {
        cout << "Copy constructor called" << endl;
    }

    // Destructor
    Circle::~Circle() {
        cout << "Destructor called" << endl;
    }

    // Assignment operator
    Circle& Circle::operator=(const Circle& source) {
        centre = source.centre;
        m_radius = source.m_radius;
        return *this;
    }

    // ostream operator << for Circle class. It uses the ToString() method to get the string representation of the circle and outputs it to the provided ostream.
    ostream& operator << (ostream& os, const Circle& c) {
        os << c.ToString();
        return os;
    }

    // Getters
    const Point& Circle::CentrePoint() const {
        return centre;
    }

    double Circle::Radius() const {
        return m_radius;
    }

    // Setters
    void Circle::CentrePoint(const Point& new_ctr) {
        centre = new_ctr;
    }

    void Circle::Radius(double new_r) {
        m_radius = new_r;
    }

    // Calculations: 
    double Circle::Diameter() const {
        return 2 * m_radius;
    }

    double Circle::Circumference() const {
        return 2 * m_radius * M_PI;
    }

    double Circle::Area() const {
        return M_PI * pow(m_radius, 2);
    }

    // To string
    string Circle::ToString() const {
        stringstream ss;
        ss << "The centre of the circle is: "
            << centre.ToString()
            << " and the radius is: "
            << m_radius;
        return ss.str();
    }

}



