#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"
#include "Point.hpp"
#include "OutOfBoundsException.hpp"

#include <iostream>
using namespace std; 

/*
    Constructors and destructors: 
*/
template <class T>
Array<T>::Array(): m_size(10){
    m_data = new T[m_size];
}

template <class T>
Array<T>::Array(int size):m_size(size){
    m_data = new T[m_size];
}

template <class T>
Array<T>::Array(const Array<T>& arr){
    m_size = arr.m_size;
    m_data = new T[arr.m_size];
    for(int i = 0; i<arr.m_size; i++){
        m_data[i] = arr.m_data[i];
    }
}
template <class T>
Array<T>::~Array(){
    delete [] m_data;
}

/*
    Assignment operator: 
*/
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& source){
    // We must avoid both memory leakage 

    // Check self-assignment:
    if (this == &source){
        return *this; 
    }
    // Delete current memory:
    delete[] m_data;

    // Copy size:  
    m_size = source.m_size;
    
    // Allocate new memory for the assignment 
    m_data = new T[m_size];

    // Assign the same values
    for(int i = 0; i < m_size; i++){
        m_data[i] = source.m_data[i];
    }
    return *this; 
}

/*
    Getters 
*/
template <class T>
int Array<T>::Size() const{
    // Size getter
    return m_size;
}
template <class T>
const T& Array<T>::GetElement(int index) const {
    // Const element getter
    if(index > m_size-1 || index < 0){
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

/*
    Setters 
*/
template <class T>
void Array<T>::SetElement(int index, const T& p){
    if(index > m_size -1 || index < 0){
        throw OutOfBoundsException(index); 
    }
    m_data[index] = p;
}

/*
    [] Operator overload. 
*/
template <class T>
T& Array<T>::operator[](int index){
    /*
        This one will be used whenever the array declared in the main file is not const.
        Array arr(10);
        Point& p = arr[0];
        This function will be called, and the reference instanced can be modified. 
    */ 
     
    if(index > m_size-1 || index < 0){
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

template <class T>
const T& Array<T>::operator[](int index) const{
    /*
        This one will be used whenever the array declared in the main file is const.
        const Array arr(10);
        const Point& p = arr[0];
        This function will be called.

        Another use case is 
        Array arr(10);
        const Point& p = arr[0];
        Since this function exists, even if the array is not const, the referenced point p is const. 
        W/o, it would not compile. 
    */ 
    if(index > m_size-1 || index < 0){
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

#endif