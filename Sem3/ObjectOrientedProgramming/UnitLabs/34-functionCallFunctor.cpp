// Write a program to perform overloading of function call operator.

#include <iostream>
class Functor {
public:
    void operator()() const {
        std::cout << "Hello from the Functor!" << std::endl;
    }
};

int main() {
    Functor functor; // Create an instance of the Functor class
    functor(); // Call the functor using the overloaded function call operator

    return 0;
}