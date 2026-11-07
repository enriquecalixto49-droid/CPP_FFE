#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"
#include <iostream>

using namespace std; 



template <class T>
class Array{
    private:
        T* m_data; // data member for a dynamic C array of Point objects (Point* m_data). 
        unsigned int m_size; //data member for the size of the array.
		static unsigned int DEFAULT_SIZE; // default size of the array.
    public:
        // Constructors: 
        Array(); // default constructor
        Array(unsigned int size); // constructor accepting size input
        Array(const Array<T>& arr); // copy constructor  
        
        // Destructors: 
        ~Array(); // default destructor

        // Assignment operator:
        Array<T>& operator=(const Array<T>& source); 

		// Getters: -> we could use unsigned int instead of int for the index, but then we would have to change the exception class to accept unsigned int.
        unsigned int Size() const;
        const T& GetElement(int index) const;
        const T& operator[](int index) const;

        // Setters:
        void SetElement(int index, const T& p);
        T& operator[](int index);

        // Static getter / setter:
        static unsigned int DefaultSize(); // static functions dont have a this pointer, so no need to use const
		static void DefaultSize(unsigned int size);

        // Printer:
        friend ostream& operator << (ostream& os, const Array& arr) {
            os << "This array is of len: " << arr.m_size << '\n';

            for (int i = 0; i < arr.m_size; i++)
            {
                os << arr.m_data[i] << ' ';
            }

            return os;

        };
};

#endif