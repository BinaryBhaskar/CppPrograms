// Practice Problem 03: Matrix Class with Deep Copy
// Concepts Tested: Dynamic Memory Allocation (new/delete), Copy Constructor, Copy Assignment Operator (operator=), Destructor.
//
// Description:
// Implement a Matrix class managing a 2D dynamic integer array on the heap. Ensure deep copying is handled
// properly so that assigning or copying Matrix objects does not cause double-free bugs or shared pointer corruption.
//
// Requirements:
// 1. Create a class named 'Matrix'.
// 2. Private Members:
//    - int rows, cols
//    - int** data (pointer to pointer for 2D array)
// 3. Constructors & Destructor:
//    - Matrix(int r, int c): Allocates memory for r x c matrix, initializes elements to 0.
//    - ~Matrix(): Frees all dynamically allocated heap memory.
//    - Matrix(const Matrix& other): Deep copy constructor allocating new heap space and copying data.
//    - Matrix& operator=(const Matrix& other): Deep copy assignment operator with self-assignment check (`if (this == &other)`).
// 4. Member Functions:
//    - void setValue(int r, int c, int val): Sets element at (r, c).
//    - int getValue(int r, int c) const: Returns element at (r, c).
//    - void print() const: Prints matrix in row-column grid format.
// 5. In main():
//    - Instantiate a 2x3 Matrix `m1` and set some values.
//    - Use copy constructor: `Matrix m2 = m1;`
//    - Modify `m1`. Verify `m2` remains unchanged (proving deep copy).
//    - Test assignment operator: `m3 = m1;`

#include <iostream>

// TODO: Define your Matrix class here

int main() {
    // TODO: Write test cases verifying constructor, copy constructor, operator=, and destructor

    return 0;
}
