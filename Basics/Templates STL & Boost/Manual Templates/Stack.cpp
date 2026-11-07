#include "Stack.hpp"
#include <iostream>
#include "StackException.hpp"
using namespace std; 

template <class T, int size>
Stack<T, size>::Stack() : m_array(size), m_idx(0) {
	// The reason m_current starts at 0 is that the stack is initially empty, 
	// so the next element pushed should go into position 0.
}

template <class T, int size>
Stack<T, size>::Stack(const Stack<T, size>& source) : m_array(source.m_array), m_idx(source.m_idx) {
}

template <class T, int size>
Stack<T, size>::~Stack() {
}


template <class T, int size>
void Stack<T, size>::Push(const T& item) {
	
	try {
		m_array[m_idx] = item;
		m_idx++;
	}
	catch(ArrayException& e){
		// We can catch an array exception since every out of bounds exception is an array exception (polymorphism/inheritance)
		// Then, we will throw an Stack exception. 
		throw StackFullException();
	}
	
}

template <class T, int size>
T Stack<T, size>::Pop() {
	try{
		m_idx--;
		return m_array[m_idx];
	}
	catch(ArrayException&){
		m_idx = 0;
		throw StackEmptyException();
	}
}