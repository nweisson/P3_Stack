#include "Stack.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace cop4530;


// zero parameter constructor. Create an empty stack.
template<typename T>
Stack<T>::Stack() {

}
// De-allocate memory if necessary
template<typename T>
Stack<T>::~Stack() {

}
// copy constructor
template<typename T>
Stack<T>::Stack(const Stack &rhs) {

    int size = rhs.size();

    for (int i = 0; i < size; ++i){
        myVec.push_back(rhs.myVec[i]);
    }


}
// move constructor
template<typename T>
Stack<T>::Stack(Stack &&rhs) {

   swap(myVec,rhs.myVec);


}
// copy assignment operator
template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &rhs) {

    myVec.clear();

    myVec = rhs.myVec;

    return *this;

}
// move assignment operator
template<typename T>
Stack<T> &Stack<T>::operator=(Stack &&rhs) {

    swap(this, rhs);

    return *this;
}
// check if empty
template<typename T>
bool Stack<T>::empty() const {

    if (myVec.empty()){
        return true;
    }
    return false;

}
// return top element (1)
template<typename T>
T &Stack<T>::top() {
    return myVec.back();
}
// return top element (2)
template<typename T>
const T &Stack<T>::top() const {
    return myVec.back();
}
// pop element
template<typename T>
void Stack<T>::pop() {

        return myVec.pop_back();
    

}
// push(1)
template<typename T>
void Stack<T>::push(const T &val) {

    myVec.push_back(val);

}
// push(2)
template<typename T>
void Stack<T>::push(T &&val) {

    myVec.push_back(std::move(val));

}
// return size
template<typename T>
int Stack<T>::size() const {
    return myVec.size();
}
