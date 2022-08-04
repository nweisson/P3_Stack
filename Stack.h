#ifndef PROJECT_3_STACK_H
#define PROJECT_3_STACK_H

#include <iostream>
#include <vector>

namespace cop4530 {

    template <typename T>
    class Stack {
    public:

        Stack();   // zero parameter constructor. Create an empty stack.
        ~Stack();  // De-allocate memory if necessary (depending on your design of the stack).
        Stack(const Stack &rhs);  // copy constructor. Create the new stack with the elements of an existing stack rhs.
        Stack(Stack &&rhs);       // move constructor. Create the new stack with the elements of an existing stack rhs.
        Stack& operator=(const Stack &rhs); // copy assignment operator.
        Stack& operator=(Stack &&rhs);      // move assignment operator.
        bool empty() const;                 // return true if there is no element in the stack; return false otherwise.
        T& top(); // return a reference to the first element in the stack.
        const T& top() const; // constant version of the above member function.
        void pop(); // remove the first element in the stack and discard it.
        void push(const T& val); // add a new element val to the stack.
        void push(T&& val); // add a new element val to the stack. val should be moved instead of copied (if possible)
        int size() const; // return the number of elements in the current stack.

    private:
        std::vector <T> myVec;
    };
    // end of class Stack

// include the implementation file here
#include "Stack.hpp"

} // end of namespace COP4530
#endif
