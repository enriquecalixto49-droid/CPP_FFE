/*
Not only generic types can act as template variable. You can also use an int value as template 
variable. This value can then be used inside the class. Change the Stack class so that it uses a 
value template argument to set the stack size (remove the constructor with size): 
template <typename T, int size> class Stack {}; 
Note that now only stacks with the same size template argument can be copied/assigned.
*/
#include <iostream>
#include <random>
#include "Point.hpp"
#include "Array.cpp"
#include "Stack.cpp"

using namespace std;

int main() {
	// Generation of random numbers
	random_device rd;
	mt19937 gen(rd());

	uniform_real_distribution<double> doubleDist(0.0, 10.0);

	// It wouldnt compile if we try to use a variable as template argument. Just if we use constexpr int size = 9;

	// Stack of doubles
	Stack<double, 9> intStack;
	
	// Randomly generate two doubles and push them onto the stack
	double x = doubleDist(gen);
	double y = doubleDist(gen);

	cout << "values pushed onto the stack: " << x << ", " << y << endl;
	try {
		intStack.Push(x);
		intStack.Push(y);

		// Copy constructor
		Stack<double, 9> intStack2(intStack);

		// Pop the top value from the stack and store it in a variable
		double z = intStack2.Pop();
		double a = intStack2.Pop();
		double b = intStack2.Pop(); // It should crash here. 
	}
	catch (const StackException& e) {
		cout << e.GetMessage() << endl;
	}


	return 0; 

}
