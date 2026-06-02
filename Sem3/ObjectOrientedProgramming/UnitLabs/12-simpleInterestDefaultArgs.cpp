// Write a program to calculate simple interest. Use default argument for rate. Write main function to exhibit the use of default argument.

#include <iostream>
using namespace std;

float simpleInterest(float p, float t, float r=5) {
    return p*t*r/100;
}

int main() {
    float p, t, r;
    cout << "Enter principal amount: ";
    cin >> p;
    cout << "Enter time period: ";
    cin >> t;
    cout << "Enter rate (or 0 to use default): ";
    cin >> r;
    if (r==0) {
        cout << "Simple interest is: " << simpleInterest(p, t) << endl;
    } else {
        cout << "Simple interest is: " << simpleInterest(p, t, r) << endl;
    }
}