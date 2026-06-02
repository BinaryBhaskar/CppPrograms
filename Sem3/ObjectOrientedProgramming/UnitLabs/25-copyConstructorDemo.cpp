// Write a program to initialize an object with another using copy constructor.

#include <iostream>

class MyClass {
private:
    int value;
public:
    MyClass(int v) : value(v) {}
    MyClass(const MyClass& other) : value(other.value) {
        std::cout << "Copy constructor called!" << std::endl;
    }
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1(10); // Create an object with value 10
    std::cout << "Object 1: ";
    obj1.display();

    MyClass obj2 = obj1; // Initialize obj2 with obj1 using copy constructor
    std::cout << "Object 2 (copy of Object 1): ";
    obj2.display();
    return 0;
}