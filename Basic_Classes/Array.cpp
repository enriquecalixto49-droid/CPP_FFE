#include "Array.hpp"
#include "Point.hpp"

#include <iostream>
using namespace std; 

namespace Enrique::Container {

    /*
    Constructors and destructors:
*/
    Array::Array() : m_size(10) {
        m_data = new CAD::Point[m_size];
    }

    Array::Array(int size) :m_size(size) {
        m_data = new CAD::Point[m_size];
    }

    Array::Array(const Array& arr) {
        m_size = arr.m_size;
        m_data = new CAD::Point[arr.m_size];
        for (int i = 0; i < arr.m_size; i++) {
            m_data[i] = arr.m_data[i];
        }
    }

    Array::~Array() {
        delete[] m_data;
    }

    /*
        Assignment operator:
    */
    Array& Array::operator=(const Array& source) {
        // We must avoid both memory leakage 

        // Check self-assignment:
        if (this == &source) {
            return *this;
        }
        // Delete current memory:
        delete[] m_data;

        // Copy size:  
        m_size = source.m_size;

        // Allocate new memory for the assignment 
        m_data = new CAD::Point[m_size];

        // Assign the same values
        for (int i = 0; i < m_size; i++) {
            m_data[i] = source.m_data[i];
        }
        return *this;
    }

    /*
        Getters
    */

    int Array::Size() const {
        // Size getter
        return m_size;
    }

    const CAD::Point& Array::GetElement(int index) const {
        // Const element getter
        if (index > m_size - 1 || index < 0) {
            index = 0;
        }
        return m_data[index];
    }

    /*
        Setters
    */
    void Array::SetElement(int index, const CAD::Point& p) {
        if (index > m_size - 1 || index < 0) {
            return;
        }
        m_data[index] = p;
    }

    /*
        [] Operator overload.
    */

    CAD::Point& Array::operator[](int index) {
        /*
            This one will be used whenever the array declared in the main file is not const.
            Array arr(10);
            CAD::Point& p = arr[0];
            This function will be called, and the reference instanced can be modified.
        */

        if (index > m_size - 1 || index < 0) {
            return m_data[0];
        }
        return m_data[index];
    }

    const CAD::Point& Array::operator[](int index) const {
        /*
            This one will be used whenever the array declared in the main file is const.
            const Array arr(10);
            const CAD::Point& p = arr[0];
            This function will be called.

            Another use case is
            Array arr(10);
            const CAD::Point& p = arr[0];
            Since this function exists, even if the array is not const, the referenced CAD::Point p is const.
            W/o, it would not compile.
        */
        if (index > m_size - 1 || index < 0) {
            return m_data[0];
        }
        return m_data[index];
    }

    ostream& operator << (ostream& os, const Array& arr) {
        os << "This array is of len: " << arr.m_size << '\n';

        for (int i = 0; i < arr.m_size; i++)
        {
            os << arr.m_data[i] << ' ';
        }

        return os;

    }
}


