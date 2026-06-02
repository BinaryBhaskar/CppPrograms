// Write a program with overloaded volume function. Use volume function to calculate the volume of a cube, cone, sphere etc.

#include <iostream>
using namespace std;

float volume(float a) {
    return a*a*a;
}

float volume(float r, float h) {
    return 3.14*r*r*h/3;
}

float volume(float r, float h, int dummy) {
    return 4*3.14*r*r*r/3;
}

int main() {
    float a, r, h;
    cout << "Enter side of cube: ";
    cin >> a;
    cout << "Volume of cube is: " << volume(a) << endl;

    cout << "Enter radius and height of cone: ";
    cin >> r >> h;
    cout << "Volume of cone is: " << volume(r, h) << endl;

    cout << "Enter radius of sphere: ";
    cin >> r;
    cout << "Volume of sphere is: " << volume(r, h, 0) << endl;

    return 0;
}
