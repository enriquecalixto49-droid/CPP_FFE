// Implementation of the Point class
#include "Point.hpp"
#include <sstream>
using namespace std; 

namespace Enrique::CAD {
	// Constructors :
	Point::Point() : m_x(0), m_y(0) {
		cout << "Default constructor called" << endl;
	}

	Point::Point(double x, double y) : m_x(x), m_y(y) {
		cout << "Constructor with parameters called" << endl;
	}

	Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
		cout << "Copy constructor called" << endl;
	}

	// Implicit constructor to prevent implicit conversions from double to Point
	Point::Point(double value) : m_x(value), m_y(value) {
		cout << "Explicit constructor called" << endl;
	}

	Point::~Point() {
		cout << "Destructor called" << endl;
	}

	// Operators creating a new object (const and return type Point):
	Point Point::operator-() const {
		return Point(-m_x, -m_y);
	}

	Point Point::operator*(double factor) const {
		return Point(m_x * factor, m_y * factor);
	}

	Point Point::operator+(const Point& p) const {
		return Point(m_x + p.m_x, m_y + p.m_y);
	}

	// Comparison operators:
	bool Point::operator==(const Point& p) const {
		return (m_x == p.m_x && m_y == p.m_y);
	}

	// Operators modifying the current object (not const and return type Point&):
	/*
	The = and *= operator changes the current object so they can’t be const functions.
	To make it possible to chain the = and *= operators (E.g.: a=b+=c), it must return the “this” object.
	*/

	Point& Point::operator=(const Point& source) {
		m_x = source.m_x;
		m_y = source.m_y;
		return *this;
	}

	Point& Point::operator*=(double factor) {
		m_x *= factor;
		m_y *= factor;
		return *this;
	}

	//ostream operator << for Point class. Since it is a friend, now it can access the internal private members of the Point passed by reference
	ostream& operator << (ostream& os, const Point& p) {
		os << "Point(" << p.m_x << ", " << p.m_y << ")";
		return os;
	};

	string Point::ToString() const {
		stringstream ss;
		ss << "Point(" << m_x << ", " << m_y << ")";
		return ss.str();
	}

	double Point::Distance() const {
		return sqrt(m_x * m_x + m_y * m_y);
	}

	double Point::Distance(const Point& p) const {
		return sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2));
	}


}
