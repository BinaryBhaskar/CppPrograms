// Practice Problem 07: Abstract Geometry Shapes & Dynamic Polymorphism
// Concepts Tested: Abstract Base Class (ABC), Pure Virtual Functions (= 0), Dynamic Binding, Base Pointers.
//
// Description:
// Create an abstract geometry shape engine. Calculate area and perimeter for arbitrary shapes at runtime using polymorphism.
//
// Requirements:
// 1. Abstract Base Class 'Shape':
//    - Protected Member: std::string color.
//    - Constructor: Shape(std::string c)
//    - Pure Virtual Functions:
//        * virtual double calculateArea() const = 0;
//        * virtual double calculatePerimeter() const = 0;
//    - Virtual Destructor: virtual ~Shape() {}
//    - Virtual Function: virtual void draw() const { std::cout << "Drawing shape of color: " << color << std::endl; }
// 2. Concrete Derived Class 'Circle':
//    - Private Member: double radius.
//    - Implement calculateArea() [π * r^2] and calculatePerimeter() [2 * π * r]. (Use 3.14159 for π).
// 3. Concrete Derived Class 'Rectangle':
//    - Private Members: double width, height.
//    - Implement calculateArea() [w * h] and calculatePerimeter() [2 * (w + h)].
// 4. In main():
//    - Create an array of Shape pointers (`Shape* shapes[2]`).
//    - Assign a dynamic `Circle` and `Rectangle` object to the pointers.
//    - Loop through the array, calling `draw()`, `calculateArea()`, and `calculatePerimeter()` polymorphically.
//    - Clean up dynamic memory using `delete`.

#include <iostream>
#include <string>

// TODO: Define Shape, Circle, and Rectangle classes here

int main() {
    // TODO: Demonstrate runtime polymorphism via base class pointers

    return 0;
}
