#ifndef STACK_HPP
#define STACK_HPP

#include "Array.cpp"
#include <iostream>

/*
	Using another class as data member is called composition. 
	In this case the Stack class uses internally an Array class. 
	Forwarding functionality to another class is called delegation.
	Here the Stack class delegates the storage of elements to the Array class.
*/
template <class T, int size>
class Stack {
	private:
		Array<T> m_array;
		unsigned int m_idx;
	public:
		Stack();
		Stack(const Stack<T, size>& source);

		~Stack();

		void Push(const T& item);
		T Pop();

};

#endif