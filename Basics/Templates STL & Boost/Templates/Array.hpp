#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"
#include <iostream>

using namespace std; 

template <class T>
class Array{
    private:
        T* m_data; // data member for a dynamic C array of Point objects (Point* m_data). 
        int m_size; //data member for the size of the array.
    
    public:
        // Constructors: 
        Array(); // default constructor
        Array(int size); // constructor accepting size input
        Array(const Array<T>& arr); // copy constructor  
        
        // Destructors: 
        ~Array(); // default destructor

        // Assignment operator:
        Array<T>& operator=(const Array<T>& source); 

        // Getters:
        int Size() const;
        const T& GetElement(int index) const;
        const T& operator[](int index) const;

        // Setters:
        void SetElement(int index, const T& p);
        T& operator[](int index);

        // Printer:

        /*
        friend declaration inside the class creates a regular (non-template) function for each Array<T>. When main prints an Array<Line>, it needs exactly operator<<(ostream&, const Array<Line>&). But the .cpp defined a template version, which is a different thing, so even with the recipe available nobody generates that exact function. Hence the linker error names that signature.

        Why the fixes work

        Both fixes put the recipe where the compiler sees it at the moment of use:

        - Defining everything in the header (or #include-ing the .cpp at the end of it) means every file that includes Array.hpp also sees the bodies, so the compiler can generate Array<Line> right there.
        - Defining the friend function inside the class means it’s generated together with each instantiation
        
        Lesson!!!!: 
        Be careful with friend operators in templates. They must be defined in the header and defined in the header of every other class suitable for the template. 
        */
        friend ostream& operator << (ostream& os, const Array& arr) {
            os << "This array is of len: " << arr.m_size << '\n';

            for (int i = 0; i < arr.m_size; i++)
            {
                os << arr.m_data[i] << ' ';
            }

            return os;

        };
};


/*
    Tip: by placing the following code at the end of the array header file, but before the header 
    file’s #endif, the client can keep including the header file for template classes instead of the 
    source file. 
        #ifndef Array_cpp      
        #include "Array.cpp" 
        #endif
*/
#endif