// Practice Problem 09: Custom String Class (Subscript [] & Concatenation + Operators)
// Concepts Tested: Operator Overloading ([], +, ==), Dynamic Character Array Management, C-String Manipulation functions.
//
// Description:
// Create your own string class `MyString` wrapping a dynamically allocated character buffer (`char* buffer`).
//
// Requirements:
// 1. Create a class named 'MyString'.
// 2. Private Members:
//    - char* buffer
//    - int length
// 3. Constructors & Destructor:
//    - Default constructor initializing empty string ("").
//    - Parameterized constructor MyString(const char* str).
//    - Copy constructor MyString(const MyString& other).
//    - Copy assignment operator MyString& operator=(const MyString& other).
//    - Destructor ~MyString().
// 4. Overloaded Operators:
//    - char& operator[](int index): Returns reference to character at index with bounds checking.
//    - MyString operator+(const MyString& other) const: Concatenates two MyString objects into a new object.
//    - bool operator==(const MyString& other) const: Compares content using std::strcmp.
// 5. Utility Functions:
//    - int getLength() const
//    - void print() const: Prints buffer to console.
// 6. In main():
//    - Instantiate `s1("Hello, ")` and `s2("World!")`.
//    - Concatenate: `MyString s3 = s1 + s2;` -> print s3.
//    - Modify a character via subscript operator: `s3[0] = 'h';`
//    - Test string comparison using `==`.

#include <iostream>
#include <cstring>

// TODO: Define your MyString class here

int main() {
    // TODO: Write test cases for MyString operators

    return 0;
}
