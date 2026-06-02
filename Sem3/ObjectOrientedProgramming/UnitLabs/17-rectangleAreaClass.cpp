// Write a program to print the area of a rectangle by creating a class named 'Area' having two functions.First function named as ‘readData' takes the length and breadth of the rectangle as parameters and the second function named as ‘calculateArea' returns the area of the rectangle. Length and breadth of the rectangle are entered through keyboard.

#include <iostream>
using namespace std;

class Area {
private:
    float length;
    float breadth;
public:
    void readData() {
        cout << "Enter length of the rectangle: ";
        cin >> length;
        cout << "Enter breadth of the rectangle: ";
        cin >> breadth;
    }
    float calculateArea() {
        return length * breadth;
    }
};

int main() {
    Area rectangle;
    rectangle.readData();
    float area = rectangle.calculateArea();
    cout << "The area of the rectangle is: " << area << endl;
    return 0;
}