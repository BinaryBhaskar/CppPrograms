// Practice Problem 13: Custom Exception Handling & Safe Division
// Concepts Tested: Exception Handling (try, throw, catch), Custom Exception Class inheriting from std::exception, overriding what().
//
// Description:
// Build a robust math division module using custom exception classes to catch divide-by-zero errors gracefully.
//
// Requirements:
// 1. Custom Exception Class 'DivisionByZeroException':
//    - Inherits publicly from `std::exception`.
//    - Overrides const char* what() const noexcept override to return "Error: Division by zero is undefined!".
// 2. Custom Exception Class 'NegativeValueException':
//    - Inherits publicly from `std::exception`.
//    - Constructor accepting error message string.
//    - Overrides `what()`.
// 3. Functions:
//    - double safeDivide(double numerator, double denominator):
//      Throws `DivisionByZeroException` if denominator == 0.
//    - double calculateSquareRoot(double value):
//      Throws `NegativeValueException` if value < 0. (Use std::sqrt from <cmath>).
// 4. In main():
//    - Execute `safeDivide` inside a `try-catch` block testing valid and zero-denominator cases.
//    - Execute `calculateSquareRoot` inside a `try-catch` block testing positive and negative numbers.
//    - Catch exceptions by reference (`const std::exception& e`) and output `e.what()`.

#include <iostream>
#include <exception>
#include <cmath>

// TODO: Define custom exception classes and functions here

int main() {
    // TODO: Write try-catch blocks to test exception handling

    return 0;
}
