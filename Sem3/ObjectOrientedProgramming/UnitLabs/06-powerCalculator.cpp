// Write a function to calculate the power of a number raised to another number using function. Write appropriate main() function to read and display the result.

#include <iostream>
using namespace std;

int pow(int num, int exp) {
    if (exp<=0) return 1;
    return num*pow(num, exp-1);
}

int main() {
    int a, m;

    cout << "Enter a number: ";
    cin >> a;

    cout << "Enter exponent: ";
    cin >> m;

    cout << "Result is " << pow(a, m) << endl;
    return 0;
}