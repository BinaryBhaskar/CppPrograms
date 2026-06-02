// Write a program to perform overloading of subscripting operator.

#include <iostream>
class MyArray {
private:
    int arr[5];
public:
    MyArray() {
        for (int i = 0; i < 5; ++i) {
            arr[i] = 0; // Initialize array elements to 0
        }
    }
    int& operator[](int index) {
        if (index >= 0 && index < 5) {
            return arr[index]; // Return reference to the array element
        } else {
            throw std::out_of_range("Index out of range");
        }
    }
    void display() const {
        std::cout << "Array elements: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyArray myArray; // Create an instance of MyArray
    myArray.display(); // Display initial array elements

    // Modify array elements using the overloaded subscript operator
    for (int i = 0; i < 5; ++i) {
        myArray[i] = i + 1; // Set array elements to 1, 2, 3, 4, 5
    }

    myArray.display(); // Display modified array elements

    return 0;
}