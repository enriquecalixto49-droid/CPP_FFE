#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP

#include <string>
using namespace std; 

class StackException{
    public:
        virtual string GetMessage() const
        {
            return "Stack exception";
        }
};

class StackFullException: public StackException{
    public:
        virtual string GetMessage() const{
            return "Stack is full";
        }
};

class StackEmptyException: public StackException{
    public:
        virtual string GetMessage() const{
            return "Stack is empty";
        }
};

#endif 