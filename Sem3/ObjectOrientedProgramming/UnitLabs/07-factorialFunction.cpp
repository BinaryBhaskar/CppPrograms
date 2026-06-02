// Write a function factorial to calculate the factorial of a number, write appropriate main function also.

#include <iostream>
using namespace std;

int fact(int num) {
    if (num<0) return 0;
    if (num==0) return 1;
    return num*fact(num-1);
}

int main() {
    int a;

    cout << "Enter a number: ";
    cin >> a;

    cout << "Result is " << fact(a) << endl;
    return 0;
}