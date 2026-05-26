// The Connected Cluster
// Concepts: The this Pointer, Dynamic Allocation (new[]/delete[]), Pointer to Class Members Syntax.
// Task: Create a system tracking coordinates using raw memory structures.
// Requirements:
// Create a class Point with public data attributes int x and int y.
// Implement a constructor where the parameters are also named x and y. Use the this pointer explicitly to resolve the naming conflict.
// Write a public method inside Point named render() that displays coordinates on screen.
// In main(), use the dynamic allocation operator to allocate an array of 3 Point objects on the Heap. Use the bracket syntax initialization rules to set unique values.
// Declare a pointer to a data member specifically targeting the y variable (int Point::*yPtr). Use it to increment the y coordinate of the second element in your dynamic array.
// Declare a pointer to a member function targeting render(). Invoke it using the array element pointer structure.
// Run standard explicit cleanup using the correct variant of delete to avoid a heap memory leak.

#include <iostream>

class Point {
public:
    int x, y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void render() {
        std::cout << "Point is located at x = " << x << ", y = " << y << std::endl;
    }
};

int main() {
    Point* points = new Point[3] {
        Point(1,3),
        Point(5,6),
        Point(2,7)
    };

    int Point::*yPtr = &Point::y;

    points[1].*yPtr += 1;

    void (Point::*renderPtr)() = &Point::render;

    for (int i = 0; i < 3; i++) {
        (points[i].*renderPtr)();
    }

    delete[] points;

    return 0;
}