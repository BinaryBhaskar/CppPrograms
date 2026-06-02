// Write a program to perform overloading of area function.

#include <iostream>
using namespace std;

float area(float r) {
    return 3.14*r*r;
}

float area(float l, float b) {
    return l*b;
}

int main() {
    float r, l, b;
    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of circle is: " << area(r) << endl;

    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of rectangle is: " << area(l, b) << endl;

    return 0;
}