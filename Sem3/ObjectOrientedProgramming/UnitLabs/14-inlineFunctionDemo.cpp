// Write a program with at least one function made as inline.
// An inline function is a function that is expanded in line when it is called. When the inline function is called, the compiler replaces the function call with the actual code of the function. This can improve performance by eliminating the overhead of a function call, but it can also increase the size of the binary if the function is large or called many times.

#include <iostream>
inline int square(int num) {
    return num*num;
}

int main() {
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "Square of the number is: " << square(a) << std::endl;
    return 0;
}