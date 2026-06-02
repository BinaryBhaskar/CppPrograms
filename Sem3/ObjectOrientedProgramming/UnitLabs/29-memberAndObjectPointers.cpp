// Write a program to illustrate pointer to member and pointer to object concepts of OOP.

#include <iostream>

class MyClass {
public:
    void display() const {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    MyClass obj; // Create an object of MyClass

    // Pointer to member function
    void (MyClass::*ptrToMember)() const = &MyClass::display;

    // Pointer to object
    MyClass* ptrToObject = &obj;

    // Call the member function using the pointer to member
    (ptrToObject->*ptrToMember)(); // Output: Hello from MyClass!

    return 0;
}