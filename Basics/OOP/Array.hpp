#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"
#include <iostream>

class Array{
    private:
        Point* m_data; // data member for a dynamic C array of Point objects (Point* m_data). 
        int m_size; //data member for the size of the array.
    
    public:
        // Constructors: 
        Array(); // default constructor
        Array(int size); // constructor accepting size input
        Array(const Array& arr); // copy constructor  
        
        // Destructors: 
        ~Array(); // default destructor

        // Assignment operator:
        Array& operator=(const Array& source); 

        // Getters:
        int Size() const;
        const Point& GetElement(int index) const;
        const Point& operator[](int index) const;

        // Setters:
        void SetElement(int index, const Point& p);
        Point& operator[](int index);

        // Printer:
        friend ostream& operator << (ostream& os, const Array& arr);
};

#endif