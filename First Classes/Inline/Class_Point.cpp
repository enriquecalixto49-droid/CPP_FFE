// Implementation of the Point class
// Since the body of the inline functions X() and Y() are defined in the header file, they can be inlined by the compiler.
// No need to include the implementation of these functions in the .cpp file.

#include "The_class_concept.hpp"
#include <sstream>
using namespace std; 

Point::Point(): m_x(0), m_y(0){
	cout << "Default constructor called" << endl;
}

Point::Point(double x, double y) : m_x(x), m_y(y) {
	cout << "Constructor with parameters called" << endl;
}

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
	cout << "Copy constructor called" << endl;
}

Point::~Point(){
	cout << "Destructor called" << endl;
}

string Point::ToString() const{
    stringstream ss;
    ss << "Point(" << m_x << ", "<< m_y<<")";
    return ss.str();
}

double Point::Distance() const {
	return sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(const Point& p) const  {
    return sqrt(pow((m_x-p.m_x), 2) + pow((m_y-p.m_y), 2));
}

