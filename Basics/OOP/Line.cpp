// Implementation of the Line class
#include "Line.hpp"
#include "Shape.hpp"
#include <sstream>
using namespace std; 

// Default constructor initializes p_start and p_end to (0,0)
Line::Line(): Shape(), p_start(), p_end(){
	cout << "Default constructor called" << endl;
}

// Constructor with parameters initializes p_start and p_end using the provided Point objects.
// p_start(p1) calls Point's copy constructor. Thus, no need to put the coordinates
Line::Line(int id, const Point& p1, const Point& p2): Shape(id), p_start(p1), p_end(p2){
	cout << "Constructor with parameters called" << endl;
}

// Copy constructor initializes p_start and p_end using the provided Line object's points.
Line::Line(const Line& l): Shape(l), p_start(l.p_start),  p_end(l.p_end){
	cout << "Copy constructor called" << endl;
}

// Destructor
Line::~Line(){
	cout << "Destructor from Line called" << endl;
}

// Assigment operator
Line& Line::operator=(const Line& source) {
    Shape::operator=(source);
    p_start = source.p_start;
	p_end = source.p_end;
    return *this;
}

// ostream operator << for Line class. It uses the ToString() method to get the string representation of the line and outputs it to the provided ostream.
ostream& operator << (ostream& os, const Line& l) {
	os << l.ToString();
	return os;
}

// Getter for p_start 
const Point& Line::P1() const{
    return p_start;
}

// Getter for p_end
const Point& Line::P2() const{
    return p_end;
}

// Setters for p_start 
void Line::P1(const Point& new_p1){
    p_start = new_p1;
}

// Setters for p_end
void Line::P2(const Point& new_p2){
    p_end = new_p2;
}
/*
Delegation use cases: 
- ToString: we use the toString function from the Point class to get the coordinates of each point.
- Length: delegates the calculation to Point::Distance().
*/
string Line::ToString() const {
    string s = Shape::ToString();
    stringstream ss;
    ss << s
        << " & Line starts at: "
        << p_start.ToString()
        << " and ends at: "
        << p_end.ToString();
    return ss.str();
}

double Line::Length() const {
	return p_end.Distance(p_start);
}

// Draw Function: 
void Line::Draw() {
    cout << "A line ----- " << endl;
}

