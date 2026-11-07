#ifndef OUTOFBOUNDSEXCEPTION_HPP
#define OUTOFBOUNDSEXCEPTION_HPP

#include <iostream>
#include <sstream>
using namespace std; 

class ArrayException{
    public:
        // Purely Virtual Member function, making the class abstract: 
        virtual string GetMessage() const = 0;
        virtual ~ArrayException() = default;
};

class OutOfBoundsException: public ArrayException{
    private: 
        int m_index;
    public:
        OutOfBoundsException(int idx): m_index(idx){
        }
        string GetMessage() const{
            stringstream ss;
            ss << "Index " << m_index << " is out of bounds";
            return ss.str(); 
        }
        ~OutOfBoundsException() = default;
};


#endif