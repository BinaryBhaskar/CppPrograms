#include <iostream>

class BaseClass {
public:
    virtual void displayType() { std::cout << "This is the Base Class layout." << std::endl; }
};

class DerivedClass : public BaseClass {
public:
    void displayType() override { std::cout << "This is the Derived Class layout." << std::endl; }
};

class Counter {
public:
    int count = 0;
};

// 1. Reference Parameter / Call by Reference
// Avoids copying overhead; manipulates the target original data element directly.
void incrementValue(int& valueRef) {
    valueRef++;
}

// 2. Passing References to Objects
void resetCounter(Counter& cRef) {
    cRef.count = 0; // Updates the target object variable directly
}

// 3. Return by Reference
// Returns an actual alias back. Allows the function call expression to exist on the LEFT side of "="!
int& globalArrayLookup(int index, int* sourceArray) {
    return sourceArray[index]; 
}

int main() {
    std::cout << "=== TOPIC: REFERENCES & POINTERS ===" << std::endl;

    // 4. Independent Reference
    // Must be bound directly to an existing variable upon declaration. Cannot be NULL or re-assigned.
    int primaryData = 10;
    int& independentRef = primaryData; 
    independentRef = 50; // Alters primaryData directly
    std::cout << "Independent Reference Value Update: " << primaryData << std::endl;

    // Call by Reference Check
    int targetNum = 5;
    incrementValue(targetNum);
    std::cout << "Value post call-by-reference function: " << targetNum << std::endl;

    // Return by Reference Assignment Check
    int grades[3] = {70, 80, 90};
    globalArrayLookup(1, grades) = 99; // Overwrites the element at index 1 directly!
    std::cout << "Modified array element via Return-by-Reference: " << grades[1] << std::endl;

    // 5. Type Checking C++ Pointers
    int numericalVal = 100;
    int* pInt = &numericalVal;
    // double* pDouble = pInt; // COMPILER ERROR: C++ enforces strict static data type pointer rules.

    // 6. Pointer to Derived Types
    std::cout << "\n--- Polymorphic Base Pointer Execution ---" << std::endl;
    BaseClass* polymorphismPtr;
    DerivedClass derivedObj;
    polymorphismPtr = &derivedObj; // Completely valid context rule: Base pointer targets Derived object
    polymorphismPtr->displayType(); // Executes derived method implementation due to virtual keyword behavior

    return 0;
}