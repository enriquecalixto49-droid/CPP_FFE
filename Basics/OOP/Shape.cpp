#include "Shape.hpp"
#include <iostream>
#include "stdlib.h"
#include <sstream>
using namespace std; 

// Constructors: 
Shape::Shape(): m_id(rand()){}
Shape::Shape(int id): m_id(id){}
Shape::Shape(const Shape& shp): m_id(shp.m_id){}

// Destructor:
Shape::~Shape(){
    cout << "Destructor from Shape called" << endl;
}

// Assignment operator
Shape& Shape::operator=(const Shape& shp){
    m_id = shp.m_id; 
    return *this; // this is a pointer to the current object on which a member function is being called. By returning *this, we correctly return the reference. 
}

// ToString
string Shape::ToString() const{
    stringstream ss;
    ss << "Shape with an id: " << m_id;  
    return ss.str(); 
}
void Shape::Print() const {
    cout << ToString() << endl;
}
// ID getter: 
int Shape::ID() const{
    return m_id; 
}

// Print function 
/*
You have now created a function for the base class (Print()) that does all the functionality
common to all derived classes. Only the part of that function that is different for each derived
class is delegated to a polymorphic function (ToString()). This mechanism is an often used
design pattern called the “Template Method Pattern”.
*/
