#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
using namespace std; 
class Shape{
    private:
        int m_id;
    public:
        Shape(); // Default constructor
        Shape(int id); // Input-like constructor
        Shape(const Shape& shp); // Copy constructor

        virtual ~Shape(); // Destructor

        Shape& operator=(const Shape& shp); // Assignment operator

        virtual string ToString() const; // To string function
        int ID() const; // ID getter
        virtual void Print() const; // Print interface
        /*
           Pure Virtual Member Function:
           As soon as a class contains at least one pure virtual function,
           it becomes an abstract class, and you cannot create instances of it.
       */

        virtual void Draw() = 0;

};

#endif