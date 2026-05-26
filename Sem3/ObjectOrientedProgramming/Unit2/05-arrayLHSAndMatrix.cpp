// Left-Hand Side Array Matrix
// Concepts: Return by Reference, Independent References, Type Checking Verification.
// Task: Build a lightweight integer array tracking utility.
// Requirements:
// Create a global array containing 5 elements initialized to 10, 20, 30, 40, 50.
// Write a function named modifyElement(int index) that returns a reference to that element within the global array.
// In main(), invoke this function on the left side of an assignment operator to change the value of the 3rd element (index 2) directly to 999 (e.g., modifyElement(2) = 999;).
// Declare an independent reference pointing directly to that same 3rd element slot to display the updated change.
// Concept Validation: Write a commented-out section in your code explaining what happens if you try to assign a float* to point directly to your global int array. Why does C++ reject this?

#include <iostream>

int arr[5] = {10, 20, 30, 40, 50};

int& modifyElement(int index) {
    return arr[index];
}

int main() {
    modifyElement(2) = 999;

    int& independentRef = arr[2];

    // float* floatRef = &arr[2];
    // C++ rejects this because trying to read int as float, C++ will only find garbage data.

    std::cout << independentRef << std::endl;
    return 0;
}