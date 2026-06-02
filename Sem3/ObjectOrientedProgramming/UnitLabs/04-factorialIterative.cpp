// Write a program to calculate factorial of a given number.

#include <iostream>
using namespace std;

int main() {
    int num, fac=1;
    cout << "Enter a number: ";
    cin >> num;

    for (int i=1; i<=num; i++) {
        fac *= i;
    }

    cout << "Factorial result: " << fac << endl;

    return 0;
}
