// Write a program to demonstrate the use of Static Keyword and dynamic 'new' operator initialization.

#include <iostream>

class Counter {
private:
    static int count; // Static member to keep track of count
public:
    Counter() {
        count++; // Increment count whenever a new object is created
    }
    static int getCount() {
        return count; // Return the current count
    }
};

int Counter::count = 0; // Initialize static member

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter* c1 = new Counter(); // Create first counter object
    std::cout << "Count after creating c1: " << Counter::getCount() << std::endl;

    Counter* c2 = new Counter(); // Create second counter object
    std::cout << "Count after creating c2: " << Counter::getCount() << std::endl;

    delete c1; // Clean up dynamically allocated memory
    delete c2;

    return 0;
}