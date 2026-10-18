#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"
#include <iostream>

namespace Enrique::Container {
    class Array {
    private:
        CAD::Point* m_data; // data member for a dynamic C array of Point objects (Point* m_data). 
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
        const CAD::Point& GetElement(int index) const;
        const CAD::Point& operator[](int index) const;

        // Setters:
        void SetElement(int index, const CAD::Point& p);
        CAD::Point& operator[](int index);

        // Printer:
        friend ostream& operator << (ostream& os, const Array& arr);
    };

}

#endif