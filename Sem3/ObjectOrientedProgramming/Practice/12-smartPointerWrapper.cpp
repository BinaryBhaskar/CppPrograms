// Practice Problem 12: Custom Smart Pointer Template (RAII & Operator Overloading)
// Concepts Tested: Class Templates, Resource Acquisition Is Initialization (RAII), Overloading Arrow (->) & Dereference (*) Operators.
//
// Description:
// Build a custom template smart pointer class `SmartPtr<T>` that wraps a raw dynamically allocated heap pointer
// and automatically deletes it when out of scope.
//
// Requirements:
// 1. Template Class 'SmartPtr<T>':
//    - Private Member: T* ptr
// 2. Constructors & Destructor:
//    - Explicit Constructor: explicit SmartPtr(T* p = nullptr) : ptr(p) {}
//    - Destructor: ~SmartPtr() { delete ptr; } -> Prevents memory leaks.
//    - Delete Copy Constructor and Copy Assignment Operator (`SmartPtr(const SmartPtr&) = delete;`) to avoid duplicate free.
// 3. Overloaded Operators:
//    - T& operator*(): Dereferences pointer.
//    - T* operator->(): Provides arrow member access.
//    - bool isNull() const: Returns true if ptr is nullptr.
// 4. Test Helper Class 'TestObject':
//    - Include a method `void speak() const { std::cout << "TestObject method called!" << std::endl; }`.
// 5. In main():
//    - Create a `SmartPtr<int>` wrapping `new int(42)`. Dereference it using `*` operator.
//    - Create a `SmartPtr<TestObject>` wrapping `new TestObject()`. Access `speak()` using `->` operator.
//    - Verify that no memory leaks occur when execution leaves main scope.

#include <iostream>

// TODO: Define SmartPtr<T> template class and TestObject here

int main() {
    // TODO: Test custom smart pointer behavior

    return 0;
}
