// Practice Problem 16: Generic Stack Data Structure (Class Templates)
// Concepts Tested: Class Templates (template <typename T>), Dynamic Memory, Exception Handling, Template Member Functions.
//
// Description:
// Implement a generic LIFO Stack container `Stack<T>` capable of working with any data type (int, double, std::string).
//
// Requirements:
// 1. Template Class 'Stack<T>':
//    - Private Members:
//        * T* elements (dynamic array for elements)
//        * int capacity
//        * int topIndex
// 2. Constructors & Destructor:
//    - Stack(int cap = 10): Allocates array of size capacity, initializes topIndex = -1.
//    - ~Stack(): Deallocates elements memory.
//    - Prevent copy by deleting copy constructor/assignment operator (`= delete`).
// 3. Member Functions:
//    - void push(const T& val): Adds element to stack. Throws `std::overflow_error` if full.
//    - T pop(): Removes and returns top element. Throws `std::underflow_error` if empty.
//    - T top() const: Returns top element without removing. Throws `std::underflow_error` if empty.
//    - bool isEmpty() const: Returns true if topIndex == -1.
//    - int size() const: Returns current number of elements.
// 4. In main():
//    - Instantiate `Stack<int>` with capacity 5. Push integers 10, 20, 30. Pop and print them.
//    - Instantiate `Stack<std::string>` with capacity 3. Push strings "OOP", "C++", "Templates". Pop and print them.
//    - Test underflow exception by popping from an empty stack inside a try-catch block.

#include <iostream>
#include <string>
#include <stdexcept>

// TODO: Define generic template class Stack<T> here

int main() {
    // TODO: Write code testing Stack template with int and std::string

    return 0;
}
