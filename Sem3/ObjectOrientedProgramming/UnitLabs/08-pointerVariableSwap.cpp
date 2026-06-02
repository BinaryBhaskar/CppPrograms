// Write a function swap to swap the value of two integer variables. Write appropriate main function for the program.

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int* p = a;
    a = b;
    b = p;
}

int main() {
    int a=1, b=2;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}