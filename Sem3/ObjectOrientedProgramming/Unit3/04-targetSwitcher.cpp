// The Target Switcher
// Concepts: Function Overloading, Finding the Address of an Overloaded Function.
// Task: Create a math processing module that resolves function paths based strictly on function pointer signatures.
// Requirements:
// Write two global overloaded functions named process:
// void process(int x) → prints the value multiplied by 10.
// void process(std::string s) → prints the string wrapped in square brackets (e.g., [Hello]).
// In main(), you cannot call process() directly. Instead, you must declare two separate function pointers with distinct signatures.
// Assign the address of the overloaded process function to each pointer.
// Invoke both functions through your pointers to demonstrate how the compiler automatically resolves the matching address.

#include <iostream>
#include <string>

void process(int x) {
    std::cout << x*10 << std::endl;
}

void process(std::string s) {
    std::cout << "[" << s << "]" << std::endl;
}

int main() {
    void (*intProcessor)(int) = process;
    void (*strProcessor)(std::string) = process;

    intProcessor(32);
    strProcessor("Bhaskar");

    return 0;
}