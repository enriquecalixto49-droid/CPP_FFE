// Implementation of the Point class
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

double Point::X() const{
    return m_x;
}

double Point::Y() const{
    return m_y;
}

void Point::X(double new_m_x){
    m_x = new_m_x;
}

void Point::Y(double new_m_y){
    m_y = new_m_y;
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

