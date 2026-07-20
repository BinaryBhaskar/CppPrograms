// Practice Problem 08: Complex Number Arithmetic (Member Operator Overloading)
// Concepts Tested: Binary Operator Overloading (+, -, *), Unary Operator Overloading (-), Equality Operator (==).
//
// Description:
// Implement a mathematical Complex class representing complex numbers (a + bi) and overload arithmetic operators as member functions.
//
// Requirements:
// 1. Create a class named 'Complex'.
// 2. Private Members:
//    - double real
//    - double imag
// 3. Constructors:
//    - Default constructor initializing real = 0.0, imag = 0.0.
//    - Parameterized constructor Complex(double r, double i).
// 4. Overloaded Operators (as Member Functions):
//    - Complex operator+(const Complex& other) const: (a+c) + (b+d)i
//    - Complex operator-(const Complex& other) const: (a-c) + (b-d)i
//    - Complex operator*(const Complex& other) const: (ac - bd) + (ad + bc)i
//    - Complex operator-() const: Unary minus returning (-real, -imag).
//    - bool operator==(const Complex& other) const: Returns true if real and imag are equal.
// 5. Member Functions:
//    - void display() const: Prints in format `a + bi` (or `a - bi` if imag is negative).
// 6. In main():
//    - Instantiate `c1(3.0, 4.0)` and `c2(1.0, 2.0)`.
//    - Compute `c3 = c1 + c2`, `c4 = c1 - c2`, `c5 = c1 * c2`.
//    - Test unary negation: `c6 = -c1`.
//    - Test equality: `c1 == c2`.
//    - Display results of all operations.

#include <iostream>

// TODO: Define your Complex class here

int main() {
    // TODO: Write test cases verifying overloaded operators

    return 0;
}
