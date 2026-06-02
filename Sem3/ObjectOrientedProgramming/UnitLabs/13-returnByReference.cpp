// Write a program to show the use of return by reference.

#include <iostream>
using namespace std;

int& getElement(int* arr, int index) {
    return arr[index];
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    getElement(arr, 2) = 10; // Modifying the element at index 2

    cout << "Modified array: ";
    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}