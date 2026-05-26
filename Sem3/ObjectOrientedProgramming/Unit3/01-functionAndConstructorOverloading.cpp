#include <iostream>

class Vector2D {
public:
    int x, y;

    // 1. Constructor Overloading (Multiple constructors under the same name)
    Vector2D() : x(0), y(0) {
        std::cout << "[Constructor] Default initialization." << std::endl;
    }

    Vector2D(int xVal, int yVal) : x(xVal), y(yVal) {
        std::cout << "[Constructor] Parameterized initialization." << std::endl;
    }

    // 2. Function Overloading (Same name, different parameter signatures)
    void scale(int factor) {
        this->x *= factor;
        this->y *= factor;
    }

    void scale(double factor) {
        this->x = static_cast<int>(this->x * factor);
        this->y = static_cast<int>(this->y * factor);
    }
};

// Global overloaded functions to demonstrate finding their memory address
void compute(int value) {
    std::cout << "Computing integer square: " << value * value << std::endl;
}

void compute(double value) {
    std::cout << "Computing double division: " << value / 2.0 << std::endl;
}

int main() {
    std::cout << "=== TOPIC: FUNCTION & CONSTRUCTOR OVERLOADING ===" << std::endl;

    Vector2D v1;        // Triggers default constructor
    Vector2D v2(5, 10); // Triggers parameterized constructor

    v2.scale(2);    // Matches scale(int)
    v2.scale(1.5);  // Matches scale(double)

    // 3. Finding the Address of an Overloaded Function
    // CRITICAL EXAM TRAP: If you have overloaded functions, how do you point to one?
    // ANSWER: The signature of the function pointer dictates WHICH function address is resolved.
    
    // Explicitly defining a pointer to a function taking an 'int'
    void (*intFuncPointer)(int) = compute; 
    
    // Explicitly defining a pointer to a function taking a 'double'
    void (*doubleFuncPointer)(double) = compute;

    std::cout << "\n--- Invoking via Function Pointers ---" << std::endl;
    intFuncPointer(4);       // Executes compute(int)
    doubleFuncPointer(5.0);  // Executes compute(double)

    return 0;
}