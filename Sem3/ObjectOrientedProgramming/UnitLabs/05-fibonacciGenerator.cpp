// Write a program to generate n numbers of fibonacii series. Value of n should be provided by user.

#include <iostream>
using namespace std;

int main() {
    int num, prev=0, next = 1;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Fibonacci series: ";
    if (num>1) cout << prev << " " << next;
    else if (num>=0) cout << prev;

    for (int i=1; i<=num-2; i++) {
        int temp = next;
        next = prev + next;
        prev = temp;
        cout << " " << next;
    }

    cout << endl;

    return 0;
}